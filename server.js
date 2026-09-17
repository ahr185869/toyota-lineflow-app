const express = require('express');
const cors = require('cors');
const helmet = require('helmet');
const morgan = require('morgan');
const path = require('path');
const crypto = require('crypto');

let bcrypt = null;
try { bcrypt = require('bcrypt'); } catch (_) {}

const app = express();
const PORT = Number(process.env.PORT || 3000);
const PUBLIC_DIR = path.join(__dirname, 'public');

const SUPABASE_URL = String(process.env.SUPABASE_URL || '').replace(/\/$/, '');
const SUPABASE_SERVICE_ROLE_KEY =
  process.env.SUPABASE_SERVICE_ROLE_KEY ||
  process.env.SUPABASE_SERVICE_KEY ||
  '';

const USE_SUPABASE = Boolean(SUPABASE_URL && SUPABASE_SERVICE_ROLE_KEY);

const MODULES = [
  'fmds',
  'glKpi',
  'glActivity',
  'tlKpi',
  'processAllocation',
  'trainingHub'
];

const SESSION_DAYS_DEFAULT = 1;
const SESSION_DAYS_REMEMBER = 7;

function requireSupabase() {
  if (!USE_SUPABASE) {
    throw new Error(
      'Supabase is not configured. Set SUPABASE_URL and SUPABASE_SERVICE_ROLE_KEY in Render Environment.'
    );
  }
}

function safeJsonParse(value, fallback) {
  try {
    return typeof value === 'string' ? JSON.parse(value) : value;
  } catch (_) {
    return fallback;
  }
}

function jsonString(value) {
  return typeof value === 'string' ? value : JSON.stringify(value ?? null);
}

function genToken() {
  return crypto.randomBytes(40).toString('hex');
}

async function hashPassword(plain) {
  if (bcrypt) return bcrypt.hash(plain, 10);
  const salt = crypto.randomBytes(16).toString('hex');
  const hash = crypto.pbkdf2Sync(plain, salt, 100000, 64, 'sha512').toString('hex');
  return `pbkdf2:${salt}:${hash}`;
}

async function verifyPassword(plain, stored) {
  if (!stored) return false;
  if (bcrypt && !String(stored).startsWith('pbkdf2:')) {
    return bcrypt.compare(plain, stored);
  }
  const [, salt, hash] = String(stored).split(':');
  if (!salt || !hash) return false;
  const attempt = crypto.pbkdf2Sync(plain, salt, 100000, 64, 'sha512').toString('hex');
  return attempt === hash;
}

function sbHeaders(extra = {}) {
  return {
    apikey: SUPABASE_SERVICE_ROLE_KEY,
    Authorization: `Bearer ${SUPABASE_SERVICE_ROLE_KEY}`,
    'Content-Type': 'application/json',
    ...extra
  };
}

async function sb(pathname, options = {}) {
  requireSupabase();

  const response = await fetch(`${SUPABASE_URL}/rest/v1/${pathname}`, {
    ...options,
    headers: sbHeaders(options.headers || {})
  });

  const text = await response.text();
  let body = null;
  try {
    body = text ? JSON.parse(text) : null;
  } catch (_) {
    body = text;
  }

  if (!response.ok) {
    throw new Error(
      (body && (body.message || body.error || body.details)) ||
      text ||
      `Supabase HTTP ${response.status}`
    );
  }

  return body;
}

async function ensureAdmin() {
  requireSupabase();

  const rows = await sb('users?select=id&limit=1').catch(error => {
    throw new Error(`Run SUPABASE_SETUP.sql first. ${error.message}`);
  });

  if (!rows || rows.length === 0) {
    const password_hash = await hashPassword('admin123');

    await sb('users', {
      method: 'POST',
      headers: { Prefer: 'return=minimal' },
      body: JSON.stringify([{
        username: 'admin',
        password_hash,
        display_name: 'Administrator',
        role: 'admin',
        is_active: true
      }])
    });

    console.log('Default admin created: admin / admin123');
  }
}

async function audit(action, details = {}) {
  try {
    await sb('audit_log', {
      method: 'POST',
      headers: { Prefer: 'return=minimal' },
      body: JSON.stringify([{ action, details }])
    });
  } catch (_) {}
}

function normalizeModule(name) {
  const map = {
    fmds: 'fmds',
    'gl-kpi': 'glKpi',
    glKpi: 'glKpi',
    glkpi: 'glKpi',
    'gl-activity': 'glActivity',
    glActivity: 'glActivity',
    glactivity: 'glActivity',
    'tl-kpi': 'tlKpi',
    tlKpi: 'tlKpi',
    tlkpi: 'tlKpi',
    'process-allocation': 'processAllocation',
    processAllocation: 'processAllocation',
    processallocation: 'processAllocation',
    'training-hub': 'trainingHub',
    trainingHub: 'trainingHub',
    traininghub: 'trainingHub'
  };

  return map[name] || map[String(name || '').toLowerCase()] || null;
}

