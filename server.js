
const express = require('express');
const cors = require('cors');
const helmet = require('helmet');
const morgan = require('morgan');
const multer = require('multer');
const path = require('path');
const crypto = require('crypto');
let bcrypt;
try { bcrypt = require('bcrypt'); } catch { bcrypt = null; }

const app = express();
const PORT = process.env.PORT || 3000;
const PUBLIC_DIR = path.join(__dirname, 'public');
const SUPABASE_URL = (process.env.SUPABASE_URL || '').replace(/\/$/, '');
const SUPABASE_SERVICE_ROLE_KEY = process.env.SUPABASE_SERVICE_ROLE_KEY || process.env.SUPABASE_SERVICE_KEY || '';
const USE_SUPABASE = Boolean(SUPABASE_URL && SUPABASE_SERVICE_ROLE_KEY);
const MODULES = ['fmds','glKpi','tlKpi','processAllocation','trainingHub','unifiedPortal','shared'];
const upload = multer({ storage: multer.memoryStorage(), limits: { fileSize: 25 * 1024 * 1024 } });
const SESSION_DAYS_DEFAULT = 1;
const SESSION_DAYS_REMEMBER = 7;

function requireSupabase() { if (!USE_SUPABASE) throw new Error('Supabase is not configured. Add SUPABASE_URL and SUPABASE_SERVICE_ROLE_KEY in Render Environment.'); }
function safeJsonParse(v, fallback) { try { return typeof v === 'string' ? JSON.parse(v) : v; } catch { return fallback; } }
function jsonString(v) { return typeof v === 'string' ? v : JSON.stringify(v ?? null); }
function genToken() { return crypto.randomBytes(40).toString('hex'); }
async function hashPassword(plain) {
  if (bcrypt) return bcrypt.hash(plain, 10);
  const salt = crypto.randomBytes(16).toString('hex');
  const hash = crypto.pbkdf2Sync(plain, salt, 100000, 64, 'sha512').toString('hex');
  return `pbkdf2:${salt}:${hash}`;
}
async function verifyPassword(plain, stored) {
  if (!stored) return false;
  if (bcrypt && !String(stored).startsWith('pbkdf2:')) return bcrypt.compare(plain, stored);
  const [, salt, hash] = String(stored).split(':');
  const attempt = crypto.pbkdf2Sync(plain, salt, 100000, 64, 'sha512').toString('hex');
  return attempt === hash;
}
function sbHeaders(extra={}) { return { apikey: SUPABASE_SERVICE_ROLE_KEY, Authorization: `Bearer ${SUPABASE_SERVICE_ROLE_KEY}`, 'Content-Type': 'application/json', ...extra }; }
async function sb(pathname, options={}) {
  requireSupabase();
  const res = await fetch(`${SUPABASE_URL}/rest/v1/${pathname}`, { ...options, headers: sbHeaders(options.headers || {}) });
  const text = await res.text();
  let body = null; try { body = text ? JSON.parse(text) : null; } catch { body = text; }
  if (!res.ok) throw new Error((body && (body.message || body.error || body.details)) || text || `Supabase HTTP ${res.status}`);
  return body;
}
async function ensureAdmin() {
  requireSupabase();
  const rows = await sb('users?select=id&limit=1', { method:'GET' }).catch(e => { throw new Error('Run SUPABASE_SETUP.sql first. ' + e.message); });
  if (!rows || rows.length === 0) {
    const password_hash = await hashPassword('admin123');
    await sb('users', { method:'POST', headers:{Prefer:'return=minimal'}, body: JSON.stringify([{username:'admin', password_hash, display_name:'Administrator', role:'admin', is_active:true}]) });
    console.log('Default admin created: admin / admin123');
  }
}
async function audit(action, details={}) { try { await sb('audit_log', { method:'POST', headers:{Prefer:'return=minimal'}, body: JSON.stringify([{action, details}]) }); } catch {} }

app.use(cors());
app.use(helmet({ contentSecurityPolicy:false, crossOriginEmbedderPolicy:false }));
app.use(morgan('dev'));
app.use(express.json({ limit:'100mb' }));
app.use(express.urlencoded({ extended:true, limit:'100mb' }));

async function requireAuth(req,res,next) {
  try {
    const auth=req.headers.authorization||'';
    const token=auth.startsWith('Bearer ')?auth.slice(7):req.query._token;
    if(!token) return res.status(401).json({ok:false,error:'Unauthorized'});
    const sessions=await sb(`sessions?select=id,user_id,expires_at,users(id,username,display_name,role,is_active)&token=eq.${encodeURIComponent(token)}&limit=1`, {method:'GET'});
    const s=sessions&&sessions[0];
    if(!s) return res.status(401).json({ok:false,error:'Invalid or expired session'});
    if(new Date(s.expires_at)<new Date()) { await sb(`sessions?id=eq.${s.id}`, {method:'DELETE'}).catch(()=>{}); return res.status(401).json({ok:false,error:'Session expired'}); }
    if(!s.users || !s.users.is_active) return res.status(403).json({ok:false,error:'Account disabled'});
    req.user={id:s.users.id, username:s.users.username, displayName:s.users.display_name, role:s.users.role};
    next();
  } catch(e) { next(e); }
}
function requireRole(...roles){return (req,res,next)=>{ if(!req.user) return res.status(401).json({ok:false,error:'Unauthorized'}); if(!roles.includes(req.user.role)) return res.status(403).json({ok:false,error:'Forbidden'}); next(); };}

