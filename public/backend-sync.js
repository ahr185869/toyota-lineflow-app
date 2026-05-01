(function () {
  const API = window.BACKEND_API || '';
  const statusId = 'backend-sync-status';
  const RELOAD_FLAG = 'backend-sync-reloaded:' + location.pathname;

  const originalSet = localStorage.setItem.bind(localStorage);
  const originalGet = localStorage.getItem.bind(localStorage);
  const originalRemove = localStorage.removeItem.bind(localStorage);
  const originalClear = localStorage.clear.bind(localStorage);

  let ready = false;
  let pulling = true;
  let flushing = false;
  let queue = [];
  let timer = null;

  function showStatus(text, ok) {
    function attach() {
      let el = document.getElementById(statusId);
      if (!el && document.body) {
        el = document.createElement('div');
        el.id = statusId;
        el.style.cssText = 'position:fixed;right:10px;bottom:10px;z-index:999999;padding:6px 10px;border-radius:999px;font:11px Arial;background:rgba(10,15,28,.92);color:#e6f1ff;border:1px solid rgba(0,212,255,.3);box-shadow:0 4px 15px rgba(0,0,0,.35)';
        document.body.appendChild(el);
      }
      if (el) {
        el.textContent = text;
        el.style.borderColor = ok ? 'rgba(0,255,136,.45)' : 'rgba(255,204,0,.45)';
      }
    }
    if (document.body) attach();
    else document.addEventListener('DOMContentLoaded', attach, { once: true });
  }

  function snapshotLocalStorage() {
    const data = {};
    for (let i = 0; i < localStorage.length; i++) {
      const key = localStorage.key(i);
      if (!key) continue;
      if (key.startsWith('backend-sync-')) continue;
      data[key] = originalGet(key);
    }
    return data;
  }

  async function postBulk(batch) {
    const res = await fetch(API + '/api/storage/bulk', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(batch),
      keepalive: JSON.stringify(batch).length < 60000
    });
    if (!res.ok) throw new Error('Backend save failed: ' + res.status);
    const json = await res.json().catch(() => ({}));
    if (json && json.ok === false) throw new Error(json.error || 'Backend save failed');
    return json;
  }

  async function pullFromBackend() {
    pulling = true;
    showStatus('Backend sync: loading...', false);
    try {
      const res = await fetch(API + '/api/storage', { cache: 'no-store' });
      if (!res.ok) throw new Error('Backend load failed: ' + res.status);
      const json = await res.json();
      if (!json.ok) throw new Error(json.error || 'Backend not ok');

      const remote = json.data || {};
      const remoteKeys = Object.keys(remote);
      const localBefore = snapshotLocalStorage();
      let changed = false;

      if (remoteKeys.length > 0) {
        remoteKeys.forEach(key => {
          const value = remote[key];
          if (value === null || value === undefined) return;
          const text = typeof value === 'string' ? value : JSON.stringify(value);
          if (originalGet(key) !== text) changed = true;
          originalSet(key, text);
        });
      } else if (Object.keys(localBefore).length > 0) {
        // First deployment / empty Supabase: seed backend from existing browser data.
        await postBulk(localBefore);
      }

      pulling = false;
      ready = true;
      window.BACKEND_SYNC_READY = true;
      showStatus('Backend sync: connected', true);
      window.dispatchEvent(new Event('backend-sync-ready'));

      // Existing dashboard scripts may have already rendered from empty/default data.
      // Reload once after restoring remote data so UI initializes from Supabase-backed storage.
      if (changed && !sessionStorage.getItem(RELOAD_FLAG)) {
        sessionStorage.setItem(RELOAD_FLAG, '1');
        setTimeout(() => location.reload(), 120);
      }
    } catch (err) {
      console.error('Backend sync load failed:', err);
      pulling = false;
      ready = true;
      window.BACKEND_SYNC_READY = true;
      showStatus('Backend sync: offline/local', false);
      window.dispatchEvent(new Event('backend-sync-ready'));
    }
  }

  async function flushToBackend() {
    if (flushing || queue.length === 0 || !ready) return;
    flushing = true;
    const batch = {};
    queue.splice(0).forEach(item => { batch[item.key] = item.value; });
    try {
      await postBulk(batch);
      showStatus('Backend sync: saved', true);
    } catch (err) {
      console.error('Backend sync save failed:', err);
      Object.entries(batch).forEach(([key, value]) => queue.push({ key, value }));
      showStatus('Backend sync: retrying', false);
    } finally {
      flushing = false;
    }
  }

  function scheduleFlush(delay) {
    clearTimeout(timer);
    timer = setTimeout(flushToBackend, delay || 350);
  }

  localStorage.setItem = function (key, value) {
    key = String(key);
    value = String(value);
    originalSet(key, value);

    // Do not let startup/default writes overwrite Supabase while initial pull is running.
    if (pulling || !ready || key.startsWith('backend-sync-')) return;

    queue.push({ key, value });
    scheduleFlush(300);
  };

  localStorage.removeItem = function (key) {
    key = String(key);
    originalRemove(key);
    if (!ready || pulling) return;
    fetch(API + '/api/storage/' + encodeURIComponent(key), { method: 'DELETE', keepalive: true }).catch(() => {});
  };

  localStorage.clear = function () {
    const keys = Object.keys(snapshotLocalStorage());
    originalClear();
    if (!ready || pulling) return;
    keys.forEach(key => fetch(API + '/api/storage/' + encodeURIComponent(key), { method: 'DELETE', keepalive: true }).catch(() => {}));
  };

  window.backendSyncNow = flushToBackend;
  window.backendPullNow = pullFromBackend;

  pullFromBackend();
  setInterval(flushToBackend, 3000);
  window.addEventListener('beforeunload', flushToBackend);
})();
