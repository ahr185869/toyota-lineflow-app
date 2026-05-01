# Toyota LineFlow - Supabase Direct Persistence Package

This package hosts your Toyota LineFlow dashboard files and stores persistent data in Supabase PostgreSQL through the Node.js backend.

## Required Render environment variables

```text
NODE_ENV=production
DATABASE_URL=postgresql://postgres.YOUR_PROJECT:YOUR_PASSWORD@YOUR_POOLER_HOST:6543/postgres
```

Use the Supabase **Transaction pooler URI** on Render Free if direct connection gives `ENETUNREACH`.

## Correct structure

```text
server.js
package.json
public/
  index.html
  fmds.html
  gl-kpi.html
  tl-kpi.html
  process-allocation.html
  training-hub.html
  backend-sync.js
```

## Deploy

1. Upload all files to GitHub.
2. In Render, connect the repo.
3. Set Build Command: `npm install`.
4. Set Start Command: `npm start`.
5. Add `DATABASE_URL` and `NODE_ENV`.
6. Deploy.

## Test

Open:

```text
https://YOUR-APP.onrender.com/api/health
https://YOUR-APP.onrender.com/api/storage
```

The app uses the browser localStorage API as a compatibility cache for the existing dashboards, but persistence is saved to Supabase through `/api/storage/bulk`.
