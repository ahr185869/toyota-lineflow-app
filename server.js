const express = require('express');
const cors = require('cors');
const helmet = require('helmet');
const morgan = require('morgan');
const multer = require('multer');
const path = require('path');
const { Pool } = require('pg');

const app = express();
const PORT = process.env.PORT || 3000;
const PUBLIC_DIR = path.join(__dirname, 'public');

if (!process.env.DATABASE_URL) {
  console.warn('WARNING: DATABASE_URL is not set. Add your Supabase PostgreSQL connection string in Render Environment Variables.');
}

const pool = new Pool({
  connectionString: process.env.DATABASE_URL,
  ssl: process.env.NODE_ENV === 'production' ? { rejectUnauthorized: false } : false
});

const upload = multer({ storage: multer.memoryStorage(), limits: { fileSize: 25 * 1024 * 1024 } });

const MODULES = ['fmds', 'glKpi', 'tlKpi', 'processAllocation', 'trainingHub', 'unifiedPortal', 'shared'];

function normalizeModuleName(name) {
  const map = {
    fmds: 'fmds',
    'gl-kpi': 'glKpi',
    glKpi: 'glKpi',
    glkpi: 'glKpi',
    'tl-kpi': 'tlKpi',
    tlKpi: 'tlKpi',
    tlkpi: 'tlKpi',
    'process-allocation': 'processAllocation',
    processAllocation: 'processAllocation',
    processallocation: 'processAllocation',
    'training-hub': 'trainingHub',
    trainingHub: 'trainingHub',
    traininghub: 'trainingHub',
    unified: 'unifiedPortal',
    unifiedPortal: 'unifiedPortal',
    unifiedportal: 'unifiedPortal',
    shared: 'shared'
  };
  return map[name] || map[String(name || '').toLowerCase()] || null;
}

function safeValue(value, fallback = {}) {
  if (value === null || value === undefined) return fallback;
  if (typeof value === 'string') {
    try { return JSON.parse(value); } catch { return value; }
  }
  return value;
}

async function query(sql, params = []) {
  return pool.query(sql, params);
}

async function withTransaction(work) {
  const client = await pool.connect();
  try {
    await client.query('BEGIN');
    const result = await work(client);
    await client.query('COMMIT');
    return result;
  } catch (err) {
    await client.query('ROLLBACK').catch(() => {});
    throw err;
  } finally {
    client.release();
  }
}

async function initDatabase() {
  await query(`CREATE TABLE IF NOT EXISTS app_meta (
    key TEXT PRIMARY KEY,
    value TEXT NOT NULL,
    updated_at TIMESTAMPTZ NOT NULL DEFAULT NOW()
  )`);

  await query(`CREATE TABLE IF NOT EXISTS module_data (
    module TEXT PRIMARY KEY,
    data JSONB NOT NULL DEFAULT '{}'::jsonb,
    created_at TIMESTAMPTZ NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMPTZ NOT NULL DEFAULT NOW()
  )`);

  await query(`CREATE TABLE IF NOT EXISTS storage_items (
    key TEXT PRIMARY KEY,
    value JSONB,
    created_at TIMESTAMPTZ NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMPTZ NOT NULL DEFAULT NOW()
  )`);

  await query(`CREATE TABLE IF NOT EXISTS audit_log (
    id BIGSERIAL PRIMARY KEY,
    action TEXT NOT NULL,
    details JSONB NOT NULL DEFAULT '{}'::jsonb,
    created_at TIMESTAMPTZ NOT NULL DEFAULT NOW()
  )`);

  await query(`CREATE TABLE IF NOT EXISTS named_records (
    id BIGSERIAL PRIMARY KEY,
    module TEXT NOT NULL,
    record_type TEXT NOT NULL,
    record_key TEXT,
    data JSONB NOT NULL DEFAULT '{}'::jsonb,
    created_at TIMESTAMPTZ NOT NULL DEFAULT NOW(),
    updated_at TIMESTAMPTZ NOT NULL DEFAULT NOW()
  )`);

  await query(`CREATE INDEX IF NOT EXISTS idx_named_records_module_type ON named_records(module, record_type)`);

  await query(`INSERT INTO app_meta(key, value) VALUES('version', '3.0.0-supabase') ON CONFLICT(key) DO NOTHING`);
  await query(`INSERT INTO app_meta(key, value) VALUES('createdAt', $1) ON CONFLICT(key) DO NOTHING`, [new Date().toISOString()]);
  for (const moduleName of MODULES) {
    await query(`INSERT INTO module_data(module, data) VALUES($1, '{}'::jsonb) ON CONFLICT(module) DO NOTHING`, [moduleName]);
  }
}

