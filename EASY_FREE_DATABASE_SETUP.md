# Easy Free Supabase Setup

1. Supabase > SQL Editor > run `SUPABASE_SETUP.sql`.
2. Supabase > Project Settings > API, copy:
   - Project URL
   - service_role key
3. Render > Your Web Service > Environment, add:
   - `SUPABASE_URL` = Project URL
   - `SUPABASE_SERVICE_ROLE_KEY` = service_role key
   - `NODE_ENV` = production
4. Deploy.
5. Open `/api/health`. It must show `database: supabase-free-tier`.
6. Open the same Render website URL on all PCs.
