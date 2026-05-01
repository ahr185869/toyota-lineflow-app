# Deploy Toyota LineFlow Supabase Backend on Render Free Plan

This version uses **Supabase PostgreSQL**, so data persists even on Render Free plan. No Render persistent disk is required.

## 1. Create Supabase database

1. Go to Supabase and create a free project.
2. Open **Project Settings > Database**.
3. Copy the PostgreSQL connection string.
4. Replace `[YOUR-PASSWORD]` with your database password.

Example:

```text
postgresql://postgres:YOUR_PASSWORD@db.PROJECT_REF.supabase.co:5432/postgres
```

## 2. Upload this project to GitHub

Upload all files and folders, including:

```text
server.js
package.json
public/
render.yaml
```

## 3. Deploy on Render

Create **New > Web Service** and connect your GitHub repository.

Use:

```text
Environment: Node
Build Command: npm install
Start Command: npm start
Health Check Path: /api/health
```

## 4. Add environment variables in Render

```text
NODE_ENV = production
DATABASE_URL = your_supabase_connection_string
```

Do not add `DATA_DIR`. Do not add a persistent disk.

## 5. Deploy

Click **Deploy Web Service**.

After deploy, open:

```text
https://your-app-name.onrender.com/api/health
```

It should show:

```json
{ "ok": true, "database": "supabase-postgresql" }
```
