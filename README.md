# Toyota LineFlow - Supabase Ready Version

This package uses Supabase as the shared database for all PCs. SQLite has been removed from the backend dependencies.

## Setup
1. In Supabase SQL Editor, run `SUPABASE_SETUP.sql`.
2. In Render Environment Variables add:
   - `SUPABASE_URL=https://YOUR_PROJECT_REF.supabase.co`
   - `SUPABASE_SERVICE_ROLE_KEY=YOUR_SERVICE_ROLE_KEY`
   - `NODE_ENV=production`
3. Build Command: `npm install`
4. Start Command: `npm start`
5. Open the same Render URL on every PC. Do not open HTML files directly.

## Sync
Pages load `/supabase-sync.js`, which syncs the app's saved browser data to Supabase through the backend endpoints. Supabase is the source of truth; localStorage is only a temporary browser cache for compatibility with your current HTML pages.

## Test
Open `/api/health`. It should show:

```json
{ "database": "supabase-free-tier" }
```
