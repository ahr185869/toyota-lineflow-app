const express = require('express');
const cors = require('cors');
const helmet = require('helmet');
const morgan = require('morgan');
const multer = require('multer');
const fs = require('fs');
const fsp = fs.promises;
const path = require('path');
const sqlite3 = require('sqlite3').verbose();

const app = express();
const PORT = process.env.PORT || 3000;
const DATA_DIR = process.env.DATA_DIR || path.join(__dirname, 'data');
const DB_FILE = process.env.DATABASE_FILE || path.join(DATA_DIR, 'toyota_lineflow.sqlite');
const BACKUP_DIR = process.env.BACKUP_DIR || path.join(DATA_DIR, 'backups');
const PUBLIC_DIR = path.join(__dirname, 'public');

const upload = multer({ storage: multer.memoryStorage(), limits: { fileSize: 25 * 1024 * 1024 } });

const MODULES = [
  'fmds',
  'glKpi',
  'tlKpi',
  'processAllocation',
  'trainingHub',
  'unifiedPortal',
  'shared'
];

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

async function ensureDirs() {
  await fsp.mkdir(DATA_DIR, { recursive: true });
  await fsp.mkdir(BACKUP_DIR, { recursive: true });
}

let db;

function openDatabase() {
  return new Promise((resolve, reject) => {
    const database = new sqlite3.Database(DB_FILE, err => {
      if (err) reject(err);
      else resolve(database);
    });
  });
}

function run(sql, params = []) {
  return new Promise((resolve, reject) => {
    db.run(sql, params, function(err) {
      if (err) reject(err);
      else resolve({ lastID: this.lastID, changes: this.changes });
    });
  });
}

function get(sql, params = []) {
  return new Promise((resolve, reject) => {
    db.get(sql, params, (err, row) => {
      if (err) reject(err);
      else resolve(row);
    });
  });
}

function all(sql, params = []) {
  return new Promise((resolve, reject) => {
    db.all(sql, params, (err, rows) => {
      if (err) reject(err);
      else resolve(rows);
    });
  });
}

function safeJsonParse(value, fallback) {
  if (value === null || value === undefined || value === '') return fallback;
  try { return JSON.parse(value); } catch { return fallback; }
}

async function initDatabase() {
  await ensureDirs();
  db = await openDatabase();
  await run('PRAGMA journal_mode = WAL');
  await run('PRAGMA foreign_keys = ON');

  await run(`CREATE TABLE IF NOT EXISTS app_meta (
    key TEXT PRIMARY KEY,
    value TEXT NOT NULL,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP
  )`);

  await run(`CREATE TABLE IF NOT EXISTS module_data (
    module TEXT PRIMARY KEY,
    data TEXT NOT NULL DEFAULT '{}',
    created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP
  )`);

  await run(`CREATE TABLE IF NOT EXISTS storage_items (
    key TEXT PRIMARY KEY,
    value TEXT,
    created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP
  )`);

  await run(`CREATE TABLE IF NOT EXISTS audit_log (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    action TEXT NOT NULL,
    details TEXT NOT NULL DEFAULT '{}',
    created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP
  )`);

  await run(`CREATE TABLE IF NOT EXISTS named_records (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    module TEXT NOT NULL,
    record_type TEXT NOT NULL,
    record_key TEXT,
    data TEXT NOT NULL DEFAULT '{}',
    created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP
  )`);

  await run(`CREATE INDEX IF NOT EXISTS idx_named_records_module_type ON named_records(module, record_type)`);

  await run(`INSERT OR IGNORE INTO app_meta(key, value) VALUES('version', '2.0.0-sqlite')`);
  await run(`INSERT OR IGNORE INTO app_meta(key, value) VALUES('createdAt', ?)`, [new Date().toISOString()]);
  for (const moduleName of MODULES) {
    await run(`INSERT OR IGNORE INTO module_data(module, data) VALUES(?, '{}')`, [moduleName]);
  }
}

async function audit(action, details = {}) {
  await run(`INSERT INTO audit_log(action, details) VALUES(?, ?)`, [action, JSON.stringify(details)]);
}