async function audit(action, details = {}) {
  await query(`INSERT INTO audit_log(action, details) VALUES($1, $2::jsonb)`, [action, JSON.stringify(details)]);
}

async function getDatabaseSnapshot() {
  const metaRows = (await query(`SELECT key, value FROM app_meta`)).rows;
  const modules = {};
  const moduleRows = (await query(`SELECT module, data, updated_at FROM module_data ORDER BY module`)).rows;
  for (const row of moduleRows) modules[row.module] = safeValue(row.data, {});

  const localStorage = {};
  const storageRows = (await query(`SELECT key, value FROM storage_items ORDER BY key`)).rows;
  for (const row of storageRows) localStorage[row.key] = safeValue(row.value, null);

  const auditRows = (await query(`SELECT id, action, details, created_at FROM audit_log ORDER BY id DESC LIMIT 500`)).rows;
  const meta = Object.fromEntries(metaRows.map(r => [r.key, r.value]));
  const latestModule = (await query(`SELECT MAX(updated_at) AS "updatedAt" FROM module_data`)).rows[0];
  const latestStorage = (await query(`SELECT MAX(updated_at) AS "updatedAt" FROM storage_items`)).rows[0];
  const updatedAt = [latestModule?.updatedAt, latestStorage?.updatedAt].filter(Boolean).sort().pop() || new Date().toISOString();

  return {
    version: meta.version || '3.0.0-supabase',
    createdAt: meta.createdAt,
    updatedAt,
    database: 'supabase-postgresql',
    modules,
    localStorage,
    audit: auditRows.map(r => ({ id: r.id, at: r.created_at, action: r.action, details: safeValue(r.details, {}) }))
  };
}

app.use(cors());
app.use(helmet({ contentSecurityPolicy: false, crossOriginEmbedderPolicy: false }));
app.use(morgan('dev'));
app.use(express.json({ limit: '25mb' }));
app.use(express.urlencoded({ extended: true, limit: '25mb' }));

app.get('/api/health', async (req, res, next) => {
  try {
    const snapshot = await getDatabaseSnapshot();
    res.json({ ok: true, app: 'Toyota LineFlow Backend', database: 'supabase-postgresql', updatedAt: snapshot.updatedAt, modules: Object.keys(snapshot.modules) });
  } catch (err) { next(err); }
});

app.get('/api/data', async (req, res, next) => {
  try { res.json(await getDatabaseSnapshot()); } catch (err) { next(err); }
});

