# Toyota LineFlow — Reset Deployment Package

## Backend
- `server.js` — Supabase-only API + static server
- `package.json` — Node dependencies/start script
- `render.yaml` — Render web service configuration
- `supabase-sync.js` — client-side localStorage ↔ Supabase sync

## Render environment variables
Set:
- `SUPABASE_URL`
- `SUPABASE_SERVICE_ROLE_KEY`

Do not put the service-role key into any HTML/JS file.

## Public folder
Put the dashboard HTML files in `public/`.

Use the exact filenames requested for the LineFlow index links:
- `fmds(7).html`
- `GL Activity(6).html`
- `gl-kpi(5).html`
- `PA(3).html`
- `TL KPI(20260917-132626).html`
- `training-hub(4).html`

The index should use direct links/redirects to those exact filenames, with every file in the same `public` folder.

The backend serves static files from `public` and does not use the old SQLite disk configuration.
