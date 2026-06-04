LineFlow Auto-Save All Changes Fix

Replace your current project files with these files and redeploy Render.

This package makes Supabase update automatically for:
- members added/removed
- dashboard changes
- process allocation changes
- KPI/FMDS edits
- uploaded photos/documents stored by the app in localStorage/base64
- changes made without pressing the page Save button

After deployment:
1. Open the PC where latest correct data is visible.
2. Press F12 > Console.
3. Run: forceSupabaseSyncAll()
4. Wait until bottom-right says: Supabase sync: saved
5. Open the same Render URL on another PC and refresh.

Note: If any page keeps data only in JavaScript variables and never writes that data to localStorage, no browser sync script can save that hidden variable. This package forces sync for all localStorage-based app data and all common add/remove/upload/input events.