app.use(cors());
app.use(helmet({
  contentSecurityPolicy: false,
  crossOriginEmbedderPolicy: false
}));
app.use(morgan('dev'));
app.use(express.json({ limit: '100mb' }));
app.use(express.urlencoded({ extended: true, limit: '100mb' }));

async function requireAuth(req, res, next) {
  try {
    const auth = req.headers.authorization || '';
    const token = auth.startsWith('Bearer ')
      ? auth.slice(7)
      : req.query._token;

    if (!token) {
      return res.status(401).json({ ok: false, error: 'Unauthorized' });
    }

    const sessions = await sb(
      `sessions?select=id,user_id,expires_at,users(id,username,display_name,role,is_active)&token=eq.${encodeURIComponent(token)}&limit=1`
    );

    const session = sessions && sessions[0];

    if (!session) {
      return res.status(401).json({ ok: false, error: 'Invalid or expired session' });
    }

    if (new Date(session.expires_at) < new Date()) {
      await sb(`sessions?id=eq.${session.id}`, { method: 'DELETE' }).catch(() => {});
      return res.status(401).json({ ok: false, error: 'Session expired' });
    }

    if (!session.users || !session.users.is_active) {
      return res.status(403).json({ ok: false, error: 'Account disabled' });
    }

    req.user = {
      id: session.users.id,
      username: session.users.username,
      displayName: session.users.display_name,
      role: session.users.role
    };

    next();
  } catch (error) {
    next(error);
  }
}

function requireRole(...roles) {
  return (req, res, next) => {
    if (!req.user) return res.status(401).json({ ok: false, error: 'Unauthorized' });
    if (!roles.includes(req.user.role)) {
      return res.status(403).json({ ok: false, error: 'Forbidden' });
    }
    next();
  };
}

app.post('/api/auth/login', async (req, res, next) => {
  try {
    const { username, password, remember } = req.body || {};

    if (!username || !password) {
      return res.status(400).json({
        ok: false,
        error: 'Username and password required'
      });
    }

    const users = await sb(
      `users?select=*&username=ilike.${encodeURIComponent(String(username).trim())}&limit=1`
    );

    const user = users && users[0];

    if (!user || !(await verifyPassword(String(password), user.password_hash))) {
      return res.status(401).json({
        ok: false,
        error: 'Invalid username or password'
      });
    }

    if (!user.is_active) {
      return res.status(403).json({ ok: false, error: 'Account is disabled' });
    }

    const token = genToken();
    const expiresAt = new Date(
      Date.now() +
      (remember ? SESSION_DAYS_REMEMBER : SESSION_DAYS_DEFAULT) *
      86400000
    ).toISOString();

    await sb('sessions', {
      method: 'POST',
      headers: { Prefer: 'return=minimal' },
      body: JSON.stringify([{
        user_id: user.id,
        token,
        expires_at: expiresAt
      }])
    });

    await audit('login', { username: user.username });

    res.json({
      ok: true,
      token,
      username: user.username,
      displayName: user.display_name,
      role: user.role,
      expiresAt
    });
  } catch (error) {
    next(error);
  }
});

app.post('/api/auth/logout', requireAuth, async (req, res, next) => {
  try {
    const auth = req.headers.authorization || '';
    const token = auth.startsWith('Bearer ')
      ? auth.slice(7)
      : req.query._token;

    await sb(`sessions?token=eq.${encodeURIComponent(token)}`, {
      method: 'DELETE'
    });

    res.json({ ok: true });
  } catch (error) {
    next(error);
  }
});

app.get('/api/auth/me', requireAuth, (req, res) => {
  res.json({ ok: true, user: req.user });
});

app.post('/api/auth/change-password', requireAuth, async (req, res, next) => {
  try {
    const { currentPassword, newPassword } = req.body || {};

    if (!currentPassword || !newPassword) {
      return res.status(400).json({
        ok: false,
        error: 'Both passwords required'
      });
    }

    const rows = await sb(
      `users?select=password_hash&id=eq.${req.user.id}&limit=1`
    );

    if (!(await verifyPassword(
      String(currentPassword),
      rows[0]?.password_hash
    ))) {
      return res.status(401).json({
        ok: false,
        error: 'Current password is incorrect'
      });
    }

    await sb(`users?id=eq.${req.user.id}`, {
      method: 'PATCH',
      headers: { Prefer: 'return=minimal' },
      body: JSON.stringify({
        password_hash: await hashPassword(String(newPassword))
      })
    });

    await sb(`sessions?user_id=eq.${req.user.id}`, {
      method: 'DELETE'
    });

    res.json({ ok: true });
  } catch (error) {
    next(error);
  }
});

