# Toyota LineFlow Backend with Supabase PostgreSQL

This package serves the Toyota dashboard HTML files and stores application data in **Supabase PostgreSQL**.

This is better for Render Free plan because data is stored in Supabase, not in Render's temporary filesystem.

## Included

- Express backend server
- Supabase PostgreSQL database support via `pg`
- Static HTML dashboard hosting from `public/`
- Browser localStorage sync using `public/backend-sync.js`
- APIs for FMDS, GL KPI, TL KPI, Process Allocation, Training Hub, Unified Portal, and shared data
- JSON export/import backup endpoints

## Run locally

```bash
npm install
set DATABASE_URL=your_supabase_connection_string
npm start
```

On Mac/Linux:

```bash
export DATABASE_URL=your_supabase_connection_string
npm start
```

Open:

```text
http://localhost:3000
```

Health check:

```text
http://localhost:3000/api/health
```

## Render environment variables

```text
NODE_ENV=production
DATABASE_URL=your_supabase_connection_string
```

No persistent disk is required.

## Main API endpoints

```http
GET  /api/data
PUT  /api/data
GET  /api/modules/:module
PUT  /api/modules/:module
PATCH /api/modules/:module
GET  /api/storage
GET  /api/storage/:key
PUT  /api/storage/:key
DELETE /api/storage/:key
POST /api/storage/bulk
GET  /api/records/:module/:recordType
POST /api/records/:module/:recordType
PUT  /api/records/:id
DELETE /api/records/:id
POST /api/backup
GET  /api/export-json
POST /api/import-json
```

## Database tables

The backend creates these tables automatically:

- `app_meta`
- `module_data`
- `storage_items`
- `named_records`
- `audit_log`

See `DEPLOY_RENDER.md` for deployment steps.
