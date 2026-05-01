(function () {
  const API = window.BACKEND_API || '';
  const statusId = 'backend-sync-status';

  const originalSet = localStorage.setItem.bind(localStorage);
  const originalGet = localStorage.getItem.bind(localStorage);
  const originalRemove = localStorage.removeItem.bind(localStorage);

  let queue = [];
  let syncing = false;
  let pulled = false;
  window.BACKEND_SYNC_READY = false;

  function showStatus(text, ok) {
    function attach() {
      let el = document.getElementById(statusId);
      if (!el && document.body) {
        el = document.createElement('div');
        el.id = statusId;
        el.style.cssText =
          'position:fixed;right:10px;bottom:10px;z-index:999999;padding:6px 10px;border-radius:999px;font:11px Arial;background:rgba(10,15,28,.9);color:#e6f1ff;border:1px solid rgba(0,212,255,.3);box-shadow:0 4px 15px rgba(0,0,0,.35)';
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

  function normalizeForLocalStorage(value) {
    if (value === null || value === undefined) return null;
    return typeof value === 'string' ? value : JSON.stringify(value);
  }

  async function pullFromBackend() {
    try {
      const res = await fetch(API + '/api/storage', { cache: 'no-store' });
      const json = await res.json();
      if (!json.ok) throw new Error(json.error || 'Backend not ok');

      Object.entries(json.data || {}).forEach(([key, value]) => {
        const normalized = normalizeForLocalStorage(value);
        if (normalized !== null) originalSet(key, normalized);
      });

      pulled = true;
      window.BACKEND_SYNC_READY = true;
      showStatus('Backend sync: loaded', true);
      window.dispatchEvent(new Event('backend-sync-ready'));
    } catch (err) {
      console.error('Backend pull failed:', err);
      pulled = true;
      window.BACKEND_SYNC_READY = true;
      showStatus('Backend sync: offline/local', false);
      window.dispatchEvent(new Event('backend-sync-ready'));
    }
  }

  async function flushToBackend() {
    if (syncing || queue.length === 0) return;
    syncing = true;

    const batch = {};
    queue.splice(0).forEach(item => {
      batch[item.key] = item.value;
    });

    try {
      const res = await fetch(API + '/api/storage/bulk', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(batch)
      });
      if (!res.ok) throw new Error('Save failed: ' + res.status);
      showStatus('Backend sync: saved', true);
    } catch (err) {
      console.error('Backend save failed:', err);
      Object.entries(batch).forEach(([key, value]) => queue.push({ key, value }));
      showStatus('Backend sync: retrying', false);
    } finally {
      syncing = false;
    }
  }

  localStorage.setItem = function (key, value) {
    originalSet(key, value);

    // Avoid overwriting backend during the first pull phase.
    if (pulled && window.BACKEND_SYNC_READY) {
      queue.push({ key: String(key), value: String(value) });
      setTimeout(flushToBackend, 300);
    }
  };

  localStorage.removeItem = function (key) {
    originalRemove(key);
    if (pulled && window.BACKEND_SYNC_READY) {
      fetch(API + '/api/storage/' + encodeURIComponent(key), {
        method: 'DELETE'
      }).catch(() => {});
    }
  };

  window.backendSyncNow = flushToBackend;
  window.backendPullNow = pullFromBackend;

  // Start pulling as early as possible.
  pullFromBackend();

  setInterval(flushToBackend, 3000);
  window.addEventListener('beforeunload', flushToBackend);
})();