async function upsertStorage(values) {
  const rows = Object.entries(values || {}).map(([key, value]) => ({
    key: String(key),
    value: jsonString(value),
    updated_at: new Date().toISOString()
  }));

  if (!rows.length) return 0;

  await sb('storage_items?on_conflict=key', {
    method: 'POST',
    headers: {
      Prefer: 'resolution=merge-duplicates,return=minimal'
    },
    body: JSON.stringify(rows)
  });

  return rows.length;
}

app.get('/api/storage', async (req, res, next) => {
  try {
    const rows = await sb(
      'storage_items?select=key,value,updated_at&order=key.asc'
    );

    const data = {};
    const updatedAt = {};

    (rows || []).forEach(row => {
      data[row.key] = safeJsonParse(row.value, row.value);
      updatedAt[row.key] = row.updated_at;
    });

    res.set('Cache-Control', 'no-store');

    res.json({
      ok: true,
      data,
      updatedAt,
      database: 'supabase'
    });
  } catch (error) {
    next(error);
  }
});

app.get('/api/storage/:key', async (req, res, next) => {
  try {
    const rows = await sb(
      `storage_items?select=key,value,updated_at&key=eq.${encodeURIComponent(req.params.key)}&limit=1`
    );

    const row = rows && rows[0];

    res.json({
      ok: true,
      key: req.params.key,
      value: row ? safeJsonParse(row.value, row.value) : null,
      updatedAt: row?.updated_at || null,
      database: 'supabase'
    });
  } catch (error) {
    next(error);
  }
});

app.put('/api/storage/:key', async (req, res, next) => {
  try {
    await upsertStorage({
      [req.params.key]: req.body?.value
    });

    res.json({
      ok: true,
      key: req.params.key,
      database: 'supabase'
    });
  } catch (error) {
    next(error);
  }
});

app.delete('/api/storage/:key', async (req, res, next) => {
  try {
    await sb(
      `storage_items?key=eq.${encodeURIComponent(req.params.key)}`,
      { method: 'DELETE' }
    );

    res.json({
      ok: true,
      deleted: true,
      key: req.params.key,
      database: 'supabase'
    });
  } catch (error) {
    next(error);
  }
});

app.post('/api/storage/bulk', async (req, res, next) => {
  try {
    res.json({
      ok: true,
      count: await upsertStorage(req.body || {}),
      database: 'supabase'
    });
  } catch (error) {
    next(error);
  }
});

app.post('/api/storage/bulk-beacon',
  express.text({ type: '*/*', limit: '100mb' }),
  async (req, res, next) => {
    try {
      const payload = JSON.parse(req.body || '{}');

      res.json({
        ok: true,
        count: await upsertStorage(payload),
        database: 'supabase'
      });
    } catch (error) {
      next(error);
    }
  }
);

app.get('/api/modules/:module', async (req, res, next) => {
  try {
    const module = normalizeModule(req.params.module);

    if (!module) {
      return res.status(400).json({
        ok: false,
        error: 'Unknown module'
      });
    }

    const rows = await sb(
      `module_data?select=module,data,updated_at&module=eq.${encodeURIComponent(module)}&limit=1`
    );

    const row = rows && rows[0];

    res.json({
      ok: true,
      module,
      data: row ? safeJsonParse(row.data, {}) : {},
      updatedAt: row?.updated_at || null,
      database: 'supabase'
    });
  } catch (error) {
    next(error);
  }
});

app.put('/api/modules/:module', async (req, res, next) => {
  try {
    const module = normalizeModule(req.params.module);

    if (!module) {
      return res.status(400).json({
        ok: false,
        error: 'Unknown module'
      });
    }

    await sb('module_data?on_conflict=module', {
      method: 'POST',
      headers: {
        Prefer: 'resolution=merge-duplicates,return=minimal'
      },
      body: JSON.stringify([{
        module,
        data: req.body?.data || req.body || {},
        updated_at: new Date().toISOString()
      }])
    });

    res.json({ ok: true, module, database: 'supabase' });
  } catch (error) {
    next(error);
  }
});

