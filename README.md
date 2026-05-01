# Toyota LineFlow Backend with SQLite

This package serves the uploaded Toyota dashboard HTML files and stores application data in a local SQLite database.

## Included

- Express backend server
- SQLite database at `data/toyota_lineflow.sqlite`
- APIs for FMDS, GL KPI, TL KPI, Process Allocation, Training Hub, Unified Portal, and shared data
- Browser localStorage sync using `public/backend-sync.js`
- Generic `named_records` API for future structured data
- SQLite backup and JSON export/import

## Run

```bash
npm install
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
GET  /api/backups
GET  /api/export-json
POST /api/import-json
```

Accepted module names include:

- `fmds`
- `gl-kpi`
- `tl-kpi`
- `process-allocation`
- `training-hub`
- `unified`
- `shared`

## SQLite schema

The backend creates these tables automatically:

- `app_meta`
- `module_data`
- `storage_items`
- `named_records`
- `audit_log`

No separate database server is required.


## Live deployment
This package is ready for live hosting with SQLite + Node.js.

Recommended host: Render with persistent disk.

Environment variables:
```text
DATA_DIR=/var/data
NODE_ENV=production
```

SQLite database location on live server:
```text
/var/data/toyota_lineflow.sqlite
```

See `DEPLOY_RENDER.md`.
