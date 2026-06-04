/* LineFlow Supabase Auto-Save Sync v3 */
(function () {
  const API = window.BACKEND_API || '';
  const MAX_VALUE_LENGTH = 50 * 1024 * 1024;
  const statusId = 'backend-sync-status';
  const META_KEY = '__lineflow_sync_meta_v3__';
  const INTERNAL_KEYS = new Set([META_KEY]);
  const originalSet = localStorage.setItem.bind(localStorage);
  const originalGet = localStorage.getItem.bind(localStorage);
  const originalRemove = localStorage.removeItem.bind(localStorage);
  let queue = {}; let timer = null; let lastPulled = 0; let pullInProgress = false; let suppressQueue = false;
  function now(){return Date.now();}
  function parseJsonSafe(v,f){try{return v?JSON.parse(v):f;}catch{return f;}}
  function getMeta(){return parseJsonSafe(originalGet(META_KEY),{});} function setMeta(m){try{originalSet(META_KEY,JSON.stringify(m||{}));}catch{}}
  function markLocalChange(key){key=String(key); if(INTERNAL_KEYS.has(key))return; const m=getMeta(); m[key]=now(); setMeta(m);}
  function showStatus(text,ok){let el=document.getElementById(statusId); if(!el){el=document.createElement('div');el.id=statusId;el.style.cssText='position:fixed;right:10px;bottom:10px;z-index:999999;padding:6px 10px;border-radius:999px;font:11px Arial;background:rgba(10,15,28,.92);color:#e6f1ff;border:1px solid rgba(0,212,255,.3);box-shadow:0 4px 15px rgba(0,0,0,.35)'; const add=()=>document.body&&document.body.appendChild(el); if(document.body)add(); else document.addEventListener('DOMContentLoaded',add);} el.textContent=text; el.style.borderColor=ok?'rgba(0,255,136,.45)':'rgba(255,204,0,.55)';}
  function normalizeValueForServer(v){if(v===undefined)return ''; if(typeof v==='string')return v; try{return JSON.stringify(v);}catch{return String(v);}}
  function queueSet(key,value,immediate){key=String(key); if(INTERNAL_KEYS.has(key))return; const str=normalizeValueForServer(value); if(str.length>MAX_VALUE_LENGTH){showStatus('Supabase sync: item too large',false);return;} queue[key]=str; if(immediate)flush(); else scheduleFlush(300);}
  function scheduleFlush(ms){clearTimeout(timer); timer=setTimeout(flush,ms||500);}
  async function pull(){if(pullInProgress)return; pullInProgress=true; try{const res=await fetch(API+'/api/storage',{cache:'no-store'}); const json=await res.json(); if(!json.ok)throw new Error(json.error||'Storage API failed'); const meta=getMeta(); suppressQueue=true; Object.entries(json.data||{}).forEach(([k,v])=>{if(v===null||v===undefined||INTERNAL_KEYS.has(k))return; if((meta[k]||0)>lastPulled)return; originalSet(k,typeof v==='string'?v:JSON.stringify(v));}); suppressQueue=false; lastPulled=now(); showStatus('Supabase sync: connected',true);}catch(e){suppressQueue=false; showStatus('Supabase sync: offline/local mode',false);}finally{pullInProgress=false;}}
  async function flush(){clearTimeout(timer); const entries=Object.entries(queue); if(!entries.length)return {ok:true,count:0}; const batch={}; entries.forEach(([k,v])=>batch[k]=v); queue={}; try{const payload=JSON.stringify(batch); const res=await fetch(API+'/api/storage/bulk',{method:'POST',headers:{'Content-Type':'application/json'},body:payload,keepalive:payload.length<60000}); const json=await res.json().catch(()=>({})); if(!res.ok||json.ok===false)throw new Error(json.error||'Bulk save failed'); showStatus('Supabase sync: saved',true); return json;}catch(e){Object.assign(queue,batch); showStatus('Supabase sync: retrying',false); scheduleFlush(3000); return {ok:false,error:e.message};}}
  function queueAllLocalStorage(immediate){for(let i=0;i<localStorage.length;i++){const key=localStorage.key(i); if(!key||INTERNAL_KEYS.has(key))continue; const val=originalGet(key); if(val!==null&&val!==undefined)queueSet(key,val,false);} if(immediate)return flush(); scheduleFlush(500);}
  localStorage.setItem=function(key,value){originalSet(key,value); if(!suppressQueue){markLocalChange(key); queueSet(key,value,true);}};
  localStorage.removeItem=function(key){originalRemove(key); markLocalChange(key); fetch(API+'/api/storage/'+encodeURIComponent(key),{method:'DELETE',keepalive:true}).then(()=>showStatus('Supabase sync: deleted',true)).catch(()=>showStatus('Supabase sync: delete retry later',false));};
  function handleLikelyChangeEvent(){setTimeout(()=>queueAllLocalStorage(true),250);}
  ['change','input','blur'].forEach(evt=>document.addEventListener(evt,e=>{const t=e.target; if(t&&t.matches&&t.matches('input, textarea, select, [contenteditable="true"]'))handleLikelyChangeEvent();},true));
  document.addEventListener('click',e=>{const el=e.target&&e.target.closest?e.target.closest('button, .btn, .ghost, [onclick], [role="button"]'):null; if(el){setTimeout(()=>queueAllLocalStorage(true),350);setTimeout(()=>queueAllLocalStorage(true),1200);}},true);
  const startObserver=()=>{try{const mo=new MutationObserver(()=>{clearTimeout(window.__lineflowAutoSaveMutationTimer); window.__lineflowAutoSaveMutationTimer=setTimeout(()=>queueAllLocalStorage(false),1000);}); mo.observe(document.body,{childList:true,subtree:true,attributes:true,characterData:true});}catch{}}; if(document.body)startObserver(); else document.addEventListener('DOMContentLoaded',startObserver);
  window.backendSyncNow=flush; window.supabaseSyncNow=flush; window.forceSupabaseSyncAll=()=>queueAllLocalStorage(true); window.backendPullNow=pull; window.supabasePullNow=pull;
  pull().then(()=>setTimeout(()=>queueAllLocalStorage(false),1200)); setInterval(()=>queueAllLocalStorage(false),10000); setInterval(flush,5000);
  function finalSave(){try{const batch={}; for(let i=0;i<localStorage.length;i++){const key=localStorage.key(i); if(!key||INTERNAL_KEYS.has(key))continue; const val=originalGet(key); if(val!==null&&val!==undefined&&String(val).length<=MAX_VALUE_LENGTH)batch[key]=val;} Object.assign(queue,batch); const payload=JSON.stringify(queue); if(navigator.sendBeacon&&payload.length<60*1024){navigator.sendBeacon(API+'/api/storage/bulk-beacon',new Blob([payload],{type:'application/json'})); queue={};}else{flush();}}catch{}}
  window.addEventListener('pagehide',finalSave); window.addEventListener('beforeunload',finalSave); document.addEventListener('visibilitychange',()=>{if(document.visibilityState==='hidden')finalSave(); if(document.visibilityState==='visible')pull();});
})();