app.post('/api/auth/login', async (req,res,next)=>{try{
  const {username,password,remember}=req.body||{}; if(!username||!password) return res.status(400).json({ok:false,error:'Username and password required'});
  const users=await sb(`users?select=*&username=ilike.${encodeURIComponent(String(username).trim())}&limit=1`, {method:'GET'});
  const u=users&&users[0]; if(!u || !(await verifyPassword(String(password), u.password_hash))) return res.status(401).json({ok:false,error:'Invalid username or password'});
  if(!u.is_active) return res.status(403).json({ok:false,error:'Account is disabled'});
  const token=genToken(), expires_at=new Date(Date.now()+(remember?SESSION_DAYS_REMEMBER:SESSION_DAYS_DEFAULT)*86400000).toISOString();
  await sb('sessions', {method:'POST', headers:{Prefer:'return=minimal'}, body:JSON.stringify([{user_id:u.id, token, expires_at}])}); await audit('login',{username:u.username});
  res.json({ok:true,token,username:u.username,displayName:u.display_name,role:u.role,expiresAt:expires_at});
}catch(e){next(e)}});
app.post('/api/auth/logout', requireAuth, async (req,res,next)=>{try{const auth=req.headers.authorization||''; const token=auth.startsWith('Bearer ')?auth.slice(7):req.query._token; await sb(`sessions?token=eq.${encodeURIComponent(token)}`,{method:'DELETE'}); res.json({ok:true});}catch(e){next(e)}});
app.get('/api/auth/me', requireAuth, (req,res)=>res.json({ok:true,user:req.user}));
app.post('/api/auth/change-password', requireAuth, async (req,res,next)=>{try{const {currentPassword,newPassword}=req.body||{}; if(!currentPassword||!newPassword) return res.status(400).json({ok:false,error:'Both passwords required'}); const rows=await sb(`users?select=password_hash&id=eq.${req.user.id}&limit=1`,{method:'GET'}); if(!(await verifyPassword(String(currentPassword), rows[0]?.password_hash))) return res.status(401).json({ok:false,error:'Current password is incorrect'}); await sb(`users?id=eq.${req.user.id}`,{method:'PATCH',headers:{Prefer:'return=minimal'},body:JSON.stringify({password_hash:await hashPassword(String(newPassword))})}); await sb(`sessions?user_id=eq.${req.user.id}`,{method:'DELETE'}); res.json({ok:true});}catch(e){next(e)}});

app.get('/api/storage', async (req,res,next)=>{try{const rows=await sb('storage_items?select=key,value,updated_at&order=key.asc',{method:'GET'}); const data={}; (rows||[]).forEach(r=>data[r.key]=safeJsonParse(r.value,r.value)); res.json({ok:true,data,database:'supabase'});}catch(e){next(e)}});
app.get('/api/storage/:key', async (req,res,next)=>{try{const rows=await sb(`storage_items?select=key,value,updated_at&key=eq.${encodeURIComponent(req.params.key)}&limit=1`,{method:'GET'}); const r=rows&&rows[0]; res.json({ok:true,key:req.params.key,value:r?safeJsonParse(r.value,r.value):null,updatedAt:r?.updated_at||null,database:'supabase'});}catch(e){next(e)}});
async function upsertStorage(obj){const rows=Object.entries(obj).map(([key,value])=>({key:String(key),value:jsonString(value),updated_at:new Date().toISOString()})); if(!rows.length) return 0; await sb('storage_items?on_conflict=key',{method:'POST',headers:{Prefer:'resolution=merge-duplicates,return=minimal'},body:JSON.stringify(rows)}); return rows.length;}
app.put('/api/storage/:key', async (req,res,next)=>{try{await upsertStorage({[req.params.key]: req.body?.value}); res.json({ok:true,key:req.params.key,database:'supabase'});}catch(e){next(e)}});
app.delete('/api/storage/:key', async (req,res,next)=>{try{await sb(`storage_items?key=eq.${encodeURIComponent(req.params.key)}`,{method:'DELETE'}); res.json({ok:true,deleted:true,key:req.params.key,database:'supabase'});}catch(e){next(e)}});
app.post('/api/storage/bulk', async (req,res,next)=>{try{res.json({ok:true,count:await upsertStorage(req.body||{}),database:'supabase'});}catch(e){next(e)}});
app.post('/api/storage/bulk-beacon', express.text({type:'*/*',limit:'100mb'}), async (req,res,next)=>{try{res.json({ok:true,count:await upsertStorage(JSON.parse(req.body||'{}')),database:'supabase'});}catch(e){next(e)}});

