# Deploy Toyota LineFlow SQLite Backend Live on Render

1. Upload this folder to a GitHub repository.
2. In Render, create **New > Web Service** and connect the repository.
3. Use:
   - Environment: `Node`
   - Build Command: `npm install`
   - Start Command: `npm start`
   - Health Check Path: `/api/health`
4. Add a persistent disk:
   - Name: `toyota-lineflow-data`
   - Mount Path: `/var/data`
   - Size: `1 GB` or more
5. Add environment variables:
   - `DATA_DIR=/var/data`
   - `NODE_ENV=production`
6. Deploy and open your Render URL.

SQLite DB path on live server:
`/var/data/toyota_lineflow.sqlite`