app.put('/api/data', async (req, res, next) => {
  try {
    const incoming = req.body || {};
    await withTransaction(async (client) => {
      if (incoming.modules) {
        for (const [rawName, data] of Object.entries(incoming.modules)) {
          const moduleName = normalizeModuleName(rawName);
          if (moduleName) await client.query(`INSERT INTO module_data(module, data, updated_at) VALUES($1, $2::jsonb, NOW())
            ON CONFLICT(module) DO UPDATE SET data=EXCLUDED.data, updated_at=NOW()`, [moduleName, JSON.stringify(data || {})]);
        }
      }
      if (incoming.localStorage) {
        for (const [key, value] of Object.entries(incoming.localStorage)) {
          await client.query(`INSERT INTO storage_items(key, value, updated_at) VALUES($1, $2::jsonb, NOW())
            ON CONFLICT(key) DO UPDATE SET value=EXCLUDED.value, updated_at=NOW()`, [key, JSON.stringify(value)]);
        }
      }
      await client.query(`INSERT INTO audit_log(action, details) VALUES('replace_database', $1::jsonb)`, [JSON.stringify({ modules: Object.keys(incoming.modules || {}).length, storageKeys: Object.keys(incoming.localStorage || {}).length })]);
    });
    res.json({ ok: true, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.get('/api/modules/:module', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    const row = (await query(`SELECT data, updated_at FROM module_data WHERE module = $1`, [moduleName])).rows[0];
    res.json({ ok: true, module: moduleName, data: safeValue(row?.data, {}), updatedAt: row?.updated_at || null });
  } catch (err) { next(err); }
});

app.put('/api/modules/:module', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    await query(`INSERT INTO module_data(module, data, updated_at) VALUES($1, $2::jsonb, NOW())
      ON CONFLICT(module) DO UPDATE SET data=EXCLUDED.data, updated_at=NOW()`, [moduleName, JSON.stringify(req.body || {})]);
    await audit('save_module', { module: moduleName });
    res.json({ ok: true, module: moduleName, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.patch('/api/modules/:module', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    const row = (await query(`SELECT data FROM module_data WHERE module = $1`, [moduleName])).rows[0];
    const current = safeValue(row?.data, {});
    const nextData = { ...current, ...(req.body || {}) };
    await query(`INSERT INTO module_data(module, data, updated_at) VALUES($1, $2::jsonb, NOW())
      ON CONFLICT(module) DO UPDATE SET data=EXCLUDED.data, updated_at=NOW()`, [moduleName, JSON.stringify(nextData)]);
    await audit('patch_module', { module: moduleName, keys: Object.keys(req.body || {}) });
    res.json({ ok: true, module: moduleName, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.get('/api/storage', async (req, res, next) => {
  try {
    const rows = (await query(`SELECT key, value, updated_at FROM storage_items ORDER BY key`)).rows;
    const data = {};
    rows.forEach(row => { data[row.key] = safeValue(row.value, null); });
    res.json({ ok: true, data });
  } catch (err) { next(err); }
});

app.get('/api/storage/:key', async (req, res, next) => {
  try {
    const row = (await query(`SELECT value, updated_at FROM storage_items WHERE key = $1`, [req.params.key])).rows[0];
    res.json({ ok: true, key: req.params.key, value: row ? safeValue(row.value, null) : null, updatedAt: row?.updated_at || null });
  } catch (err) { next(err); }
});

app.put('/api/storage/:key', async (req, res, next) => {
  try {
    await query(`INSERT INTO storage_items(key, value, updated_at) VALUES($1, $2::jsonb, NOW())
      ON CONFLICT(key) DO UPDATE SET value=EXCLUDED.value, updated_at=NOW()`, [req.params.key, JSON.stringify(req.body.value)]);
    await audit('set_storage_key', { key: req.params.key });
    res.json({ ok: true, key: req.params.key, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.delete('/api/storage/:key', async (req, res, next) => {
  try {
    const result = await query(`DELETE FROM storage_items WHERE key = $1`, [req.params.key]);
    await audit('delete_storage_key', { key: req.params.key });
    res.json({ ok: true, key: req.params.key, deleted: result.rowCount > 0 });
  } catch (err) { next(err); }
});

app.post('/api/storage/bulk', async (req, res, next) => {
  try {
    const entries = Object.entries(req.body || {});
    await withTransaction(async (client) => {
      for (const [key, value] of entries) {
        await client.query(`INSERT INTO storage_items(key, value, updated_at) VALUES($1, $2::jsonb, NOW())
          ON CONFLICT(key) DO UPDATE SET value=EXCLUDED.value, updated_at=NOW()`, [key, JSON.stringify(value)]);
      }
      await client.query(`INSERT INTO audit_log(action, details) VALUES('bulk_storage_save', $1::jsonb)`, [JSON.stringify({ count: entries.length })]);
    });
    res.json({ ok: true, count: entries.length, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.get('/api/records/:module/:recordType', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    const rows = (await query(`SELECT id, module, record_type, record_key, data, created_at, updated_at FROM named_records WHERE module=$1 AND record_type=$2 ORDER BY id DESC`, [moduleName, req.params.recordType])).rows;
    res.json({ ok: true, records: rows.map(r => ({ ...r, data: safeValue(r.data, {}) })) });
  } catch (err) { next(err); }
});

app.post('/api/records/:module/:recordType', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    const result = await query(`INSERT INTO named_records(module, record_type, record_key, data) VALUES($1, $2, $3, $4::jsonb) RETURNING id`, [moduleName, req.params.recordType, req.body.recordKey || null, JSON.stringify(req.body.data || req.body || {})]);
    const id = result.rows[0].id;
    await audit('create_record', { module: moduleName, recordType: req.params.recordType, id });
    res.json({ ok: true, id });
  } catch (err) { next(err); }
});

app.put('/api/records/:id', async (req, res, next) => {
  try {
    const result = await query(`UPDATE named_records SET data=$1::jsonb, record_key=COALESCE($2, record_key), updated_at=NOW() WHERE id=$3`, [JSON.stringify(req.body.data || req.body || {}), req.body.recordKey || null, req.params.id]);
    await audit('update_record', { id: req.params.id });
    res.json({ ok: true, updated: result.rowCount > 0 });
  } catch (err) { next(err); }
});

app.delete('/api/records/:id', async (req, res, next) => {
  try {
    const result = await query(`DELETE FROM named_records WHERE id=$1`, [req.params.id]);
    await audit('delete_record', { id: req.params.id });
    res.json({ ok: true, deleted: result.rowCount > 0 });
  } catch (err) { next(err); }
});

app.post('/api/backup', async (req, res, next) => {
  try {
    const snapshot = await getDatabaseSnapshot();
    await audit('manual_supabase_json_backup', { createdAt: new Date().toISOString() });
    res.json({ ok: true, backupType: 'json', data: snapshot });
  } catch (err) { next(err); }
});

app.get('/api/backups', async (req, res) => {
  res.json({ ok: true, files: [], note: 'Supabase mode stores data in PostgreSQL. Use /api/export-json for backups.' });
});

app.post('/api/import-json', upload.single('backup'), async (req, res, next) => {
  try {
    const raw = req.file ? req.file.buffer.toString('utf8') : JSON.stringify(req.body);
    const imported = JSON.parse(raw);
    await withTransaction(async (client) => {
      if (imported.modules) {
        for (const [rawName, data] of Object.entries(imported.modules)) {
          const moduleName = normalizeModuleName(rawName);
          if (moduleName) await client.query(`INSERT INTO module_data(module, data, updated_at) VALUES($1, $2::jsonb, NOW())
            ON CONFLICT(module) DO UPDATE SET data=EXCLUDED.data, updated_at=NOW()`, [moduleName, JSON.stringify(data || {})]);
        }
      }
      if (imported.localStorage) {
        for (const [key, value] of Object.entries(imported.localStorage)) {
          await client.query(`INSERT INTO storage_items(key, value, updated_at) VALUES($1, $2::jsonb, NOW())
            ON CONFLICT(key) DO UPDATE SET value=EXCLUDED.value, updated_at=NOW()`, [key, JSON.stringify(value)]);
        }
      }
      await client.query(`INSERT INTO audit_log(action, details) VALUES('import_json_to_supabase', $1::jsonb)`, [JSON.stringify({ importedAt: new Date().toISOString() })]);
    });
    res.json({ ok: true, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.get('/api/export-json', async (req, res, next) => {
  try { res.json(await getDatabaseSnapshot()); } catch (err) { next(err); }
});

app.use(express.static(PUBLIC_DIR));
app.get('/', (req, res) => res.sendFile(path.join(PUBLIC_DIR, 'index.html')));
app.get('*', (req, res, next) => {
  if (req.path.startsWith('/api/')) return next();
  res.sendFile(path.join(PUBLIC_DIR, 'index.html'));
});

app.use((err, req, res, next) => {
  console.error(err);
  res.status(500).json({ ok: false, error: err.message || 'Server error' });
});

initDatabase().then(() => {
  app.listen(PORT, () => console.log(`Toyota backend with Supabase PostgreSQL running on http://localhost:${PORT}`));
}).catch(err => {
  console.error('Failed to start backend:', err);
  process.exit(1);
});