function normModule(n){const m={fmds:'fmds','gl-kpi':'glKpi',glKpi:'glKpi',glkpi:'glKpi','tl-kpi':'tlKpi',tlKpi:'tlKpi',tlkpi:'tlKpi','process-allocation':'processAllocation',processAllocation:'processAllocation',processallocation:'processAllocation','training-hub':'trainingHub',trainingHub:'trainingHub',traininghub:'trainingHub',unified:'unifiedPortal',unifiedPortal:'unifiedPortal',unifiedportal:'unifiedPortal',shared:'shared'}; return m[n]||m[String(n||'').toLowerCase()]||null;}
app.get('/api/modules/:module', async(req,res,next)=>{try{const module=normModule(req.params.module); const rows=await sb(`module_data?select=module,data,updated_at&module=eq.${module}&limit=1`,{method:'GET'}); const r=rows&&rows[0]; res.json({ok:true,module,data:r?safeJsonParse(r.data,{}):{},updatedAt:r?.updated_at||null,database:'supabase'});}catch(e){next(e)}});
app.put('/api/modules/:module', async(req,res,next)=>{try{const module=normModule(req.params.module); await sb('module_data?on_conflict=module',{method:'POST',headers:{Prefer:'resolution=merge-duplicates,return=minimal'},body:JSON.stringify([{module,data:req.body?.data||req.body||{},updated_at:new Date().toISOString()}])}); res.json({ok:true,module,database:'supabase'});}catch(e){next(e)}});
app.patch('/api/modules/:module', async(req,res,next)=>{try{const module=normModule(req.params.module); const rows=await sb(`module_data?select=data&module=eq.${module}&limit=1`,{method:'GET'}); const current=safeJsonParse(rows?.[0]?.data||{},{}); const data={...current,...(req.body?.data||req.body||{})}; await sb('module_data?on_conflict=module',{method:'POST',headers:{Prefer:'resolution=merge-duplicates,return=minimal'},body:JSON.stringify([{module,data,updated_at:new Date().toISOString()}])}); res.json({ok:true,module,data,database:'supabase'});}catch(e){next(e)}});

app.get('/api/health', async(req,res)=>{try{await ensureAdmin(); res.json({ok:true,app:'Toyota LineFlow Backend',database:'supabase-free-tier',supabase:'connected',updatedAt:new Date().toISOString(),modules:MODULES});}catch(e){res.status(500).json({ok:false,database:'supabase-free-tier',error:e.message});}});
app.get('/api/data', async(req,res,next)=>{try{const storageRows=await sb('storage_items?select=key,value',{method:'GET'}); const moduleRows=await sb('module_data?select=module,data',{method:'GET'}); const localStorage={}; (storageRows||[]).forEach(r=>localStorage[r.key]=safeJsonParse(r.value,r.value)); const modules={}; (moduleRows||[]).forEach(r=>modules[r.module]=safeJsonParse(r.data,{})); res.json({ok:true,database:'supabase-free-tier',modules,localStorage});}catch(e){next(e)}});
app.put('/api/data', async(req,res,next)=>{try{if(req.body?.localStorage) await upsertStorage(req.body.localStorage); res.json({ok:true,database:'supabase'});}catch(e){next(e)}});
app.post('/api/export-json', async(req,res,next)=>{try{const rows=await sb('storage_items?select=key,value',{method:'GET'}); const localStorage={}; (rows||[]).forEach(r=>localStorage[r.key]=safeJsonParse(r.value,r.value)); res.json({ok:true,exportedAt:new Date().toISOString(),database:'supabase-free-tier',localStorage});}catch(e){next(e)}});
app.get('/api/export-json', async(req,res,next)=>{try{const rows=await sb('storage_items?select=key,value',{method:'GET'}); const localStorage={}; (rows||[]).forEach(r=>localStorage[r.key]=safeJsonParse(r.value,r.value)); res.json({ok:true,exportedAt:new Date().toISOString(),database:'supabase-free-tier',localStorage});}catch(e){next(e)}});
app.post('/api/import-json', async(req,res,next)=>{try{if(req.body?.localStorage) await upsertStorage(req.body.localStorage); res.json({ok:true,database:'supabase'});}catch(e){next(e)}});
app.post('/api/backup', async(req,res)=>res.json({ok:true,message:'Supabase is the live database. Use Supabase backups/export for backup.'}));
app.get('/api/backups', async(req,res)=>res.json({ok:true,backups:[],message:'Supabase mode'}));

app.use(express.static(PUBLIC_DIR));
app.get('/', (req,res)=>res.sendFile(path.join(PUBLIC_DIR,'login.html')));
app.use((err,req,res,next)=>{console.error(err);res.status(500).json({ok:false,error:err.message||'Server error'});});

ensureAdmin().catch(e=>console.warn('Startup Supabase check:', e.message)).finally(()=>{
  app.listen(PORT,()=>console.log(`Toyota LineFlow Supabase backend running on :${PORT}`));
});
