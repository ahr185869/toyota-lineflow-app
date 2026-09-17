/* LineFlow Supabase Sync v2 - source-of-truth protection and immediate save
   - Pulls Supabase BEFORE page scripts initialize when possible, preventing default old data from overwriting DB data.
   - Tracks per-key timestamps so newer local changes are not overwritten by older Supabase rows.
   - Flushes immediately/periodically/pagehide to prevent lost saves after restart.
*/
(function () {
  const API = window.BACKEND_API || '';
  const MAX_VALUE_LENGTH = 8 * 1024 * 1024;
  const statusId = 'backend-sync-status';
  const META_KEY = '__lineflow_sync_meta_v2';
  const originalSet = localStorage.setItem.bind(localStorage);
  const originalGet = localStorage.getItem.bind(localStorage);
  const originalRemove = localStorage.removeItem.bind(localStorage);
  let ready = false;
  let applyingRemote = false;
  let queue = [];
  let timer = null;

  function now() { return Date.now(); }
  function parseJSON(v, d) { try { return v ? JSON.parse(v) : d; } catch { return d; } }
  function getMeta() { return parseJSON(originalGet(META_KEY), {}); }
  function setMeta(meta) { try { originalSet(META_KEY, JSON.stringify(meta || {})); } catch {} }
  function markLocalChange(key) {
    if (!key || key === META_KEY) return;
    const meta = getMeta();
    meta[key] = { localAt: now(), remoteAt: meta[key]?.remoteAt || 0, dirty: true };
    setMeta(meta);
  }
  function markRemoteApplied(key, remoteAt) {
    if (!key || key === META_KEY) return;
    const meta = getMeta();
    meta[key] = { localAt: remoteAt || now(), remoteAt: remoteAt || now(), dirty: false };
    setMeta(meta);
  }
  function markFlushed(keys) {
    const meta = getMeta();
    const t = now();
    keys.forEach(k => {
      if (!k || k === META_KEY) return;
      meta[k] = { localAt: t, remoteAt: t, dirty: false };
    });
    setMeta(meta);
  }

  function showStatus(text, ok) {
    let el = document.getElementById(statusId);
    if (!el) {
      el = document.createElement('div');
      el.id = statusId;
      el.style.cssText = 'position:fixed;right:10px;bottom:10px;z-index:999999;padding:6px 10px;border-radius:999px;font:11px Arial;background:rgba(10,15,28,.9);color:#e6f1ff;border:1px solid rgba(0,212,255,.3);box-shadow:0 4px 15px rgba(0,0,0,.35)';
      const attach = () => { if (document.body && !document.getElementById(statusId)) document.body.appendChild(el); };
      if (document.readyState === 'loading') document.addEventListener('DOMContentLoaded', attach);
      else attach();
    }
    el.textContent = text;
    el.style.borderColor = ok ? 'rgba(0,255,136,.45)' : 'rgba(255,204,0,.45)';
  }

  function normalizeValueForLocal(v) {
    if (v === null || v === undefined) return null;
    return typeof v === 'string' ? v : JSON.stringify(v);
  }

  function applyRemotePayload(json) {
    if (!json || !json.ok) return;
    const data = json.data || {};
    const updatedAt = json.updatedAt || json.updated_at || {};
    const meta = getMeta();
    applyingRemote = true;
    try {
      Object.entries(data).forEach(([k, v]) => {
        if (k === META_KEY || v === null || v === undefined) return;
        const remoteMs = updatedAt[k] ? Date.parse(updatedAt[k]) || 0 : 0;
        const localVal = originalGet(k);
        const m = meta[k] || {};
        const localIsDirty = !!m.dirty;
        const localAt = Number(m.localAt || 0);

        // Do not let old Supabase/default data overwrite a newer local unsynced change.
        if (localVal !== null && localIsDirty && localAt && remoteMs && localAt > remoteMs) {
          queue.push({ key: k, value: localVal });
          return;
        }

        // If local exists but has no metadata (old PC cache), keep it and upload it once.
        // This is useful for migrating old localStorage data into Supabase.
        if (localVal !== null && !m.localAt && !m.remoteAt) {
          markLocalChange(k);
          queue.push({ key: k, value: localVal });
          return;
        }

        const str = normalizeValueForLocal(v);
        if (str === null) return;
        originalSet(k, str);
        markRemoteApplied(k, remoteMs || now());
      });
    } finally {
      applyingRemote = false;
    }
  }

  function pullSyncBeforeAppStarts() {
    try {
      const xhr = new XMLHttpRequest();
      xhr.open('GET', API + '/api/storage?ts=' + Date.now(), false); // intentional sync: prevents page default data overwrite
      xhr.setRequestHeader('Cache-Control', 'no-cache');
      xhr.send(null);
      if (xhr.status >= 200 && xhr.status < 300) {
        applyRemotePayload(JSON.parse(xhr.responseText || '{}'));
        ready = true;
        showStatus('Supabase sync: connected', true);
      }
    } catch (e) {
      // Continue offline/local; async pull will retry.
    }
  }

  async function pull() {
    try {
      const res = await fetch(API + '/api/storage?ts=' + Date.now(), { cache: 'no-store' });
      const json = await res.json();
      applyRemotePayload(json);
      ready = true;
      showStatus('Supabase sync: connected', true);
      if (queue.length) flush();
    } catch (e) {
      showStatus('Supabase sync: offline/local mode', false);
    }
  }

  async function flush() {
    if (!queue.length) return { ok: true, count: 0 };
    const batch = {};
    queue.splice(0).forEach(item => {
      if (!item || !item.key || item.key === META_KEY) return;
      batch[item.key] = item.value;
    });
    const keys = Object.keys(batch);
    if (!keys.length) return { ok: true, count: 0 };
    try {
      const res = await fetch(API + '/api/storage/bulk', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json', 'Cache-Control': 'no-cache' },
        body: JSON.stringify(batch),
        keepalive: true
      });
      const json = await res.json().catch(() => ({}));
      if (!res.ok || json.ok === false) throw new Error(json.error || 'Save failed');
      markFlushed(keys);
      showStatus('Supabase sync: saved', true);
      return json;
    } catch (e) {
      queue.push(...Object.entries(batch).map(([key, value]) => ({ key, value })));
      showStatus('Supabase sync: retrying', false);
      return { ok: false, error: e.message };
    }
  }

  function queueSet(key, value, delay) {
    if (key === META_KEY) return;
    const strValue = String(value);
    if (strValue.length > MAX_VALUE_LENGTH) { showStatus('Supabase sync: item too large', false); return; }
    queue.push({ key: String(key), value: strValue });
    clearTimeout(timer);
    timer = setTimeout(flush, delay == null ? 120 : delay);
  }

  localStorage.setItem = function (key, value) {
    originalSet(key, value);
    if (applyingRemote) return;
    markLocalChange(String(key));
    queueSet(String(key), String(value), ready ? 120 : 800);
  };

  localStorage.removeItem = function (key) {
    originalRemove(key);
    const meta = getMeta();
    delete meta[key];
    setMeta(meta);
    fetch(API + '/api/storage/' + encodeURIComponent(key), { method: 'DELETE', keepalive: true }).catch(() => {});
  };

  function beaconFlushAllPending() {
    try {
      if (!queue.length || !navigator.sendBeacon) return;
      const batch = Object.fromEntries(queue.map(i => [i.key, i.value]).filter(([k]) => k && k !== META_KEY));
      if (!Object.keys(batch).length) return;
      navigator.sendBeacon(API + '/api/storage/bulk-beacon', new Blob([JSON.stringify(batch)], { type: 'application/json' }));
    } catch(e) {}
  }

  window.backendSyncNow = flush;
  window.backendPullNow = pull;
  window.forceSupabaseSyncAll = async function () {
    const batch = {};
    for (let i = 0; i < localStorage.length; i++) {
      const k = localStorage.key(i);
      if (!k || k === META_KEY) continue;
      const v = originalGet(k);
      if (v !== null && String(v).length <= MAX_VALUE_LENGTH) batch[k] = v;
    }
    queue.push(...Object.entries(batch).map(([key, value]) => ({ key, value })));
    return flush();
  };

  pullSyncBeforeAppStarts();
  window.addEventListener('pagehide', beaconFlushAllPending);
  window.addEventListener('beforeunload', beaconFlushAllPending);
  document.addEventListener('visibilitychange', () => { if (document.visibilityState === 'hidden') beaconFlushAllPending(); });
  setInterval(flush, 3000);
  setTimeout(pull, 250);
})();