async function getDatabaseSnapshot() {
  const metaRows = await all(`SELECT key, value FROM app_meta`);
  const modules = {};
  const moduleRows = await all(`SELECT module, data, updated_at FROM module_data ORDER BY module`);
  for (const row of moduleRows) modules[row.module] = safeJsonParse(row.data, {});

  const localStorage = {};
  const storageRows = await all(`SELECT key, value FROM storage_items ORDER BY key`);
  for (const row of storageRows) localStorage[row.key] = safeJsonParse(row.value, row.value);

  const auditRows = await all(`SELECT id, action, details, created_at FROM audit_log ORDER BY id DESC LIMIT 500`);
  const meta = Object.fromEntries(metaRows.map(r => [r.key, r.value]));
  const latestModule = await get(`SELECT MAX(updated_at) AS updatedAt FROM module_data`);
  const latestStorage = await get(`SELECT MAX(updated_at) AS updatedAt FROM storage_items`);
  const updatedAt = [latestModule?.updatedAt, latestStorage?.updatedAt].filter(Boolean).sort().pop() || new Date().toISOString();

  return {
    version: meta.version || '2.0.0-sqlite',
    createdAt: meta.createdAt,
    updatedAt,
    sqliteFile: DB_FILE,
    modules,
    localStorage,
    audit: auditRows.map(r => ({ id: r.id, at: r.created_at, action: r.action, details: safeJsonParse(r.details, {}) }))
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
    res.json({ ok: true, app: 'Toyota LineFlow Backend', database: 'sqlite', sqliteFile: DB_FILE, updatedAt: snapshot.updatedAt, modules: Object.keys(snapshot.modules) });
  } catch (err) { next(err); }
});

app.get('/api/data', async (req, res, next) => {
  try { res.json(await getDatabaseSnapshot()); } catch (err) { next(err); }
});

app.put('/api/data', async (req, res, next) => {
  try {
    const incoming = req.body || {};
    await run('BEGIN TRANSACTION');
    if (incoming.modules) {
      for (const [rawName, data] of Object.entries(incoming.modules)) {
        const moduleName = normalizeModuleName(rawName);
        if (moduleName) await run(`INSERT INTO module_data(module, data, updated_at) VALUES(?, ?, CURRENT_TIMESTAMP)
          ON CONFLICT(module) DO UPDATE SET data=excluded.data, updated_at=CURRENT_TIMESTAMP`, [moduleName, JSON.stringify(data || {})]);
      }
    }
    if (incoming.localStorage) {
      for (const [key, value] of Object.entries(incoming.localStorage)) {
        await run(`INSERT INTO storage_items(key, value, updated_at) VALUES(?, ?, CURRENT_TIMESTAMP)
          ON CONFLICT(key) DO UPDATE SET value=excluded.value, updated_at=CURRENT_TIMESTAMP`, [key, JSON.stringify(value)]);
      }
    }
    await run(`INSERT INTO audit_log(action, details) VALUES('replace_database', ?)`, [JSON.stringify({ modules: Object.keys(incoming.modules || {}).length, storageKeys: Object.keys(incoming.localStorage || {}).length })]);
    await run('COMMIT');
    res.json({ ok: true, updatedAt: new Date().toISOString() });
  } catch (err) { await run('ROLLBACK').catch(() => {}); next(err); }
});

app.get('/api/modules/:module', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    const row = await get(`SELECT data, updated_at FROM module_data WHERE module = ?`, [moduleName]);
    res.json({ ok: true, module: moduleName, data: safeJsonParse(row?.data, {}), updatedAt: row?.updated_at || null });
  } catch (err) { next(err); }
});