app.patch('/api/modules/:module', async (req, res, next) => {
  try {
    const module = normalizeModule(req.params.module);

    if (!module) {
      return res.status(400).json({
        ok: false,
        error: 'Unknown module'
      });
    }

    const rows = await sb(
      `module_data?select=data&module=eq.${encodeURIComponent(module)}&limit=1`
    );

    const current = safeJsonParse(rows?.[0]?.data || {}, {});
    const data = {
      ...current,
      ...(req.body?.data || req.body || {})
    };

    await sb('module_data?on_conflict=module', {
      method: 'POST',
      headers: {
        Prefer: 'resolution=merge-duplicates,return=minimal'
      },
      body: JSON.stringify([{
        module,
        data,
        updated_at: new Date().toISOString()
      }])
    });

    res.json({
      ok: true,
      module,
      data,
      database: 'supabase'
    });
  } catch (error) {
    next(error);
  }
});

app.get('/api/health', async (req, res) => {
  try {
    await ensureAdmin();

    res.json({
      ok: true,
      app: 'Toyota LineFlow Backend',
      database: 'supabase',
      supabase: 'connected',
      updatedAt: new Date().toISOString(),
      modules: MODULES
    });
  } catch (error) {
    res.status(500).json({
      ok: false,
      database: 'supabase',
      supabase: 'not-configured-or-error',
      error: error.message
    });
  }
});

app.get('/api/data', async (req, res, next) => {
  try {
    const storageRows = await sb('storage_items?select=key,value');
    const moduleRows = await sb('module_data?select=module,data');

    const localStorage = {};
    (storageRows || []).forEach(row => {
      localStorage[row.key] = safeJsonParse(row.value, row.value);
    });

    const modules = {};
    (moduleRows || []).forEach(row => {
      modules[row.module] = safeJsonParse(row.data, {});
    });

    res.json({
      ok: true,
      database: 'supabase',
      modules,
      localStorage
    });
  } catch (error) {
    next(error);
  }
});

app.put('/api/data', async (req, res, next) => {
  try {
    if (req.body?.localStorage) {
      await upsertStorage(req.body.localStorage);
    }

    res.json({ ok: true, database: 'supabase' });
  } catch (error) {
    next(error);
  }
});

app.get('/api/export-json', async (req, res, next) => {
  try {
    const rows = await sb('storage_items?select=key,value');
    const localStorage = {};

    (rows || []).forEach(row => {
      localStorage[row.key] = safeJsonParse(row.value, row.value);
    });

    res.json({
      ok: true,
      exportedAt: new Date().toISOString(),
      database: 'supabase',
      localStorage
    });
  } catch (error) {
    next(error);
  }
});

app.post('/api/export-json', async (req, res, next) => {
  try {
    const rows = await sb('storage_items?select=key,value');
    const localStorage = {};

    (rows || []).forEach(row => {
      localStorage[row.key] = safeJsonParse(row.value, row.value);
    });

    res.json({
      ok: true,
      exportedAt: new Date().toISOString(),
      database: 'supabase',
      localStorage
    });
  } catch (error) {
    next(error);
  }
});

app.post('/api/import-json', async (req, res, next) => {
  try {
    if (req.body?.localStorage) {
      await upsertStorage(req.body.localStorage);
    }

    res.json({ ok: true, database: 'supabase' });
  } catch (error) {
    next(error);
  }
});

app.post('/api/backup', async (req, res) => {
  res.json({
    ok: true,
    message: 'Supabase is the live database. Use Supabase backup/export for database backups.'
  });
});

app.get('/api/backups', async (req, res) => {
  res.json({
    ok: true,
    backups: [],
    message: 'Supabase mode'
  });
});

/* Static files:
   Put login.html and all LineFlow module HTML files inside /public.
   Exact uploaded filenames are supported, including spaces and parentheses.
*/
app.use(express.static(PUBLIC_DIR, {
  extensions: ['html'],
  index: false
}));

app.get('/', (req, res) => {
  res.sendFile(path.join(PUBLIC_DIR, 'login.html'));
});

app.get('/login', (req, res) => {
  res.sendFile(path.join(PUBLIC_DIR, 'login.html'));
});

/* Friendly route fallback for simple names such as /gl-kpi.
   Exact filenames should normally be linked directly from the index:
   /gl-kpi(5).html, /GL%20Activity(6).html, etc.
*/
app.get('/:page', (req, res, next) => {
  const file = path.join(PUBLIC_DIR, `${req.params.page}.html`);
  res.sendFile(file, err => {
    if (err) next();
  });
});

app.use((err, req, res, next) => {
  console.error(err);
  res.status(500).json({
    ok: false,
    error: err.message || 'Server error'
  });
});

ensureAdmin()
  .catch(error => console.warn('Startup Supabase check:', error.message))
  .finally(() => {
    app.listen(PORT, () => {
      console.log(`Toyota LineFlow Supabase backend running on :${PORT}`);
    });
  });
