Toyota LineFlow fixed Supabase sync package

Upload these files into your GitHub repository under the public folder:
- backend-sync.js
- index.html
- fmds.html
- gl-kpi.html
- tl-kpi.html
- process-allocation.html
- training-hub.html

Then in Render:
Manual Deploy -> Deploy latest commit

Test:
1. Open the app.
2. Enter data and save.
3. Open /api/storage in browser to confirm data exists.
4. Restart/redeploy app.
5. Refresh the page and confirm data stays.

Important:
This package keeps localStorage as the front-end storage, but syncs it to Supabase through your Node backend.