app.put('/api/modules/:module', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    await run(`INSERT INTO module_data(module, data, updated_at) VALUES(?, ?, CURRENT_TIMESTAMP)
      ON CONFLICT(module) DO UPDATE SET data=excluded.data, updated_at=CURRENT_TIMESTAMP`, [moduleName, JSON.stringify(req.body || {})]);
    await audit('save_module', { module: moduleName });
    res.json({ ok: true, module: moduleName, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.patch('/api/modules/:module', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    const row = await get(`SELECT data FROM module_data WHERE module = ?`, [moduleName]);
    const current = safeJsonParse(row?.data, {});
    const nextData = { ...current, ...(req.body || {}) };
    await run(`INSERT INTO module_data(module, data, updated_at) VALUES(?, ?, CURRENT_TIMESTAMP)
      ON CONFLICT(module) DO UPDATE SET data=excluded.data, updated_at=CURRENT_TIMESTAMP`, [moduleName, JSON.stringify(nextData)]);
    await audit('patch_module', { module: moduleName, keys: Object.keys(req.body || {}) });
    res.json({ ok: true, module: moduleName, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.get('/api/storage', async (req, res, next) => {
  try {
    const rows = await all(`SELECT key, value, updated_at FROM storage_items ORDER BY key`);
    const data = {};
    rows.forEach(row => { data[row.key] = safeJsonParse(row.value, row.value); });
    res.json({ ok: true, data });
  } catch (err) { next(err); }
});

app.get('/api/storage/:key', async (req, res, next) => {
  try {
    const row = await get(`SELECT value, updated_at FROM storage_items WHERE key = ?`, [req.params.key]);
    res.json({ ok: true, key: req.params.key, value: row ? safeJsonParse(row.value, row.value) : null, updatedAt: row?.updated_at || null });
  } catch (err) { next(err); }
});

app.put('/api/storage/:key', async (req, res, next) => {
  try {
    await run(`INSERT INTO storage_items(key, value, updated_at) VALUES(?, ?, CURRENT_TIMESTAMP)
      ON CONFLICT(key) DO UPDATE SET value=excluded.value, updated_at=CURRENT_TIMESTAMP`, [req.params.key, JSON.stringify(req.body.value)]);
    await audit('set_storage_key', { key: req.params.key });
    res.json({ ok: true, key: req.params.key, updatedAt: new Date().toISOString() });
  } catch (err) { next(err); }
});

app.delete('/api/storage/:key', async (req, res, next) => {
  try {
    const result = await run(`DELETE FROM storage_items WHERE key = ?`, [req.params.key]);
    await audit('delete_storage_key', { key: req.params.key });
    res.json({ ok: true, key: req.params.key, deleted: result.changes > 0 });
  } catch (err) { next(err); }
});

app.post('/api/storage/bulk', async (req, res, next) => {
  try {
    const entries = Object.entries(req.body || {});
    await run('BEGIN TRANSACTION');
    for (const [key, value] of entries) {
      await run(`INSERT INTO storage_items(key, value, updated_at) VALUES(?, ?, CURRENT_TIMESTAMP)
        ON CONFLICT(key) DO UPDATE SET value=excluded.value, updated_at=CURRENT_TIMESTAMP`, [key, JSON.stringify(value)]);
    }
    await run(`INSERT INTO audit_log(action, details) VALUES('bulk_storage_save', ?)`, [JSON.stringify({ count: entries.length })]);
    await run('COMMIT');
    res.json({ ok: true, count: entries.length, updatedAt: new Date().toISOString() });
  } catch (err) { await run('ROLLBACK').catch(() => {}); next(err); }
});

app.get('/api/records/:module/:recordType', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    const rows = await all(`SELECT id, module, record_type, record_key, data, created_at, updated_at FROM named_records WHERE module=? AND record_type=? ORDER BY id DESC`, [moduleName, req.params.recordType]);
    res.json({ ok: true, records: rows.map(r => ({ ...r, data: safeJsonParse(r.data, {}) })) });
  } catch (err) { next(err); }
});

app.post('/api/records/:module/:recordType', async (req, res, next) => {
  try {
    const moduleName = normalizeModuleName(req.params.module);
    if (!moduleName) return res.status(404).json({ ok: false, error: 'Unknown module' });
    const result = await run(`INSERT INTO named_records(module, record_type, record_key, data) VALUES(?, ?, ?, ?)`, [moduleName, req.params.recordType, req.body.recordKey || null, JSON.stringify(req.body.data || req.body || {})]);
    await audit('create_record', { module: moduleName, recordType: req.params.recordType, id: result.lastID });
    res.json({ ok: true, id: result.lastID });
  } catch (err) { next(err); }
});

app.put('/api/records/:id', async (req, res, next) => {
  try {
    const result = await run(`UPDATE named_records SET data=?, record_key=COALESCE(?, record_key), updated_at=CURRENT_TIMESTAMP WHERE id=?`, [JSON.stringify(req.body.data || req.body || {}), req.body.recordKey || null, req.params.id]);
    await audit('update_record', { id: req.params.id });
    res.json({ ok: true, updated: result.changes > 0 });
  } catch (err) { next(err); }
});

app.delete('/api/records/:id', async (req, res, next) => {
  try {
    const result = await run(`DELETE FROM named_records WHERE id=?`, [req.params.id]);
    await audit('delete_record', { id: req.params.id });
    res.json({ ok: true, deleted: result.changes > 0 });
  } catch (err) { next(err); }
});

app.post('/api/backup', async (req, res, next) => {
  try {
    await ensureDirs();
    const filename = `sqlite-backup-${new Date().toISOString().replace(/[:.]/g, '-')}.sqlite`;
    const backupPath = path.join(BACKUP_DIR, filename);
    await run('PRAGMA wal_checkpoint(FULL)');
    await fsp.copyFile(DB_FILE, backupPath);
    await audit('manual_sqlite_backup', { filename });
    res.json({ ok: true, filename, download: `/api/backup/${filename}` });
  } catch (err) { next(err); }
});

app.get('/api/backups', async (req, res, next) => {
  try {
    await ensureDirs();
    const files = (await fsp.readdir(BACKUP_DIR)).filter(f => f.endsWith('.sqlite') || f.endsWith('.json')).sort().reverse();
    res.json({ ok: true, files });
  } catch (err) { next(err); }
});

app.get('/api/backup/:filename', async (req, res) => {
  const file = path.join(BACKUP_DIR, path.basename(req.params.filename));
  if (!fs.existsSync(file)) return res.status(404).json({ ok: false, error: 'Backup not found' });
  res.download(file);
});

app.post('/api/import-json', upload.single('backup'), async (req, res, next) => {
  try {
    const raw = req.file ? req.file.buffer.toString('utf8') : JSON.stringify(req.body);
    const imported = JSON.parse(raw);
    await run('BEGIN TRANSACTION');
    if (imported.modules) {
      for (const [rawName, data] of Object.entries(imported.modules)) {
        const moduleName = normalizeModuleName(rawName);
        if (moduleName) await run(`INSERT INTO module_data(module, data, updated_at) VALUES(?, ?, CURRENT_TIMESTAMP)
          ON CONFLICT(module) DO UPDATE SET data=excluded.data, updated_at=CURRENT_TIMESTAMP`, [moduleName, JSON.stringify(data || {})]);
      }
    }
    if (imported.localStorage) {
      for (const [key, value] of Object.entries(imported.localStorage)) {
        await run(`INSERT INTO storage_items(key, value, updated_at) VALUES(?, ?, CURRENT_TIMESTAMP)
          ON CONFLICT(key) DO UPDATE SET value=excluded.value, updated_at=CURRENT_TIMESTAMP`, [key, JSON.stringify(value)]);
      }
    }
    await run(`INSERT INTO audit_log(action, details) VALUES('import_json_to_sqlite', ?)`, [JSON.stringify({ importedAt: new Date().toISOString() })]);
    await run('COMMIT');
    res.json({ ok: true, updatedAt: new Date().toISOString() });
  } catch (err) { await run('ROLLBACK').catch(() => {}); next(err); }
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
  app.listen(PORT, () => console.log(`Toyota backend with SQLite running on http://localhost:${PORT}`));
}).catch(err => {
  console.error('Failed to start backend:', err);
  process.exit(1);
});
