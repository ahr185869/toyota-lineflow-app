(function () {
  const API = window.BACKEND_API || '';
  const statusId = 'backend-sync-status';
  const originalSet = localStorage.setItem.bind(localStorage);
  const originalRemove = localStorage.removeItem.bind(localStorage);
  let ready = false;
  let queue = [];
  let timer = null;

  function showStatus(text, ok) {
    let el = document.getElementById(statusId);
    if (!el) {
      el = document.createElement('div');
      el.id = statusId;
      el.style.cssText = 'position:fixed;right:10px;bottom:10px;z-index:999999;padding:6px 10px;border-radius:999px;font:11px Arial;background:rgba(10,15,28,.9);color:#e6f1ff;border:1px solid rgba(0,212,255,.3);box-shadow:0 4px 15px rgba(0,0,0,.35)';
      document.addEventListener('DOMContentLoaded', () => document.body.appendChild(el));
      if (document.body) document.body.appendChild(el);
    }
    el.textContent = text;
    el.style.borderColor = ok ? 'rgba(0,255,136,.45)' : 'rgba(255,204,0,.45)';
  }

  async function pull() {
    try {
      const res = await fetch(API + '/api/storage');
      const json = await res.json();
      if (!json.ok) return;
      Object.entries(json.data || {}).forEach(([k, v]) => {
        if (v === null || v === undefined) return;
        originalSet(k, v);
      });
      ready = true;
      showStatus('Backend sync: connected', true);
    } catch (e) {
      showStatus('Backend sync: offline/local mode', false);
    }
  }

  async function flush() {
    if (!queue.length) return;
    const batch = {};
    queue.splice(0).forEach(item => { batch[item.key] = item.value; });
    try {
      await fetch(API + '/api/storage/bulk', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(batch)
      });
      showStatus('Backend sync: saved', true);
    } catch (e) {
      queue.push(...Object.entries(batch).map(([key, value]) => ({ key, value })));
      showStatus('Backend sync: retrying', false);
    }
  }

  localStorage.setItem = function (key, value) {
    originalSet(key, value);
    queue.push({ key: String(key), value: String(value) });
    clearTimeout(timer);
    timer = setTimeout(flush, ready ? 250 : 1500);
  };

  localStorage.removeItem = function (key) {
    originalRemove(key);
    fetch(API + '/api/storage/' + encodeURIComponent(key), { method: 'DELETE' }).catch(() => {});
  };

  window.backendSyncNow = flush;
  window.backendPullNow = pull;
  pull();
  setInterval(flush, 5000);
})();
