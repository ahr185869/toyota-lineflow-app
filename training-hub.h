<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8"/>
<meta name="viewport" content="width=device-width,initial-scale=1.0"/>
<title>Toyota Unified Training Portal</title>
<link href="https://fonts.googleapis.com/css2?family=Rajdhani:wght@500;600;700&family=Share+Tech+Mono&display=swap" rel="stylesheet">
<style>
:root{
  --bg:#0a0f1c; --card:#111827; --muted:#8b9dc3; --accent:#00d4ff;
  --glass:rgba(0,212,255,0.05); --danger:#ff2e63; --ok:#00ff88;
  --warn:#ffcc00; --info:#0099ff; --accent-hover:#00b8e6;
  --shadow:0 8px 30px rgba(0,212,255,0.15); --radius:14px;
  --bg2:#0f1118; --bg3:#151a25; --bdr:#252e42; --acc2:#ff6030;
  --grn:#00e676; --red:#ff3333; --txt:#dde2ee; --txt2:#7a87a8; --txt3:#3e4a62;
  --fh:'Rajdhani',sans-serif; --fm:'Share Tech Mono',monospace;
}
*{box-sizing:border-box;margin:0;padding:0;font-family:Inter,Segoe UI,Arial,sans-serif;}
body{background:linear-gradient(180deg,#0a0f1c 0%,#111827 100%);color:#e6f1ff;min-height:100vh;font-size:13px;}

/* ── HEADER ── */
.combined-header{
  display:flex;align-items:center;gap:10px;padding:8px 16px;
  background:linear-gradient(90deg,rgba(0,212,255,0.12),transparent);
  border-bottom:1px solid rgba(0,212,255,0.12);position:sticky;top:0;z-index:200;
}
.brand{display:flex;align-items:center;gap:10px;}
.logo{width:36px;height:36px;border-radius:8px;background:linear-gradient(135deg,var(--accent),#9d4edd);display:flex;align-items:center;justify-content:center;box-shadow:var(--shadow);}
.logo svg{width:22px;height:22px;}
.brand-title{font-size:15px;font-weight:700;letter-spacing:2px;text-transform:uppercase;}
.brand-sub{font-size:10px;color:var(--muted);letter-spacing:1.5px;text-transform:uppercase;border-left:1px solid rgba(0,212,255,0.25);padding-left:10px;}
.header-right{margin-left:auto;display:flex;align-items:center;gap:10px;}
.sys-time{display:flex;align-items:center;gap:6px;padding:5px 12px;cursor:default;white-space:nowrap;background:rgba(0,212,255,0.07);border:1px solid rgba(0,212,255,0.2);border-radius:999px;font-size:11px;color:#e6f1ff;}
.tv{font-size:12px;color:var(--accent);font-weight:700;}
.tl{font-size:8px;color:var(--muted);text-transform:uppercase;letter-spacing:0.5px;margin-top:1px;}
.tsep{color:var(--accent);font-size:10px;opacity:0.5;}
.usr-dot{width:30px;height:30px;border-radius:50%;background:rgba(0,212,255,0.14);border:1px solid rgba(0,212,255,0.3);display:flex;align-items:center;justify-content:center;font-size:11px;font-weight:700;color:var(--accent);}

/* ── LANGUAGE SWITCHER ── */
.lang-switcher{display:flex;align-items:center;gap:5px;padding:4px 8px;background:rgba(0,212,255,0.07);border:1px solid rgba(0,212,255,0.2);border-radius:999px;}
.lang-btn{padding:3px 8px;border-radius:999px;font-size:10px;font-weight:600;cursor:pointer;border:none;background:transparent;color:var(--muted);transition:all 0.15s;font-family:inherit;letter-spacing:0.5px;}
.lang-btn:hover{color:#e6f1ff;background:rgba(0,212,255,0.1);}
.lang-btn.active{background:var(--accent);color:#0a0f1c;}

/* ── NAV ── */
.nav-controls{display:flex;gap:6px;padding:7px 16px;flex-wrap:wrap;background:rgba(0,212,255,0.04);border-bottom:1px solid rgba(0,212,255,0.1);align-items:center;}
.nav-btn{display:inline-flex;align-items:center;gap:7px;padding:5px 14px;font-size:11px;font-weight:500;color:#e6f1ff;background:rgba(0,212,255,0.08);border:1px solid rgba(0,212,255,0.25);border-radius:999px;cursor:pointer;transition:all 0.2s;font-family:inherit;white-space:nowrap;}
.nav-btn:hover{background:rgba(0,212,255,0.15);transform:translateY(-1px);}
.nav-btn.active{background:rgba(0,212,255,0.22);border-color:var(--accent);font-weight:600;box-shadow:0 0 0 1px rgba(0,212,255,0.35),0 0 12px rgba(0,212,255,0.3);}
.pill-dot{width:8px;height:8px;border-radius:50%;box-shadow:0 0 5px currentColor;flex-shrink:0;}

/* ── LAYOUT ── */
.main-layout{display:flex;min-height:calc(100vh - 88px);}
.sidebar{width:200px;flex-shrink:0;background:var(--card);border-right:1px solid rgba(0,212,255,0.1);padding:10px 0;overflow-y:auto;position:sticky;top:88px;height:calc(100vh - 88px);}
.sidebar::-webkit-scrollbar{width:3px;}
.sidebar::-webkit-scrollbar-thumb{background:rgba(0,212,255,0.2);}
.sb-sec{font-size:9px;letter-spacing:2px;text-transform:uppercase;color:var(--muted);padding:8px 14px 4px;font-weight:600;margin-top:6px;}
.sb-item{display:flex;align-items:center;gap:8px;padding:8px 14px;cursor:pointer;color:#b0c4de;font-size:12px;border-left:2px solid transparent;transition:all 0.15s;}
.sb-item:hover{background:rgba(0,212,255,0.06);color:#e6f1ff;}
.sb-item.active{background:rgba(0,212,255,0.12);color:var(--accent);border-left-color:var(--accent);}
.sb-badge{margin-left:auto;background:rgba(0,212,255,0.15);color:var(--accent);font-size:9px;font-weight:700;padding:1px 6px;border-radius:10px;}
.sb-badge.red{background:rgba(255,46,99,0.15);color:var(--danger);}
.sb-badge.green{background:rgba(0,255,136,0.12);color:var(--ok);}

/* ── CONTENT ── */
.content{flex:1;padding:14px;overflow-y:auto;}
.sec-page{display:none;}
.sec-page.active{display:block;animation:fadeIn 0.25s ease;}
@keyframes fadeIn{from{opacity:0;transform:translateY(8px);}to{opacity:1;transform:translateY(0);}}

/* ── PAGE HEADER ── */
.pg-hdr{display:flex;align-items:center;justify-content:space-between;margin-bottom:12px;padding-bottom:10px;border-bottom:1px solid rgba(0,212,255,0.12);}
.pg-tag{font-size:9px;letter-spacing:2px;text-transform:uppercase;color:var(--accent);margin-bottom:3px;}
.pg-hdr h1{font-size:18px;font-weight:700;letter-spacing:0.5px;}

/* ── EDIT HEADLINE BUTTON ── */
.editable-title{display:inline-flex;align-items:center;gap:8px;}
.edit-btn{background:none;border:1px solid rgba(0,212,255,0.2);color:var(--muted);border-radius:4px;padding:2px 7px;font-size:10px;cursor:pointer;transition:all 0.15s;}
.edit-btn:hover{border-color:var(--accent);color:var(--accent);background:rgba(0,212,255,0.07);}
.inline-edit-input{background:rgba(0,212,255,0.08);border:1px solid var(--accent);color:#e6f1ff;border-radius:4px;padding:3px 8px;font-size:16px;font-weight:700;font-family:inherit;outline:none;width:300px;}

/* ── BUTTONS ── */
.btn{display:inline-flex;align-items:center;gap:5px;padding:5px 12px;border-radius:4px;font-size:11px;font-weight:600;cursor:pointer;border:none;transition:all 0.2s;font-family:inherit;}
.btn-accent{background:var(--accent);color:#0a0f1c;}
.btn-accent:hover{background:var(--accent-hover);transform:translateY(-1px);box-shadow:0 2px 8px rgba(0,212,255,0.35);}
.btn-ghost{background:transparent;border:1px solid rgba(0,212,255,0.2);color:var(--muted);}
.btn-ghost:hover{background:rgba(0,212,255,0.1);border-color:rgba(0,212,255,0.4);color:#e6f1ff;}
.btn-danger{background:rgba(255,46,99,0.14);color:var(--danger);border:1px solid rgba(255,46,99,0.25);}
.btn-danger:hover{background:rgba(255,46,99,0.24);}
.btn-ok{background:rgba(0,255,136,0.12);color:var(--ok);border:1px solid rgba(0,255,136,0.2);}
.btn-ok:hover{background:rgba(0,255,136,0.22);}
.btn-warn{background:rgba(255,204,0,0.12);color:var(--warn);border:1px solid rgba(255,204,0,0.2);}
.btn-warn:hover{background:rgba(255,204,0,0.22);}
.btn-info{background:rgba(0,153,255,0.12);color:var(--info);border:1px solid rgba(0,153,255,0.2);}
.btn-info:hover{background:rgba(0,153,255,0.22);}

/* ── STAT CARDS ── */
.stats-row{display:grid;grid-template-columns:repeat(5,1fr);gap:8px;margin-bottom:12px;}
.stat-card{background:var(--card);border-radius:var(--radius);padding:12px 14px;border:1px solid rgba(0,212,255,0.1);transition:all 0.2s;}
.stat-card:hover{border-color:rgba(0,212,255,0.3);transform:translateY(-1px);box-shadow:0 4px 16px rgba(0,212,255,0.1);}
.st-lbl{font-size:9px;color:var(--muted);text-transform:uppercase;letter-spacing:1px;font-weight:600;margin-bottom:4px;}
.st-val{font-size:28px;font-weight:700;color:var(--accent);line-height:1;}
.st-sub{font-size:10px;color:var(--muted);margin-top:3px;}
.stat-card.red .st-val{color:var(--danger);}
.stat-card.ok .st-val{color:var(--ok);}
.stat-card.warn .st-val{color:var(--warn);}

/* ── SEARCH ── */
.search-bar{display:flex;gap:8px;margin-bottom:12px;}
.srch{flex:1;padding:7px 12px;border:1px solid rgba(0,212,255,0.2);border-radius:4px;font-size:12px;background:rgba(0,212,255,0.05);color:#e6f1ff;outline:none;transition:all 0.2s;font-family:inherit;}
.srch::placeholder{color:var(--muted);}
.srch:focus{border-color:var(--accent);background:rgba(0,212,255,0.09);}
.fsel{padding:7px 10px;border:1px solid rgba(0,212,255,0.2);border-radius:4px;font-size:11px;background:rgba(0,212,255,0.05);color:#e6f1ff;font-family:inherit;outline:none;}
.fsel option{background:#1a2235;color:#e6f1ff;}

/* ── PLAYLIST ── */
.pl-wrap{display:grid;grid-template-columns:1fr 290px;gap:10px;margin-bottom:14px;}
.player-main{background:var(--card);border-radius:10px;border:1px solid rgba(0,212,255,0.15);overflow:hidden;}
.player-screen{width:100%;aspect-ratio:16/9;background:#000;display:flex;align-items:center;justify-content:center;flex-direction:column;position:relative;}
.player-screen video{width:100%;height:100%;object-fit:contain;display:none;}
.player-idle{display:flex;flex-direction:column;align-items:center;justify-content:center;gap:10px;width:100%;height:100%;color:var(--muted);}
.idle-icon{width:52px;height:52px;background:rgba(0,212,255,0.1);border:1px solid rgba(0,212,255,0.2);border-radius:50%;display:flex;align-items:center;justify-content:center;}
.player-controls{padding:10px 12px;background:rgba(0,212,255,0.03);border-top:1px solid rgba(0,212,255,0.1);display:flex;flex-direction:column;gap:8px;}
.pl-title{font-size:13px;font-weight:600;color:#e6f1ff;}
.pl-meta{font-size:10px;color:var(--muted);}
.pl-btns{display:flex;align-items:center;gap:6px;flex-wrap:wrap;}
.play-all-btn{display:inline-flex;align-items:center;gap:6px;padding:6px 14px;background:var(--accent);color:#0a0f1c;border:none;border-radius:20px;font-size:11px;font-weight:700;cursor:pointer;transition:all 0.2s;font-family:inherit;}
.play-all-btn:hover{background:var(--accent-hover);box-shadow:0 0 14px rgba(0,212,255,0.45);}
.play-all-btn.playing{background:var(--warn);color:#0a0f1c;}
.ctrl-btn{width:28px;height:28px;border-radius:50%;background:rgba(0,212,255,0.1);border:1px solid rgba(0,212,255,0.2);color:var(--accent);cursor:pointer;display:flex;align-items:center;justify-content:center;transition:all 0.2s;}
.ctrl-btn:hover{background:rgba(0,212,255,0.2);transform:scale(1.1);}
.ctrl-btn:disabled{opacity:0.3;cursor:not-allowed;transform:none;}
.prog-wrap{display:flex;align-items:center;gap:8px;font-size:10px;color:var(--muted);}
.prog-track{flex:1;height:4px;background:rgba(0,212,255,0.1);border-radius:2px;cursor:pointer;overflow:hidden;}
.prog-fill{height:100%;background:var(--accent);border-radius:2px;width:0%;transition:width 0.3s;}
.pl-sidebar{background:var(--card);border-radius:10px;border:1px solid rgba(0,212,255,0.12);overflow:hidden;display:flex;flex-direction:column;max-height:400px;}
.pl-hdr{padding:8px 12px;background:rgba(0,212,255,0.08);border-bottom:1px solid rgba(0,212,255,0.1);font-size:11px;font-weight:600;color:var(--accent);display:flex;align-items:center;gap:6px;}
.pl-list{overflow-y:auto;flex:1;}
.pl-list::-webkit-scrollbar{width:3px;}
.pl-list::-webkit-scrollbar-thumb{background:rgba(0,212,255,0.2);}
.pl-item{display:flex;align-items:center;gap:8px;padding:8px 10px;cursor:pointer;border-bottom:1px solid rgba(0,212,255,0.06);transition:all 0.15s;position:relative;}
.pl-item:hover{background:rgba(0,212,255,0.07);}
.pl-item.playing{background:rgba(0,212,255,0.12);border-left:2px solid var(--accent);}
.pl-num{width:20px;height:20px;border-radius:50%;background:rgba(0,212,255,0.1);border:1px solid rgba(0,212,255,0.2);display:flex;align-items:center;justify-content:center;font-size:9px;font-weight:700;color:var(--muted);flex-shrink:0;}
.pl-item.playing .pl-num{background:var(--accent);color:#0a0f1c;animation:plPulse 1.4s ease-in-out infinite;}
@keyframes plPulse{0%,100%{box-shadow:0 0 0 0 rgba(0,212,255,0.4);}50%{box-shadow:0 0 0 5px rgba(0,212,255,0);}}
.pl-info{flex:1;min-width:0;}
.pl-t{font-size:11px;font-weight:500;color:#e6f1ff;white-space:nowrap;overflow:hidden;text-overflow:ellipsis;}
.pl-m{font-size:9px;color:var(--muted);}
.pl-d{font-size:9px;color:var(--muted);flex-shrink:0;}
.mandatory-dot{position:absolute;top:5px;right:5px;width:5px;height:5px;border-radius:50%;background:var(--danger);box-shadow:0 0 4px var(--danger);}

/* ── VIDEO GRID ── */
.video-grid{display:grid;grid-template-columns:repeat(auto-fill,minmax(275px,1fr));gap:10px;margin-bottom:14px;}
.vcard{background:var(--card);border-radius:10px;overflow:hidden;border:1px solid rgba(0,212,255,0.1);transition:all 0.2s;cursor:pointer;}
.vcard:hover{border-color:rgba(0,212,255,0.3);transform:translateY(-2px);box-shadow:0 4px 18px rgba(0,212,255,0.1);}
.vcard.ql{border-color:var(--accent);box-shadow:0 0 0 1px rgba(0,212,255,0.25);}
.vthumb{width:100%;aspect-ratio:16/9;background:#06101e;position:relative;display:flex;align-items:center;justify-content:center;}
.vplay{width:40px;height:40px;background:rgba(0,212,255,0.9);border-radius:50%;display:flex;align-items:center;justify-content:center;box-shadow:0 0 14px rgba(0,212,255,0.5);transition:all 0.2s;}
.vcard:hover .vplay{transform:scale(1.12);box-shadow:0 0 22px rgba(0,212,255,0.7);}
.vdur{position:absolute;bottom:6px;right:6px;background:rgba(0,0,0,0.75);color:#e6f1ff;font-size:9px;font-weight:600;padding:1px 5px;border-radius:2px;}
.vcat{position:absolute;top:6px;left:6px;font-size:8px;font-weight:700;padding:2px 6px;border-radius:2px;text-transform:uppercase;letter-spacing:0.3px;}
.vcat.safety{background:var(--danger);color:#fff;}
.vcat.quality{background:var(--info);color:#fff;}
.vmand{position:absolute;top:6px;right:6px;background:rgba(255,46,99,0.85);color:#fff;font-size:7px;font-weight:700;padding:1px 5px;border-radius:2px;letter-spacing:0.5px;}
.vinfo{padding:10px 12px;}
.vtitle{font-size:12px;font-weight:600;color:#e6f1ff;line-height:1.4;margin-bottom:4px;}
.vmeta{display:flex;align-items:center;gap:10px;font-size:10px;color:var(--muted);}
.vactions{display:flex;gap:5px;padding:0 12px 10px;}

/* ── SECTION DIVIDER ── */
.sec-div{display:flex;align-items:center;gap:10px;margin:14px 0 10px;}
.sec-div-lbl{font-size:13px;font-weight:700;color:var(--accent);white-space:nowrap;letter-spacing:0.5px;}
.sec-div-line{flex:1;height:1px;background:rgba(0,212,255,0.12);}
.sec-div-cnt{font-size:10px;color:var(--muted);}

/* ── SPEC TRAINING ── */
.spec-outer{display:grid;grid-template-columns:220px 1fr;gap:12px;min-height:600px;}
.spec-items-panel{background:var(--card);border-radius:10px;border:1px solid rgba(0,212,255,0.12);overflow:hidden;display:flex;flex-direction:column;}
.spec-items-hdr{padding:8px 12px;background:rgba(0,212,255,0.07);border-bottom:1px solid rgba(0,212,255,0.1);font-size:11px;font-weight:600;color:var(--accent);display:flex;align-items:center;justify-content:space-between;flex-shrink:0;}
.spec-items-search{padding:6px 8px;border-bottom:1px solid rgba(0,212,255,0.08);flex-shrink:0;}
.spec-items-search input{width:100%;padding:4px 8px;border:1px solid rgba(0,212,255,0.18);border-radius:4px;font-size:11px;background:rgba(0,212,255,0.05);color:#e6f1ff;outline:none;font-family:inherit;}
.spec-items-search input::placeholder{color:var(--muted);}
.spec-items-search input:focus{border-color:var(--accent);}
.spec-items-list{overflow-y:auto;flex:1;}
.spec-items-list::-webkit-scrollbar{width:3px;}
.spec-items-list::-webkit-scrollbar-thumb{background:rgba(0,212,255,0.2);}
.spec-item-row{padding:6px 12px;cursor:pointer;border-bottom:1px solid rgba(0,212,255,0.05);transition:all 0.15s;display:flex;align-items:center;justify-content:space-between;}
.spec-item-row:hover{background:rgba(0,212,255,0.07);}
.spec-item-row.active{background:rgba(0,212,255,0.14);color:var(--accent);border-left:2px solid var(--accent);}
.spec-item-name{font-size:11px;font-weight:500;color:#e6f1ff;}
.spec-item-row.active .spec-item-name{color:var(--accent);}
.spec-item-cnt{font-size:9px;color:var(--muted);background:rgba(0,212,255,0.1);padding:1px 5px;border-radius:10px;white-space:nowrap;}
.spec-detail-panel{background:var(--card);border-radius:10px;border:1px solid rgba(0,212,255,0.12);overflow:hidden;display:flex;flex-direction:column;}
.spec-detail-hdr{padding:10px 14px;background:rgba(0,212,255,0.06);border-bottom:1px solid rgba(0,212,255,0.1);display:flex;align-items:center;justify-content:space-between;flex-shrink:0;flex-wrap:wrap;gap:6px;}
.spec-detail-title{font-size:13px;font-weight:700;color:var(--accent);}
.spec-detail-sub{font-size:10px;color:var(--muted);margin-top:2px;}
.spec-detail-actions{display:flex;gap:5px;}
.spec-types-wrap{padding:10px;flex:1;overflow-y:auto;}
.spec-types-wrap::-webkit-scrollbar{width:3px;}
.spec-types-wrap::-webkit-scrollbar-thumb{background:rgba(0,212,255,0.2);}
.spec-empty{display:flex;flex-direction:column;align-items:center;justify-content:center;height:200px;color:var(--muted);font-size:12px;gap:10px;}

.types-grid{display:grid;grid-template-columns:repeat(auto-fill,minmax(185px,1fr));gap:8px;}
.type-block{background:rgba(0,212,255,0.04);border:1px solid rgba(0,212,255,0.1);border-radius:6px;overflow:hidden;transition:border-color 0.2s;}
.type-block:hover{border-color:rgba(0,212,255,0.25);}
.type-hdr{display:flex;align-items:center;justify-content:space-between;padding:5px 8px;background:rgba(0,212,255,0.06);cursor:pointer;transition:background 0.15s;}
.type-hdr:hover{background:rgba(0,212,255,0.1);}
.type-name{font-size:10px;font-weight:700;color:var(--accent);letter-spacing:0.4px;text-transform:uppercase;white-space:normal;overflow:visible;word-break:break-word;line-height:1.35;}
.type-body{padding:6px 8px;display:flex;flex-direction:column;gap:5px;}
.type-img-area{
  width:100%;background:#06101e;border:1px dashed rgba(0,212,255,0.2);
  border-radius:4px;display:flex;align-items:center;justify-content:center;
  flex-direction:column;gap:3px;cursor:pointer;transition:all 0.2s;overflow:hidden;position:relative;
  min-height:80px;
}
.type-img-area.has-image{aspect-ratio:unset;min-height:unset;}
.type-img-area:hover{border-color:var(--accent);background:rgba(0,212,255,0.05);}
.type-img-area img{width:100%;height:auto;object-fit:contain;display:none;position:relative;}
.type-img-placeholder{display:flex;flex-direction:column;align-items:center;gap:3px;color:var(--muted);font-size:9px;pointer-events:none;}
.type-img-actions{display:flex;gap:4px;align-items:center;justify-content:space-between;}
.type-img-label{font-size:9px;color:var(--muted);}

.add-type-row{display:flex;gap:5px;padding:8px 10px;border-top:1px solid rgba(0,212,255,0.08);}
.add-type-input{flex:1;padding:4px 8px;border:1px solid rgba(0,212,255,0.2);border-radius:4px;font-size:11px;background:rgba(0,212,255,0.05);color:#e6f1ff;outline:none;font-family:inherit;}
.add-type-input::placeholder{color:var(--muted);}
.add-type-input:focus{border-color:var(--accent);}
.add-item-bar{padding:8px 10px;border-top:1px solid rgba(0,212,255,0.08);display:flex;gap:5px;flex-shrink:0;}
.add-item-input{flex:1;padding:4px 8px;border:1px solid rgba(0,212,255,0.2);border-radius:4px;font-size:11px;background:rgba(0,212,255,0.05);color:#e6f1ff;outline:none;font-family:inherit;}
.add-item-input::placeholder{color:var(--muted);}
.add-item-input:focus{border-color:var(--accent);}

/* ── IMAGE QUIZ MODAL ── */
.quiz-overlay{display:none;position:fixed;inset:0;background:rgba(0,0,0,0.88);z-index:600;align-items:center;justify-content:center;}
.quiz-overlay.open{display:flex;}
.quiz-box{background:#111827;border-radius:14px;width:92vw;max-width:700px;border:1px solid rgba(0,212,255,0.3);box-shadow:0 12px 60px rgba(0,0,0,0.7);display:flex;flex-direction:column;max-height:92vh;overflow:hidden;}
.quiz-hdr{padding:14px 18px;background:rgba(0,212,255,0.08);border-bottom:1px solid rgba(0,212,255,0.12);display:flex;align-items:center;justify-content:space-between;}
.quiz-title{font-size:14px;font-weight:700;color:var(--accent);}
.quiz-close{background:none;border:none;color:var(--muted);cursor:pointer;font-size:18px;padding:0 4px;}
.quiz-close:hover{color:#e6f1ff;}
.quiz-body{padding:18px;flex:1;overflow-y:auto;}
.quiz-progress{display:flex;align-items:center;gap:10px;margin-bottom:16px;}
.quiz-prog-bar{flex:1;height:4px;background:rgba(0,212,255,0.1);border-radius:2px;overflow:hidden;}
.quiz-prog-fill{height:100%;background:var(--accent);border-radius:2px;transition:width 0.4s;}
.quiz-counter{font-size:11px;color:var(--muted);white-space:nowrap;}
.quiz-q{font-size:14px;font-weight:700;color:#e6f1ff;margin-bottom:4px;line-height:1.5;}
.quiz-q-sub{font-size:11px;color:var(--muted);margin-bottom:16px;}
/* Image quiz options grid */
.quiz-img-opts{display:grid;grid-template-columns:repeat(2,1fr);gap:10px;}
.quiz-img-opt{border:2px solid rgba(0,212,255,0.18);border-radius:8px;cursor:pointer;overflow:hidden;transition:all 0.15s;background:rgba(0,212,255,0.04);display:flex;flex-direction:column;align-items:center;}
.quiz-img-opt:hover{border-color:var(--accent);transform:scale(1.02);box-shadow:0 0 12px rgba(0,212,255,0.2);}
.quiz-img-opt.correct{border-color:var(--ok);box-shadow:0 0 14px rgba(0,255,136,0.3);}
.quiz-img-opt.wrong{border-color:var(--danger);box-shadow:0 0 14px rgba(255,46,99,0.2);}
.quiz-img-opt.reveal{border-color:var(--ok);}
.quiz-img-opt:disabled{cursor:default;}
.quiz-img-block{width:100%;height:140px;display:flex;align-items:center;justify-content:center;font-size:22px;font-weight:700;letter-spacing:1px;overflow:hidden;background:#06101e;}
.quiz-img-block img{width:100%;height:140px;object-fit:contain;display:block;}
.quiz-img-label{padding:6px 10px;font-size:11px;font-weight:600;color:#e6f1ff;text-align:center;width:100%;background:rgba(0,0,0,0.25);display:none;}
.quiz-img-opt.show-label .quiz-img-label{display:block;}
.quiz-img-label-visible{padding:6px 10px;font-size:11px;font-weight:600;color:#e6f1ff;text-align:center;width:100%;background:rgba(0,0,0,0.25);}
/* Text quiz options */
.quiz-opts{display:flex;flex-direction:column;gap:7px;}
.quiz-opt{padding:9px 14px;border:1px solid rgba(0,212,255,0.18);border-radius:6px;cursor:pointer;font-size:12px;color:#e6f1ff;background:rgba(0,212,255,0.04);transition:all 0.15s;text-align:left;}
.quiz-opt:hover{border-color:var(--accent);background:rgba(0,212,255,0.1);}
.quiz-opt.correct{border-color:var(--ok);background:rgba(0,255,136,0.1);color:var(--ok);}
.quiz-opt.wrong{border-color:var(--danger);background:rgba(255,46,99,0.1);color:var(--danger);}
.quiz-opt.reveal{border-color:var(--ok);background:rgba(0,255,136,0.06);color:var(--ok);}
.quiz-opt:disabled{cursor:default;}
.quiz-feedback{margin-top:12px;padding:10px 12px;border-radius:6px;font-size:12px;}
.quiz-feedback.correct{background:rgba(0,255,136,0.08);border:1px solid rgba(0,255,136,0.2);color:var(--ok);}
.quiz-feedback.wrong{background:rgba(255,46,99,0.08);border:1px solid rgba(255,46,99,0.2);color:var(--danger);}
.quiz-actions{padding:14px 18px;border-top:1px solid rgba(0,212,255,0.1);display:flex;justify-content:space-between;align-items:center;gap:10px;}
.quiz-score{font-size:11px;color:var(--muted);}
.quiz-score b{color:var(--accent);}
.quiz-result{text-align:center;padding:20px;}
.quiz-result-score{font-size:48px;font-weight:700;color:var(--accent);line-height:1;}
.quiz-result-label{font-size:14px;color:var(--muted);margin-top:4px;}
.quiz-result-detail{font-size:12px;color:#e6f1ff;margin-top:12px;}

/* ── INSPECTION TRAINER (InspectPro) ── */
.inspect-wrap{background:var(--bg);border-radius:10px;border:1px solid rgba(0,212,255,0.12);overflow:hidden;display:flex;flex-direction:column;min-height:700px;}
.ipt-hdr{height:48px;background:linear-gradient(90deg,#0d1422,#0f1824);border-bottom:1px solid var(--bdr);display:flex;align-items:center;padding:0 1rem;gap:1rem;position:relative;overflow:hidden;}
.ipt-hdr::after{content:'';position:absolute;bottom:0;left:0;right:0;height:1.5px;background:linear-gradient(90deg,transparent,var(--accent),transparent);animation:scan 3s linear infinite;}
@keyframes scan{from{transform:translateX(-100%)}to{transform:translateX(100%)}}
.ipt-logo{font-family:var(--fh);font-size:18px;font-weight:700;letter-spacing:3px;color:var(--accent);text-transform:uppercase;}
.ipt-logo b{color:var(--acc2);}
.ipt-tag{font-size:9px;color:var(--txt3);border:1px solid var(--bdr);padding:2px 7px;border-radius:2px;letter-spacing:1px;}
.ipt-online{margin-left:auto;display:flex;align-items:center;gap:7px;font-size:10px;color:var(--grn);letter-spacing:1px;}
.ipt-dot{width:6px;height:6px;border-radius:50%;background:var(--grn);animation:blink 1.5s ease-in-out infinite;}
@keyframes blink{0%,100%{opacity:1}50%{opacity:.15}}
.ipt-body{flex:1;display:grid;grid-template-columns:160px 1fr;overflow:hidden;}
.ipt-sb{background:var(--bg2);border-right:1px solid var(--bdr);display:flex;flex-direction:column;overflow-y:auto;padding:.6rem 0;}
.ipt-sb-lbl{font-size:9px;color:var(--txt3);letter-spacing:2px;padding:0 .8rem;margin-bottom:3px;text-transform:uppercase;}
.ipt-ni{display:flex;align-items:center;gap:7px;padding:8px .8rem;cursor:pointer;border-left:3px solid transparent;transition:all .12s;}
.ipt-ni:hover{background:rgba(0,200,240,.04);border-left-color:rgba(0,200,240,.2);}
.ipt-ni.on{background:rgba(0,200,240,.07);border-left-color:var(--accent);}
.ipt-nic{width:24px;height:24px;border-radius:3px;background:var(--bg3);border:1px solid var(--bdr);display:flex;align-items:center;justify-content:center;flex-shrink:0;}
.ipt-ni.on .ipt-nic{background:rgba(0,200,240,.1);border-color:var(--accent);}
.ipt-nic svg{width:12px;height:12px;}
.ipt-ntx{font-family:var(--fh);font-size:11px;font-weight:600;letter-spacing:1px;color:var(--txt2);}
.ipt-ni.on .ipt-ntx{color:var(--accent);}
.ipt-nst{font-size:9px;color:var(--txt3);margin-top:1px;}
.ipt-nb{font-size:9px;padding:1px 5px;border-radius:6px;background:var(--bg3);color:var(--txt3);border:1px solid var(--bdr);margin-left:auto;white-space:nowrap;}
.ipt-ni.on .ipt-nb{background:rgba(0,200,240,.1);color:var(--accent);border-color:var(--accent);}
.ipt-sdiv{height:1px;background:var(--bdr);margin:5px .8rem;}
.ipt-sp{margin:auto .8rem 0;background:var(--bg3);border:1px solid var(--bdr);border-radius:4px;padding:.6rem;}
.ipt-spt{font-size:9px;color:var(--txt3);letter-spacing:2px;margin-bottom:5px;text-transform:uppercase;}
.ipt-spr{display:flex;justify-content:space-between;padding:2px 0;font-size:10px;}
.ipt-spr span:first-child{color:var(--txt2);}
.ipt-spr span:last-child{color:var(--accent);}
.ipt-main{overflow-y:auto;background:var(--bg);padding:.8rem;}
.ipt-pane{display:none;}
.ipt-pane.on{display:flex;flex-direction:column;gap:.7rem;}
.ipt-mh{display:flex;align-items:flex-start;justify-content:space-between;gap:1rem;}
.ipt-mt{font-family:var(--fh);font-size:17px;font-weight:700;letter-spacing:2px;text-transform:uppercase;line-height:1;}
.ipt-mt span{color:var(--accent);}
.ipt-md{font-size:11px;color:var(--txt2);margin-top:3px;line-height:1.45;}
.ipt-stag{font-size:10px;padding:3px 8px;border-radius:2px;background:rgba(255,215,0,.07);border:1px solid rgba(255,215,0,.28);color:var(--warn);white-space:nowrap;letter-spacing:1px;}
.ipt-cw{background:#000;border-radius:6px;overflow:auto;position:relative;}
.ipt-cw canvas{display:block;image-rendering:pixelated;}
.ipt-cam{position:absolute;top:6px;left:6px;font-size:9px;color:var(--txt3);letter-spacing:2px;text-transform:uppercase;background:rgba(0,0,0,.75);padding:2px 6px;border-radius:2px;border:1px solid var(--bdr);}
.ipt-cb{background:var(--bg2);border:1px solid var(--bdr);border-radius:5px;padding:.65rem .8rem;display:flex;flex-direction:column;gap:8px;}
.ipt-ir{display:flex;gap:7px;align-items:flex-end;flex-wrap:wrap;}
.ipt-fg{display:flex;flex-direction:column;gap:3px;}
.ipt-fl{font-size:9px;color:var(--txt3);letter-spacing:1.5px;text-transform:uppercase;}
.ipt-fi{background:var(--bg3);border:1px solid var(--bdr);border-radius:3px;color:var(--txt);font-family:var(--fm);font-size:13px;padding:5px 8px;width:85px;outline:none;transition:border-color .2s;}
.ipt-fi:focus{border-color:var(--accent);}
.ipt-fs{background:var(--bg3);border:1px solid var(--bdr);border-radius:3px;color:var(--txt);font-family:var(--fh);font-size:12px;font-weight:600;letter-spacing:.5px;padding:5px 8px;outline:none;cursor:pointer;min-width:110px;}
.ipt-bc{padding:6px 13px;font-family:var(--fh);font-size:12px;font-weight:700;letter-spacing:2px;text-transform:uppercase;border-radius:3px;border:1px solid var(--accent);background:rgba(0,200,240,.1);color:var(--accent);cursor:pointer;transition:all .14s;}
.ipt-bc:hover{background:rgba(0,200,240,.2);}
.ipt-bn{padding:6px 11px;font-family:var(--fh);font-size:11px;font-weight:600;letter-spacing:1px;text-transform:uppercase;border-radius:3px;border:1px solid var(--bdr);background:transparent;color:var(--txt2);cursor:pointer;transition:all .14s;}
.ipt-bn:hover{border-color:var(--txt2);color:var(--txt);}
.ipt-tn{font-size:10px;color:var(--txt3);}
.ipt-fb{padding:7px 10px;border-radius:3px;font-size:11px;display:none;animation:fi .2s ease;}
@keyframes fi{from{opacity:0;transform:translateY(-3px)}to{opacity:1;transform:translateY(0)}}
.ipt-fb.p{display:block;background:rgba(0,230,118,.07);border:1px solid rgba(0,230,118,.32);color:var(--grn);}
.ipt-fb.f{display:block;background:rgba(255,51,51,.07);border:1px solid rgba(255,51,51,.32);color:var(--red);}
.ipt-sc{display:flex;gap:5px;}
.ipt-sp2{font-size:10px;padding:2px 7px;border-radius:2px;letter-spacing:1px;}
.ipt-sp2.g{background:rgba(0,230,118,.09);color:var(--grn);border:1px solid rgba(0,230,118,.28);}
.ipt-sp2.t{background:var(--bg3);color:var(--txt2);border:1px solid var(--bdr);}
.ipt-hb{font-size:10px;color:var(--accent);background:none;border:none;cursor:pointer;padding:0;text-decoration:underline;text-underline-offset:3px;}
.ipt-hx{font-size:11px;color:var(--txt2);background:rgba(0,200,240,.04);border:1px solid rgba(0,200,240,.14);border-radius:3px;padding:5px 8px;display:none;}
.ipt-hx.show{display:block;}

/* ── DASHBOARD ── */
.dash-grid{display:grid;grid-template-columns:2fr 1fr;gap:10px;margin-top:4px;}
.dash-card{background:var(--card);border-radius:var(--radius);padding:14px;border:1px solid rgba(0,212,255,0.1);}
.dash-card-title{font-size:12px;font-weight:600;color:#e6f1ff;margin-bottom:10px;padding-bottom:8px;border-bottom:1px solid rgba(0,212,255,0.1);display:flex;align-items:center;gap:7px;}
.prog-item{display:flex;align-items:center;gap:8px;margin-bottom:8px;}
.prog-lbl{font-size:11px;color:#e6f1ff;min-width:160px;}
.prog-trk{flex:1;height:5px;background:rgba(0,212,255,0.1);border-radius:3px;overflow:hidden;}
.prog-bar{height:100%;border-radius:3px;background:var(--accent);transition:width 0.7s ease;}
.prog-bar.ok{background:var(--ok);}
.prog-bar.info{background:var(--info);}
.prog-pct{font-size:10px;font-weight:600;color:var(--muted);min-width:28px;text-align:right;}
.act-item{display:flex;gap:8px;padding:7px 0;border-bottom:1px solid rgba(0,212,255,0.06);}
.act-item:last-child{border:none;}
.adot{width:7px;height:7px;border-radius:50%;margin-top:4px;flex-shrink:0;}
.adot.r{background:var(--danger);box-shadow:0 0 4px var(--danger);}
.adot.g{background:var(--ok);box-shadow:0 0 4px var(--ok);}
.adot.b{background:var(--info);box-shadow:0 0 4px var(--info);}
.act-text{font-size:11px;color:#e6f1ff;line-height:1.4;}
.act-time{font-size:9px;color:var(--muted);}

/* ── EDIT CONTENT MODAL ── */
.modal-overlay{display:none;position:fixed;inset:0;background:rgba(0,0,0,0.75);z-index:500;align-items:center;justify-content:center;}
.modal-overlay.open{display:flex;}
.modal-box{background:#111827;border-radius:var(--radius);width:90vw;max-width:560px;padding:22px;border:1px solid rgba(0,212,255,0.22);box-shadow:0 12px 50px rgba(0,0,0,0.6);max-height:90vh;overflow-y:auto;}
.modal-title{font-size:15px;font-weight:700;color:var(--accent);margin-bottom:4px;}
.modal-sub{font-size:11px;color:var(--muted);margin-bottom:14px;padding-bottom:12px;border-bottom:1px solid rgba(0,212,255,0.1);}
.form-row{margin-bottom:10px;}
.form-row2{display:grid;grid-template-columns:1fr 1fr;gap:8px;}
.flbl{display:block;font-size:10px;font-weight:600;text-transform:uppercase;letter-spacing:0.8px;color:var(--muted);margin-bottom:4px;}
.finput,.fselect,.ftarea{width:100%;padding:7px 10px;border:1px solid rgba(0,212,255,0.18);border-radius:4px;font-size:12px;font-family:inherit;outline:none;background:rgba(0,212,255,0.05);color:#e6f1ff;transition:all 0.15s;}
.finput::placeholder{color:var(--muted);}
.finput:focus,.fselect:focus,.ftarea:focus{border-color:var(--accent);background:rgba(0,212,255,0.09);}
.ftarea{resize:vertical;min-height:80px;}
.fselect option{background:#1a2235;color:#e6f1ff;}
.upload-zone{width:100%;padding:16px;border:1px dashed rgba(0,212,255,0.25);border-radius:4px;text-align:center;cursor:pointer;color:var(--muted);font-size:11px;transition:all 0.15px;display:flex;flex-direction:column;align-items:center;gap:4px;}
.upload-zone:hover{border-color:var(--accent);background:rgba(0,212,255,0.05);}
.modal-footer{display:flex;justify-content:flex-end;gap:8px;margin-top:14px;padding-top:12px;border-top:1px solid rgba(0,212,255,0.1);}

/* ── LIGHTBOX ── */
.lb{display:none;position:fixed;inset:0;background:rgba(0,0,0,0.92);z-index:800;align-items:center;justify-content:center;flex-direction:column;}
.lb.open{display:flex;}
.lb-cls{position:absolute;top:16px;right:20px;background:none;border:none;color:#e6f1ff;font-size:26px;cursor:pointer;opacity:0.6;}
.lb-cls:hover{opacity:1;}
.lb img{max-width:88vw;max-height:80vh;border-radius:8px;object-fit:contain;}
.lb-cap{margin-top:12px;font-size:12px;color:var(--muted);}

/* ── TOAST ── */
.toast{position:fixed;bottom:20px;right:20px;background:#1a2235;border:1px solid rgba(0,212,255,0.25);border-radius:8px;padding:8px 14px;display:flex;align-items:center;gap:8px;font-size:12px;z-index:900;opacity:0;transform:translateY(8px);transition:all 0.3s;pointer-events:none;}
.toast.show{opacity:1;transform:translateY(0);}
.tdot{width:7px;height:7px;border-radius:50%;background:var(--ok);box-shadow:0 0 6px var(--ok);}

/* ── EDIT CONTENT PANEL ── */
.page-edit-bar{display:flex;align-items:center;gap:8px;padding:8px 12px;background:rgba(255,204,0,0.06);border:1px solid rgba(255,204,0,0.15);border-radius:8px;margin-bottom:12px;}
.page-edit-bar span{font-size:11px;color:var(--warn);flex:1;}
.content-block-editable{position:relative;}
.content-block-editable:hover .content-edit-trigger{opacity:1;}
.content-edit-trigger{position:absolute;top:4px;right:4px;opacity:0;transition:opacity 0.15s;background:rgba(255,204,0,0.15);border:1px solid rgba(255,204,0,0.3);color:var(--warn);padding:2px 7px;border-radius:3px;font-size:9px;cursor:pointer;}

/* ══ SOS PAGE ══ */
.sos-outer{display:grid;grid-template-columns:240px 1fr;gap:12px;min-height:600px;}
.sos-proc-panel{background:var(--card);border-radius:10px;border:1px solid rgba(255,153,0,0.15);overflow:hidden;display:flex;flex-direction:column;}
.sos-proc-hdr{padding:8px 12px;background:rgba(255,153,0,0.07);border-bottom:1px solid rgba(255,153,0,0.12);font-size:11px;font-weight:600;color:#ff9900;display:flex;align-items:center;gap:6px;}
.sos-proc-search{padding:6px 8px;border-bottom:1px solid rgba(255,153,0,0.08);}
.sos-proc-search input{width:100%;padding:4px 8px;border:1px solid rgba(255,153,0,0.2);border-radius:4px;font-size:11px;background:rgba(255,153,0,0.04);color:#e6f1ff;outline:none;font-family:inherit;}
.sos-proc-search input::placeholder{color:var(--muted);}
.sos-proc-search input:focus{border-color:#ff9900;}
.sos-proc-list{overflow-y:auto;flex:1;}
.sos-proc-list::-webkit-scrollbar{width:3px;}
.sos-proc-list::-webkit-scrollbar-thumb{background:rgba(255,153,0,0.2);}
.sos-proc-row{display:flex;flex-direction:column;gap:2px;padding:8px 12px;cursor:pointer;border-bottom:1px solid rgba(255,153,0,0.06);transition:all 0.15s;border-left:2px solid transparent;}
.sos-proc-row:hover{background:rgba(255,153,0,0.06);}
.sos-proc-row.active{background:rgba(255,153,0,0.1);border-left-color:#ff9900;}
.sos-proc-name{font-size:11px;font-weight:600;color:#e6f1ff;line-height:1.3;}
.sos-proc-meta{font-size:9px;color:var(--muted);letter-spacing:0.3px;}
.sos-proc-cnt{font-size:9px;color:#ff9900;font-weight:600;}
.sos-detail-panel{background:var(--card);border-radius:10px;border:1px solid rgba(255,153,0,0.15);overflow:hidden;display:flex;flex-direction:column;}
.sos-detail-empty{display:flex;flex-direction:column;align-items:center;justify-content:center;gap:10px;height:400px;color:var(--muted);font-size:12px;}
.sos-proc-info{padding:10px 14px;background:rgba(255,153,0,0.05);border-bottom:1px solid rgba(255,153,0,0.1);display:flex;align-items:center;gap:12px;flex-wrap:wrap;}
.sos-info-tag{font-size:10px;padding:2px 8px;border-radius:3px;font-weight:600;letter-spacing:0.5px;}
.sos-info-tag.model{background:rgba(0,212,255,0.1);color:var(--accent);border:1px solid rgba(0,212,255,0.2);}
.sos-info-tag.takt{background:rgba(255,204,0,0.1);color:var(--warn);border:1px solid rgba(255,204,0,0.2);}
.sos-info-tag.process{background:rgba(255,153,0,0.1);color:#ff9900;border:1px solid rgba(255,153,0,0.2);}
.sos-table-wrap{overflow-x:auto;overflow-y:auto;max-height:calc(100vh - 320px);}
.sos-table-wrap::-webkit-scrollbar{width:4px;height:4px;}
.sos-table-wrap::-webkit-scrollbar-thumb{background:rgba(255,153,0,0.2);}
.sos-table{width:100%;border-collapse:collapse;font-size:11px;}
.sos-table th{background:rgba(255,153,0,0.08);color:#ff9900;font-size:9px;font-weight:600;letter-spacing:1px;text-transform:uppercase;padding:6px 8px;border-bottom:1px solid rgba(255,153,0,0.15);white-space:nowrap;position:sticky;top:0;z-index:2;}
.sos-table td{padding:5px 8px;border-bottom:1px solid rgba(255,153,0,0.05);vertical-align:middle;line-height:1.4;}
.sos-table tr:hover td{background:rgba(255,153,0,0.04);}
.sos-table tr.new-item td{background:rgba(255,153,0,0.06);}
.sos-sl{font-size:10px;font-weight:600;color:var(--muted);text-align:center;}
.sos-step{font-size:9px;font-weight:700;color:var(--accent);text-align:center;}
.sos-item{color:#dde2ee;font-size:11px;}
.sos-item-local{font-size:10px;color:rgba(255,180,0,0.85);margin-top:2px;display:block;line-height:1.4;font-weight:500;}
.sos-check{font-size:10px;font-weight:600;padding:2px 5px;border-radius:2px;}
.sos-check.miss{background:rgba(255,46,99,0.12);color:var(--danger);}
.sos-check.half{background:rgba(255,204,0,0.1);color:var(--warn);}
.sos-check.unlock{background:rgba(255,153,0,0.1);color:#ff9900;}
.sos-check.coming{background:rgba(255,100,0,0.12);color:#ff6030;}
.sos-check.interference{background:rgba(255,0,100,0.1);color:#ff2e63;}
.sos-check.looseness{background:rgba(0,153,255,0.1);color:var(--info);}
.sos-check.default{background:rgba(255,255,255,0.05);color:var(--muted);}
.sos-standard{font-size:10px;color:#b0c4de;}
.sos-method{font-size:9px;padding:2px 5px;border-radius:2px;background:rgba(0,212,255,0.07);color:var(--accent);font-weight:500;white-space:nowrap;}
.sos-actions{display:flex;gap:3px;}
.sos-del-btn{background:rgba(255,46,99,0.1);border:1px solid rgba(255,46,99,0.2);color:var(--danger);border-radius:3px;padding:2px 5px;font-size:9px;cursor:pointer;transition:all 0.15s;}
.sos-del-btn:hover{background:rgba(255,46,99,0.2);}
.sos-edit-btn{background:rgba(255,204,0,0.1);border:1px solid rgba(255,204,0,0.2);color:var(--warn);border-radius:3px;padding:2px 5px;font-size:9px;cursor:pointer;transition:all 0.15s;}
.sos-edit-btn:hover{background:rgba(255,204,0,0.2);}
.sos-add-row{display:flex;align-items:center;gap:6px;padding:8px 12px;background:rgba(255,153,0,0.04);border-top:1px solid rgba(255,153,0,0.1);flex-wrap:wrap;}
.sos-add-input{padding:5px 8px;border:1px solid rgba(255,153,0,0.2);border-radius:4px;font-size:11px;background:rgba(255,153,0,0.04);color:#e6f1ff;outline:none;font-family:inherit;flex:1;min-width:100px;}
.sos-add-input::placeholder{color:var(--muted);}
.sos-add-input:focus{border-color:#ff9900;}
.sos-lang-note{font-size:9px;color:var(--muted);padding:4px 14px 6px;border-top:1px solid rgba(255,153,0,0.06);background:rgba(255,153,0,0.02);}
.sos-item-translated{display:inline-block;font-size:9px;color:rgba(255,153,0,0.55);margin-left:4px;}
.sb-badge.warn{background:rgba(255,153,0,0.15);color:#ff9900;}

/* ── SOS ROW ACTION BUTTONS ── */
.sos-view-btn{background:rgba(0,212,255,0.1);border:1px solid rgba(0,212,255,0.2);color:var(--accent);border-radius:3px;padding:2px 5px;font-size:9px;cursor:pointer;transition:all 0.15s;}
.sos-view-btn:hover{background:rgba(0,212,255,0.2);}
.sos-quiz-btn{background:rgba(0,255,136,0.1);border:1px solid rgba(0,255,136,0.2);color:var(--ok);border-radius:3px;padding:2px 5px;font-size:9px;cursor:pointer;transition:all 0.15s;}
.sos-quiz-btn:hover{background:rgba(0,255,136,0.2);}

/* ── OK/NG VIEWER MODAL ── */
.okng-overlay{display:none;position:fixed;inset:0;background:rgba(0,0,0,0.92);z-index:700;align-items:flex-start;justify-content:center;overflow-y:auto;padding:20px 0;}
.okng-overlay.open{display:flex;}
.okng-box{background:#111827;border-radius:14px;width:96vw;max-width:900px;border:1px solid rgba(0,212,255,0.3);box-shadow:0 12px 60px rgba(0,0,0,0.8);display:flex;flex-direction:column;margin:auto;}
.okng-hdr{padding:14px 18px;background:rgba(0,212,255,0.06);border-bottom:1px solid rgba(0,212,255,0.12);display:flex;align-items:center;gap:10px;flex-wrap:wrap;}
.okng-title{font-size:14px;font-weight:700;color:var(--accent);flex:1;min-width:0;}
.okng-close{background:none;border:none;color:var(--muted);cursor:pointer;font-size:20px;padding:0 4px;line-height:1;}
.okng-close:hover{color:#e6f1ff;}
.okng-body{padding:16px;}
.okng-cols{display:grid;grid-template-columns:1fr 1fr;gap:14px;}
.okng-col{display:flex;flex-direction:column;gap:8px;}
.okng-col-hdr{display:flex;align-items:center;justify-content:space-between;padding:6px 10px;border-radius:6px;font-size:11px;font-weight:700;letter-spacing:1px;}
.okng-col-hdr.ok{background:rgba(0,255,136,0.1);border:1px solid rgba(0,255,136,0.2);color:var(--ok);}
.okng-col-hdr.ng{background:rgba(255,46,99,0.1);border:1px solid rgba(255,46,99,0.2);color:var(--danger);}
.okng-img-list{display:flex;flex-direction:column;gap:8px;}
.okng-img-card{background:rgba(255,255,255,0.03);border:1px solid rgba(255,255,255,0.08);border-radius:8px;overflow:hidden;position:relative;}
.okng-img-card img{width:100%;height:160px;object-fit:contain;display:block;background:#06101e;}
.okng-img-lbl{padding:4px 8px;font-size:9px;color:var(--muted);border-top:1px solid rgba(255,255,255,0.05);display:flex;align-items:center;justify-content:space-between;}
.okng-img-del{background:rgba(255,46,99,0.1);border:1px solid rgba(255,46,99,0.2);color:var(--danger);border-radius:3px;padding:1px 5px;font-size:9px;cursor:pointer;}
.okng-img-del:hover{background:rgba(255,46,99,0.2);}
.okng-add-zone{border:2px dashed rgba(255,255,255,0.1);border-radius:8px;padding:20px;display:flex;flex-direction:column;align-items:center;gap:6px;cursor:pointer;transition:all 0.2s;min-height:80px;justify-content:center;}
.okng-add-zone:hover{border-color:rgba(0,212,255,0.35);background:rgba(0,212,255,0.04);}
.okng-add-zone.ok-zone:hover{border-color:rgba(0,255,136,0.35);}
.okng-add-zone.ng-zone:hover{border-color:rgba(255,46,99,0.35);}
.okng-add-icon{font-size:20px;opacity:0.5;}
.okng-add-txt{font-size:10px;color:var(--muted);}
.okng-note{margin-top:10px;padding:8px 12px;border-radius:6px;background:rgba(255,204,0,0.05);border:1px solid rgba(255,204,0,0.12);font-size:10px;color:rgba(255,204,0,0.8);line-height:1.5;}

/* ── NG PUZZLE QUIZ ── */
.ng-quiz-overlay{display:none;position:fixed;inset:0;background:rgba(0,0,0,0.92);z-index:710;align-items:center;justify-content:center;}
.ng-quiz-overlay.open{display:flex;}
.ng-quiz-box{background:#111827;border-radius:14px;width:94vw;max-width:780px;border:1px solid rgba(0,255,136,0.25);box-shadow:0 12px 60px rgba(0,0,0,0.8);display:flex;flex-direction:column;max-height:94vh;overflow:hidden;}
.ng-quiz-hdr{padding:12px 16px;background:rgba(0,255,136,0.05);border-bottom:1px solid rgba(0,255,136,0.12);display:flex;align-items:center;gap:10px;}
.ng-quiz-title{font-size:13px;font-weight:700;color:var(--ok);flex:1;}
.ng-quiz-close{background:none;border:none;color:var(--muted);cursor:pointer;font-size:20px;padding:0 4px;}
.ng-quiz-close:hover{color:#e6f1ff;}
.ng-quiz-body{padding:16px;overflow-y:auto;flex:1;}
.ng-quiz-instr{font-size:12px;color:#e6f1ff;margin-bottom:14px;padding:8px 12px;background:rgba(0,255,136,0.06);border:1px solid rgba(0,255,136,0.15);border-radius:6px;line-height:1.5;}
.ng-quiz-grid{display:grid;grid-template-columns:repeat(auto-fill,minmax(170px,1fr));gap:10px;}
.ng-quiz-img-card{border:2px solid rgba(255,255,255,0.1);border-radius:8px;overflow:hidden;cursor:pointer;transition:all 0.18s;position:relative;background:rgba(255,255,255,0.02);}
.ng-quiz-img-card:hover{border-color:var(--accent);transform:scale(1.03);}
.ng-quiz-img-card.selected{border-color:var(--danger);box-shadow:0 0 12px rgba(255,46,99,0.4);background:rgba(255,46,99,0.06);}
.ng-quiz-img-card.correct{border-color:var(--ok);box-shadow:0 0 12px rgba(0,255,136,0.3);}
.ng-quiz-img-card.wrong{border-color:var(--warn);box-shadow:0 0 12px rgba(255,204,0,0.3);}
.ng-quiz-img-card.missed{border-color:var(--danger);box-shadow:0 0 12px rgba(255,46,99,0.3);}
.ng-quiz-img-card img{width:100%;height:130px;object-fit:contain;display:block;background:#06101e;}
.ng-quiz-img-placeholder{width:100%;height:130px;display:flex;align-items:center;justify-content:center;font-size:28px;background:#06101e;}
.ng-quiz-img-label{padding:5px 8px;font-size:10px;font-weight:500;text-align:center;background:rgba(0,0,0,0.3);}
.ng-quiz-badge{position:absolute;top:5px;right:5px;width:22px;height:22px;border-radius:50%;display:flex;align-items:center;justify-content:center;font-size:11px;font-weight:700;display:none;}
.ng-quiz-card-check{display:none;position:absolute;top:5px;left:5px;width:18px;height:18px;border-radius:50%;background:var(--danger);color:#fff;font-size:11px;font-weight:700;align-items:center;justify-content:center;}
.ng-quiz-img-card.selected .ng-quiz-card-check{display:flex;}
.ng-quiz-actions{padding:12px 16px;border-top:1px solid rgba(0,255,136,0.1);display:flex;justify-content:space-between;align-items:center;gap:10px;flex-wrap:wrap;}
.ng-quiz-score-line{font-size:11px;color:var(--muted);}
.ng-quiz-score-line b{color:var(--ok);}
.ng-quiz-result{text-align:center;padding:20px 10px;}
.ng-quiz-result-score{font-size:42px;font-weight:700;color:var(--ok);line-height:1;}
.ng-quiz-result-label{font-size:13px;color:var(--muted);margin-top:4px;}
.ng-quiz-result-detail{font-size:11px;color:#e6f1ff;margin-top:12px;line-height:1.6;}
.ng-quiz-no-images{display:flex;flex-direction:column;align-items:center;justify-content:center;min-height:200px;color:var(--muted);font-size:12px;gap:12px;text-align:center;}

.spec-proc-add-row{display:flex;gap:5px;padding:7px 8px;border-top:1px solid rgba(255,204,0,0.12);background:rgba(255,204,0,0.04);}
.spec-proc-add-input{flex:1;min-width:0;padding:4px 7px;border:1px solid rgba(255,204,0,0.25);border-radius:4px;font-size:11px;background:rgba(255,204,0,0.05);color:#e6f1ff;outline:none;}
.spec-proc-add-input:focus{border-color:var(--warn);}

/* ── JUDGEMENT TRAINER PAGE ── */
.jt-layout{display:grid;grid-template-columns:260px 1fr;gap:12px;min-height:600px;}
.jt-item-panel{background:var(--card);border-radius:10px;border:1px solid rgba(192,132,252,0.2);overflow:hidden;display:flex;flex-direction:column;}
.jt-item-hdr{padding:8px 12px;background:rgba(192,132,252,0.08);border-bottom:1px solid rgba(192,132,252,0.12);font-size:11px;font-weight:600;color:#c084fc;display:flex;align-items:center;gap:6px;}
.jt-item-search{padding:6px 8px;border-bottom:1px solid rgba(192,132,252,0.08);}
.jt-item-search input{width:100%;padding:4px 8px;border:1px solid rgba(192,132,252,0.2);border-radius:4px;font-size:11px;background:rgba(192,132,252,0.04);color:#e6f1ff;outline:none;font-family:inherit;}
.jt-item-search input::placeholder{color:var(--muted);}
.jt-item-search input:focus{border-color:#c084fc;}
.jt-item-list{overflow-y:auto;flex:1;}
.jt-item-list::-webkit-scrollbar{width:3px;}
.jt-item-list::-webkit-scrollbar-thumb{background:rgba(192,132,252,0.2);}
.jt-proc-row{display:flex;flex-direction:column;gap:2px;padding:7px 12px;cursor:pointer;border-bottom:1px solid rgba(192,132,252,0.06);transition:all 0.15s;border-left:2px solid transparent;}
.jt-proc-row:hover{background:rgba(192,132,252,0.06);}
.jt-proc-row.active{background:rgba(192,132,252,0.1);border-left-color:#c084fc;}
.jt-proc-name{font-size:11px;font-weight:600;color:#e6f1ff;line-height:1.3;}
.jt-proc-meta{font-size:9px;color:var(--muted);}
.jt-proc-img-cnt{font-size:9px;color:#c084fc;font-weight:600;}
.jt-detail-panel{background:var(--card);border-radius:10px;border:1px solid rgba(192,132,252,0.2);overflow:hidden;display:flex;flex-direction:column;}
.jt-detail-hdr{padding:10px 14px;background:rgba(192,132,252,0.06);border-bottom:1px solid rgba(192,132,252,0.12);display:flex;align-items:center;justify-content:space-between;flex-wrap:wrap;gap:8px;}
.jt-detail-title{font-size:14px;font-weight:700;color:#c084fc;}
.jt-detail-sub{font-size:10px;color:var(--muted);margin-top:2px;}
.jt-detail-actions{display:flex;gap:6px;align-items:center;flex-wrap:wrap;}
.jt-detail-body{padding:14px;overflow-y:auto;flex:1;}
.jt-detail-empty{display:flex;flex-direction:column;align-items:center;justify-content:center;gap:12px;min-height:350px;color:var(--muted);font-size:12px;}

/* Judgement Trainer — Item rows (expandable) */
.jt-check-list{display:flex;flex-direction:column;gap:8px;}
.jt-check-item{background:rgba(192,132,252,0.04);border:1px solid rgba(192,132,252,0.12);border-radius:8px;overflow:hidden;}
.jt-check-hdr{padding:8px 12px;display:flex;align-items:center;gap:8px;cursor:pointer;transition:background 0.15s;}
.jt-check-hdr:hover{background:rgba(192,132,252,0.07);}
.jt-check-sl{font-size:10px;font-weight:700;color:var(--muted);min-width:22px;text-align:center;}
.jt-check-name{flex:1;font-size:11px;font-weight:600;color:#e6f1ff;line-height:1.4;}
.jt-check-badges{display:flex;gap:4px;align-items:center;flex-shrink:0;}
.jt-badge-ok{font-size:9px;font-weight:700;padding:2px 6px;border-radius:10px;background:rgba(0,255,136,0.12);color:var(--ok);border:1px solid rgba(0,255,136,0.2);}
.jt-badge-ng{font-size:9px;font-weight:700;padding:2px 6px;border-radius:10px;background:rgba(255,46,99,0.12);color:var(--danger);border:1px solid rgba(255,46,99,0.2);}
.jt-badge-empty{font-size:9px;font-weight:600;padding:2px 6px;border-radius:10px;background:rgba(255,255,255,0.04);color:var(--muted);}
.jt-btn-upload{font-size:9px;padding:2px 7px;border-radius:3px;background:rgba(192,132,252,0.1);border:1px solid rgba(192,132,252,0.2);color:#c084fc;cursor:pointer;transition:all 0.15s;}
.jt-btn-upload:hover{background:rgba(192,132,252,0.2);}
.jt-btn-quiz{font-size:9px;padding:2px 7px;border-radius:3px;background:rgba(0,255,136,0.1);border:1px solid rgba(0,255,136,0.2);color:var(--ok);cursor:pointer;transition:all 0.15s;}
.jt-btn-quiz:hover{background:rgba(0,255,136,0.2);}
.jt-check-body{display:none;padding:10px 12px;border-top:1px solid rgba(192,132,252,0.08);}
.jt-check-body.open{display:block;}
.jt-okng-cols{display:grid;grid-template-columns:1fr 1fr;gap:10px;}
.jt-col-hdr{font-size:10px;font-weight:700;letter-spacing:1px;padding:5px 8px;border-radius:5px;margin-bottom:8px;}
.jt-col-hdr.ok{background:rgba(0,255,136,0.08);color:var(--ok);border:1px solid rgba(0,255,136,0.15);}
.jt-col-hdr.ng{background:rgba(255,46,99,0.08);color:var(--danger);border:1px solid rgba(255,46,99,0.15);}
.jt-img-grid{display:grid;grid-template-columns:repeat(auto-fill,minmax(110px,1fr));gap:6px;}
.jt-img-card{background:#06101e;border:1px solid rgba(255,255,255,0.07);border-radius:6px;overflow:hidden;position:relative;}
.jt-img-card img{width:100%;height:90px;object-fit:contain;display:block;}
.jt-img-lbl{padding:3px 6px;font-size:8px;color:var(--muted);display:flex;justify-content:space-between;align-items:center;}
.jt-img-del{background:none;border:none;color:var(--danger);cursor:pointer;font-size:10px;padding:0 2px;}
.jt-add-zone{border:2px dashed rgba(255,255,255,0.1);border-radius:6px;padding:12px;display:flex;flex-direction:column;align-items:center;gap:4px;cursor:pointer;transition:all 0.2s;min-height:60px;justify-content:center;font-size:10px;color:var(--muted);}
.jt-add-zone:hover{border-color:rgba(192,132,252,0.4);background:rgba(192,132,252,0.04);}
.jt-add-zone.ok:hover{border-color:rgba(0,255,136,0.4);}
.jt-add-zone.ng:hover{border-color:rgba(255,46,99,0.4);}

/* Judgement Trainer Puzzle Quiz styles (inline) */
.jt-quiz-panel{background:rgba(0,255,136,0.03);border:1px solid rgba(0,255,136,0.15);border-radius:10px;padding:14px;margin-top:10px;}
.jt-quiz-panel-hdr{display:flex;align-items:center;justify-content:space-between;margin-bottom:10px;}
.jt-quiz-panel-title{font-size:12px;font-weight:700;color:var(--ok);}
.jt-puzzle-grid{display:grid;grid-template-columns:repeat(auto-fill,minmax(140px,1fr));gap:10px;margin:10px 0;}
.jt-puzzle-card{border:2px solid rgba(255,255,255,0.1);border-radius:8px;overflow:hidden;cursor:pointer;transition:all 0.18s;position:relative;background:rgba(255,255,255,0.02);}
.jt-puzzle-card:hover{border-color:var(--accent);transform:scale(1.03);}
.jt-puzzle-card.selected{border-color:var(--danger);box-shadow:0 0 12px rgba(255,46,99,0.4);background:rgba(255,46,99,0.06);}
.jt-puzzle-card.correct{border-color:var(--ok);box-shadow:0 0 12px rgba(0,255,136,0.3);}
.jt-puzzle-card.wrong{border-color:var(--warn);box-shadow:0 0 12px rgba(255,204,0,0.3);}
.jt-puzzle-card.missed{border-color:var(--danger);box-shadow:0 0 12px rgba(255,46,99,0.3);}
.jt-puzzle-card img{width:100%;height:120px;object-fit:contain;display:block;background:#06101e;}
.jt-puzzle-card-label{padding:5px 8px;font-size:10px;font-weight:500;text-align:center;background:rgba(0,0,0,0.3);color:var(--muted);}
.jt-puzzle-card-check{display:none;position:absolute;top:5px;left:5px;width:20px;height:20px;border-radius:50%;background:var(--danger);color:#fff;font-size:12px;font-weight:700;align-items:center;justify-content:center;}
.jt-puzzle-card.selected .jt-puzzle-card-check{display:flex;}
.jt-quiz-feedback{margin-top:10px;padding:10px 12px;border-radius:6px;font-size:11px;line-height:1.6;display:none;}
.jt-quiz-actions{display:flex;gap:6px;align-items:center;flex-wrap:wrap;margin-top:10px;}
.jt-quiz-score{font-size:11px;color:var(--muted);}
.jt-quiz-score b{color:var(--ok);}
.jt-quiz-result{text-align:center;padding:20px 10px;}
.jt-quiz-result-score{font-size:42px;font-weight:700;color:var(--ok);}
.jt-quiz-result-label{font-size:13px;color:var(--muted);margin-top:4px;}

/* ── SPEC PROCESS LAYOUT (3-column) ── */
.spec-proc-layout{display:grid;grid-template-columns:180px 200px 1fr;gap:10px;min-height:600px;}
.spec-proc-panel{background:var(--card);border-radius:10px;border:1px solid rgba(255,204,0,0.15);overflow:hidden;display:flex;flex-direction:column;}
.spec-proc-hdr{padding:8px 12px;background:rgba(255,204,0,0.07);border-bottom:1px solid rgba(255,204,0,0.12);font-size:11px;font-weight:600;color:var(--warn);display:flex;align-items:center;gap:6px;}
.spec-proc-list{overflow-y:auto;flex:1;}
.spec-proc-list::-webkit-scrollbar{width:3px;}
.spec-proc-list::-webkit-scrollbar-thumb{background:rgba(255,204,0,0.2);}
.spec-proc-row{padding:7px 12px;cursor:pointer;border-bottom:1px solid rgba(255,204,0,0.06);transition:all 0.15s;border-left:2px solid transparent;display:flex;align-items:center;justify-content:space-between;}
.spec-proc-row:hover{background:rgba(255,204,0,0.06);}
.spec-proc-row.active{background:rgba(255,204,0,0.1);border-left-color:var(--warn);}
.spec-proc-name{font-size:11px;font-weight:500;color:#e6f1ff;line-height:1.3;}
.spec-proc-row.active .spec-proc-name{color:var(--warn);}
.spec-proc-cnt{font-size:9px;color:var(--muted);background:rgba(255,204,0,0.1);padding:1px 5px;border-radius:10px;white-space:nowrap;}
/* quiz image block styles */
.quiz-img-block{background:rgba(0,0,0,0.4);border:2px solid rgba(0,212,255,0.2);border-radius:10px;overflow:hidden;display:flex;align-items:center;justify-content:center;min-height:140px;}
.quiz-img-block img{width:100%;height:140px;object-fit:contain;display:block;}
.quiz-img-opt .quiz-img-block{min-height:120px;transition:border-color 0.15s;}
.quiz-img-opt:hover .quiz-img-block{border-color:var(--accent);}
.quiz-img-opt.correct .quiz-img-block{border-color:var(--ok)!important;box-shadow:0 0 12px rgba(0,255,136,0.4);}
.quiz-img-opt.wrong .quiz-img-block{border-color:var(--danger)!important;box-shadow:0 0 12px rgba(255,46,99,0.4);}
.quiz-img-opt.reveal .quiz-img-block{border-color:var(--ok)!important;}

.spec-del-item-btn,.jt-mini-btn{background:rgba(255,46,99,0.1);border:1px solid rgba(255,46,99,0.22);color:var(--danger);border-radius:3px;padding:1px 5px;font-size:9px;cursor:pointer;margin-left:4px;}
.spec-del-item-btn:hover,.jt-mini-btn:hover{background:rgba(255,46,99,0.22);}
.jt-add-row{display:flex;gap:5px;padding:8px;border-top:1px solid rgba(192,132,252,0.12);}
.jt-add-input{flex:1;padding:5px 8px;border:1px solid rgba(192,132,252,0.2);border-radius:4px;background:rgba(192,132,252,0.04);color:#e6f1ff;font-size:11px;outline:none;}
</style>
<body>

<!-- HEADER -->
<div class="combined-header">
  <div class="brand">
    <div class="logo"><svg viewBox="0 0 24 24" fill="none" stroke="white" stroke-width="2.5"><circle cx="12" cy="12" r="10"/><path d="M12 2a10 10 0 0 1 0 20"/><path d="M2 12h20"/></svg></div>
    <div>
      <div class="brand-title" style="color:var(--accent);" id="portal-title" onclick="editField('portal-title','Brand Title')">Toyota Training Hub</div>
      <div style="font-size:9px;color:var(--muted);letter-spacing:1px;" id="portal-subtitle" onclick="editField('portal-subtitle','Portal Subtitle')">UNIFIED QUALITY & SAFETY PORTAL</div>
    </div>
  </div>
  <div class="brand-sub" style="margin-left:8px;" id="portal-model" onclick="editField('portal-model','Model Code')">25MC · Engine A CNG</div>
  <div class="header-right">
    <!-- LANGUAGE SWITCHER -->
    <div class="lang-switcher">
      <button class="lang-btn active" onclick="setLang('en')">EN</button>
      <button class="lang-btn" onclick="setLang('hi')">हि</button>
      <button class="lang-btn" onclick="setLang('kn')">ಕ</button>
      <button class="lang-btn" onclick="setLang('mr')">म</button>
      <button class="lang-btn" onclick="setLang('ja')">日</button>
    </div>
    <div class="sys-time">
      <div><div class="tv" id="tTime">00:00:00</div><div class="tl" id="tDate">—</div></div>
      <div class="tsep">|</div>
      <div style="display:flex;flex-direction:column;">
        <div class="tv" style="font-size:10px;">LIVE</div>
        <div class="tl">SYSTEM</div>
      </div>
    </div>
    <div class="usr-dot">OP</div>
  </div>
</div>

<!-- NAV -->
<div class="nav-controls" id="topNav">
  <button class="nav-btn active" data-sec="dashboard"><span class="pill-dot" style="background:var(--ok);color:var(--ok);">●</span><span data-i18n="nav_dashboard">Dashboard</span></button>
  <button class="nav-btn" data-sec="safety"><span class="pill-dot" style="background:var(--danger);color:var(--danger);">●</span><span data-i18n="nav_safety">Safety</span></button>
  <button class="nav-btn" data-sec="quality"><span class="pill-dot" style="background:var(--info);color:var(--info);">●</span><span data-i18n="nav_quality">Quality</span></button>
  <button class="nav-btn" data-sec="spec"><span class="pill-dot" style="background:var(--warn);color:var(--warn);">●</span><span data-i18n="nav_spec">Spec Training</span></button>
  <button class="nav-btn" data-sec="inspect"><span class="pill-dot" style="background:var(--accent);color:var(--accent);">●</span><span data-i18n="nav_inspect">InspectPro</span></button>
  <button class="nav-btn" data-sec="judgement"><span class="pill-dot" style="background:#c084fc;color:#c084fc;">●</span><span data-i18n="nav_judgement">Judgement Trainer</span></button>
</div>

<!-- MAIN LAYOUT -->
<div class="main-layout">
  <!-- SIDEBAR -->
  <div class="sidebar">
    <div class="sb-sec" data-i18n="sb_training">Training</div>
    <div class="sb-item active" onclick="showSec('dashboard',this)">📊 <span data-i18n="nav_dashboard">Dashboard</span></div>
    <div class="sb-item" onclick="showSec('safety',this)">
      🛡 <span data-i18n="sb_safety_videos">Safety Videos</span> <span class="sb-badge red" id="sb-sv">0</span>
    </div>
    <div class="sb-item" onclick="showSec('quality',this)">
      ✅ <span data-i18n="sb_quality_videos">Quality Videos</span> <span class="sb-badge" id="sb-qv">0</span>
    </div>
    <div class="sb-sec" data-i18n="sb_spec_ops">Spec &amp; Ops</div>
    <div class="sb-item" onclick="showSec('spec',this)">
      🔧 <span data-i18n="sb_spec_types">Spec Types</span> <span class="sb-badge" id="sb-sp">32</span>
    </div>
    <div class="sb-item" onclick="showSec('inspect',this)">
      🎯 <span data-i18n="sb_inspectpro">InspectPro Sim</span>
    </div>
    <div class="sb-item" onclick="showSec('judgement',this)">
      🏅 <span data-i18n="sb_judgement">Judgement Trainer</span>
    </div>
  </div>

  <!-- CONTENT -->
  <div class="content">

    <!-- DASHBOARD -->
    <div class="sec-page active" id="sec-dashboard">
      <div class="pg-hdr">
        <div>
          <div class="pg-tag" data-i18n="dash_tag">Overview</div>
          <div class="editable-title">
            <h1 id="dash-h1" data-i18n="dash_h1">Training Dashboard</h1>
            <button class="edit-btn" onclick="openEditModal('dash-h1','Dashboard Headline')">✎</button>
          </div>
        </div>
        <button class="btn btn-accent" onclick="openModal('video')">+ <span data-i18n="btn_add_content">Add Content</span></button>
      </div>
      <div class="stats-row">
        <div class="stat-card red"><div class="st-lbl" data-i18n="ds_safety_videos">Safety Videos</div><div class="st-val" id="ds-sv">0</div><div class="st-sub" data-i18n="ds_mandatory_2">0 mandatory</div></div>
        <div class="stat-card"><div class="st-lbl" data-i18n="ds_quality_videos">Quality Videos</div><div class="st-val" id="ds-qv">0</div><div class="st-sub" data-i18n="ds_mandatory_3">0 mandatory</div></div>
        <div class="stat-card warn"><div class="st-lbl" data-i18n="ds_spec_items">Spec Items</div><div class="st-val" id="ds-sp">32</div><div class="st-sub" data-i18n="ds_check_types">check types</div></div>
        <div class="stat-card ok"><div class="st-lbl" data-i18n="ds_inspectpro">InspectPro</div><div class="st-val">4</div><div class="st-sub" data-i18n="ds_modules">sim modules</div></div>
        <div class="stat-card" style="border-color:rgba(255,204,0,0.2);"><div class="st-lbl">Spec Processes</div><div class="st-val" style="color:var(--warn);">8</div><div class="st-sub">processes mapped</div></div>
      </div>
      <div class="dash-grid">
        <div class="dash-card">
          <div class="dash-card-title">
            📈 <span data-i18n="dash_progress">Training Progress</span>
            <button class="edit-btn" style="margin-left:auto;" onclick="openEditModal('dash-progress-title','Progress Card Title')">✎</button>
          </div>
          <div class="prog-item"><div class="prog-lbl" data-i18n="prog_safety">Safety Modules</div><div class="prog-trk"><div class="prog-bar" style="width:72%;"></div></div><div class="prog-pct">72%</div></div>
          <div class="prog-item"><div class="prog-lbl" data-i18n="prog_quality">Quality Modules</div><div class="prog-trk"><div class="prog-bar ok" style="width:60%;"></div></div><div class="prog-pct">60%</div></div>
          <div class="prog-item"><div class="prog-lbl" data-i18n="prog_spec">Spec Types</div><div class="prog-trk"><div class="prog-bar info" style="width:45%;"></div></div><div class="prog-pct">45%</div></div>
          <div class="prog-item"><div class="prog-lbl" data-i18n="prog_inspect">InspectPro Sim</div><div class="prog-trk"><div class="prog-bar" style="width:55%;background:var(--accent);"></div></div><div class="prog-pct">55%</div></div>
        </div>
        <div class="dash-card">
          <div class="dash-card-title">
            🔔 <span data-i18n="dash_activity">Recent Activity</span>
            <button class="edit-btn" style="margin-left:auto;" onclick="openEditModal('dash-activity-title','Activity Card Title')">✎</button>
          </div>
          <div class="act-item"><div class="adot b"></div><div><div class="act-text" data-i18n="act1">InspectPro Sim integrated — 4 visual modules available</div><div class="act-time" data-i18n="act_today">Today</div></div></div>
          <div class="act-item"><div class="adot r"></div><div><div class="act-text" data-i18n="act2">Image Quiz enabled — select correct colour/variant images</div><div class="act-time" data-i18n="act_today">Today</div></div></div>
          <div class="act-item"><div class="adot g"></div><div><div class="act-text" data-i18n="act3">Multilanguage support added — EN / हि / ಕ / म / 日</div><div class="act-time" data-i18n="act_today">Today</div></div></div>
          <div class="act-item"><div class="adot g"></div><div><div class="act-text" data-i18n="act4">Portal updated — SOS page removed per guidelines</div><div class="act-time" data-i18n="act_today">Today</div></div></div>
        </div>
      </div>
    </div>

    <!-- SAFETY -->
    <div class="sec-page" id="sec-safety">
      <div class="pg-hdr">
        <div>
          <div class="pg-tag" data-i18n="safety_tag">Safety Training</div>
          <div class="editable-title">
            <h1 id="safety-h1" data-i18n="safety_h1">Safety Videos</h1>
            <button class="edit-btn" onclick="openEditModal('safety-h1','Safety Page Headline')">✎</button>
          </div>
        </div>
        <div style="display:flex;gap:6px;">
          <button class="btn btn-danger" onclick="openModal('safety-video')">+ <span data-i18n="btn_add_video">Add Video</span></button>
          <button class="btn btn-ok" onclick="saveVideoData(false)">💾 <span data-i18n="save_videos">Save Videos</span></button>
        </div>
      </div>
      <div class="pl-wrap">
        <div class="player-main">
          <div class="player-screen"><video id="safety-vel"></video><div class="player-idle" id="safety-idle"><div class="idle-icon"><svg width="20" height="20" fill="var(--accent)" viewBox="0 0 24 24"><polygon points="5 3 19 12 5 21 5 3"/></svg></div><div style="font-size:13px;color:var(--accent);font-weight:600;" data-i18n="safety_playlist">Safety Training Playlist</div><div style="font-size:10px;color:var(--muted);" data-i18n="playlist_hint">Press Play All or click a video</div></div></div>
          <div class="player-controls">
            <div class="pl-title" id="safety-ptitle" data-i18n="no_video_selected">— No video selected —</div>
            <div class="pl-meta" id="safety-pmeta" data-i18n="playlist_hint">Select a video or press Play All to begin</div>
            <div class="pl-btns">
              <button class="play-all-btn" id="safety-pabtn" onclick="playAll('safety')">▶ <span data-i18n="play_all">Play All</span></button>
              <button class="ctrl-btn" id="safety-prev" disabled onclick="plPrev('safety')">◀</button>
              <button class="ctrl-btn" id="safety-next" disabled onclick="plNext('safety')">▶</button>
              <span style="font-size:10px;color:var(--muted);margin-left:4px;" id="safety-plcnt"></span>
            </div>
            <div class="prog-wrap"><span id="safety-tcur">0:00</span><div class="prog-track" onclick="seekVid('safety',event)"><div class="prog-fill" id="safety-prog"></div></div><span id="safety-ttot">0:00</span></div>
          </div>
        </div>
        <div class="pl-sidebar">
          <div class="pl-hdr">🛡 <span data-i18n="playlist_label">Playlist</span> <span id="safety-plcount" style="margin-left:auto;font-size:10px;font-weight:400;color:var(--muted);">0</span></div>
          <div class="pl-list" id="safety-pllist"></div>
        </div>
      </div>
      <div class="search-bar"><input class="srch" data-i18n-placeholder="search_safety" placeholder="Search safety videos..." oninput="filterGrid('safety',this.value)"/></div>
      <div class="sec-div"><span class="sec-div-lbl" data-i18n="all_safety_videos">All Safety Videos</span><div class="sec-div-line"></div><span class="sec-div-cnt" id="safety-gcnt"></span></div>
      <div class="video-grid" id="safety-grid"></div>
    </div>

    <!-- QUALITY -->
    <div class="sec-page" id="sec-quality">
      <div class="pg-hdr">
        <div>
          <div class="pg-tag" data-i18n="quality_tag">Quality Training</div>
          <div class="editable-title">
            <h1 id="quality-h1" data-i18n="quality_h1">Quality Videos</h1>
            <button class="edit-btn" onclick="openEditModal('quality-h1','Quality Page Headline')">✎</button>
          </div>
        </div>
        <div style="display:flex;gap:6px;">
          <button class="btn btn-info" onclick="openModal('quality-video')">+ <span data-i18n="btn_add_video">Add Video</span></button>
          <button class="btn btn-ok" onclick="saveVideoData(false)">💾 <span data-i18n="save_videos">Save Videos</span></button>
        </div>
      </div>
      <div class="pl-wrap">
        <div class="player-main">
          <div class="player-screen"><video id="quality-vel"></video><div class="player-idle" id="quality-idle"><div class="idle-icon" style="background:rgba(0,153,255,0.1);border-color:rgba(0,153,255,0.25);"><svg width="20" height="20" fill="var(--info)" viewBox="0 0 24 24"><polygon points="5 3 19 12 5 21 5 3"/></svg></div><div style="font-size:13px;color:var(--info);font-weight:600;" data-i18n="quality_playlist">Quality Training Playlist</div><div style="font-size:10px;color:var(--muted);" data-i18n="playlist_hint">Press Play All or click a video</div></div></div>
          <div class="player-controls">
            <div class="pl-title" id="quality-ptitle" data-i18n="no_video_selected">— No video selected —</div>
            <div class="pl-meta" id="quality-pmeta" data-i18n="playlist_hint">Select a video or press Play All to begin</div>
            <div class="pl-btns">
              <button class="play-all-btn" id="quality-pabtn" onclick="playAll('quality')">▶ <span data-i18n="play_all">Play All</span></button>
              <button class="ctrl-btn" id="quality-prev" disabled onclick="plPrev('quality')">◀</button>
              <button class="ctrl-btn" id="quality-next" disabled onclick="plNext('quality')">▶</button>
              <span style="font-size:10px;color:var(--muted);margin-left:4px;" id="quality-plcnt"></span>
            </div>
            <div class="prog-wrap"><span id="quality-tcur">0:00</span><div class="prog-track" onclick="seekVid('quality',event)"><div class="prog-fill" id="quality-prog"></div></div><span id="quality-ttot">0:00</span></div>
          </div>
        </div>
        <div class="pl-sidebar">
          <div class="pl-hdr" style="color:var(--info);">✅ <span data-i18n="playlist_label">Playlist</span> <span id="quality-plcount" style="margin-left:auto;font-size:10px;font-weight:400;color:var(--muted);">0</span></div>
          <div class="pl-list" id="quality-pllist"></div>
        </div>
      </div>
      <div class="search-bar"><input class="srch" data-i18n-placeholder="search_quality" placeholder="Search quality videos..." oninput="filterGrid('quality',this.value)"/></div>
      <div class="sec-div"><span class="sec-div-lbl" style="color:var(--info);" data-i18n="all_quality_videos">All Quality Videos</span><div class="sec-div-line"></div><span class="sec-div-cnt" id="quality-gcnt"></span></div>
      <div class="video-grid" id="quality-grid"></div>
    </div>

    <!-- SPEC TRAINING (Process-based) -->
    <div class="sec-page" id="sec-spec">
      <div class="pg-hdr">
        <div>
          <div class="pg-tag" data-i18n="spec_tag">Specification Training</div>
          <div class="editable-title">
            <h1 id="spec-h1" data-i18n="spec_h1">Spec Types Reference</h1>
            <button class="edit-btn" onclick="openEditModal('spec-h1','Spec Page Headline')">✎</button>
          </div>
        </div>
        <div style="display:flex;gap:6px;flex-wrap:wrap;">
          <button class="btn btn-warn" id="spec-quiz-all-btn" style="display:none;" onclick="openProcessQuiz('all','forward')">🧠 <span data-i18n="quiz_all">Quiz — This Process</span></button>
          <button class="btn btn-info" id="spec-quiz-rev-btn" style="display:none;" onclick="openProcessQuiz('all','reverse')">🔄 <span data-i18n="quiz_reverse">Reverse Quiz</span></button>
          <button class="btn btn-ok" onclick="saveSpecData(false)">💾 Save</button>
          <button class="btn btn-accent" onclick="openModal('additem')">+ <span data-i18n="btn_add_item">Add Item</span></button>
        </div>
      </div>
      <!-- 3-column layout: Process | Spec Items | Types -->
      <div class="spec-proc-layout">
        <!-- Process list -->
        <div class="spec-proc-panel">
          <div class="spec-proc-hdr">⚙ <span data-i18n="processes_label">Processes</span> <span id="spec-proc-count" style="margin-left:auto;font-size:10px;color:var(--muted);"></span></div>
          <div class="spec-proc-list" id="spec-proc-list"></div>
          <div class="spec-proc-add-row"><input class="spec-proc-add-input" id="new-process-name" placeholder="New process name..." onkeydown="if(event.key==='Enter')addSpecProcess()"/><button class="btn btn-warn" style="padding:4px 8px;" onclick="addSpecProcess()">+</button></div>
        </div>
        <!-- Spec items list (2nd column) -->
        <div class="spec-items-panel">
          <div class="spec-items-hdr"><span>📦 <span data-i18n="items_label">Items</span> <span id="spec-item-total" style="font-weight:400;color:var(--muted);"></span></span></div>
          <div class="spec-items-search"><input id="spec-search" data-i18n-placeholder="search_items" placeholder="Search items..." oninput="filterSpecItems(this.value)"/></div>
          <div class="spec-items-list" id="spec-items-list"></div>
          <div class="add-item-bar">
            <input class="add-item-input" id="new-item-name" data-i18n-placeholder="new_item_placeholder" placeholder="New item name..." onkeydown="if(event.key==='Enter')addCheckItem()"/>
            <button class="btn btn-accent" style="padding:4px 8px;" onclick="addCheckItem()">+</button>
          </div>
        </div>
        <!-- Types detail panel (3rd column) -->
        <div class="spec-detail-panel">
          <div class="spec-detail-hdr">
            <div>
              <div class="spec-detail-title" id="spec-detail-title" data-i18n="spec_select_prompt">← Select an item</div>
              <div class="spec-detail-sub" id="spec-detail-sub" data-i18n="spec_detail_sub">Click any item to view spec types</div>
            </div>
            <div class="spec-detail-actions">
              <button class="btn btn-warn" id="spec-item-quiz-btn" style="display:none;" onclick="openQuiz('current','forward')">🧠 <span data-i18n="quiz_this_item">Quiz This Item</span></button>
              <button class="btn btn-info" id="spec-item-quiz-rev-btn" style="display:none;" onclick="openQuiz('current','reverse')">🔄</button>
              <button class="btn btn-ghost" id="spec-add-type-btn" style="display:none;" onclick="showAddType()">+ <span data-i18n="type_label">Type</span></button>
            </div>
          </div>
          <div class="spec-types-wrap" id="spec-types-wrap">
            <div class="spec-empty"><svg width="32" height="32" fill="none" stroke="rgba(0,212,255,0.2)" stroke-width="1.5" viewBox="0 0 24 24"><rect x="2" y="3" width="20" height="14" rx="2"/><line x1="8" y1="21" x2="16" y2="21"/><line x1="12" y1="17" x2="12" y2="21"/></svg><span data-i18n="spec_empty">Select a spec item to view types</span></div>
          </div>
          <div class="add-type-row" id="spec-add-type-row" style="display:none;">
            <input class="add-type-input" id="new-type-name" placeholder="Type name (e.g. CHROME)..." onkeydown="if(event.key==='Enter')commitAddType()"/>
            <button class="btn btn-accent" style="padding:4px 8px;" onclick="commitAddType()">+</button>
            <button class="btn btn-ghost" style="padding:4px 8px;" onclick="hideAddType()">✕</button>
          </div>
        </div>
      </div>
    </div>



    <!-- INSPECTPRO SIM -->
    <div class="sec-page" id="sec-inspect">
      <div class="pg-hdr">
        <div>
          <div class="pg-tag" data-i18n="inspect_tag">Simulation Trainer</div>
          <div class="editable-title">
            <h1 id="inspect-h1" data-i18n="inspect_h1">InspectPro — Visual Measurement</h1>
          </div>
        </div>
        <button class="btn btn-accent" onclick="initAllCanvases();nd();nc();ni_sim();nl_sim();toast('InspectPro refreshed')">↻ Refresh Sim</button>
      </div>

      <div class="inspect-wrap">
        <div class="ipt-hdr">
          <div class="ipt-logo">Inspect<b>Pro</b></div>
          <div class="ipt-tag">VISUAL MEASUREMENT SIM</div>
          <div class="ipt-online"><span class="ipt-dot"></span> ONLINE</div>
        </div>
        <div class="ipt-body">
          <div class="ipt-sb">
            <div class="ipt-sb-lbl">Modules</div>
            <div class="ipt-ni on" onclick="iswitch('door',this);setTimeout(()=>{initCanvas('cDoor');paintDoor();},20)">
              <div class="ipt-nic">↔</div><div><div class="ipt-ntx">Door Gap</div><div class="ipt-nst">3–7 mm OK</div></div><span class="ipt-nb" id="nb-door">0/0</span>
            </div>
            <div class="ipt-ni" onclick="iswitch('clip',this);setTimeout(()=>{initCanvas('cClip');paintClip();},20)">
              <div class="ipt-nic">◉</div><div><div class="ipt-ntx">Clip Position</div><div class="ipt-nst">2–7 mm OK</div></div><span class="ipt-nb" id="nb-clip">0/0</span>
            </div>
            <div class="ipt-ni" onclick="iswitch('insert',this);setTimeout(()=>{initCanvas('cInsert');paintInsert();},20)">
              <div class="ipt-nic">⇥</div><div><div class="ipt-ntx">Hose Insertion</div><div class="ipt-nst">0 mm target</div></div><span class="ipt-nb" id="nb-insert">0/0</span>
            </div>
            <div class="ipt-ni" onclick="iswitch('level',this);setTimeout(()=>{initCanvas('cLevel');paintLevel();},20)">
              <div class="ipt-nic">▭</div><div><div class="ipt-ntx">Levelness</div><div class="ipt-nst">±2 mm OK</div></div><span class="ipt-nb" id="nb-level">0/0</span>
            </div>
            <div class="ipt-sdiv"></div>
            <div class="ipt-sp">
              <div class="ipt-spt">Overall Score</div>
              <div class="ipt-spr"><span>Attempts</span><span id="tot-att">0</span></div>
              <div class="ipt-spr"><span>Correct</span><span id="tot-cor">0</span></div>
              <div class="ipt-spr"><span>Accuracy</span><span id="tot-acc">—</span></div>
            </div>
          </div>
          <div class="ipt-main">
            <div class="ipt-pane on" id="pane-door">
              <div class="ipt-mh"><div><div class="ipt-mt">Door Gap <span>Trainer</span></div><div class="ipt-md">Estimate the gap between front and rear door panels in millimetres.</div></div><div class="ipt-stag">SPEC: 3–7 mm</div></div>
              <div class="ipt-cw"><canvas id="cDoor"></canvas><div class="ipt-cam">CAM-01 / DOOR GAP</div></div>
              <div class="ipt-cb">
                <div class="ipt-ir"><div class="ipt-fg"><label class="ipt-fl">Your estimate (mm)</label><input id="d-ans" class="ipt-fi" type="number" step="0.5" placeholder="mm"></div><button class="ipt-bc" onclick="chk('door')">Check</button><button class="ipt-bn" onclick="nd()">New Case</button><button class="ipt-hb" onclick="ith('d-hint')">Hint</button><div class="ipt-sc"><span class="ipt-sp2 g" id="d-sc">Correct: 0</span><span class="ipt-sp2 t" id="d-tot">Attempts: 0</span></div></div>
                <div class="ipt-hx" id="d-hint">Measure the black gap between the two door panel edges. OK condition is 3 mm to 7 mm.</div><div class="ipt-fb" id="d-fb"></div>
              </div>
            </div>

            <div class="ipt-pane" id="pane-clip">
              <div class="ipt-mh"><div><div class="ipt-mt">Clip Position <span>Trainer</span></div><div class="ipt-md">Estimate the distance from hose open end to clip start line.</div></div><div class="ipt-stag">SPEC: 2–7 mm</div></div>
              <div class="ipt-cw"><canvas id="cClip"></canvas><div class="ipt-cam">CAM-02 / CLIP</div></div>
              <div class="ipt-cb">
                <div class="ipt-ir"><div class="ipt-fg"><label class="ipt-fl">Your estimate (mm)</label><input id="c-ans" class="ipt-fi" type="number" step="0.5" placeholder="mm"></div><button class="ipt-bc" onclick="chk('clip')">Check</button><button class="ipt-bn" onclick="nc()">New Case</button><button class="ipt-hb" onclick="ith('c-hint')">Hint</button><div class="ipt-sc"><span class="ipt-sp2 g" id="c-sc">Correct: 0</span><span class="ipt-sp2 t" id="c-tot">Attempts: 0</span></div></div>
                <div class="ipt-hx" id="c-hint">Measure from the hose open end to the start line/edge of the clamp. OK condition is 2 mm to 7 mm.</div><div class="ipt-fb" id="c-fb"></div>
              </div>
            </div>

            <div class="ipt-pane" id="pane-insert">
              <div class="ipt-mh"><div><div class="ipt-mt">Hose Insertion <span>Trainer</span></div><div class="ipt-md">Estimate remaining gap to the stopper/collar after hose insertion.</div></div><div class="ipt-stag">TARGET: 0 mm</div></div>
              <div class="ipt-cw"><canvas id="cInsert"></canvas><div class="ipt-cam">CAM-03 / INSERTION</div></div>
              <div class="ipt-cb">
                <div class="ipt-ir"><div class="ipt-fg"><label class="ipt-fl">Your estimate (mm)</label><input id="i-ans" class="ipt-fi" type="number" step="0.5" placeholder="mm"></div><button class="ipt-bc" onclick="chk('insert')">Check</button><button class="ipt-bn" onclick="ni_sim()">New Case</button><button class="ipt-hb" onclick="ith('i-hint')">Hint</button><div class="ipt-sc"><span class="ipt-sp2 g" id="i-sc">Correct: 0</span><span class="ipt-sp2 t" id="i-tot">Attempts: 0</span></div></div>
                <div class="ipt-hx" id="i-hint">Fully seated hose should touch the stopper/collar. Target remaining gap is 0 mm.</div><div class="ipt-fb" id="i-fb"></div>
              </div>
            </div>

            <div class="ipt-pane" id="pane-level">
              <div class="ipt-mh"><div><div class="ipt-mt">Levelness <span>Trainer</span></div><div class="ipt-md">Estimate vertical mismatch between body and door panel surfaces.</div></div><div class="ipt-stag">SPEC: 0 ± 2 mm</div></div>
              <div class="ipt-cw"><canvas id="cLevel"></canvas><div class="ipt-cam">CAM-04 / LEVELNESS</div></div>
              <div class="ipt-cb">
                <div class="ipt-ir"><div class="ipt-fg"><label class="ipt-fl">Your estimate (mm)</label><input id="l-ans" class="ipt-fi" type="number" step="0.5" placeholder="mm"></div><button class="ipt-bc" onclick="chk('level')">Check</button><button class="ipt-bn" onclick="nl_sim()">New Case</button><button class="ipt-hb" onclick="ith('l-hint')">Hint</button><div class="ipt-sc"><span class="ipt-sp2 g" id="l-sc">Correct: 0</span><span class="ipt-sp2 t" id="l-tot">Attempts: 0</span></div></div>
                <div class="ipt-hx" id="l-hint">Compare door surface height to body reference line. OK condition is within ±2 mm.</div><div class="ipt-fb" id="l-fb"></div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>

    <!-- JUDGEMENT TRAINER -->
    <div class="sec-page" id="sec-judgement">
      <div class="pg-hdr">
        <div>
          <div class="pg-tag" data-i18n="jt_tag">OK / NG Reference Training</div>
          <h1 data-i18n="jt_h1">Judgement Trainer</h1>
        </div>
        <div style="display:flex;gap:6px;align-items:center;flex-wrap:wrap;">
          <button class="btn btn-ghost" style="border-color:rgba(192,132,252,0.3);color:#c084fc;" onclick="saveJTData()">💾 <span data-i18n="save_data">Save Data</span></button>
          <button class="btn btn-ghost" style="border-color:rgba(192,132,252,0.3);color:#c084fc;" onclick="startJTProcessQuiz()" id="jt-process-quiz-btn">🧩 <span data-i18n="jt_quiz_all">Quiz All Images</span></button>
        </div>
      </div>
      <div class="jt-layout">
        <!-- Judgement item list left -->
        <div class="jt-item-panel">
          <div class="jt-item-hdr">🏅 <span data-i18n="jt_items">Judgement Items</span> <span id="jt-proc-count" style="margin-left:auto;font-size:10px;color:var(--muted);">10</span></div>
          <div class="jt-item-search"><input id="jt-proc-search" data-i18n-placeholder="jt_search_ph" placeholder="Search judgement item..." oninput="filterJTProcs(this.value)"/></div>
          <div class="jt-item-list" id="jt-item-list"></div>
          <div class="jt-add-row">
            <input class="jt-add-input" id="new-jt-item-name" data-i18n-placeholder="jt_new_item_ph" placeholder="New judgement item..." onkeydown="if(event.key==='Enter')addJTItem()"/>
            <button class="btn btn-ghost" style="padding:4px 8px;border-color:rgba(192,132,252,0.3);color:#c084fc;" onclick="addJTItem()">+</button>
          </div>
        </div>
        <!-- Detail panel right -->
        <div class="jt-detail-panel">
          <div class="jt-detail-hdr">
            <div>
              <div class="jt-detail-title" id="jt-detail-title" data-i18n="jt_select_prompt">← Select a judgement item</div>
              <div class="jt-detail-sub" id="jt-detail-sub">Click a judgement item to add OK / NG reference images</div>
            </div>
            <div class="jt-detail-actions" id="jt-detail-actions" style="display:none;">
              <button class="btn btn-ghost" style="font-size:10px;border-color:rgba(192,132,252,0.3);color:#c084fc;" onclick="openJTUpload()">📷 Upload Images</button>
              <button class="btn btn-ok" style="font-size:10px;" onclick="startJTQuiz()" id="jt-start-quiz-btn">🧩 Start Mixed OK/NG Quiz</button>
            </div>
          </div>
          <div class="jt-detail-body" id="jt-detail-body">
            <div class="jt-detail-empty">
              <svg width="44" height="44" fill="none" stroke="rgba(192,132,252,0.2)" stroke-width="1.5" viewBox="0 0 24 24"><circle cx="12" cy="12" r="10"/><path d="M9 12l2 2 4-4"/></svg>
              <span>← Select a judgement item to begin</span>
            </div>
          </div>
        </div>
      </div>
    </div>

  </div><!-- /content -->
</div><!-- /main-layout -->

<!-- ADD MODAL -->
<div class="modal-overlay" id="add-modal">
  <div class="modal-box">
    <div class="modal-title" id="am-title">Add Content</div>
    <div class="modal-sub" id="am-sub">Fill in the details below</div>
    <div id="am-form"></div>
    <div class="modal-footer">
      <button class="btn btn-ghost" onclick="closeModal()">Cancel</button>
      <button class="btn btn-accent" onclick="handleAdd()">✓ Save</button>
    </div>
  </div>
</div>

<!-- EDIT HEADLINE MODAL -->
<div class="modal-overlay" id="edit-modal">
  <div class="modal-box" style="max-width:420px;">
    <div class="modal-title" id="edit-modal-title">Edit Content</div>
    <div class="modal-sub">Update the text below and click Save</div>
    <div class="form-row"><label class="flbl" id="edit-field-label">Text</label><input class="finput" id="edit-field-input" placeholder="Enter text..."/></div>
    <div class="modal-footer">
      <button class="btn btn-ghost" onclick="closeEditModal()">Cancel</button>
      <button class="btn btn-accent" onclick="saveEdit()">✓ Save</button>
    </div>
  </div>
</div>

<!-- QUIZ MODAL -->
<div class="quiz-overlay" id="quiz-modal">
  <div class="quiz-box">
    <div class="quiz-hdr">
      <div class="quiz-title" id="quiz-title">🧠 Spec Type Quiz</div>
      <button class="quiz-close" onclick="closeQuiz()">×</button>
    </div>
    <div class="quiz-body" id="quiz-body"></div>
    <div class="quiz-actions">
      <div class="quiz-score" id="quiz-score-display"></div>
      <button class="btn btn-accent" id="quiz-next-btn" onclick="quizNext()" style="display:none;">${t('jt_next')}</button>
      <button class="btn btn-ghost" id="quiz-restart-btn" onclick="quizRestart()" style="display:none;">↺ Restart</button>
    </div>
  </div>
</div>

<!-- LIGHTBOX -->
<div class="lb" id="lb">
  <button class="lb-cls" onclick="closeLb()">×</button>
  <img id="lb-img" src="" alt=""/>
  <div class="lb-cap" id="lb-cap"></div>
</div>

<!-- TOAST -->
<div class="toast" id="toast"><div class="tdot"></div><span id="toast-msg">Done</span></div>

<!-- NG PUZZLE QUIZ MODAL -->
<div class="ng-quiz-overlay" id="ng-quiz-modal">
  <div class="ng-quiz-box">
    <div class="ng-quiz-hdr">
      <div class="ng-quiz-title">🧩 <span id="ng-quiz-title-text">NG Puzzle Quiz</span></div>
      <button class="ng-quiz-close" onclick="closeNGQuiz()">×</button>
    </div>
    <div class="ng-quiz-body" id="ng-quiz-body"></div>
    <div class="ng-quiz-actions">
      <div class="ng-quiz-score-line" id="ng-quiz-score-line"></div>
      <div style="display:flex;gap:6px;">
        <button class="btn btn-ghost" id="ng-quiz-submit-btn" onclick="submitNGQuiz()" style="display:none;"></button>
        <button class="btn btn-ok" id="ng-quiz-next-btn" onclick="nextNGQuiz()" style="display:none;"></button>
        <button class="btn btn-ghost" id="ng-quiz-restart-btn" onclick="restartNGQuiz()" style="display:none;"></button>
      </div>
    </div>
  </div>
</div>

<script>
// ═══════════════════════════════════════════
// TRANSLATIONS
// ═══════════════════════════════════════════
const LANGS = {
  en:{
    nav_sos:'SOS Checklist', sb_sos_ops:'SOS Sheets', sb_sos:'SOS Checklist',
    sos_tag:'Standard Operation Sheet', sos_h1:'SOS Checklist',
    sos_processes:'Processes', sos_select_prompt:'← Select a process to view checklist',
    btn_add_sos_item:'Add Check Item', ds_sos:'SOS Sheets', ds_sos_sub:'processes loaded',
    sos_search_ph:'Search check items...',
    sos_th_sl:'Sl No', sos_th_step:'Step', sos_th_item:'Inspection Item',
    sos_th_check:'Check Item', sos_th_standard:'Standard',
    sos_th_method:'Method', sos_th_actions:'Actions',
    sos_th_images:'Images',
    sos_method_hear:'Hear', sos_method_push_hear:'Push + Hear',
    sos_method_touch_feel:'Touch + Feel', sos_method_visual_scan:'Visual + Scan',
    sos_method_visual_feel:'Visual + Feel', sos_method_visual_shake:'Visual + Shake',
    sos_method_visual_rotate:'Visual + Rotate',
    okng_ok_label:'OK — Acceptable Condition', okng_ng_label:'NG — Not Acceptable',
    okng_add_ok:'+ Add OK Image', okng_add_ng:'+ Add NG Image',
    okng_note:'💡 Upload reference images for each check item. OK images show acceptable conditions, NG images show defects. Members can then take the NG Puzzle Quiz.',
    okng_quiz_btn:'NG Quiz',
    ng_quiz_title:'NG Puzzle Quiz',
    ng_quiz_instr:'Select ALL images that show NG (defect) conditions. You can select multiple images.',
    ng_quiz_submit:'Submit Answer',
    ng_quiz_next:'Next Question →',
    ng_quiz_restart:'↺ Restart Quiz',
    ng_quiz_no_images:'No OK/NG images uploaded yet. Use the 👁 View Images button in the SOS checklist to upload reference images first.',
    sos_add_row:'+ Add Row', sos_clear_added:'🗑 Clear Added',
    sos_proc_search_ph:'Search process...',
    sos_new_item_ph:'New inspection item...',
    sos_new_check_ph:'Check item...',
    sos_new_standard_ph:'Standard...',
    sos_all_methods:'All Methods',
    sos_method_visual:'Visual', sos_method_pull:'Visual + Pull',
    sos_method_push:'Visual + Push', sos_method_touch:'Visual + Touch',
    sos_method_function:'Function', sos_method_operation:'Operation',
    sos_items_label:'items',
    sos_takt_label:'Takt', sos_model_label:'Model',
    quiz_reverse:'Reverse Quiz',
    quiz_reverse_instruction:'Identify the type shown in the image:',
    nav_dashboard:'Dashboard', nav_safety:'Safety', nav_quality:'Quality',
    nav_spec:'Spec Training', nav_inspect:'InspectPro',
    sb_training:'Training', sb_safety_videos:'Safety Videos', sb_quality_videos:'Quality Videos',
    sb_spec_ops:'Spec & Ops', sb_spec_types:'Spec Types', sb_inspectpro:'InspectPro Sim',
    dash_tag:'Overview', dash_h1:'Training Dashboard', dash_progress:'Training Progress',
    dash_activity:'Recent Activity',
    ds_safety_videos:'Safety Videos', ds_quality_videos:'Quality Videos',
    ds_spec_items:'Spec Items', ds_inspectpro:'InspectPro',
    ds_mandatory_2:'2 mandatory', ds_mandatory_3:'3 mandatory',
    ds_check_types:'check types', ds_modules:'sim modules',
    act1:'InspectPro Sim integrated — 4 visual modules',
    act2:'Image Quiz enabled — select correct colour/variant images',
    act3:'Multilanguage support added — EN / हि / ಕ / म / 日',
    act4:'Portal updated — SOS page removed per guidelines',
    act_today:'Today',
    prog_safety:'Safety Modules', prog_quality:'Quality Modules',
    prog_spec:'Spec Types', prog_inspect:'InspectPro Sim',
    safety_tag:'Safety Training', safety_h1:'Safety Videos',
    safety_playlist:'Safety Training Playlist',
    quality_tag:'Quality Training', quality_h1:'Quality Videos',
    quality_playlist:'Quality Training Playlist',
    playlist_label:'Playlist', playlist_hint:'Press Play All or click a video',
    no_video_selected:'— No video selected —',
    play_all:'Play All',
    all_safety_videos:'All Safety Videos', all_quality_videos:'All Quality Videos',
    search_safety:'Search safety videos...', search_quality:'Search quality videos...',
    spec_tag:'Specification Training', spec_h1:'Spec Types Reference',
    quiz_all:'Quiz — All Items', quiz_this_item:'Quiz This Item',
    btn_add_content:'Add Content', btn_add_video:'Add Video',
    btn_add_item:'Add Item', btn_add:'Add',
    items_label:'Items', search_items:'Search items...',
    new_item_placeholder:'New item name...',
    spec_select_prompt:'← Select an item',
    spec_detail_sub:'Click any item from the list to view its spec types',
    spec_empty:'Select a spec item to view types',
    type_label:'Type',
    inspect_tag:'Simulation Trainer', inspect_h1:'InspectPro — Visual Measurement',
    quiz_instruction:'Select the image that shows the correct type:',
    nav_judgement:'Judgement Trainer', sb_judgement:'Judgement Trainer',
    jt_tag:'OK / NG Reference Training', jt_h1:'Judgement Trainer',
    jt_select_prompt:'← Select a process', jt_quiz_all:'Quiz All Images'
  },
  hi:{
    nav_sos:'SOS चेकलिस्ट', sb_sos_ops:'SOS शीट', sb_sos:'SOS चेकलिस्ट',
    sos_tag:'मानक संचालन शीट', sos_h1:'SOS चेकलिस्ट',
    sos_processes:'प्रक्रियाएं', sos_select_prompt:'← चेकलिस्ट देखने के लिए प्रक्रिया चुनें',
    btn_add_sos_item:'आइटम जोड़ें', ds_sos:'SOS शीट', ds_sos_sub:'प्रक्रियाएं लोड हैं',
    sos_search_ph:'जांच आइटम खोजें...',
    sos_th_sl:'क्र.सं', sos_th_step:'चरण', sos_th_item:'निरीक्षण आइटम',
    sos_th_check:'जांच आइटम', sos_th_standard:'मानक',
    sos_th_method:'विधि', sos_th_actions:'क्रियाएं',
    sos_th_images:'चित्र',
    sos_method_hear:'सुनें', sos_method_push_hear:'दबाएं + सुनें',
    sos_method_touch_feel:'स्पर्श + महसूस', sos_method_visual_scan:'दृश्य + स्कैन',
    sos_method_visual_feel:'दृश्य + महसूस', sos_method_visual_shake:'दृश्य + हिलाएं',
    sos_method_visual_rotate:'दृश्य + घुमाएं',
    okng_ok_label:'OK — स्वीकार्य स्थिति', okng_ng_label:'NG — अस्वीकार्य',
    okng_add_ok:'+ OK चित्र जोड़ें', okng_add_ng:'+ NG चित्र जोड़ें',
    okng_note:'💡 प्रत्येक जांच आइटम के लिए संदर्भ चित्र अपलोड करें। OK चित्र स्वीकार्य स्थिति दिखाते हैं, NG चित्र दोष दिखाते हैं।',
    okng_quiz_btn:'NG क्विज़',
    ng_quiz_title:'NG पहेली क्विज़',
    ng_quiz_instr:'सभी NG (दोष) स्थिति वाले चित्र चुनें। आप एकाधिक चित्र चुन सकते हैं।',
    ng_quiz_submit:'उत्तर जमा करें',
    ng_quiz_next:'अगला प्रश्न →',
    ng_quiz_restart:'↺ क्विज़ पुनः शुरू करें',
    ng_quiz_no_images:'अभी तक कोई OK/NG चित्र अपलोड नहीं हुए। पहले SOS चेकलिस्ट में 👁 बटन से चित्र अपलोड करें।',
    sos_add_row:'+ पंक्ति जोड़ें', sos_clear_added:'🗑 हटाएं',
    sos_proc_search_ph:'प्रक्रिया खोजें...',
    sos_new_item_ph:'नया निरीक्षण आइटम...',
    sos_new_check_ph:'जांच आइटम...',
    sos_new_standard_ph:'मानक...',
    sos_all_methods:'सभी विधियाँ',
    sos_method_visual:'दृश्य', sos_method_pull:'दृश्य + खींचें',
    sos_method_push:'दृश्य + धकेलें', sos_method_touch:'दृश्य + स्पर्श',
    sos_method_function:'कार्य', sos_method_operation:'संचालन',
    sos_items_label:'आइटम',
    sos_takt_label:'टैक्ट', sos_model_label:'मॉडल',
    quiz_reverse:'उल्टी क्विज़',
    quiz_reverse_instruction:'चित्र में दिखाया गया प्रकार पहचानें:',
    nav_dashboard:'डैशबोर्ड', nav_safety:'सुरक्षा', nav_quality:'गुणवत्ता',
    nav_spec:'स्पेक ट्रेनिंग', nav_inspect:'इंस्पेक्टप्रो',
    sb_training:'प्रशिक्षण', sb_safety_videos:'सुरक्षा वीडियो', sb_quality_videos:'गुणवत्ता वीडियो',
    sb_spec_ops:'स्पेक और ऑप्स', sb_spec_types:'स्पेक प्रकार', sb_inspectpro:'इंस्पेक्टप्रो सिम',
    dash_tag:'अवलोकन', dash_h1:'प्रशिक्षण डैशबोर्ड', dash_progress:'प्रशिक्षण प्रगति',
    dash_activity:'हाल की गतिविधि',
    ds_safety_videos:'सुरक्षा वीडियो', ds_quality_videos:'गुणवत्ता वीडियो',
    ds_spec_items:'स्पेक आइटम', ds_inspectpro:'इंस्पेक्टप्रो',
    ds_mandatory_2:'2 अनिवार्य', ds_mandatory_3:'3 अनिवार्य',
    ds_check_types:'प्रकार जांचें', ds_modules:'सिम मॉड्यूल',
    act1:'इंस्पेक्टप्रो सिम — 4 विज़ुअल मॉड्यूल उपलब्ध',
    act2:'इमेज क्विज़ सक्षम — सही रंग/प्रकार चुनें',
    act3:'बहुभाषी समर्थन जोड़ा गया',
    act4:'पोर्टल अपडेट — SOS पेज हटाया गया',
    act_today:'आज',
    prog_safety:'सुरक्षा मॉड्यूल', prog_quality:'गुणवत्ता मॉड्यूल',
    prog_spec:'स्पेक प्रकार', prog_inspect:'इंस्पेक्टप्रो सिम',
    safety_tag:'सुरक्षा प्रशिक्षण', safety_h1:'सुरक्षा वीडियो',
    safety_playlist:'सुरक्षा प्रशिक्षण प्लेलिस्ट',
    quality_tag:'गुणवत्ता प्रशिक्षण', quality_h1:'गुणवत्ता वीडियो',
    quality_playlist:'गुणवत्ता प्रशिक्षण प्लेलिस्ट',
    playlist_label:'प्लेलिस्ट', playlist_hint:'Play All दबाएं या वीडियो चुनें',
    no_video_selected:'— कोई वीडियो नहीं चुना —',
    play_all:'सभी चलाएं',
    all_safety_videos:'सभी सुरक्षा वीडियो', all_quality_videos:'सभी गुणवत्ता वीडियो',
    search_safety:'सुरक्षा वीडियो खोजें...', search_quality:'गुणवत्ता वीडियो खोजें...',
    spec_tag:'विशिष्टता प्रशिक्षण', spec_h1:'स्पेक प्रकार संदर्भ',
    quiz_all:'क्विज़ — सभी आइटम', quiz_this_item:'इस आइटम की क्विज़',
    btn_add_content:'सामग्री जोड़ें', btn_add_video:'वीडियो जोड़ें',
    btn_add_item:'आइटम जोड़ें', btn_add:'जोड़ें',
    items_label:'आइटम', search_items:'आइटम खोजें...',
    new_item_placeholder:'नया आइटम नाम...',
    spec_select_prompt:'← एक आइटम चुनें',
    spec_detail_sub:'स्पेक प्रकार देखने के लिए कोई आइटम चुनें',
    spec_empty:'स्पेक आइटम चुनें',
    type_label:'प्रकार',
    inspect_tag:'सिमुलेशन ट्रेनर', inspect_h1:'इंस्पेक्टप्रो — विज़ुअल माप',
    quiz_instruction:'सही प्रकार की छवि चुनें:'
  },
  kn:{
    nav_sos:'SOS ಪರಿಶೀಲನೆ', sb_sos_ops:'SOS ಶೀಟ್', sb_sos:'SOS ಪರಿಶೀಲನೆ',
    sos_tag:'ಪ್ರಮಾಣಿತ ಕಾರ್ಯಾಚರಣೆ ಶೀಟ್', sos_h1:'SOS ಪರಿಶೀಲನಾ ಪಟ್ಟಿ',
    sos_processes:'ಪ್ರಕ್ರಿಯೆಗಳು', sos_select_prompt:'← ಪರಿಶೀಲನಾ ಪಟ್ಟಿ ನೋಡಲು ಪ್ರಕ್ರಿಯೆ ಆಯ್ಕೆ ಮಾಡಿ',
    btn_add_sos_item:'ಐಟಂ ಸೇರಿಸಿ', ds_sos:'SOS ಶೀಟ್', ds_sos_sub:'ಪ್ರಕ್ರಿಯೆಗಳು ಲೋಡ್',
    sos_search_ph:'ತಪಾಸಣಾ ಐಟಂ ಹುಡುಕಿ...',
    sos_th_sl:'ಕ್ರ.ಸಂ', sos_th_step:'ಹಂತ', sos_th_item:'ತಪಾಸಣಾ ಐಟಂ',
    sos_th_check:'ಪರಿಶೀಲನಾ ಐಟಂ', sos_th_standard:'ಮಾನದಂಡ',
    sos_th_method:'ವಿಧಾನ', sos_th_actions:'ಕ್ರಿಯೆಗಳು',
    sos_th_images:'ಚಿತ್ರಗಳು',
    sos_method_hear:'ಕೇಳಿ', sos_method_push_hear:'ತಳ್ಳಿ + ಕೇಳಿ',
    sos_method_touch_feel:'ಸ್ಪರ್ಶ + ಅನುಭವ', sos_method_visual_scan:'ದೃಶ್ಯ + ಸ್ಕ್ಯಾನ್',
    sos_method_visual_feel:'ದೃಶ್ಯ + ಅನುಭವ', sos_method_visual_shake:'ದೃಶ್ಯ + ಅಲ್ಲಾಡಿಸಿ',
    sos_method_visual_rotate:'ದೃಶ್ಯ + ತಿರುಗಿಸಿ',
    okng_ok_label:'OK — ಸ್ವೀಕಾರಾರ್ಹ ಸ್ಥಿತಿ', okng_ng_label:'NG — ಅಸ್ವೀಕಾರ್ಯ',
    okng_add_ok:'+ OK ಚಿತ್ರ ಸೇರಿಸಿ', okng_add_ng:'+ NG ಚಿತ್ರ ಸೇರಿಸಿ',
    okng_note:'💡 ಪ್ರತಿ ತಪಾಸಣಾ ಐಟಂಗೆ ಉಲ್ಲೇಖ ಚಿತ್ರಗಳನ್ನು ಅಪ್‌ಲೋಡ್ ಮಾಡಿ। OK ಚಿತ್ರಗಳು ಸ್ವೀಕಾರಾರ್ಹ ಸ್ಥಿತಿ ತೋರಿಸುತ್ತವೆ, NG ಚಿತ್ರಗಳು ದೋಷ ತೋರಿಸುತ್ತವೆ।',
    okng_quiz_btn:'NG ಕ್ವಿಜ್',
    ng_quiz_title:'NG ಒಗಟು ಕ್ವಿಜ್',
    ng_quiz_instr:'NG (ದೋಷ) ಸ್ಥಿತಿ ತೋರಿಸುವ ಎಲ್ಲ ಚಿತ್ರಗಳನ್ನು ಆಯ್ಕೆ ಮಾಡಿ. ಒಂದಕ್ಕಿಂತ ಹೆಚ್ಚು ಆಯ್ಕೆ ಮಾಡಬಹುದು।',
    ng_quiz_submit:'ಉತ್ತರ ಸಲ್ಲಿಸಿ',
    ng_quiz_next:'ಮುಂದಿನ ಪ್ರಶ್ನೆ →',
    ng_quiz_restart:'↺ ಕ್ವಿಜ್ ಮರು ಪ್ರಾರಂಭ',
    ng_quiz_no_images:'ಇನ್ನೂ OK/NG ಚಿತ್ರಗಳು ಅಪ್‌ಲೋಡ್ ಆಗಿಲ್ಲ। ಮೊದಲು SOS ಚೆಕ್‌ಲಿಸ್ಟ್‌ನಲ್ಲಿ 👁 ಬಟನ್ ಬಳಸಿ ಚಿತ್ರ ಅಪ್‌ಲೋಡ್ ಮಾಡಿ।',
    sos_add_row:'+ ಸಾಲು ಸೇರಿಸಿ', sos_clear_added:'🗑 ತೆಗೆದುಹಾಕಿ',
    sos_proc_search_ph:'ಪ್ರಕ್ರಿಯೆ ಹುಡುಕಿ...',
    sos_new_item_ph:'ಹೊಸ ತಪಾಸಣಾ ಐಟಂ...',
    sos_new_check_ph:'ಪರಿಶೀಲನಾ ಐಟಂ...',
    sos_new_standard_ph:'ಮಾನದಂಡ...',
    sos_all_methods:'ಎಲ್ಲ ವಿಧಾನಗಳು',
    sos_method_visual:'ದೃಶ್ಯ', sos_method_pull:'ದೃಶ್ಯ + ಎಳೆಯಿರಿ',
    sos_method_push:'ದೃಶ್ಯ + ತಳ್ಳಿರಿ', sos_method_touch:'ದೃಶ್ಯ + ಸ್ಪರ್ಶ',
    sos_method_function:'ಕ್ರಿಯೆ', sos_method_operation:'ಕಾರ್ಯಾಚರಣೆ',
    sos_items_label:'ಐಟಂಗಳು',
    sos_takt_label:'ಟ್ಯಾಕ್ಟ್', sos_model_label:'ಮಾದರಿ',
    quiz_reverse:'ವಿರುದ್ಧ ಕ್ವಿಜ್',
    quiz_reverse_instruction:'ಚಿತ್ರದಲ್ಲಿ ತೋರಿಸಿರುವ ವಿಧವನ್ನು ಗುರುತಿಸಿ:',
    nav_dashboard:'ಡ್ಯಾಶ್‌ಬೋರ್ಡ್', nav_safety:'ಸುರಕ್ಷತೆ', nav_quality:'ಗುಣಮಟ್ಟ',
    nav_spec:'ಸ್ಪೆಕ್ ತರಬೇತಿ', nav_inspect:'ಇನ್ಸ್ಪೆಕ್ಟ್‌ಪ್ರೊ',
    sb_training:'ತರಬೇತಿ', sb_safety_videos:'ಸುರಕ್ಷತಾ ವಿಡಿಯೊಗಳು', sb_quality_videos:'ಗುಣಮಟ್ಟ ವಿಡಿಯೊಗಳು',
    sb_spec_ops:'ಸ್ಪೆಕ್ ಮತ್ತು ಕಾರ್ಯಾಚರಣೆ', sb_spec_types:'ಸ್ಪೆಕ್ ವಿಧಗಳು', sb_inspectpro:'ಇನ್ಸ್ಪೆಕ್ಟ್‌ಪ್ರೊ ಸಿಮ್',
    dash_tag:'ಅವಲೋಕನ', dash_h1:'ತರಬೇತಿ ಡ್ಯಾಶ್‌ಬೋರ್ಡ್', dash_progress:'ತರಬೇತಿ ಪ್ರಗತಿ',
    dash_activity:'ಇತ್ತೀಚಿನ ಚಟುವಟಿಕೆ',
    ds_safety_videos:'ಸುರಕ್ಷತಾ ವಿಡಿಯೊಗಳು', ds_quality_videos:'ಗುಣಮಟ್ಟ ವಿಡಿಯೊಗಳು',
    ds_spec_items:'ಸ್ಪೆಕ್ ಐಟಂಗಳು', ds_inspectpro:'ಇನ್ಸ್ಪೆಕ್ಟ್‌ಪ್ರೊ',
    ds_mandatory_2:'2 ಕಡ್ಡಾಯ', ds_mandatory_3:'3 ಕಡ್ಡಾಯ',
    ds_check_types:'ವಿಧಗಳನ್ನು ಪರಿಶೀಲಿಸಿ', ds_modules:'ಸಿಮ್ ಮಾಡ್ಯೂಲ್‌ಗಳು',
    act1:'ಇನ್ಸ್ಪೆಕ್ಟ್‌ಪ್ರೊ — 4 ವಿಷ್ಯುಯಲ್ ಮಾಡ್ಯೂಲ್‌ಗಳು',
    act2:'ಚಿತ್ರ ಕ್ವಿಜ್ ಸಕ್ರಿಯ — ಸರಿಯಾದ ಬಣ್ಣ/ವಿಧ ಆಯ್ಕೆ ಮಾಡಿ',
    act3:'ಬಹುಭಾಷಾ ಬೆಂಬಲ ಸೇರಿಸಲಾಗಿದೆ',
    act4:'ಪೋರ್ಟಲ್ ನವೀಕರಿಸಲಾಗಿದೆ — SOS ಪುಟ ತೆಗೆಯಲಾಗಿದೆ',
    act_today:'ಇಂದು',
    prog_safety:'ಸುರಕ್ಷತಾ ಮಾಡ್ಯೂಲ್‌ಗಳು', prog_quality:'ಗುಣಮಟ್ಟ ಮಾಡ್ಯೂಲ್‌ಗಳು',
    prog_spec:'ಸ್ಪೆಕ್ ವಿಧಗಳು', prog_inspect:'ಇನ್ಸ್ಪೆಕ್ಟ್‌ಪ್ರೊ ಸಿಮ್',
    safety_tag:'ಸುರಕ್ಷತಾ ತರಬೇತಿ', safety_h1:'ಸುರಕ್ಷತಾ ವಿಡಿಯೊಗಳು',
    safety_playlist:'ಸುರಕ್ಷತಾ ತರಬೇತಿ ಪ್ಲೇಲಿಸ್ಟ್',
    quality_tag:'ಗುಣಮಟ್ಟ ತರಬೇತಿ', quality_h1:'ಗುಣಮಟ್ಟ ವಿಡಿಯೊಗಳು',
    quality_playlist:'ಗುಣಮಟ್ಟ ತರಬೇತಿ ಪ್ಲೇಲಿಸ್ಟ್',
    playlist_label:'ಪ್ಲೇಲಿಸ್ಟ್', playlist_hint:'Play All ಒತ್ತಿ ಅಥವಾ ವಿಡಿಯೊ ಆಯ್ಕೆ ಮಾಡಿ',
    no_video_selected:'— ಯಾವ ವಿಡಿಯೊ ಆಯ್ಕೆಯಾಗಿಲ್ಲ —',
    play_all:'ಎಲ್ಲ ಚಲಿಸಿ',
    all_safety_videos:'ಎಲ್ಲ ಸುರಕ್ಷತಾ ವಿಡಿಯೊಗಳು', all_quality_videos:'ಎಲ್ಲ ಗುಣಮಟ್ಟ ವಿಡಿಯೊಗಳು',
    search_safety:'ಸುರಕ್ಷತಾ ವಿಡಿಯೊ ಹುಡುಕಿ...', search_quality:'ಗುಣಮಟ್ಟ ವಿಡಿಯೊ ಹುಡುಕಿ...',
    spec_tag:'ವಿಶೇಷಣ ತರಬೇತಿ', spec_h1:'ಸ್ಪೆಕ್ ವಿಧಗಳ ಉಲ್ಲೇಖ',
    quiz_all:'ಕ್ವಿಜ್ — ಎಲ್ಲ ಐಟಂಗಳು', quiz_this_item:'ಈ ಐಟಂ ಕ್ವಿಜ್',
    btn_add_content:'ವಿಷಯ ಸೇರಿಸಿ', btn_add_video:'ವಿಡಿಯೊ ಸೇರಿಸಿ',
    btn_add_item:'ಐಟಂ ಸೇರಿಸಿ', btn_add:'ಸೇರಿಸಿ',
    items_label:'ಐಟಂಗಳು', search_items:'ಐಟಂಗಳನ್ನು ಹುಡುಕಿ...',
    new_item_placeholder:'ಹೊಸ ಐಟಂ ಹೆಸರು...',
    spec_select_prompt:'← ಒಂದು ಐಟಂ ಆಯ್ಕೆ ಮಾಡಿ',
    spec_detail_sub:'ಸ್ಪೆಕ್ ವಿಧಗಳನ್ನು ನೋಡಲು ಐಟಂ ಕ್ಲಿಕ್ ಮಾಡಿ',
    spec_empty:'ಸ್ಪೆಕ್ ಐಟಂ ಆಯ್ಕೆ ಮಾಡಿ',
    type_label:'ವಿಧ',
    inspect_tag:'ಸಿಮ್ಯುಲೇಷನ್ ತರಬೇತಿ', inspect_h1:'ಇನ್ಸ್ಪೆಕ್ಟ್‌ಪ್ರೊ — ದೃಶ್ಯ ಮಾಪನ',
    quiz_instruction:'ಸರಿಯಾದ ವಿಧದ ಚಿತ್ರ ಆಯ್ಕೆ ಮಾಡಿ:'
  },
  mr:{
    nav_sos:'SOS तपासणी', sb_sos_ops:'SOS शीट', sb_sos:'SOS तपासणी',
    sos_tag:'मानक ऑपरेशन शीट', sos_h1:'SOS तपासणी यादी',
    sos_processes:'प्रक्रिया', sos_select_prompt:'← तपासणी यादी पाहण्यासाठी प्रक्रिया निवडा',
    btn_add_sos_item:'आयटम जोडा', ds_sos:'SOS शीट', ds_sos_sub:'प्रक्रिया लोड',
    sos_search_ph:'तपासणी आयटम शोधा...',
    sos_th_sl:'अ.क्र', sos_th_step:'पायरी', sos_th_item:'तपासणी आयटम',
    sos_th_check:'तपासणी घटक', sos_th_standard:'मानक',
    sos_th_method:'पद्धत', sos_th_actions:'क्रिया',
    sos_th_images:'प्रतिमा',
    sos_method_hear:'ऐका', sos_method_push_hear:'ढकला + ऐका',
    sos_method_touch_feel:'स्पर्श + जाणवा', sos_method_visual_scan:'दृश्य + स्कॅन',
    sos_method_visual_feel:'दृश्य + जाणवा', sos_method_visual_shake:'दृश्य + हलवा',
    sos_method_visual_rotate:'दृश्य + फिरवा',
    okng_ok_label:'OK — स्वीकार्य स्थिती', okng_ng_label:'NG — अस्वीकार्य',
    okng_add_ok:'+ OK प्रतिमा जोडा', okng_add_ng:'+ NG प्रतिमा जोडा',
    okng_note:'💡 प्रत्येक तपासणी आयटमसाठी संदर्भ प्रतिमा अपलोड करा। OK प्रतिमा स्वीकार्य स्थिती दाखवतात, NG प्रतिमा दोष दाखवतात।',
    okng_quiz_btn:'NG क्विझ',
    ng_quiz_title:'NG कोडे क्विझ',
    ng_quiz_instr:'NG (दोष) स्थिती दाखवणाऱ्या सर्व प्रतिमा निवडा. एकापेक्षा जास्त निवडता येतात।',
    ng_quiz_submit:'उत्तर सबमिट करा',
    ng_quiz_next:'पुढील प्रश्न →',
    ng_quiz_restart:'↺ क्विझ पुन्हा सुरू करा',
    ng_quiz_no_images:'अजून OK/NG प्रतिमा अपलोड झाल्या नाहीत। आधी SOS चेकलिस्टमध्ये 👁 बटणाने प्रतिमा अपलोड करा।',
    sos_add_row:'+ ओळ जोडा', sos_clear_added:'🗑 साफ करा',
    sos_proc_search_ph:'प्रक्रिया शोधा...',
    sos_new_item_ph:'नवीन तपासणी आयटम...',
    sos_new_check_ph:'तपासणी घटक...',
    sos_new_standard_ph:'मानक...',
    sos_all_methods:'सर्व पद्धती',
    sos_method_visual:'दृश्य', sos_method_pull:'दृश्य + ओढा',
    sos_method_push:'दृश्य + ढकला', sos_method_touch:'दृश्य + स्पर्श',
    sos_method_function:'कार्य', sos_method_operation:'संचालन',
    sos_items_label:'आयटम',
    sos_takt_label:'टॅक्ट', sos_model_label:'मॉडेल',
    quiz_reverse:'उलट क्विझ',
    quiz_reverse_instruction:'चित्रात दाखवलेला प्रकार ओळखा:',
    nav_dashboard:'डॅशबोर्ड', nav_safety:'सुरक्षा', nav_quality:'गुणवत्ता',
    nav_spec:'स्पेक प्रशिक्षण', nav_inspect:'इन्स्पेक्टप्रो',
    sb_training:'प्रशिक्षण', sb_safety_videos:'सुरक्षा व्हिडिओ', sb_quality_videos:'गुणवत्ता व्हिडिओ',
    sb_spec_ops:'स्पेक आणि ऑप्स', sb_spec_types:'स्पेक प्रकार', sb_inspectpro:'इन्स्पेक्टप्रो सिम',
    dash_tag:'आढावा', dash_h1:'प्रशिक्षण डॅशबोर्ड', dash_progress:'प्रशिक्षण प्रगती',
    dash_activity:'अलीकडील क्रियाकलाप',
    ds_safety_videos:'सुरक्षा व्हिडिओ', ds_quality_videos:'गुणवत्ता व्हिडिओ',
    ds_spec_items:'स्पेक आयटम', ds_inspectpro:'इन्स्पेक्टप्रो',
    ds_mandatory_2:'2 अनिवार्य', ds_mandatory_3:'3 अनिवार्य',
    ds_check_types:'प्रकार तपासा', ds_modules:'सिम मॉड्यूल',
    act1:'इन्स्पेक्टप्रो सिम — 4 व्हिज्युअल मॉड्यूल उपलब्ध',
    act2:'इमेज क्विझ सक्षम — योग्य रंग/प्रकार निवडा',
    act3:'बहुभाषिक समर्थन जोडले गेले',
    act4:'पोर्टल अद्यतनित — SOS पृष्ठ काढले गेले',
    act_today:'आज',
    prog_safety:'सुरक्षा मॉड्यूल', prog_quality:'गुणवत्ता मॉड्यूल',
    prog_spec:'स्पेक प्रकार', prog_inspect:'इन्स्पेक्टप्रो सिम',
    safety_tag:'सुरक्षा प्रशिक्षण', safety_h1:'सुरक्षा व्हिडिओ',
    safety_playlist:'सुरक्षा प्रशिक्षण प्लेलिस्ट',
    quality_tag:'गुणवत्ता प्रशिक्षण', quality_h1:'गुणवत्ता व्हिडिओ',
    quality_playlist:'गुणवत्ता प्रशिक्षण प्लेलिस्ट',
    playlist_label:'प्लेलिस्ट', playlist_hint:'Play All दाबा किंवा व्हिडिओ निवडा',
    no_video_selected:'— कोणताही व्हिडिओ निवडला नाही —',
    play_all:'सर्व चालवा',
    all_safety_videos:'सर्व सुरक्षा व्हिडिओ', all_quality_videos:'सर्व गुणवत्ता व्हिडिओ',
    search_safety:'सुरक्षा व्हिडिओ शोधा...', search_quality:'गुणवत्ता व्हिडिओ शोधा...',
    spec_tag:'विशिष्टता प्रशिक्षण', spec_h1:'स्पेक प्रकार संदर्भ',
    quiz_all:'क्विझ — सर्व आयटम', quiz_this_item:'या आयटमची क्विझ',
    btn_add_content:'सामग्री जोडा', btn_add_video:'व्हिडिओ जोडा',
    btn_add_item:'आयटम जोडा', btn_add:'जोडा',
    items_label:'आयटम', search_items:'आयटम शोधा...',
    new_item_placeholder:'नवीन आयटम नाव...',
    spec_select_prompt:'← एक आयटम निवडा',
    spec_detail_sub:'स्पेक प्रकार पाहण्यासाठी आयटम क्लिक करा',
    spec_empty:'स्पेक आयटम निवडा',
    type_label:'प्रकार',
    inspect_tag:'सिम्युलेशन प्रशिक्षक', inspect_h1:'इन्स्पेक्टप्रो — व्हिज्युअल मोजमाप',
    quiz_instruction:'योग्य प्रकाराची प्रतिमा निवडा:'
  },
  ja:{
    nav_sos:'SOS チェックリスト', sb_sos_ops:'SOS シート', sb_sos:'SOS チェックリスト',
    sos_tag:'標準作業シート', sos_h1:'SOS チェックリスト',
    sos_processes:'プロセス', sos_select_prompt:'← チェックリストを見るにはプロセスを選択',
    btn_add_sos_item:'アイテムを追加', ds_sos:'SOS シート', ds_sos_sub:'プロセス読込済',
    sos_search_ph:'点検項目を検索...',
    sos_th_sl:'番号', sos_th_step:'工程', sos_th_item:'点検項目',
    sos_th_check:'確認項目', sos_th_standard:'基準',
    sos_th_method:'方法', sos_th_actions:'操作',
    sos_th_images:'画像',
    sos_method_hear:'聴音', sos_method_push_hear:'押付+聴音',
    sos_method_touch_feel:'触触+感触', sos_method_visual_scan:'目視+スキャン',
    sos_method_visual_feel:'目視+感触', sos_method_visual_shake:'目視+振動',
    sos_method_visual_rotate:'目視+回転',
    okng_ok_label:'OK — 合格条件', okng_ng_label:'NG — 不合格',
    okng_add_ok:'+ OK画像追加', okng_add_ng:'+ NG画像追加',
    okng_note:'💡 各点検項目の参照画像をアップロードしてください。OK画像は合格状態、NG画像は不良を示します。',
    okng_quiz_btn:'NGクイズ',
    ng_quiz_title:'NG パズルクイズ',
    ng_quiz_instr:'NG（不良）状態を示すすべての画像を選択してください。複数選択可能です。',
    ng_quiz_submit:'回答を提出',
    ng_quiz_next:'次の問題 →',
    ng_quiz_restart:'↺ クイズを再開',
    ng_quiz_no_images:'OK/NG画像がまだアップロードされていません。SOSチェックリストの👁ボタンで画像をアップロードしてください。',
    sos_add_row:'+ 行追加', sos_clear_added:'🗑 追加削除',
    sos_proc_search_ph:'プロセスを検索...',
    sos_new_item_ph:'新しい点検項目...',
    sos_new_check_ph:'確認項目...',
    sos_new_standard_ph:'基準...',
    sos_all_methods:'全方法',
    sos_method_visual:'目視', sos_method_pull:'目視+引張',
    sos_method_push:'目視+押付', sos_method_touch:'目視+触触',
    sos_method_function:'機能', sos_method_operation:'操作',
    sos_items_label:'アイテム',
    sos_takt_label:'タクト', sos_model_label:'モデル',
    quiz_reverse:'逆クイズ',
    quiz_reverse_instruction:'画像に示されているタイプを特定してください:',
    nav_dashboard:'ダッシュボード', nav_safety:'安全', nav_quality:'品質',
    nav_spec:'仕様トレーニング', nav_inspect:'インスペクトプロ',
    sb_training:'トレーニング', sb_safety_videos:'安全動画', sb_quality_videos:'品質動画',
    sb_spec_ops:'仕様と作業', sb_spec_types:'仕様タイプ', sb_inspectpro:'インスペクトプロSim',
    dash_tag:'概要', dash_h1:'トレーニングダッシュボード', dash_progress:'トレーニング進捗',
    dash_activity:'最近の活動',
    ds_safety_videos:'安全動画', ds_quality_videos:'品質動画',
    ds_spec_items:'仕様アイテム', ds_inspectpro:'インスペクトプロ',
    ds_mandatory_2:'2 必須', ds_mandatory_3:'3 必須',
    ds_check_types:'タイプ確認', ds_modules:'シムモジュール',
    act1:'インスペクトプロSim — 4つの視覚モジュール',
    act2:'画像クイズ有効 — 正しい色/タイプを選択',
    act3:'多言語サポート追加 — EN / हि / ಕ / म / 日',
    act4:'ポータル更新 — SOSページを削除',
    act_today:'今日',
    prog_safety:'安全モジュール', prog_quality:'品質モジュール',
    prog_spec:'仕様タイプ', prog_inspect:'インスペクトプロSim',
    safety_tag:'安全トレーニング', safety_h1:'安全動画',
    safety_playlist:'安全トレーニング プレイリスト',
    quality_tag:'品質トレーニング', quality_h1:'品質動画',
    quality_playlist:'品質トレーニング プレイリスト',
    playlist_label:'プレイリスト', playlist_hint:'Play Allを押すか動画を選択',
    no_video_selected:'— 動画が選択されていません —',
    play_all:'すべて再生',
    all_safety_videos:'すべての安全動画', all_quality_videos:'すべての品質動画',
    search_safety:'安全動画を検索...', search_quality:'品質動画を検索...',
    spec_tag:'仕様トレーニング', spec_h1:'仕様タイプ リファレンス',
    quiz_all:'クイズ — 全アイテム', quiz_this_item:'このアイテムのクイズ',
    btn_add_content:'コンテンツを追加', btn_add_video:'動画を追加',
    btn_add_item:'アイテムを追加', btn_add:'追加',
    items_label:'アイテム', search_items:'アイテムを検索...',
    new_item_placeholder:'新しいアイテム名...',
    spec_select_prompt:'← アイテムを選択',
    spec_detail_sub:'仕様タイプを表示するにはアイテムをクリック',
    spec_empty:'仕様アイテムを選択してください',
    type_label:'タイプ',
    inspect_tag:'シミュレーション トレーナー', inspect_h1:'インスペクトプロ — 視覚測定',
    quiz_instruction:'正しいタイプの画像を選択してください:'
  }
};


const EXTRA_LANGS_PATCH = {
  en:{processes_label:'Processes',save_videos:'Save Videos',save_data:'Save Data',delete_label:'Delete',remove_label:'Remove',add_ok:'Add OK',add_ng:'Add NG',puzzle_test:'Puzzle Test',jt_items:'Judgement Items',jt_search_ph:'Search judgement item...',jt_new_item_ph:'New judgement item...',jt_meta:'OK / NG judgement item',jt_detail_sub:'Add multiple OK and NG images. Puzzle test will mix both image types.',jt_empty:'← Select a judgement item to begin',jt_upload_images:'Upload Images',jt_start_mixed:'Start Mixed OK/NG Quiz',jt_mixed_title:'Mixed OK/NG Puzzle Test',jt_mixed_sub:'Questions will ask either: Select OK images or Select NG images.',jt_select_ok:'Select ALL OK Images',jt_select_ng:'Select ALL NG Images',jt_target_count:'Target count',jt_click_all:'Click all matching images from the mixed OK/NG set.',jt_submit:'Submit Answer',jt_next:'Next →',jt_close:'Close',jt_score:'Score',jt_ok_good:'OK — Good Condition',jt_ng_defect:'NG — Defect Condition',jt_add_ok_images:'Add OK Images',jt_add_ng_images:'Add NG Images',jt_multiple:'Multiple allowed',spec_delete_item_confirm:'Delete this spec item?',jt_delete_item_confirm:'Delete this judgement item and its images?'},
  hi:{processes_label:'प्रक्रियाएं',save_videos:'वीडियो सहेजें',save_data:'डेटा सहेजें',delete_label:'हटाएं',remove_label:'हटाएं',add_ok:'OK जोड़ें',add_ng:'NG जोड़ें',puzzle_test:'पहेली टेस्ट',jt_items:'जजमेंट आइटम',jt_search_ph:'जजमेंट आइटम खोजें...',jt_new_item_ph:'नया जजमेंट आइटम...',jt_meta:'OK / NG जजमेंट आइटम',jt_detail_sub:'कई OK और NG चित्र जोड़ें। पहेली टेस्ट दोनों प्रकार के चित्र मिलाएगा।',jt_empty:'← शुरू करने के लिए जजमेंट आइटम चुनें',jt_upload_images:'चित्र अपलोड करें',jt_start_mixed:'मिश्रित OK/NG क्विज़ शुरू करें',jt_mixed_title:'मिश्रित OK/NG पहेली टेस्ट',jt_mixed_sub:'प्रश्न पूछेंगे: OK चित्र चुनें या NG चित्र चुनें।',jt_select_ok:'सभी OK चित्र चुनें',jt_select_ng:'सभी NG चित्र चुनें',jt_target_count:'लक्ष्य संख्या',jt_click_all:'मिश्रित OK/NG सेट से सभी मिलते चित्र क्लिक करें।',jt_submit:'उत्तर जमा करें',jt_next:'अगला →',jt_close:'बंद करें',jt_score:'स्कोर',jt_ok_good:'OK — अच्छी स्थिति',jt_ng_defect:'NG — दोष स्थिति',jt_add_ok_images:'OK चित्र जोड़ें',jt_add_ng_images:'NG चित्र जोड़ें',jt_multiple:'एकाधिक अनुमति',spec_delete_item_confirm:'यह स्पेक आइटम हटाएं?',jt_delete_item_confirm:'यह जजमेंट आइटम और इसके चित्र हटाएं?'},
  kn:{processes_label:'ಪ್ರಕ್ರಿಯೆಗಳು',save_videos:'ವೀಡಿಯೊ ಉಳಿಸಿ',save_data:'ಡೇಟಾ ಉಳಿಸಿ',delete_label:'ಅಳಿಸಿ',remove_label:'ತೆಗೆದುಹಾಕಿ',add_ok:'OK ಸೇರಿಸಿ',add_ng:'NG ಸೇರಿಸಿ',puzzle_test:'ಪಜಲ್ ಟೆಸ್ಟ್',jt_items:'ಜಡ್ಜ್ಮೆಂಟ್ ಐಟಂಗಳು',jt_search_ph:'ಜಡ್ಜ್ಮೆಂಟ್ ಐಟಂ ಹುಡುಕಿ...',jt_new_item_ph:'ಹೊಸ ಜಡ್ಜ್ಮೆಂಟ್ ಐಟಂ...',jt_meta:'OK / NG ಜಡ್ಜ್ಮೆಂಟ್ ಐಟಂ',jt_detail_sub:'ಬಹು OK ಮತ್ತು NG ಚಿತ್ರಗಳನ್ನು ಸೇರಿಸಿ. ಪಜಲ್ ಟೆಸ್ಟ್ ಎರಡನ್ನೂ ಮಿಶ್ರಣ ಮಾಡುತ್ತದೆ.',jt_empty:'← ಪ್ರಾರಂಭಿಸಲು ಜಡ್ಜ್ಮೆಂಟ್ ಐಟಂ ಆಯ್ಕೆ ಮಾಡಿ',jt_upload_images:'ಚಿತ್ರಗಳನ್ನು ಅಪ್ಲೋಡ್ ಮಾಡಿ',jt_start_mixed:'ಮಿಶ್ರ OK/NG ಕ್ವಿಜ್ ಪ್ರಾರಂಭಿಸಿ',jt_mixed_title:'ಮಿಶ್ರ OK/NG ಪಜಲ್ ಟೆಸ್ಟ್',jt_mixed_sub:'ಪ್ರಶ್ನೆಗಳು: OK ಚಿತ್ರಗಳನ್ನು ಆಯ್ಕೆ ಮಾಡಿ ಅಥವಾ NG ಚಿತ್ರಗಳನ್ನು ಆಯ್ಕೆ ಮಾಡಿ.',jt_select_ok:'ಎಲ್ಲಾ OK ಚಿತ್ರಗಳನ್ನು ಆಯ್ಕೆ ಮಾಡಿ',jt_select_ng:'ಎಲ್ಲಾ NG ಚಿತ್ರಗಳನ್ನು ಆಯ್ಕೆ ಮಾಡಿ',jt_target_count:'ಗುರಿ ಸಂಖ್ಯೆ',jt_click_all:'ಮಿಶ್ರ OK/NG ಸೆಟ್‌ನಿಂದ ಸರಿಯಾದ ಎಲ್ಲಾ ಚಿತ್ರಗಳನ್ನು ಕ್ಲಿಕ್ ಮಾಡಿ.',jt_submit:'ಉತ್ತರ ಸಲ್ಲಿಸಿ',jt_next:'ಮುಂದೆ →',jt_close:'ಮುಚ್ಚಿ',jt_score:'ಸ್ಕೋರ್',jt_ok_good:'OK — ಉತ್ತಮ ಸ್ಥಿತಿ',jt_ng_defect:'NG — ದೋಷ ಸ್ಥಿತಿ',jt_add_ok_images:'OK ಚಿತ್ರ ಸೇರಿಸಿ',jt_add_ng_images:'NG ಚಿತ್ರ ಸೇರಿಸಿ',jt_multiple:'ಬಹು ಅನುಮತಿ',spec_delete_item_confirm:'ಈ ಸ್ಪೆಕ್ ಐಟಂ ಅಳಿಸಬೇಕೆ?',jt_delete_item_confirm:'ಈ ಜಡ್ಜ್ಮೆಂಟ್ ಐಟಂ ಮತ್ತು ಅದರ ಚಿತ್ರಗಳನ್ನು ಅಳಿಸಬೇಕೆ?'},
  mr:{processes_label:'प्रक्रिया',save_videos:'व्हिडिओ सेव्ह करा',save_data:'डेटा सेव्ह करा',delete_label:'काढा',remove_label:'काढा',add_ok:'OK जोडा',add_ng:'NG जोडा',puzzle_test:'पझल टेस्ट',jt_items:'जजमेंट आयटम',jt_search_ph:'जजमेंट आयटम शोधा...',jt_new_item_ph:'नवा जजमेंट आयटम...',jt_meta:'OK / NG जजमेंट आयटम',jt_detail_sub:'अनेक OK आणि NG चित्रे जोडा. पझल टेस्ट दोन्ही प्रकार मिसळेल.',jt_empty:'← सुरू करण्यासाठी जजमेंट आयटम निवडा',jt_upload_images:'चित्रे अपलोड करा',jt_start_mixed:'मिश्र OK/NG क्विझ सुरू करा',jt_mixed_title:'मिश्र OK/NG पझल टेस्ट',jt_mixed_sub:'प्रश्न विचारतील: OK चित्रे निवडा किंवा NG चित्रे निवडा.',jt_select_ok:'सर्व OK चित्रे निवडा',jt_select_ng:'सर्व NG चित्रे निवडा',jt_target_count:'लक्ष्य संख्या',jt_click_all:'मिश्र OK/NG सेटमधील जुळणारी सर्व चित्रे क्लिक करा.',jt_submit:'उत्तर सबमिट करा',jt_next:'पुढे →',jt_close:'बंद करा',jt_score:'स्कोर',jt_ok_good:'OK — चांगली स्थिती',jt_ng_defect:'NG — दोष स्थिती',jt_add_ok_images:'OK चित्रे जोडा',jt_add_ng_images:'NG चित्रे जोडा',jt_multiple:'अनेक परवानगी',spec_delete_item_confirm:'हा स्पेक आयटम काढायचा?',jt_delete_item_confirm:'हा जजमेंट आयटम आणि त्याची चित्रे काढायची?'},
  ja:{processes_label:'工程',save_videos:'動画保存',save_data:'データ保存',delete_label:'削除',remove_label:'削除',add_ok:'OK追加',add_ng:'NG追加',puzzle_test:'パズルテスト',jt_items:'判定項目',jt_search_ph:'判定項目を検索...',jt_new_item_ph:'新しい判定項目...',jt_meta:'OK / NG 判定項目',jt_detail_sub:'複数のOK/NG画像を追加できます。パズルテストは両方を混合します。',jt_empty:'← 開始する判定項目を選択',jt_upload_images:'画像アップロード',jt_start_mixed:'混合OK/NGクイズ開始',jt_mixed_title:'混合OK/NGパズルテスト',jt_mixed_sub:'質問はOK画像選択またはNG画像選択です。',jt_select_ok:'すべてのOK画像を選択',jt_select_ng:'すべてのNG画像を選択',jt_target_count:'対象数',jt_click_all:'混合OK/NGセットから該当する全画像をクリックしてください。',jt_submit:'回答送信',jt_next:'次へ →',jt_close:'閉じる',jt_score:'スコア',jt_ok_good:'OK — 良品状態',jt_ng_defect:'NG — 不良状態',jt_add_ok_images:'OK画像追加',jt_add_ng_images:'NG画像追加',jt_multiple:'複数可',spec_delete_item_confirm:'この仕様項目を削除しますか？',jt_delete_item_confirm:'この判定項目と画像を削除しますか？'}
};
Object.keys(EXTRA_LANGS_PATCH).forEach(k=>Object.assign(LANGS[k]||(LANGS[k]={}), EXTRA_LANGS_PATCH[k]));

let currentLang = 'en';

function setLang(lang) {
  currentLang = lang;
  document.querySelectorAll('.lang-btn').forEach(b=>{
    b.classList.toggle('active', b.textContent.trim()===({en:'EN',hi:'हि',kn:'ಕ',mr:'म',ja:'日'}[lang]));
  });
  applyTranslations();
  // Re-render grids to update any dynamic text
  renderAll();
  if(activeSpecItem) {
    const it = DB.specItems.find(x=>x.name===activeSpecItem);
    if(it) renderSpecTypes(it);
  }
  // Re-render SOS proc list to update count labels
  renderSOSProcs(document.getElementById('sos-proc-search')?.value || '');
  if(typeof renderSpecProcesses==='function') renderSpecProcesses();
  if(typeof renderJTProcs==='function') renderJTProcs(document.getElementById('jt-proc-search')?.value||'');
  if(typeof renderJTDetail==='function' && typeof JT_ACTIVE_SL!=='undefined' && JT_ACTIVE_SL) renderJTDetail(JT_ACTIVE_SL);
}

function t(key) {
  return (LANGS[currentLang] && LANGS[currentLang][key]) || LANGS.en[key] || key;
}

function applyTranslations() {
  document.querySelectorAll('[data-i18n]').forEach(el=>{
    const key = el.getAttribute('data-i18n');
    const val = t(key);
    if(el.tagName === 'OPTION') el.textContent = val;
    else el.textContent = val;
  });
  document.querySelectorAll('[data-i18n-placeholder]').forEach(el=>{
    const key = el.getAttribute('data-i18n-placeholder');
    el.placeholder = t(key);
  });
  // Re-render SOS table if one is active to refresh translated cells
  if(typeof activeSosProcess !== 'undefined' && activeSosProcess) {
    renderSOSTable(activeSosProcess);
  }
}

// ═══════════════════════════════════════════
// DATA
// ═══════════════════════════════════════════
const DB = {
  safetyVideos:[],
  qualityVideos:[],
  specItems:[
    {name:'Vin Label',types:['MSIL','MSIL - S','TMC','TMC - T','TKML'],colors:['#cccccc','#aaaaaa','#eeeeee','#bbbbbb','#999999']},
    {name:'Wheel Disc',types:['STEEL','Y BLACK','Y DIAMOND CUT','SILVER','FLOWER DIAMOND CUT','V BLACK','V DIAMOND CUT'],colors:['#888888','#222222','#cccccc','#c0c0c0','#aaaaaa','#111111','#bbbbbb']},
    {name:'Driver Inner Garnish',types:['BLACK','BROWN','BORDEAUX'],colors:['#1a1a1a','#6b3a2a','#6b1a2a']},
    {name:'Radiator Grill',types:['CHROME','SMOKED CHROME','WITH TEXTURE','WITHOUT TEXTURE'],colors:['#c0c0c0','#555555','#888888','#aaaaaa']},
    {name:'Back Dr Ctr Garnish',types:['SILVER + BLACK','CHROME + BODY COLOR','SUZUKI TYPE 1'],colors:['#aaaaaa','#c0c0c0','#888888']},
    {name:'Head Lamp Bezel',types:['CHROME','BLACK PAINTED','PAINTED','UNPAINTED'],colors:['#c0c0c0','#111111','#555555','#999999']},
    {name:'Console Ornament',types:['BLACK','BROWN','BORDEAUX'],colors:['#1a1a1a','#6b3a2a','#6b1a2a']},
    {name:'IP Garnish',types:['BLACK WITHOUT STICH','BLACK WITH SILVER STICH','BLACK WITH COPPER STICH','BORDEAUX WITHOUT STICH','BORDEAUX WITH SILVER STICH','BROWN WITHOUT STICH','BROWN WITH SILVER STICH'],colors:['#1a1a1a','#1a1a1a','#1a1a1a','#6b1a2a','#6b1a2a','#6b3a2a','#6b3a2a']},
    {name:'Door Trim Fabric Material',types:['BLACK WITHOUT STICH','BLACK WITH SILVER STICH','BLACK WITH COPPER STICH','BORDEAUX WITHOUT STICH','BORDEAUX WITH SILVER STICH','BROWN WITHOUT STICH','BROWN WITH SILVER STICH'],colors:['#1a1a1a','#1a1a1a','#1a1a1a','#6b1a2a','#6b1a2a','#6b3a2a','#6b3a2a']},
    {name:'AC Label',types:['WITH RED DOT','WITH BLUE DOT'],colors:['#cc2222','#2255cc']},
    {name:'Battery Notice Label',types:['WITH','WARNING LABEL'],colors:['#ddcc00','#ff4400']},
    {name:'Battery Information Label',types:['WITH 1','WITH 4','WITH ENGLISH'],colors:['#3355aa','#3355aa','#3355aa']},
    {name:'Cooling Fan Label',types:['SPANISH FONT','HINDI FONT','ARABIC FONT'],colors:['#cc8800','#cc4400','#4488cc']},
    {name:'Ignition Switch',types:['BLUE BIG RING','BLACK BIG RING'],colors:['#2255cc','#111111']},
    {name:'Console Rear Vent',types:['3 POINT SILVER','UNPAINTED'],colors:['#c0c0c0','#888888']},
    {name:'Tyre Pressure Label',types:['BLACK FONT','BLUE FONT'],colors:['#111111','#2255cc']},
    {name:'Fuel Consumption Label',types:['H','X','V','T','A','M'],colors:['#cc5500','#cc5500','#cc5500','#cc5500','#cc5500','#cc5500']},
    {name:'A/C Register Bezel',types:['PAINTED','UNPAINTED'],colors:['#555555','#aaaaaa']},
    {name:'Rear Bumper Lower Garnish',types:['TYPE - 1 GRAY (S)','TYPE - 2 GRAY (T)','TYPE - 2 SILVER (S)'],colors:['#888888','#777777','#c0c0c0']},
    {name:'Rr Bumper Lower Garnish',types:['SILVER','GRAY'],colors:['#c0c0c0','#888888']},
    {name:'Overhead Console',types:['WITH OVERHEAD CONSOLE','WITHOUT OVERHEAD CONSOLE'],colors:['#2a2a2a','#555555']},
    {name:'Fuse Box Cover',types:['A','B','C','D'],colors:['#333333','#444444','#555555','#666666']},
    {name:'Seat Material',types:['LEATHER','STD CLOTH'],colors:['#4a3828','#555555']},
    {name:'Fuel Limitation Label',types:['WITH UPTO E20 ONLY','WITH UNLEADED FUEL ONLY'],colors:['#22aa44','#cc8800']},
    {name:'Quarter Pillar Garnish',types:['SILVER','BLACK','SMOKED CHROME'],colors:['#c0c0c0','#111111','#555555']},
    {name:'Key Remote',types:['NO (S)','TYPE A (S)','TYPE A (T)','WITH - CE','WITHOUT - CE'],colors:['#888888','#333333','#444444','#2255cc','#555555']},
    {name:'Power Window Bezel',types:['PAINTED','UNPAINTED'],colors:['#333333','#999999']},
    {name:'Tweeter Cover',types:['WITH SPEAKER','WITHOUT SPEAKER (NO HOLE)'],colors:['#222222','#555555']},
    {name:'Battery Cover',types:['SINGLE SLOT','DOUBLE SLOT','WITHOUT'],colors:['#333333','#222222','#888888']},
    {name:'Front Bumper Lower Garnish',types:['SILVER','GRAY'],colors:['#c0c0c0','#888888']},
    {name:'Shift Lever Knob',types:['BLACK + CHROME','UNPAINTED'],colors:['#111111','#999999']},
    {name:'Engine Tag Name Mark',types:['BLUE HYBRID','HYBRID','BLACK HYBRID','SMART HYBRID','NEO DRIVE'],colors:['#2255cc','#22aa44','#111111','#cc8800','#8800cc']},
    {name:'Rocker Mount',types:['PAINTED','UNPAINTED'],colors:['#333333','#999999']}
  ]
};

const SPEC_IMAGES = {};


// Persistent storage for user-added Spec items/types/images
const SPEC_STORE_KEY = 'toyota_portal_spec_training_v2';
function saveSpecData(silent=false){
  try{
    localStorage.setItem(SPEC_STORE_KEY, JSON.stringify({specItems:DB.specItems, specImages:SPEC_IMAGES, specProcesses:SPEC_PROCESSES}));
    if(!silent) toast('Spec data saved ✓');
  }catch(e){ console.warn('Spec save failed', e); if(!silent) toast('Unable to save spec data'); }
}
function loadSpecData(){
  try{
    const raw = localStorage.getItem(SPEC_STORE_KEY);
    if(!raw) return;
    const data = JSON.parse(raw);
    if(data && Array.isArray(data.specItems)) DB.specItems = data.specItems;
    if(data && data.specImages && typeof data.specImages === 'object') Object.assign(SPEC_IMAGES, data.specImages);
    if(data && Array.isArray(data.specProcesses) && typeof SPEC_PROCESSES !== 'undefined') { SPEC_PROCESSES.splice(0, SPEC_PROCESSES.length, ...data.specProcesses); }
  }catch(e){ console.warn('Spec load failed', e); }
}

const VIDEO_STORE_KEY = 'toyota_portal_training_videos_v1';
function saveVideoData(silent=false){
  try{ localStorage.setItem(VIDEO_STORE_KEY, JSON.stringify({safetyVideos:DB.safetyVideos, qualityVideos:DB.qualityVideos})); if(!silent) toast('Video data saved ✓'); }
  catch(e){ console.warn('Video save failed', e); if(!silent) toast('Unable to save video data. Use smaller videos if browser storage is full.'); }
}
function loadVideoData(){
  try{ const raw=localStorage.getItem(VIDEO_STORE_KEY); if(!raw) return; const data=JSON.parse(raw); if(data&&Array.isArray(data.safetyVideos)) DB.safetyVideos=data.safetyVideos; if(data&&Array.isArray(data.qualityVideos)) DB.qualityVideos=data.qualityVideos; }
  catch(e){ console.warn('Video load failed', e); }
}

// Offline automatic translation for newly-added Spec item/type names.
const AUTO_WORD_TRANS = {
  hi:{'HOSE':'होस','TUBE':'ट्यूब','INSERTION':'डालना','INSERT':'डालना','CLIP':'क्लिप','POSITION':'स्थिति','COME':'निकलना','OFF':'बाहर','UNLOCK':'अनलॉक','UNLOCKED':'अनलॉक','LOCK':'लॉक','HALF':'आधा','NOT':'नहीं','CONNECTED':'कनेक्टेड','CONNECTOR':'कनेक्टर','BOLT':'बोल्ट','LOOSENESS':'ढीलापन','LOOSE':'ढीला','CLAMP':'क्लैम्प','PART':'पार्ट','INTERFERENCE':'हस्तक्षेप','MARK':'मार्क','MISS':'गुम','MISSING':'गुम','DAMAGE':'नुकसान','DAMAGED':'नुकसान','LABEL':'लेबल','COVER':'कवर','GARNISH':'गार्निश','BUMPER':'बम्पर','FRONT':'फ्रंट','REAR':'रियर','LOWER':'लोअर','UPPER':'अपर','LEFT':'लेफ्ट','RIGHT':'राइट','LH':'LH','RH':'RH','DOOR':'डोर','ENGINE':'इंजन','BATTERY':'बैटरी','FUSE':'फ्यूज','BOX':'बॉक्स','WHEEL':'व्हील','DISC':'डिस्क','BLACK':'काला','BROWN':'भूरा','SILVER':'सिल्वर','CHROME':'क्रोम','PAINTED':'पेंटेड','UNPAINTED':'अनपेंटेड','WITH':'सहित','WITHOUT':'रहित','WRONG':'गलत','COLOR':'रंग','PROCESS':'प्रोसेस','PROCESSES':'प्रोसेस','SPEC':'स्पेक','PIT':'पिट','FIT':'फिट','INT':'इंटीरियर','INTERIOR':'इंटीरियर','EXT':'एक्सटीरियर','ROOM':'रूम','BACK':'बैक','FR':'फ्रंट','RR':'रियर','CTR':'सेंटर','STICH':'स्टिच','STITCH':'स्टिच','TYPE':'टाइप','ITEM':'आइटम','ITEMS':'आइटम','OK':'OK','NG':'NG'},
  kn:{'HOSE':'ಹೋಸ್','TUBE':'ಟ್ಯೂಬ್','INSERTION':'ಸೇರ್ಪಡೆ','INSERT':'ಸೇರಿಸಿ','CLIP':'ಕ್ಲಿಪ್','POSITION':'ಸ್ಥಾನ','COME':'ಬರುವುದು','OFF':'ಬೇರ್ಪಡೆ','UNLOCK':'ಅನ್‌ಲಾಕ್','UNLOCKED':'ಅನ್‌ಲಾಕ್','LOCK':'ಲಾಕ್','HALF':'ಅರ್ಧ','NOT':'ಇಲ್ಲ','CONNECTED':'ಕನೆಕ್ಟ್','CONNECTOR':'ಕನೆಕ್ಟರ್','BOLT':'ಬೋಲ್ಟ್','LOOSENESS':'ಸಡಿಲತೆ','LOOSE':'ಸಡಿಲ','CLAMP':'ಕ್ಲ್ಯಾಂಪ್','PART':'ಪಾರ್ಟ್','INTERFERENCE':'ಹಸ್ತಕ್ಷೇಪ','MARK':'ಗುರುತು','MISS':'ಮಿಸ್','MISSING':'ಕಾಣೆಯಾಗಿದೆ','DAMAGE':'ಹಾನಿ','DAMAGED':'ಹಾನಿ','LABEL':'ಲೇಬಲ್','COVER':'ಕವರ್','GARNISH':'ಗಾರ್ನಿಷ್','BUMPER':'ಬಂಪರ್','FRONT':'ಮುಂಭಾಗ','REAR':'ಹಿಂಭಾಗ','LOWER':'ಕೆಳ','UPPER':'ಮೇಲಿನ','LEFT':'ಎಡ','RIGHT':'ಬಲ','LH':'LH','RH':'RH','DOOR':'ಡೋರ್','ENGINE':'ಎಂಜಿನ್','BATTERY':'ಬ್ಯಾಟರಿ','FUSE':'ಫ್ಯೂಸ್','BOX':'ಬಾಕ್ಸ್','WHEEL':'ವೀಲ್','DISC':'ಡಿಸ್ಕ್','BLACK':'ಕಪ್ಪು','BROWN':'ಕಂದು','SILVER':'ಸಿಲ್ವರ್','CHROME':'ಕ್ರೋಮ್','PAINTED':'ಪೇಂಟೆಡ್','UNPAINTED':'ಅನ್‌ಪೇಂಟೆಡ್','WITH':'ಸಹಿತ','WITHOUT':'ರಹಿತ','WRONG':'ತಪ್ಪು','COLOR':'ಬಣ್ಣ','OK':'OK','NG':'NG'},
  mr:{'HOSE':'होज','TUBE':'ट्यूब','INSERTION':'घालणे','INSERT':'घाला','CLIP':'क्लिप','POSITION':'स्थिती','COME':'निघणे','OFF':'बाहेर','UNLOCK':'अनलॉक','UNLOCKED':'अनलॉक','LOCK':'लॉक','HALF':'अर्धे','NOT':'नाही','CONNECTED':'कनेक्टेड','CONNECTOR':'कनेक्टर','BOLT':'बोल्ट','LOOSENESS':'सैलपणा','LOOSE':'सैल','CLAMP':'क्लॅम्प','PART':'पार्ट','INTERFERENCE':'अडथळा','MARK':'मार्क','MISS':'चुकले','MISSING':'हरवले','DAMAGE':'नुकसान','DAMAGED':'नुकसान','LABEL':'लेबल','COVER':'कव्हर','GARNISH':'गार्निश','BUMPER':'बम्पर','FRONT':'फ्रंट','REAR':'रियर','LOWER':'लोअर','UPPER':'अपर','LEFT':'लेफ्ट','RIGHT':'राइट','LH':'LH','RH':'RH','DOOR':'डोर','ENGINE':'इंजिन','BATTERY':'बॅटरी','FUSE':'फ्यूज','BOX':'बॉक्स','WHEEL':'व्हील','DISC':'डिस्क','BLACK':'काळा','BROWN':'तपकिरी','SILVER':'सिल्वर','CHROME':'क्रोम','PAINTED':'पेंटेड','UNPAINTED':'अनपेंटेड','WITH':'सहित','WITHOUT':'रहित','WRONG':'चुकीचा','COLOR':'रंग','OK':'OK','NG':'NG'},
  ja:{'HOSE':'ホース','TUBE':'チューブ','INSERTION':'挿入','INSERT':'挿入','CLIP':'クリップ','POSITION':'位置','COME':'外れ','OFF':'外れ','UNLOCK':'未ロック','UNLOCKED':'未ロック','LOCK':'ロック','HALF':'半','NOT':'未','CONNECTED':'接続','CONNECTOR':'コネクタ','BOLT':'ボルト','LOOSENESS':'緩み','LOOSE':'緩み','CLAMP':'クランプ','PART':'部品','INTERFERENCE':'干渉','MARK':'マーク','MISS':'無し','MISSING':'欠品','DAMAGE':'損傷','DAMAGED':'損傷','LABEL':'ラベル','COVER':'カバー','GARNISH':'ガーニッシュ','BUMPER':'バンパー','FRONT':'フロント','REAR':'リア','LOWER':'ロア','UPPER':'アッパー','LEFT':'左','RIGHT':'右','LH':'LH','RH':'RH','DOOR':'ドア','ENGINE':'エンジン','BATTERY':'バッテリー','FUSE':'ヒューズ','BOX':'ボックス','WHEEL':'ホイール','DISC':'ディスク','BLACK':'ブラック','BROWN':'ブラウン','SILVER':'シルバー','CHROME':'クロム','PAINTED':'塗装','UNPAINTED':'未塗装','WITH':'付き','WITHOUT':'なし','WRONG':'誤','COLOR':'色','OK':'OK','NG':'NG'}
};
function transliterateWord(word, lang){
  const w = String(word || '').toLowerCase();
  if(!w) return word;
  const maps = {
    hi:{a:'अ',b:'ब',c:'क',d:'द',e:'े',f:'फ',g:'ग',h:'ह',i:'ि',j:'ज',k:'क',l:'ल',m:'म',n:'न',o:'ो',p:'प',q:'क',r:'र',s:'स',t:'ट',u:'ु',v:'व',w:'व',x:'क्स',y:'य',z:'ज'},
    mr:{a:'अ',b:'ब',c:'क',d:'द',e:'े',f:'फ',g:'ग',h:'ह',i:'ि',j:'ज',k:'क',l:'ल',m:'म',n:'न',o:'ो',p:'प',q:'क',r:'र',s:'स',t:'ट',u:'ु',v:'व',w:'व',x:'क्स',y:'य',z:'ज'},
    kn:{a:'ಅ',b:'ಬ',c:'ಕ',d:'ದ',e:'ೆ',f:'ಫ',g:'ಗ',h:'ಹ',i:'ಿ',j:'ಜ',k:'ಕ',l:'ಲ',m:'ಮ',n:'ನ',o:'ೊ',p:'ಪ',q:'ಕ',r:'ರ',s:'ಸ',t:'ಟ',u:'ು',v:'ವ',w:'ವ',x:'ಕ್ಸ್',y:'ಯ',z:'ಜ'},
    ja:{a:'ア',b:'ブ',c:'ク',d:'ド',e:'エ',f:'フ',g:'グ',h:'ハ',i:'イ',j:'ジ',k:'ク',l:'ル',m:'ム',n:'ン',o:'オ',p:'プ',q:'ク',r:'ル',s:'ス',t:'ト',u:'ウ',v:'ブ',w:'ワ',x:'ックス',y:'イ',z:'ズ'}
  };
  const map = maps[lang];
  if(!map) return word;
  return w.replace(/[a-z]/g, ch => map[ch] || ch);
}
function autoTranslateText(text, lang=currentLang){
  if(!text || lang==='en') return text || '';
  const dict = AUTO_WORD_TRANS[lang] || {};
  const exact = dict[String(text).trim().toUpperCase()];
  if(exact) return exact;
  return String(text).replace(/[A-Za-z]+/g, w => dict[w.toUpperCase()] || transliterateWord(w, lang));
}


// ═══════════════════════════════════════════
// SPEC ITEM + TYPE TRANSLATIONS
// ═══════════════════════════════════════════
const SPEC_ITEM_NAMES = {
  en:{
    'Vin Label':'Vin Label','Wheel Disc':'Wheel Disc','Driver Inner Garnish':'Driver Inner Garnish',
    'Radiator Grill':'Radiator Grill','Back Dr Ctr Garnish':'Back Dr Ctr Garnish',
    'Head Lamp Bezel':'Head Lamp Bezel','Console Ornament':'Console Ornament','IP Garnish':'IP Garnish',
    'Door Trim Fabric Material':'Door Trim Fabric Material','AC Label':'AC Label',
    'Battery Notice Label':'Battery Notice Label','Battery Information Label':'Battery Information Label',
    'Cooling Fan Label':'Cooling Fan Label','Ignition Switch':'Ignition Switch',
    'Console Rear Vent':'Console Rear Vent','Tyre Pressure Label':'Tyre Pressure Label',
    'Fuel Consumption Label':'Fuel Consumption Label','A/C Register Bezel':'A/C Register Bezel',
    'Rear Bumper Lower Garnish':'Rear Bumper Lower Garnish','Overhead Console':'Overhead Console',
    'Fuse Box Cover':'Fuse Box Cover','Seat Material':'Seat Material',
    'Fuel Limitation Label':'Fuel Limitation Label','Quarter Pillar Garnish':'Quarter Pillar Garnish',
    'Key Remote':'Key Remote','Power Window Bezel':'Power Window Bezel',
    'Tweeter Cover':'Tweeter Cover','Battery Cover':'Battery Cover',
    'Front Bumper Lower Garnish':'Front Bumper Lower Garnish','Shift Lever Knob':'Shift Lever Knob',
    'Engine Tag Name Mark':'Engine Tag Name Mark','Rocker Mount':'Rocker Mount'
  },
  hi:{
    'Vin Label':'विन लेबल','Wheel Disc':'व्हील डिस्क','Driver Inner Garnish':'ड्राइवर इनर गार्निश',
    'Radiator Grill':'रेडिएटर ग्रिल','Back Dr Ctr Garnish':'बैक डोर सेंटर गार्निश',
    'Head Lamp Bezel':'हेडलैंप बेज़ल','Console Ornament':'कंसोल ऑर्नामेंट','IP Garnish':'IP गार्निश',
    'Door Trim Fabric Material':'दरवाज़ा ट्रिम फैब्रिक','AC Label':'AC लेबल',
    'Battery Notice Label':'बैटरी नोटिस लेबल','Battery Information Label':'बैटरी जानकारी लेबल',
    'Cooling Fan Label':'कूलिंग फैन लेबल','Ignition Switch':'इग्निशन स्विच',
    'Console Rear Vent':'कंसोल रियर वेंट','Tyre Pressure Label':'टायर प्रेशर लेबल',
    'Fuel Consumption Label':'ईंधन खपत लेबल','A/C Register Bezel':'A/C रजिस्टर बेज़ल',
    'Rear Bumper Lower Garnish':'रियर बम्पर लोअर गार्निश','Overhead Console':'ओवरहेड कंसोल',
    'Fuse Box Cover':'फ्यूज बॉक्स कवर','Seat Material':'सीट सामग्री',
    'Fuel Limitation Label':'ईंधन सीमा लेबल','Quarter Pillar Garnish':'क्वार्टर पिलर गार्निश',
    'Key Remote':'की रिमोट','Power Window Bezel':'पावर विंडो बेज़ल',
    'Tweeter Cover':'ट्वीटर कवर','Battery Cover':'बैटरी कवर',
    'Front Bumper Lower Garnish':'फ्रंट बम्पर लोअर गार्निश','Shift Lever Knob':'शिफ्ट लीवर नॉब',
    'Engine Tag Name Mark':'इंजन टैग नाम मार्क','Rocker Mount':'रॉकर माउंट'
  },
  kn:{
    'Vin Label':'ವಿನ್ ಲೇಬಲ್','Wheel Disc':'ವೀಲ್ ಡಿಸ್ಕ್','Driver Inner Garnish':'ಡ್ರೈವರ್ ಇನ್ನರ್ ಗಾರ್ನಿಷ್',
    'Radiator Grill':'ರೇಡಿಯೇಟರ್ ಗ್ರಿಲ್','Back Dr Ctr Garnish':'ಬ್ಯಾಕ್ ಡೋರ್ ಸೆಂಟರ್ ಗಾರ್ನಿಷ್',
    'Head Lamp Bezel':'ಹೆಡ್‌ಲ್ಯಾಂಪ್ ಬೆಜೆಲ್','Console Ornament':'ಕನ್ಸೋಲ್ ಆಭರಣ','IP Garnish':'IP ಗಾರ್ನಿಷ್',
    'Door Trim Fabric Material':'ಡೋರ್ ಟ್ರಿಮ್ ಫ್ಯಾಬ್ರಿಕ್','AC Label':'AC ಲೇಬಲ್',
    'Battery Notice Label':'ಬ್ಯಾಟರಿ ಸೂಚನಾ ಲೇಬಲ್','Battery Information Label':'ಬ್ಯಾಟರಿ ಮಾಹಿತಿ ಲೇಬಲ್',
    'Cooling Fan Label':'ಕೂಲಿಂಗ್ ಫ್ಯಾನ್ ಲೇಬಲ್','Ignition Switch':'ಇಗ್ನಿಷನ್ ಸ್ವಿಚ್',
    'Console Rear Vent':'ಕನ್ಸೋಲ್ ರಿಯರ್ ವೆಂಟ್','Tyre Pressure Label':'ಟೈರ್ ಒತ್ತಡ ಲೇಬಲ್',
    'Fuel Consumption Label':'ಇಂಧನ ಬಳಕೆ ಲೇಬಲ್','A/C Register Bezel':'A/C ರಿಜಿಸ್ಟರ್ ಬೆಜೆಲ್',
    'Rear Bumper Lower Garnish':'ರಿಯರ್ ಬಂಪರ್ ಲೋವರ್ ಗಾರ್ನಿಷ್','Overhead Console':'ಓವರ್‌ಹೆಡ್ ಕನ್ಸೋಲ್',
    'Fuse Box Cover':'ಫ್ಯೂಸ್ ಬಾಕ್ಸ್ ಕವರ್','Seat Material':'ಸೀಟ್ ವಸ್ತು',
    'Fuel Limitation Label':'ಇಂಧನ ಮಿತಿ ಲೇಬಲ್','Quarter Pillar Garnish':'ಕ್ವಾರ್ಟರ್ ಪಿಲ್ಲರ್ ಗಾರ್ನಿಷ್',
    'Key Remote':'ಕೀ ರಿಮೋಟ್','Power Window Bezel':'ಪವರ್ ವಿಂಡೋ ಬೆಜೆಲ್',
    'Tweeter Cover':'ಟ್ವೀಟರ್ ಕವರ್','Battery Cover':'ಬ್ಯಾಟರಿ ಕವರ್',
    'Front Bumper Lower Garnish':'ಫ್ರಂಟ್ ಬಂಪರ್ ಲೋವರ್ ಗಾರ್ನಿಷ್','Shift Lever Knob':'ಶಿಫ್ಟ್ ಲಿವರ್ ನಾಬ್',
    'Engine Tag Name Mark':'ಎಂಜಿನ್ ಟ್ಯಾಗ್ ಹೆಸರು ಮಾರ್ಕ್','Rocker Mount':'ರಾಕರ್ ಮೌಂಟ್'
  },
  mr:{
    'Vin Label':'व्हिन लेबल','Wheel Disc':'व्हील डिस्क','Driver Inner Garnish':'ड्रायव्हर इनर गार्निश',
    'Radiator Grill':'रेडिएटर ग्रिल','Back Dr Ctr Garnish':'बॅक डोर सेंटर गार्निश',
    'Head Lamp Bezel':'हेडलॅम्प बेझेल','Console Ornament':'कन्सोल अलंकार','IP Garnish':'IP गार्निश',
    'Door Trim Fabric Material':'दरवाजा ट्रिम फॅब्रिक','AC Label':'AC लेबल',
    'Battery Notice Label':'बॅटरी सूचना लेबल','Battery Information Label':'बॅटरी माहिती लेबल',
    'Cooling Fan Label':'कूलिंग फॅन लेबल','Ignition Switch':'इग्निशन स्विच',
    'Console Rear Vent':'कन्सोल रियर व्हेंट','Tyre Pressure Label':'टायर दाब लेबल',
    'Fuel Consumption Label':'इंधन वापर लेबल','A/C Register Bezel':'A/C रजिस्टर बेझेल',
    'Rear Bumper Lower Garnish':'रियर बम्पर लोअर गार्निश','Overhead Console':'ओव्हरहेड कन्सोल',
    'Fuse Box Cover':'फ्यूज बॉक्स कव्हर','Seat Material':'सीट साहित्य',
    'Fuel Limitation Label':'इंधन मर्यादा लेबल','Quarter Pillar Garnish':'क्वार्टर पिलर गार्निश',
    'Key Remote':'की रिमोट','Power Window Bezel':'पॉवर विंडो बेझेल',
    'Tweeter Cover':'ट्वीटर कव्हर','Battery Cover':'बॅटरी कव्हर',
    'Front Bumper Lower Garnish':'फ्रंट बम्पर लोअर गार्निश','Shift Lever Knob':'शिफ्ट लीव्हर नॉब',
    'Engine Tag Name Mark':'इंजिन टॅग नाव मार्क','Rocker Mount':'रॉकर माउंट'
  },
  ja:{
    'Vin Label':'VINラベル','Wheel Disc':'ホイールディスク','Driver Inner Garnish':'ドライバーインナーガーニッシュ',
    'Radiator Grill':'ラジエーターグリル','Back Dr Ctr Garnish':'バックドアセンターガーニッシュ',
    'Head Lamp Bezel':'ヘッドランプベゼル','Console Ornament':'コンソールオーナメント','IP Garnish':'インパネガーニッシュ',
    'Door Trim Fabric Material':'ドアトリム生地','AC Label':'ACラベル',
    'Battery Notice Label':'バッテリー注意ラベル','Battery Information Label':'バッテリー情報ラベル',
    'Cooling Fan Label':'冷却ファンラベル','Ignition Switch':'イグニッションスイッチ',
    'Console Rear Vent':'コンソールリアベント','Tyre Pressure Label':'タイヤ空気圧ラベル',
    'Fuel Consumption Label':'燃費ラベル','A/C Register Bezel':'A/Cレジスターベゼル',
    'Rear Bumper Lower Garnish':'リアバンパーロアガーニッシュ','Overhead Console':'オーバーヘッドコンソール',
    'Fuse Box Cover':'ヒューズボックスカバー','Seat Material':'シート素材',
    'Fuel Limitation Label':'燃料制限ラベル','Quarter Pillar Garnish':'クォーターピラーガーニッシュ',
    'Key Remote':'キーリモコン','Power Window Bezel':'パワーウィンドウベゼル',
    'Tweeter Cover':'ツイーターカバー','Battery Cover':'バッテリーカバー',
    'Front Bumper Lower Garnish':'フロントバンパーロアガーニッシュ','Shift Lever Knob':'シフトレバーノブ',
    'Engine Tag Name Mark':'エンジンタグネームマーク','Rocker Mount':'ロッカーマウント'
  }
};

function tItem(name){ return (SPEC_ITEM_NAMES[currentLang]&&SPEC_ITEM_NAMES[currentLang][name]) || autoTranslateText(name,currentLang) || name; }
function tProcessName(name){ return autoTranslateText(name,currentLang) || name; }
function tAnyText(text){ if(text===undefined||text===null) return ''; const raw=String(text); if(currentLang==='en') return raw; return autoTranslateText(raw,currentLang)||raw; }
function escHtml(s){ return String(s||'').replace(/[&<>"']/g, m=>({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[m])); }
function escJS(s){ return String(s||'').replace(/\\/g,'\\\\').replace(/'/g,"\\'").replace(/"/g,'&quot;'); }
function itemDisplayWithOriginal(name){ const tr=tItem(name); return currentLang==='en'||tr===name ? escHtml(name) : escHtml(tr)+'<span style="display:block;font-size:9px;color:var(--muted);margin-top:1px;">'+escHtml(name)+'</span>'; }
function jtName(ci){ const nm=(typeof ci==='string')?ci:((ci&&ci.name)||''); return tAnyText(nm); }

function attachItemToActiveProcess(itemName){
  if(!activeProcessId) return false;
  const proc = SPEC_PROCESSES.find(p=>p.id===activeProcessId);
  if(!proc) return false;
  if(!Array.isArray(proc.items)) proc.items = [];
  if(!proc.items.some(x=>String(x).toLowerCase()===String(itemName).toLowerCase())) proc.items.push(itemName);
  return true;
}

// Translate SOS method strings
const SOS_METHOD_MAP = {
  'Visual': 'sos_method_visual',
  'Visual + Pull': 'sos_method_pull',
  'Visual + Push': 'sos_method_push',
  'Visual + Touch': 'sos_method_touch',
  'Visual+Touch': 'sos_method_touch',
  'Visual+touch': 'sos_method_touch',
  'Visual + touch': 'sos_method_touch',
  'Function': 'sos_method_function',
  'Operation': 'sos_method_operation',
  'Hear': 'sos_method_hear',
  'Touch + Feel': 'sos_method_touch_feel',
  'Touch + feel': 'sos_method_touch_feel',
  'Push+Hear': 'sos_method_push_hear',
  'Push + Hear': 'sos_method_push_hear',
  'Visual+Scan': 'sos_method_visual_scan',
  'Visual + Scan': 'sos_method_visual_scan',
  'Visual+scan': 'sos_method_visual_scan',
  'Visual + Feel': 'sos_method_visual_feel',
  'Visual+feel': 'sos_method_visual_feel',
  'Visual+Feel': 'sos_method_visual_feel',
  'Visual + Shake': 'sos_method_visual_shake',
  'Visual+Shake': 'sos_method_visual_shake',
  'Visual + Rotate': 'sos_method_visual_rotate',
  'Visual+Rotate': 'sos_method_visual_rotate',
  'Visual +Hear': 'sos_method_visual',
  'Touch + Pull': 'sos_method_pull',
  'Touch + Push': 'sos_method_push',
};
function tSOSMethod(method) {
  if (!method || currentLang === 'en') return method || '—';
  const key = SOS_METHOD_MAP[method] || SOS_METHOD_MAP[method.trim()];
  if (key) return t(key);
  // Try normalizing: "Visual+feel" → "Visual + Feel"
  const norm = method.replace(/\+/g,' + ').replace(/\s+/g,' ').trim();
  const key2 = SOS_METHOD_MAP[norm];
  if (key2) return t(key2);
  // Word-by-word translate using the method word dict
  const methodWordMap = {
    hi:{'Visual':'दृश्य','Pull':'खींचें','Push':'धकेलें','Touch':'स्पर्श','Function':'कार्य','Operation':'संचालन','Hear':'सुनें','Feel':'महसूस','Scan':'स्कैन','Shake':'हिलाएं','Rotate':'घुमाएं'},
    kn:{'Visual':'ದೃಶ್ಯ','Pull':'ಎಳೆಯಿರಿ','Push':'ತಳ್ಳಿರಿ','Touch':'ಸ್ಪರ್ಶ','Function':'ಕ್ರಿಯೆ','Operation':'ಕಾರ್ಯಾಚರಣೆ','Hear':'ಕೇಳಿ','Feel':'ಅನುಭವ','Scan':'ಸ್ಕ್ಯಾನ್','Shake':'ಅಲ್ಲಾಡಿಸಿ','Rotate':'ತಿರುಗಿಸಿ'},
    mr:{'Visual':'दृश्य','Pull':'ओढा','Push':'ढकला','Touch':'स्पर्श','Function':'कार्य','Operation':'संचालन','Hear':'ऐका','Feel':'जाणवा','Scan':'स्कॅन','Shake':'हलवा','Rotate':'फिरवा'},
    ja:{'Visual':'目視','Pull':'引張','Push':'押付','Touch':'触触','Function':'機能','Operation':'操作','Hear':'聴音','Feel':'感触','Scan':'スキャン','Shake':'振動','Rotate':'回転'}
  };
  const wm = methodWordMap[currentLang] || {};
  return method.replace(/\b(\w+)\b/g, w => wm[w] || w);
}

// Translate common SOS check item terms
const SOS_CHECK_TRANS = {
  hi: {
    'Not Allowed':'अनुमति नहीं','Not allowed':'अनुमति नहीं','Missing':'गायब',
    'Half Lock':'हाफ लॉक','Unlocked':'अनलॉक','Coming off':'निकल रहा','Looseness':'ढीलापन',
    'Interference':'हस्तक्षेप','Function':'कार्य','Scan':'स्कैन','Mismatch':'मेल नहीं',
    'Damage':'नुकसान','Wrong part':'गलत पुर्जा','Wrong Color':'गलत रंग',
    'Open':'खोलें','Close':'बंद करें','Insertion':'डालना','Lock Function':'लॉक कार्य',
    'Abnormal noise':'असामान्य शोर','Performance':'प्रदर्शन','Looseness/ Bolt mark miss':'ढीलापन/बोल्ट मार्क गुम',
    'Missing / Extra part':'गायब / अतिरिक्त पुर्जा','Missing / Extra part / Wrong part':'गायब / अतिरिक्त / गलत पुर्जा',
    'Missing / Extra part/ Wrong Color':'गायब / अतिरिक्त / गलत रंग','Missing / Extra part/ Wrong part':'गायब / अतिरिक्त / गलत पुर्जा',
    'Number Mismatch':'नंबर मेल नहीं','Hose mark':'होस मार्क','Operation':'संचालन',
    'Capture':'कैप्चर','Paste':'चिपकाएं','Touching':'स्पर्श','Wrong Part':'गलत पुर्जा',
    'Levelness':'समतलता','Unlock':'अनलॉक','Reverse check &':'रिवर्स जांच और',
    'Lock securely':'सुरक्षित लॉक','Mismatch / Wrong':'मेल नहीं/गलत',
    'Insertion':'सम्मिलन'
  },
  kn: {
    'Not Allowed':'ಅನುಮತಿಸಿಲ್ಲ','Not allowed':'ಅನುಮತಿಸಿಲ್ಲ','Missing':'ಕಾಣೆಯಾಗಿದೆ',
    'Half Lock':'ಅರ್ಧ ಲಾಕ್','Unlocked':'ಅನ್‌ಲಾಕ್','Coming off':'ಬೇರ್ಪಡುತ್ತಿದೆ','Looseness':'ಸಡಿಲ',
    'Interference':'ಹಸ್ತಕ್ಷೇಪ','Function':'ಕಾರ್ಯ','Scan':'ಸ್ಕ್ಯಾನ್','Mismatch':'ಹೊಂದಾಣಿಕೆ ಇಲ್ಲ',
    'Damage':'ಹಾನಿ','Wrong part':'ತಪ್ಪು ಬಿಡಿಭಾಗ','Wrong Color':'ತಪ್ಪು ಬಣ್ಣ',
    'Open':'ತೆರೆಯಿರಿ','Close':'ಮುಚ್ಚಿರಿ','Insertion':'ಸೇರ್ಪಡೆ','Lock Function':'ಲಾಕ್ ಕಾರ್ಯ',
    'Abnormal noise':'ಅಸಾಮಾನ್ಯ ಶಬ್ದ','Performance':'ಕಾರ್ಯಕ್ಷಮತೆ','Looseness/ Bolt mark miss':'ಸಡಿಲ/ಬೋಲ್ಟ್ ಗುರುತು ಇಲ್ಲ',
    'Missing / Extra part':'ಕಾಣೆ / ಹೆಚ್ಚುವರಿ ಭಾಗ','Missing / Extra part / Wrong part':'ಕಾಣೆ / ಹೆಚ್ಚು / ತಪ್ಪು ಭಾಗ',
    'Missing / Extra part/ Wrong Color':'ಕಾಣೆ / ಹೆಚ್ಚು / ತಪ್ಪು ಬಣ್ಣ','Missing / Extra part/ Wrong part':'ಕಾಣೆ / ಹೆಚ್ಚು / ತಪ್ಪು ಭಾಗ',
    'Number Mismatch':'ನಂಬರ್ ಹೊಂದಾಣಿಕೆ ಇಲ್ಲ','Hose mark':'ಹೋಸ್ ಗುರುತು','Operation':'ಕಾರ್ಯಾಚರಣೆ',
    'Capture':'ಕ್ಯಾಪ್ಚರ್','Paste':'ಅಂಟಿಸಿ','Touching':'ಸ್ಪರ್ಶ','Wrong Part':'ತಪ್ಪು ಭಾಗ',
    'Levelness':'ಸಮತಲ','Unlock':'ಅನ್‌ಲಾಕ್','Reverse check &':'ರಿವರ್ಸ್ ಪರಿಶೀಲನೆ',
    'Mismatch / Wrong':'ಹೊಂದಾಣಿಕೆ ಇಲ್ಲ/ತಪ್ಪು'
  },
  mr: {
    'Not Allowed':'परवानगी नाही','Not allowed':'परवानगी नाही','Missing':'हरवले',
    'Half Lock':'अर्धे लॉक','Unlocked':'अनलॉक','Coming off':'निघत आहे','Looseness':'सैलपणा',
    'Interference':'अडथळा','Function':'कार्य','Scan':'स्कॅन','Mismatch':'जुळत नाही',
    'Damage':'नुकसान','Wrong part':'चुकीचा भाग','Wrong Color':'चुकीचा रंग',
    'Open':'उघडा','Close':'बंद करा','Insertion':'घालणे','Lock Function':'लॉक कार्य',
    'Abnormal noise':'असामान्य आवाज','Performance':'कामगिरी','Looseness/ Bolt mark miss':'सैलपणा/बोल्ट खूण नाही',
    'Missing / Extra part':'हरवले / अतिरिक्त भाग','Missing / Extra part / Wrong part':'हरवले / अतिरिक्त / चुकीचा भाग',
    'Missing / Extra part/ Wrong Color':'हरवले / अतिरिक्त / चुकीचा रंग','Missing / Extra part/ Wrong part':'हरवले / अतिरिक्त / चुकीचा भाग',
    'Number Mismatch':'नंबर जुळत नाही','Hose mark':'होज खूण','Operation':'संचालन',
    'Capture':'कॅप्चर','Paste':'चिकटवा','Touching':'स्पर्श','Wrong Part':'चुकीचा भाग',
    'Levelness':'सपाटपणा','Unlock':'अनलॉक','Reverse check &':'रिव्हर्स तपासणी',
    'Mismatch / Wrong':'जुळत नाही/चुकीचे'
  },
  ja: {
    'Not Allowed':'不可','Not allowed':'不可','Missing':'欠品',
    'Half Lock':'半ロック','Unlocked':'未ロック','Coming off':'外れ','Looseness':'緩み',
    'Interference':'干渉','Function':'機能','Scan':'スキャン','Mismatch':'不一致',
    'Damage':'損傷','Wrong part':'誤部品','Wrong Color':'誤色',
    'Open':'開扉','Close':'閉扉','Insertion':'挿入','Lock Function':'ロック機能',
    'Abnormal noise':'異音','Performance':'性能','Looseness/ Bolt mark miss':'緩み/ボルトマーク無し',
    'Missing / Extra part':'欠品/余品','Missing / Extra part / Wrong part':'欠品/余品/誤品',
    'Missing / Extra part/ Wrong Color':'欠品/余品/誤色','Missing / Extra part/ Wrong part':'欠品/余品/誤品',
    'Number Mismatch':'番号不一致','Hose mark':'ホースマーク','Operation':'操作',
    'Capture':'撮影','Paste':'貼付','Touching':'当たり','Wrong Part':'誤部品',
    'Levelness':'面一','Unlock':'解錠','Reverse check &':'リバース確認',
    'Mismatch / Wrong':'不一致/誤り'
  }
};
function tSOSCheck(text) {
  if (!text || currentLang === 'en') return text || '—';
  const map = SOS_CHECK_TRANS[currentLang] || {};
  // Try exact match first
  if (map[text]) return map[text];
  // Try case-insensitive exact match
  const lower = text.toLowerCase();
  for (const [k,v] of Object.entries(map)) {
    if (k.toLowerCase() === lower) return v;
  }
  // Partial key match - find the longest key that's in the text
  let best = '', bestLen = 0;
  for (const [k,v] of Object.entries(map)) {
    if (text.toLowerCase().includes(k.toLowerCase()) && k.length > bestLen) {
      best = v; bestLen = k.length;
    }
  }
  if (best) return best;
  return text;
}

// ═══════════════════════════════════════════
// EDIT HEADLINE & CONTENT
// ═══════════════════════════════════════════
let currentEditId = '';

function editField(id, label) {
  const el = document.getElementById(id);
  if(!el) return;
  const curr = el.textContent;
  const input = document.createElement('input');
  input.className = 'inline-edit-input';
  input.value = curr;
  input.onblur = ()=>{ el.textContent = input.value || curr; el.style.display=''; input.remove(); };
  input.onkeydown = e=>{ if(e.key==='Enter'||e.key==='Escape') input.blur(); };
  el.style.display='none';
  el.parentNode.insertBefore(input, el.nextSibling);
  input.focus();
}

function openEditModal(id, label) {
  currentEditId = id;
  const el = document.getElementById(id);
  document.getElementById('edit-modal-title').textContent = 'Edit: ' + label;
  document.getElementById('edit-field-label').textContent = label;
  document.getElementById('edit-field-input').value = el ? el.textContent : '';
  document.getElementById('edit-modal').classList.add('open');
  setTimeout(()=>document.getElementById('edit-field-input').focus(),100);
}

function closeEditModal() {
  document.getElementById('edit-modal').classList.remove('open');
}

function saveEdit() {
  const val = document.getElementById('edit-field-input').value.trim();
  if(!val) { toast('Text cannot be empty'); return; }
  const el = document.getElementById(currentEditId);
  if(el) el.textContent = val;
  closeEditModal();
  toast('Content updated');
}

// ═══════════════════════════════════════════
// IMAGE-BASED QUIZ — colour swatch renderer
// ═══════════════════════════════════════════
const QUIZ = { questions:[], idx:0, correct:0, answered:false, mode:'', direction:'forward' };

// Generate colour swatches as SVG data URIs
function makeSwatchDataURI(hexColor, label) {
  // Create a canvas-like SVG swatch
  const lightness = parseInt(hexColor.slice(1,3),16)*0.299 +
                    parseInt(hexColor.slice(3,5),16)*0.587 +
                    parseInt(hexColor.slice(5,7),16)*0.114;
  const textColor = lightness > 128 ? '#111111' : '#ffffff';
  const svg = `<svg xmlns='http://www.w3.org/2000/svg' width='200' height='90'><rect width='200' height='90' fill='${hexColor}'/><text x='100' y='52' font-family='Arial' font-size='13' font-weight='bold' fill='${textColor}' text-anchor='middle'>${label}</text></svg>`;
  return 'data:image/svg+xml;base64,' + btoa(unescape(encodeURIComponent(svg)));
}

function buildSpecQuiz(mode) {
  const qs = [];
  const baseMode = mode.replace('_reverse','');
  const pool = baseMode === 'current' && activeSpecItem
    ? [DB.specItems.find(x=>x.name===activeSpecItem)].filter(Boolean)
    : DB.specItems;

  pool.forEach(item => {
    if(item.types.length < 2) return;
    // IMAGE QUIZ: pick a correct type, show swatches/images, user selects the right one
    const correctIdx = Math.floor(Math.random()*item.types.length);
    const correctType = item.types[correctIdx];
    const correctColor = (item.colors && item.colors[correctIdx]) || '#444444';

    // Collect distractor options (other types from same item or other items)
    let distractors = item.types
      .map((tp,i)=>({tp,color:(item.colors&&item.colors[i])||'#444444'}))
      .filter((_,i)=>i!==correctIdx);
    if(distractors.length < 3) {
      // fill from other items of same kind
      DB.specItems.filter(x=>x.name!==item.name).forEach(oth=>{
        oth.types.forEach((tp,i)=>{
          if(!item.types.includes(tp)) distractors.push({tp,color:(oth.colors&&oth.colors[i])||'#444444'});
        });
      });
    }
    distractors = shuffle(distractors).slice(0,3);
    const allOpts = shuffle([{tp:correctType,color:correctColor,isCorrect:true},...distractors.map(d=>({...d,isCorrect:false}))]);

    // Use uploaded image if available, otherwise colour swatch
    const key = specKey(item.name, correctType);
    const img = SPEC_IMAGES[key];

    const correctKey = specKey(item.name, correctType);
    const correctImg = SPEC_IMAGES[correctKey] || makeSwatchDataURI(correctColor, correctType);
    qs.push({
      type:'image',
      direction: mode.includes('reverse') ? 'reverse' : 'forward',
      q: mode.includes('reverse') ? t('quiz_reverse_instruction') : t('quiz_instruction'),
      sub: mode.includes('reverse')
        ? `Item: "${item.name}" — Which type is shown?`
        : `Item: "${item.name}" — Select: ${correctType}`,
      revImg: correctImg,
      revColor: correctColor,
      opts: allOpts.map(o=>{
        const k = specKey(item.name, o.tp);
        const oImg = SPEC_IMAGES[k];
        return {
          label: o.tp,
          color: o.color,
          img: oImg || makeSwatchDataURI(o.color, o.tp),
          isCorrect: o.isCorrect
        };
      }),
      correct: correctType,
      explain: `"${correctType}" is the correct type for "${item.name}".`
    });
  });
  return shuffle(qs).slice(0, Math.min(qs.length, baseMode==='current'?8:20));
}

function getAllOtherTypes(excludeItem) {
  return DB.specItems
    .filter(x=>x.name!==excludeItem.name)
    .flatMap(x=>x.types)
    .filter((v,i,a)=>a.indexOf(v)===i && !excludeItem.types.includes(v));
}

function shuffle(arr) { return [...arr].sort(()=>Math.random()-0.5); }

function openQuiz(mode, direction='forward') {
  QUIZ.mode = mode;
  QUIZ.direction = direction;
  QUIZ.idx = 0;
  QUIZ.correct = 0;
  QUIZ.answered = false;
  // pass direction into buildSpecQuiz so questions know their type
  const buildMode = direction==='reverse' ? mode+'_reverse' : mode;
  QUIZ.questions = buildSpecQuiz(buildMode);
  const icon = direction==='reverse' ? '🔄' : '🧠';
  const dirLabel = direction==='reverse' ? ' (Reverse)' : '';
  document.getElementById('quiz-title').textContent = mode==='current'
    ? `${icon} Quiz — ${activeSpecItem}${dirLabel}`
    : `${icon} Spec Types Quiz — All Items${dirLabel}`;
  if(QUIZ.questions.length===0){toast('Not enough data for quiz');return;}
  document.getElementById('quiz-modal').classList.add('open');
  renderQuizQ();
}

function closeQuiz() { document.getElementById('quiz-modal').classList.remove('open'); }

function renderQuizQ() {
  const q = QUIZ.questions[QUIZ.idx];
  const total = QUIZ.questions.length;
  const pct = (QUIZ.idx/total*100).toFixed(0);
  document.getElementById('quiz-score-display').innerHTML = `Score: <b>${QUIZ.correct}</b>/${QUIZ.idx}`;
  document.getElementById('quiz-next-btn').style.display = 'none';
  document.getElementById('quiz-restart-btn').style.display = 'none';
  QUIZ.answered = false;

  if(q.direction === 'reverse') {
    // REVERSE: Show correct image prominently, user picks type name from text options
    document.getElementById('quiz-body').innerHTML = `
      <div class="quiz-progress">
        <div class="quiz-prog-bar"><div class="quiz-prog-fill" style="width:${pct}%"></div></div>
        <div class="quiz-counter">${QUIZ.idx+1} / ${total}</div>
      </div>
      <div class="quiz-q">${q.q}</div>
      <div class="quiz-q-sub" style="margin-bottom:10px;">${q.sub}</div>
      <div class="quiz-img-block" style="max-height:200px;margin-bottom:16px;background:${q.revColor}20;">
        <img src="${q.revImg}" alt="?" style="max-width:100%;max-height:200px;object-fit:contain;" onerror="this.style.display='none'"/>
      </div>
      <div class="quiz-opts" id="quiz-opts">
        ${q.opts.map((opt,i)=>`
          <button class="quiz-opt" id="qopt-${i}" onclick="selectQuizOpt(${i},'${escQ(opt.label)}','${escQ(q.correct)}')">
            <span style="display:inline-block;width:12px;height:12px;border-radius:50%;background:${opt.color};margin-right:8px;vertical-align:middle;border:1px solid rgba(255,255,255,0.2);"></span>
            ${opt.label}
          </button>`).join('')}
      </div>
      <div id="quiz-feedback" class="quiz-feedback" style="display:none;"></div>
    `;
  } else {
    // FORWARD: Show image options, NO label shown below image
    document.getElementById('quiz-body').innerHTML = `
      <div class="quiz-progress">
        <div class="quiz-prog-bar"><div class="quiz-prog-fill" style="width:${pct}%"></div></div>
        <div class="quiz-counter">${QUIZ.idx+1} / ${total}</div>
      </div>
      <div class="quiz-q">${q.q}</div>
      <div class="quiz-q-sub">${q.sub}</div>
      <div class="quiz-img-opts" id="quiz-opts">
        ${q.opts.map((opt,i)=>`
          <button class="quiz-img-opt" id="qopt-${i}" data-opt-label="${escQ(opt.label)}" onclick="selectQuizOpt(${i},'${escQ(opt.label)}','${escQ(q.correct)}')">
            <div class="quiz-img-block" style="background:${opt.color}20;">
              <img src="${opt.img}" alt="${escQ(opt.label)}" style="width:100%;max-height:130px;object-fit:contain;display:block;" onerror="this.style.display='none'"/>
            </div>
          </button>`).join('')}
      </div>
      <div id="quiz-feedback" class="quiz-feedback" style="display:none;"></div>
    `;
  }
}

function escQ(s){return (s||'').replace(/'/g,"\\'").replace(/"/g,'&quot;');}

function selectQuizOpt(i, chosen, correct) {
  if(QUIZ.answered) return;
  QUIZ.answered = true;
  const isCorrect = chosen === correct;
  if(isCorrect) QUIZ.correct++;

  const q = QUIZ.questions[QUIZ.idx];
  if(q.direction === 'reverse') {
    // Reverse mode: text options
    document.querySelectorAll('.quiz-opt').forEach(btn=>btn.disabled=true);
    document.querySelectorAll('.quiz-opt').forEach((btn)=>{
      // find which option this btn corresponds to
      const lbl = btn.textContent.replace(/^.*●\s*/,'').trim();
      if(lbl === correct) btn.classList.add('reveal');
    });
    document.getElementById('qopt-'+i).classList.remove('reveal');
    document.getElementById('qopt-'+i).classList.add(isCorrect?'correct':'wrong');
  } else {
    // Forward mode: image options — disable and reveal labels
    document.querySelectorAll('.quiz-img-opt').forEach(btn=>btn.disabled=true);
    document.querySelectorAll('.quiz-img-opt').forEach((btn)=>{
      btn.classList.add('show-label');
      if(!btn.querySelector('.quiz-img-label-visible')) {
        const lv = document.createElement('div');
        lv.className = 'quiz-img-label-visible';
        lv.textContent = btn.getAttribute('data-opt-label') || '';
        btn.appendChild(lv);
      }
    });
    document.querySelectorAll('.quiz-img-opt').forEach((btn)=>{
      if(btn.getAttribute('data-opt-label')===correct) btn.classList.add('reveal');
    });
    document.getElementById('qopt-'+i).classList.remove('reveal');
    document.getElementById('qopt-'+i).classList.add(isCorrect?'correct':'wrong');
  }

  const fb = document.getElementById('quiz-feedback');
  fb.style.display = 'block';
  fb.className = 'quiz-feedback '+(isCorrect?'correct':'wrong');
  fb.innerHTML = (isCorrect?'✓ Correct! ':'✗ Incorrect. ')+q.explain;

  document.getElementById('quiz-score-display').innerHTML = `Score: <b>${QUIZ.correct}</b>/${QUIZ.idx+1}`;

  if(QUIZ.idx+1 >= QUIZ.questions.length) {
    document.getElementById('quiz-next-btn').style.display = 'none';
    setTimeout(showQuizResult,1200);
  } else {
    document.getElementById('quiz-next-btn').style.display = '';
  }
}

function quizNext() {
  QUIZ.idx++;
  if(QUIZ.idx >= QUIZ.questions.length) { showQuizResult(); return; }
  renderQuizQ();
}

function showQuizResult() {
  const total = QUIZ.questions.length;
  const pct = Math.round(QUIZ.correct/total*100);
  const grade = pct>=90?'🏆 Excellent!':pct>=70?'✅ Good Job!':pct>=50?'📚 Keep Practicing':'🔁 Review Needed';
  document.getElementById('quiz-body').innerHTML = `
    <div class="quiz-result">
      <div class="quiz-result-score">${QUIZ.correct}/${total}</div>
      <div class="quiz-result-label">${pct}% — ${grade}</div>
      <div class="quiz-result-detail" style="margin-top:16px;">
        ${pct>=70?'Great performance! You have a solid understanding of the spec types.':'Review the spec items and try again to improve your score.'}
      </div>
    </div>`;
  document.getElementById('quiz-next-btn').style.display = 'none';
  document.getElementById('quiz-restart-btn').style.display = '';
  document.getElementById('quiz-score-display').innerHTML = `Final: <b>${QUIZ.correct}</b>/${total}`;
}

function quizRestart() {
  QUIZ.idx = 0;
  QUIZ.correct = 0;
  QUIZ.answered = false;
  const buildMode = QUIZ.direction==='reverse' ? QUIZ.mode+'_reverse' : QUIZ.mode;
  QUIZ.questions = buildSpecQuiz(buildMode);
  renderQuizQ();
}

// ═══════════════════════════════════════════
// SPEC ITEMS
// ═══════════════════════════════════════════
let activeSpecItem = null;

function renderSpecItems(filter='') {
  const list = document.getElementById('spec-items-list');
  const filtered = DB.specItems.filter(it=>{
    const display = tItem(it.name).toLowerCase();
    const orig = it.name.toLowerCase();
    return display.includes(filter.toLowerCase()) || orig.includes(filter.toLowerCase());
  });
  list.innerHTML = filtered.map(it=>{
    const imgCount = it.types.filter(tp=>SPEC_IMAGES[specKey(it.name,tp)]).length;
    return `<div class="spec-item-row${activeSpecItem===it.name?' active':''}" onclick="selectSpecItem('${it.name.replace(/'/g,"\\'")}')">
      <span class="spec-item-name" title="${it.name}">${tItem(it.name)}</span>
      <span class="spec-item-cnt">${it.types.length}t${imgCount?' · '+imgCount+'📷':''}</span>
    </div>`;
  }).join('');
  updateStats();
}

function specKey(item, type){ return (item+'__'+type).replace(/[^a-zA-Z0-9_]/g,'_'); }

function selectSpecItem(name) {
  activeSpecItem = name;
  const it = DB.specItems.find(x=>x.name===name);
  if(!it) return;
  document.getElementById('spec-detail-title').textContent = tItem(it.name);
  document.getElementById('spec-detail-sub').textContent = it.types.length+' types — click image area to upload reference photo';
  document.getElementById('spec-add-type-btn').style.display='';
  document.getElementById('spec-item-quiz-btn').style.display='';
  document.getElementById('spec-item-quiz-rev-btn').style.display='';
  document.getElementById('spec-add-type-row').style.display='none';
  renderSpecTypes(it);
  if(activeProcessId) {
    const proc = SPEC_PROCESSES.find(p => p.id === activeProcessId);
    if(proc) { renderSpecItemsForProcess(proc); return; }
  }
  renderSpecItems(document.getElementById('spec-search')?.value||'');
}

function renderSpecTypes(it) {
  // Type name translations for common terms
  const TYPE_TRANS = {
    hi:{'CHROME':'क्रोम','BLACK':'काला','BROWN':'भूरा','SILVER':'चांदी','PAINTED':'रंगीत','UNPAINTED':'बिना रंग',
        'WITH':'सहित','WITHOUT':'रहित','LEATHER':'चमड़ा','STEEL':'स्टील'},
    kn:{'CHROME':'ಕ್ರೋಮ್','BLACK':'ಕಪ್ಪು','BROWN':'ಕಂದು','SILVER':'ಬೆಳ್ಳಿ','PAINTED':'ಬಣ್ಣ ಹಚ್ಚಿದ','UNPAINTED':'ಬಣ್ಣವಿಲ್ಲದ',
        'WITH':'ಸಹಿತ','WITHOUT':'ರಹಿತ','LEATHER':'ಚರ್ಮ','STEEL':'ಉಕ್ಕು'},
    mr:{'CHROME':'क्रोम','BLACK':'काळा','BROWN':'तपकिरी','SILVER':'चांदी','PAINTED':'रंगवलेले','UNPAINTED':'न रंगवलेले',
        'WITH':'सहित','WITHOUT':'रहित','LEATHER':'चामडे','STEEL':'स्टील'},
    ja:{'CHROME':'クロム','BLACK':'ブラック','BROWN':'ブラウン','SILVER':'シルバー','PAINTED':'塗装','UNPAINTED':'未塗装',
        'WITH':'付き','WITHOUT':'なし','LEATHER':'レザー','STEEL':'スチール'}
  };
  function tType(tp){
    if(currentLang==='en') return '';
    const map=TYPE_TRANS[currentLang]||{};
    // Exact phrase first; otherwise translate every known word automatically.
    if(map[tp]) return map[tp];
    return autoTranslateText(tp,currentLang);
  }
  const wrap = document.getElementById('spec-types-wrap');
  wrap.innerHTML = `<div class="types-grid">${it.types.map((tp,ti)=>{
    const key = specKey(it.name, tp);
    const img = SPEC_IMAGES[key] || '';
    const color = (it.colors && it.colors[ti]) || '#444444';
    const localName = tType(tp);
    return `<div class="type-block" id="tb-${key}">
      <div class="type-hdr" onclick="toggleType('${key}')">
        <div style="display:flex;flex-direction:column;gap:1px;flex:1;min-width:0;">
          <span class="type-name" title="${tp}">${tp}</span>
          ${localName?`<span style="font-size:9px;color:rgba(0,212,255,0.55);font-weight:500;">${localName}</span>`:''}
        </div>
        <div style="display:flex;align-items:center;gap:5px;">
          <span style="font-size:9px;color:${img?'var(--ok)':'var(--muted)'};">${img?'✓':''}</span>
          <button class="sos-del-btn" title="${t('remove_label')}" onclick="event.stopPropagation();deleteSpecType('${escJS(it.name)}','${escJS(tp)}')">✕</button>
        </div>
      </div>
      <div class="type-body" id="tbody-${key}">
        <div class="type-img-area${img?' has-image':''}" onclick="triggerImgUpload('${key}')" id="imgarea-${key}" style="${img?'':'background:'+color+'20;'}">
          <img id="imgel-${key}" src="${img}" alt="" style="${img?'display:block;':'display:none;'}" onload="this.parentElement.classList.add('has-image')"/>
          <div class="type-img-placeholder" id="imgph-${key}" style="${img?'display:none;':'display:flex;flex-direction:column;align-items:center;gap:3px;'}">
            <div style="width:100%;height:52px;background:${color};border-radius:3px;display:flex;align-items:center;justify-content:center;">
              <span style="font-size:8px;font-weight:700;color:${parseInt(color.slice(1,3),16)*0.299+parseInt(color.slice(3,5),16)*0.587+parseInt(color.slice(5,7),16)*0.114>128?'#111':'#fff'};text-align:center;padding:0 4px;">${tp}</span>
            </div>
            <span style="font-size:8px;color:var(--muted);margin-top:2px;">📷 Upload photo</span>
          </div>
        </div>
        <div class="type-img-actions">
          <span class="type-img-label" id="imglbl-${key}" style="font-size:9px;color:var(--muted);">${img?'✓ Photo':'No photo'}</span>
          ${img?`<button class="btn btn-ghost" style="font-size:9px;padding:1px 6px;" onclick="event.stopPropagation();removeTypeImg('${key}')">✕</button>
                 <button class="btn btn-ok" style="font-size:9px;padding:1px 6px;" onclick="event.stopPropagation();viewTypeImg('${key}','${it.name} — ${tp}')">👁</button>`:''}
        </div>
      </div>
      <input type="file" id="fup-${key}" accept="image/*" style="display:none;" onchange="onTypeImgUpload(this,'${key}')"/>
    </div>`;
  }).join('')}</div>`;
}

function toggleType(key) {
  const body = document.getElementById('tbody-'+key);
  if(body) body.style.display = body.style.display==='none'?'':'none';
}
function triggerImgUpload(key) {
  const inp = document.getElementById('fup-'+key);
  if(inp) inp.click();
}
function onTypeImgUpload(inp, key) {
  if(!inp.files[0]) return;
  const r = new FileReader();
  r.onload = e => {
    SPEC_IMAGES[key] = e.target.result;
    const it = DB.specItems.find(x=>activeSpecItem===x.name);
    if(it) renderSpecTypes(it);
    if(activeProcessId){const proc=SPEC_PROCESSES.find(p=>p.id===activeProcessId);if(proc){renderSpecItemsForProcess(proc);}else{renderSpecItems(document.getElementById('spec-search')?.value||'');}}else{renderSpecItems(document.getElementById('spec-search')?.value||'');}
    saveSpecData(true);
    toast('Image uploaded and saved');
  };
  r.readAsDataURL(inp.files[0]);
}
function removeTypeImg(key) {
  delete SPEC_IMAGES[key];
  const it = DB.specItems.find(x=>activeSpecItem===x.name);
  if(it) renderSpecTypes(it);
  if(activeProcessId){const proc=SPEC_PROCESSES.find(p=>p.id===activeProcessId);if(proc){renderSpecItemsForProcess(proc);return;}}
  renderSpecItems();
  saveSpecData(true);
  toast('Image removed and saved');
}
function viewTypeImg(key, caption) {
  const src = SPEC_IMAGES[key];
  if(!src) return;
  document.getElementById('lb-img').src = src;
  document.getElementById('lb-cap').textContent = caption;
  document.getElementById('lb').classList.add('open');
}
function filterSpecItems(v) { renderSpecItems(v); }
function showAddType() {
  document.getElementById('spec-add-type-row').style.display='flex';
  document.getElementById('new-type-name').focus();
}
function hideAddType() {
  document.getElementById('spec-add-type-row').style.display='none';
  document.getElementById('new-type-name').value='';
}

function deleteSpecType(itemName, typeName) {
  const it = DB.specItems.find(x => String(x.name).toLowerCase() === String(itemName).toLowerCase());
  if(!it) return;
  if(!confirm('Remove this spec type?')) return;
  const idx = (it.types || []).findIndex(tp => String(tp).toLowerCase() === String(typeName).toLowerCase());
  if(idx < 0) return;
  const removedType = it.types[idx];
  delete SPEC_IMAGES[specKey(it.name, removedType)];
  it.types.splice(idx, 1);
  if(Array.isArray(it.colors)) it.colors.splice(idx, 1);
  renderSpecTypes(it);
  if(activeProcessId){
    const proc = SPEC_PROCESSES.find(p => p.id === activeProcessId);
    if(proc) renderSpecItemsForProcess(proc);
  } else {
    renderSpecItems(document.getElementById('spec-search')?.value || '');
  }
  saveSpecData(true);
  toast('Spec type removed and saved');
}
function commitAddType() {
  const val = document.getElementById('new-type-name').value.trim().toUpperCase();
  if(!val||!activeSpecItem) return;
  const it = DB.specItems.find(x=>x.name===activeSpecItem);
  if(!it) return;
  if(it.types.includes(val)){toast('Type already exists');return;}
  it.types.push(val);
  if(!it.colors) it.colors = it.types.map(()=>'#666666');
  else it.colors.push('#666666');
  renderSpecTypes(it);
  renderSpecItems();
  saveSpecData(true);
  renderSpecProcesses();
  hideAddType();
  toast('Type "'+val+'" added and auto-translated');
}
function addCheckItem() {
  const val = document.getElementById('new-item-name').value.trim();
  if(!val) return;
  if(DB.specItems.find(x=>x.name.toLowerCase()===val.toLowerCase())){toast('Item already exists');return;}
  const newItem = {name:val,types:[],colors:[]};
  DB.specItems.push(newItem);
  attachItemToActiveProcess(val);
  document.getElementById('new-item-name').value='';
  activeSpecItem = val;
  saveSpecData(true);
  renderSpecProcesses();
  renderSpecItems();
  selectSpecItem(val);
  toast('Item "'+val+'" added, shown and auto-translated');
}


// ═══════════════════════════════════════════
// SPEC PROCESSES DATA
// Process → [spec item names]
// ═══════════════════════════════════════════
const SPEC_PROCESSES = [
  {
    id: 'lh_pit_fit',
    name: 'Lh Pit Fit',
    items: ['Wheel Disc', 'Rocker Mount']
  },
  {
    id: 'rh_pit_fit',
    name: 'Rh Pit Fit',
    items: ['Wheel Disc', 'Vin Label', 'Engine Tag Name Mark', 'Rear Bumper Lower Garnish', 'Rocker Mount', 'Rr Bumper Lower Garnish']
  },
  {
    id: 'lh_fr_int_spec',
    name: 'Lh Fr Int Spec',
    items: ['Tyre Pressure Label', 'Seat Material', 'A/C Register Bezel', 'IP Garnish', 'Console Ornament', 'Driver Inner Garnish', 'Door Trim Fabric Material', 'Overhead Console', 'Power Window Bezel', 'Tweeter Cover', 'Shift Lever Knob']
  },
  {
    id: 'rh_fr_int_spec',
    name: 'Rh Fr Int Spec',
    items: ['Tyre Pressure Label', 'Seat Material', 'A/C Register Bezel', 'IP Garnish', 'Console Ornament', 'Driver Inner Garnish', 'Door Trim Fabric Material', 'Power Window Bezel', 'Tweeter Cover', 'Ignition Switch', 'Key Remote']
  },
  {
    id: 'rh_rr_int_spec',
    name: 'Rh Rr Int Spec',
    items: ['Door Trim Fabric Material', 'Power Window Bezel', 'Quarter Pillar Garnish', 'Console Rear Vent', 'Rocker Mount']
  },
  {
    id: 'lh_rr_int_spec',
    name: 'Lh Rr Int Spec',
    items: ['Door Trim Fabric Material', 'Power Window Bezel', 'Quarter Pillar Garnish', 'Rocker Mount', 'Fuel Consumption Label']
  },
  {
    id: 'backdoor_spec',
    name: 'BackDoor Spec',
    items: ['Back Dr Ctr Garnish']
  },
  {
    id: 'engine_room_spec',
    name: 'Engine Room Spec',
    items: ['Radiator Grill', 'Head Lamp Bezel', 'AC Label', 'Battery Notice Label', 'Battery Information Label', 'Cooling Fan Label', 'Fuse Box Cover', 'Battery Cover', 'Front Bumper Lower Garnish', 'Vin Label']
  }
];

// Map DB item names to process item names (case-insensitive matching)
function findSpecItem(name) {
  const lower = name.toLowerCase();
  return DB.specItems.find(x => x.name.toLowerCase() === lower ||
    x.name.toLowerCase().replace(/[^a-z0-9]/g,'') === lower.replace(/[^a-z0-9]/g,''));
}

let activeProcessId = null;

function renderSpecProcesses() {
  const list = document.getElementById('spec-proc-list');
  const cnt = document.getElementById('spec-proc-count');
  if(!list) return;
  cnt.textContent = SPEC_PROCESSES.length;
  list.innerHTML = SPEC_PROCESSES.map(proc => {
    const itemCount = proc.items.length;
    return `<div class="spec-proc-row${activeProcessId===proc.id?' active':''}" onclick="selectSpecProcess('${proc.id}')">
      <span class="spec-proc-name" title="${proc.name}">${tProcessName(proc.name)}</span>
      <span class="spec-proc-cnt">${itemCount}</span>
      <button class="sos-del-btn" title="Delete process" onclick="event.stopPropagation();deleteSpecProcess('${proc.id}')">✕</button>
    </div>`;
  }).join('');
}

function addSpecProcess(){
  const inp=document.getElementById('new-process-name');
  const name=(inp&&inp.value||'').trim();
  if(!name){toast('Enter process name');return;}
  if(SPEC_PROCESSES.some(p=>p.name.toLowerCase()===name.toLowerCase())){toast('Process already exists');return;}
  const id='proc_'+Date.now();
  SPEC_PROCESSES.push({id,name,items:[]});
  if(inp) inp.value='';
  activeProcessId=id;
  saveSpecData(true);
  renderSpecProcesses();
  selectSpecProcess(id);
  toast('Process added, translated and saved');
}
function deleteSpecProcess(procId){
  if(!confirm('Delete this process? Items will not be deleted.')) return;
  const idx=SPEC_PROCESSES.findIndex(p=>p.id===procId);
  if(idx>=0) SPEC_PROCESSES.splice(idx,1);
  if(activeProcessId===procId) activeProcessId=null;
  saveSpecData(true); renderSpecProcesses(); renderSpecItems(); toast('Process deleted and saved');
}

function selectSpecProcess(procId) {
  activeProcessId = procId;
  activeSpecItem = null;
  const proc = SPEC_PROCESSES.find(p => p.id === procId);
  renderSpecProcesses();
  // Show process items in items panel
  renderSpecItemsForProcess(proc);
  // Clear types panel
  const wrap = document.getElementById('spec-types-wrap');
  if(wrap) wrap.innerHTML = `<div class="spec-empty"><svg width="32" height="32" fill="none" stroke="rgba(0,212,255,0.2)" stroke-width="1.5" viewBox="0 0 24 24"><rect x="2" y="3" width="20" height="14" rx="2"/><line x1="8" y1="21" x2="16" y2="21"/><line x1="12" y1="17" x2="12" y2="21"/></svg><span>Select a spec item to view types</span></div>`;
  document.getElementById('spec-detail-title').textContent = '← Select an item';
  document.getElementById('spec-detail-sub').textContent = 'Click any item to view spec types';
  document.getElementById('spec-item-quiz-btn').style.display = 'none';
  document.getElementById('spec-item-quiz-rev-btn').style.display = 'none';
  document.getElementById('spec-add-type-btn').style.display = 'none';
  document.getElementById('spec-add-type-row').style.display = 'none';
  // Show process quiz buttons
  document.getElementById('spec-quiz-all-btn').style.display = '';
  document.getElementById('spec-quiz-rev-btn').style.display = '';
  // Update quiz labels to reflect the process
  document.getElementById('spec-quiz-all-btn').innerHTML = '🧠 Quiz — ' + tProcessName(proc.name);
  document.getElementById('spec-quiz-rev-btn').innerHTML = '🔄 Reverse — ' + tProcessName(proc.name);
}

function renderSpecItemsForProcess(proc) {
  const list = document.getElementById('spec-items-list');
  const totalEl = document.getElementById('spec-item-total');
  if(!list) return;
  const items = proc ? proc.items.map(name => findSpecItem(name)).filter(Boolean) : DB.specItems;
  if(totalEl) totalEl.textContent = items.length + ' ' + t('items_label');
  list.innerHTML = items.map(it => {
    const imgCount = it.types.filter(tp=>SPEC_IMAGES[specKey(it.name,tp)]).length;
    return `<div class="spec-item-row${activeSpecItem===it.name?' active':''}" onclick="selectSpecItem('${escJS(it.name)}')">
      <span class="spec-item-name" title="${escHtml(it.name)}">${itemDisplayWithOriginal(it.name)}</span>
      <span class="spec-item-cnt">${it.types.length}t${imgCount?' · '+imgCount+'📷':''}</span>
      <button class="spec-del-item-btn" title="${t('delete_label')}" onclick="event.stopPropagation();deleteSpecItem('${escJS(it.name)}')">✕</button>
    </div>`;
  }).join('');
}
function deleteSpecItem(name){
  if(!confirm(t('spec_delete_item_confirm'))) return;
  const idx=DB.specItems.findIndex(x=>x.name.toLowerCase()===String(name).toLowerCase());
  if(idx<0) return;
  const item=DB.specItems[idx]; (item.types||[]).forEach(tp=>{ delete SPEC_IMAGES[specKey(item.name,tp)]; });
  DB.specItems.splice(idx,1); SPEC_PROCESSES.forEach(p=>{ if(Array.isArray(p.items)) p.items=p.items.filter(n=>String(n).toLowerCase()!==String(name).toLowerCase()); });
  if(activeSpecItem===name) activeSpecItem=null;
  saveSpecData(true); renderSpecProcesses(); renderSpecItems(document.getElementById('spec-search')?.value||'');
  const wrap=document.getElementById('spec-types-wrap'); if(wrap) wrap.innerHTML=`<div class="spec-empty"><span>${t('spec_empty')}</span></div>`;
  toast(t('remove_label')+' ✓');
}

// Override renderSpecItems to respect active process// Override renderSpecItems to respect active process
const _origRenderSpecItems = renderSpecItems;
function renderSpecItems(filter) {
  if(activeProcessId) { const proc = SPEC_PROCESSES.find(p => p.id === activeProcessId); if(proc) { renderSpecItemsForProcess(proc); return; } }
  const list = document.getElementById('spec-items-list'); const totalEl = document.getElementById('spec-item-total'); if(!list) return;
  const f=(filter||'').toLowerCase();
  const filtered=DB.specItems.filter(it=>tItem(it.name).toLowerCase().includes(f)||it.name.toLowerCase().includes(f));
  if(totalEl) totalEl.textContent=filtered.length+' '+t('items_label');
  list.innerHTML=filtered.map(it=>{ const imgCount=it.types.filter(tp=>SPEC_IMAGES[specKey(it.name,tp)]).length; return `<div class="spec-item-row${activeSpecItem===it.name?' active':''}" onclick="selectSpecItem('${escJS(it.name)}')"><span class="spec-item-name" title="${escHtml(it.name)}">${itemDisplayWithOriginal(it.name)}</span><span class="spec-item-cnt">${it.types.length}t${imgCount?' · '+imgCount+'📷':''}</span><button class="spec-del-item-btn" title="${t('delete_label')}" onclick="event.stopPropagation();deleteSpecItem('${escJS(it.name)}')">✕</button></div>`; }).join('');
  updateStats();
}

// Process-level quiz: quiz all items in the active process// Process-level quiz: quiz all items in the active process
function openProcessQuiz(mode, direction) {
  if(!activeProcessId && mode==='all') {
    toast('Select a process first');
    return;
  }
  QUIZ.mode = 'process';
  QUIZ.direction = direction;
  QUIZ.idx = 0;
  QUIZ.correct = 0;
  QUIZ.answered = false;
  const proc = SPEC_PROCESSES.find(p => p.id === activeProcessId);
  const procItems = proc ? proc.items.map(name => findSpecItem(name)).filter(Boolean) : DB.specItems;
  const buildMode = direction === 'reverse' ? 'process_reverse' : 'process';
  QUIZ.questions = buildProcessQuiz(procItems, direction);
  const icon = direction==='reverse' ? '🔄' : '🧠';
  const procName = proc ? tProcessName(proc.name) : 'All Items';
  document.getElementById('quiz-title').textContent = icon + ' Quiz — ' + procName;
  if(QUIZ.questions.length === 0) { toast('Not enough data for quiz'); return; }
  document.getElementById('quiz-modal').classList.add('open');
  renderQuizQ();
}

function buildProcessQuiz(itemsPool, direction) {
  const qs = [];
  itemsPool.forEach(item => {
    if(!item || item.types.length < 2) return;
    const correctIdx = Math.floor(Math.random() * item.types.length);
    const correctType = item.types[correctIdx];
    const correctColor = (item.colors && item.colors[correctIdx]) || '#444444';
    let distractors = item.types
      .map((tp, i) => ({tp, color: (item.colors && item.colors[i]) || '#444444'}))
      .filter((_, i) => i !== correctIdx);
    if(distractors.length < 3) {
      DB.specItems.filter(x => x.name !== item.name).forEach(oth => {
        oth.types.forEach((tp, i) => {
          if(!item.types.includes(tp)) distractors.push({tp, color: (oth.colors && oth.colors[i]) || '#444444'});
        });
      });
    }
    distractors = shuffle(distractors).slice(0, 3);
    const allOpts = shuffle([{tp: correctType, color: correctColor, isCorrect: true}, ...distractors.map(d => ({...d, isCorrect: false}))]);
    const correctKey = specKey(item.name, correctType);
    const correctImg = SPEC_IMAGES[correctKey] || makeSwatchDataURI(correctColor, correctType);
    qs.push({
      type: 'image',
      direction: direction,
      q: direction === 'reverse' ? t('quiz_reverse_instruction') : t('quiz_instruction'),
      sub: direction === 'reverse'
        ? 'Item: "' + item.name + '" — Which type is shown?'
        : 'Item: "' + item.name + '" — Select: ' + correctType,
      revImg: correctImg,
      revColor: correctColor,
      opts: allOpts.map(o => {
        const k = specKey(item.name, o.tp);
        const oImg = SPEC_IMAGES[k];
        return {
          label: o.tp,
          color: o.color,
          img: oImg || makeSwatchDataURI(o.color, o.tp),
          isCorrect: o.isCorrect
        };
      }),
      correct: correctType,
      explain: '"' + correctType + '" is the correct type for "' + item.name + '".'
    });
  });
  return shuffle(qs).slice(0, Math.min(qs.length, itemsPool.length <= 4 ? qs.length : 15));
}

// ═══════════════════════════════════════════
// RENDER ALL
// ═══════════════════════════════════════════
function renderAll() {
  renderPL('safety'); renderPL('quality');
  renderGrid('safety'); renderGrid('quality');
  renderSpecItems();
  renderSpecProcesses();
  updateStats();
}

function updateStats() {
  const specCount = DB.specItems.length;
  document.getElementById('ds-sv').textContent = DB.safetyVideos.length;
  document.getElementById('ds-qv').textContent = DB.qualityVideos.length;
  document.getElementById('ds-sp').textContent = specCount;
  document.getElementById('sb-sv').textContent = DB.safetyVideos.length;
  document.getElementById('sb-qv').textContent = DB.qualityVideos.length;
  document.getElementById('sb-sp').textContent = specCount;
  document.getElementById('spec-item-total').textContent = specCount+' items';
}

// ═══════════════════════════════════════════
// PLAYLIST ENGINE
// ═══════════════════════════════════════════
const PL = {safety:{idx:-1,playing:false},quality:{idx:-1,playing:false}};
const SIM = {};

function getVids(t){return t==='safety'?DB.safetyVideos:DB.qualityVideos;}
function getVEl(t){return document.getElementById(t+'-vel');}

function renderPL(t) {
  const vids=getVids(t);
  document.getElementById(t+'-plcount').textContent=vids.length;
  document.getElementById(t+'-pllist').innerHTML=vids.map((v,i)=>`
    <div class="pl-item${PL[t].idx===i?' playing':''}" id="pli-${t}-${i}" onclick="playAt(${i},'${t}')">
      <div class="pl-num">${PL[t].idx===i?'▶':i+1}</div>
      <div class="pl-info"><div class="pl-t">${v.title}</div><div class="pl-m">${v.date}</div></div>
      <span class="pl-d">${v.duration}</span>
      ${v.mandatory?'<div class="mandatory-dot" title="Mandatory"></div>':''}
    </div>`).join('');
}

function renderGrid(t) {
  const vids=getVids(t);
  const cntEl=document.getElementById(t+'-gcnt');
  if(cntEl) cntEl.textContent=vids.length+' video'+(vids.length!==1?'s':'');
  document.getElementById(t+'-grid').innerHTML=vids.map((v,i)=>`
    <div class="vcard${PL[t].idx===i?' ql':''}" id="vc-${v.id}">
      <div class="vthumb" onclick="playAt(${i},'${t}')">
        <div class="vplay"><svg width="14" height="14" fill="white" viewBox="0 0 24 24"><polygon points="5 3 19 12 5 21 5 3"/></svg></div>
        <span class="vdur">${v.duration}</span>
        <span class="vcat ${t}">${t==='safety'?'Safety':'Quality'}</span>
        ${v.mandatory?'<span class="vmand">MANDATORY</span>':''}
      </div>
      <div class="vinfo"><div class="vtitle">${v.title}</div><div class="vmeta"><span>${v.duration}</span><span>${v.date}</span></div></div>
      <div class="vactions">
        <button class="btn btn-ok" style="flex:1;font-size:10px;padding:4px 8px;" onclick="playAt(${i},'${t}')">▶ Play</button>
        <button class="btn btn-ghost" style="font-size:10px;padding:4px 7px;" onclick="event.stopPropagation();delVideo('${v.id}','${t}')">🗑</button>
      </div>
    </div>`).join('');
}

function playAt(i, t) {
  const vids=getVids(t);
  if(i<0||i>=vids.length) return;
  PL[t].idx=i; PL[t].playing=true;
  const v=vids[i];
  const vel=getVEl(t);
  const idle=document.getElementById(t+'-idle');
  const accentClr=t==='safety'?'var(--accent)':'var(--info)';
  document.getElementById(t+'-ptitle').textContent=v.title;
  document.getElementById(t+'-pmeta').textContent=v.date+' · '+v.duration+(v.mandatory?' · MANDATORY':'');
  document.getElementById(t+'-plcnt').textContent=(i+1)+' / '+vids.length;
  document.getElementById(t+'-prev').disabled=i===0;
  document.getElementById(t+'-next').disabled=i===vids.length-1;
  const btn=document.getElementById(t+'-pabtn');
  btn.classList.add('playing');
  btn.querySelector('span').textContent='Pause';
  clearInterval(SIM[t]);
  if(v.src&&(v.local||v.src.startsWith('http'))){
    idle.style.display='none'; vel.style.display='block';
    vel.src=v.src; vel.load(); vel.play().catch(()=>{});
    vel.onended=()=>autoNext(t);
    vel.ontimeupdate=()=>updateProg(t);
  } else {
    vel.pause(); vel.src=''; vel.style.display='none'; idle.style.display='flex';
    idle.innerHTML=`<div class="idle-icon" style="${t==='quality'?'background:rgba(0,153,255,0.1);border-color:rgba(0,153,255,0.25);':''}">
      <svg width="20" height="20" fill="${accentClr}" viewBox="0 0 24 24"><polygon points="5 3 19 12 5 21 5 3"/></svg></div>
      <div style="font-size:13px;font-weight:600;color:#e6f1ff;text-align:center;max-width:260px;">${v.title}</div>
      <div style="font-size:10px;color:var(--muted);">${v.duration} · ${v.date}</div>
      <div style="font-size:11px;color:var(--muted);max-width:280px;text-align:center;line-height:1.5;">${v.desc}</div>`;
    simProg(t, v.duration);
  }
  renderPL(t); renderGrid(t);
  setTimeout(()=>{const el=document.getElementById('pli-'+t+'-'+i);if(el)el.scrollIntoView({block:'nearest',behavior:'smooth'});},100);
}

function autoNext(t){const n=PL[t].idx+1;if(n<getVids(t).length){setTimeout(()=>playAt(n,t),700);}else{plStop(t);toast('Playlist complete!');}}
function playAll(t){if(PL[t].playing){plStop(t);}else{playAt(0,t);}}
function plNext(t){if(PL[t].idx<getVids(t).length-1)playAt(PL[t].idx+1,t);}
function plPrev(t){if(PL[t].idx>0)playAt(PL[t].idx-1,t);}

function plStop(t){
  PL[t].playing=false; PL[t].idx=-1;
  clearInterval(SIM[t]);
  const vel=getVEl(t); vel.pause(); vel.src=''; vel.style.display='none';
  const idle=document.getElementById(t+'-idle');
  idle.style.display='flex';
  const c=t==='safety'?'var(--accent)':'var(--info)';
  idle.innerHTML=`<div class="idle-icon" style="${t==='quality'?'background:rgba(0,153,255,0.1);border-color:rgba(0,153,255,0.25);':''}">
    <svg width="20" height="20" fill="${c}" viewBox="0 0 24 24"><polygon points="5 3 19 12 5 21 5 3"/></svg></div>
    <div style="font-size:13px;color:${c};font-weight:600;">${t==='safety'?'Safety':'Quality'} Training Playlist</div>
    <div style="font-size:10px;color:var(--muted);">Press Play All or click a video</div>`;
  document.getElementById(t+'-ptitle').textContent='— No video selected —';
  document.getElementById(t+'-pmeta').textContent='Select a video or press Play All to begin';
  document.getElementById(t+'-plcnt').textContent='';
  document.getElementById(t+'-prev').disabled=true;
  document.getElementById(t+'-next').disabled=true;
  const btn=document.getElementById(t+'-pabtn');
  btn.classList.remove('playing');
  btn.querySelector('span').textContent=t('play_all');
  document.getElementById(t+'-prog').style.width='0%';
  document.getElementById(t+'-tcur').textContent='0:00';
  document.getElementById(t+'-ttot').textContent='0:00';
  renderPL(t); renderGrid(t);
}

function updateProg(t){const vel=getVEl(t);if(!vel.duration)return;const pct=(vel.currentTime/vel.duration)*100;document.getElementById(t+'-prog').style.width=pct+'%';document.getElementById(t+'-tcur').textContent=fmt(vel.currentTime);document.getElementById(t+'-ttot').textContent=fmt(vel.duration);}
function simProg(t,durStr){clearInterval(SIM[t]);const parts=durStr.split(':').map(Number);const total=parts[0]*60+(parts[1]||0);let cur=0;document.getElementById(t+'-ttot').textContent=fmt(total);SIM[t]=setInterval(()=>{cur+=2;if(cur>total){clearInterval(SIM[t]);return;}document.getElementById(t+'-prog').style.width=(cur/total*100)+'%';document.getElementById(t+'-tcur').textContent=fmt(cur);},2000);}
function seekVid(t,e){const vel=getVEl(t);if(!vel.duration)return;const r=e.currentTarget.getBoundingClientRect();vel.currentTime=((e.clientX-r.left)/r.width)*vel.duration;}
function fmt(s){s=Math.floor(s);return Math.floor(s/60)+':'+String(s%60).padStart(2,'0');}
function filterGrid(t,q){document.getElementById(t+'-grid').querySelectorAll('.vcard').forEach(c=>{c.style.display=c.querySelector('.vtitle').textContent.toLowerCase().includes(q.toLowerCase())?'':'none';});}
function delVideo(id,t){if(!confirm('Remove this video?'))return;if(t==='safety')DB.safetyVideos=DB.safetyVideos.filter(v=>v.id!==id);else DB.qualityVideos=DB.qualityVideos.filter(v=>v.id!==id);if(PL[t].playing)plStop(t);saveVideoData(true);renderAll();toast('Video removed and saved');}

// ═══════════════════════════════════════════
// ADD MODAL
// ═══════════════════════════════════════════
let addType='';
function openModal(type){
  addType=type;
  const titles={video:'Add New Video','safety-video':'Add Safety Video','quality-video':'Add Quality Video',file:'Upload Reference File',additem:'Add Check Item'};
  document.getElementById('am-title').textContent=titles[type]||'Add Content';
  const f=document.getElementById('am-form');
  if(type.includes('video')){
    f.innerHTML=`
      <div class="form-row"><label class="flbl">Title</label><input class="finput" id="f-title" placeholder="Video title"/></div>
      <div class="form-row2">
        <div class="form-row"><label class="flbl">Category</label><select class="fselect" id="f-cat"><option value="safety">Safety</option><option value="quality">Quality</option></select></div>
        <div class="form-row"><label class="flbl">Duration</label><input class="finput" id="f-dur" placeholder="5:30"/></div>
      </div>
      <div class="form-row"><label class="flbl">Description</label><textarea class="ftarea" id="f-desc" placeholder="Brief description..."></textarea></div>
      <div class="form-row"><label class="flbl">Upload Video or Paste URL</label>
        <div class="upload-zone" onclick="document.getElementById('f-file').click()">⬆ Click to upload MP4, MOV, AVI</div>
        <input type="file" id="f-file" accept="video/*" style="display:none" onchange="onFC(this,'f-fn')"/>
        <div id="f-fn" style="font-size:10px;color:var(--ok);margin-top:4px;"></div>
        <input class="finput" id="f-url" placeholder="or paste https://..." style="margin-top:6px;"/>
      </div>
      <div class="form-row"><label style="display:flex;align-items:center;gap:6px;font-size:11px;color:var(--muted);cursor:pointer;"><input type="checkbox" id="f-mand" style="width:auto;accent-color:var(--accent);"/> Mark as Mandatory</label></div>`;
  } else if(type==='additem'){
    f.innerHTML=`<div class="form-row"><label class="flbl">Check Item Name</label><input class="finput" id="f-title" placeholder="e.g. Door Handle Bezel"/></div>
      <div class="form-row"><label class="flbl">Initial Types (comma separated)</label><input class="finput" id="f-types" placeholder="e.g. CHROME, BLACK, SILVER"/></div>`;
  }
  document.getElementById('add-modal').classList.add('open');
}
function closeModal(){document.getElementById('add-modal').classList.remove('open');}
function onFC(inp,targetId){if(inp.files[0])document.getElementById(targetId).textContent='✓ '+inp.files[0].name;}
function handleAdd(){
  const title=document.getElementById('f-title')?.value.trim();
  if(!title){toast('Please enter a title');return;}
  if(addType.includes('video')){
    const cat=document.getElementById('f-cat').value;
    const dur=document.getElementById('f-dur')?.value||'0:00';
    const desc=document.getElementById('f-desc')?.value||'';
    const fi=document.getElementById('f-file');const url=document.getElementById('f-url')?.value||'';
    const mand=document.getElementById('f-mand')?.checked||false;
    const addVideoRecord = (src, local) => { const v={id:'v'+Date.now(),title,duration:dur,cat,desc,src,local,date:new Date().toISOString().slice(0,10),mandatory:mand}; if(cat==='safety')DB.safetyVideos.push(v);else DB.qualityVideos.push(v); saveVideoData(true); renderAll(); closeModal(); toast('Video added and saved'); };
    if(fi&&fi.files[0]){ const r = new FileReader(); r.onload = e => addVideoRecord(e.target.result, true); r.onerror = () => toast('Video upload failed'); r.readAsDataURL(fi.files[0]); return; }
    else if(url) addVideoRecord(url, false);
    else { toast('Upload a video or paste URL'); return; }
  }else if(addType==='additem'){
    if(DB.specItems.find(x=>x.name.toLowerCase()===title.toLowerCase())){toast('Item already exists');return;}
    const typesRaw=document.getElementById('f-types')?.value||'';
    const types=typesRaw.split(',').map(t=>t.trim().toUpperCase()).filter(Boolean);
    DB.specItems.push({name:title,types,colors:types.map(()=>'#666666')});
    attachItemToActiveProcess(title);
    activeSpecItem = title;
    saveSpecData(true);
    renderSpecProcesses();
    renderSpecItems();
    selectSpecItem(title);
    toast('Item added, shown and auto-translated');
  }
  closeModal();
}

// ═══════════════════════════════════════════
// NAVIGATION
// ═══════════════════════════════════════════
function showSec(id, el) {
  document.querySelectorAll('.sec-page').forEach(s=>s.classList.remove('active'));
  document.querySelectorAll('.sb-item').forEach(s=>s.classList.remove('active'));
  document.getElementById('sec-'+id).classList.add('active');
  if(el) el.classList.add('active');
  document.querySelectorAll('#topNav .nav-btn').forEach(b=>b.classList.toggle('active',b.dataset.sec===id));
  if(id==='inspect') { setTimeout(()=>{nd();nc();ni_sim();nl_sim();},100); }
}

document.querySelectorAll('#topNav .nav-btn').forEach(btn=>{
  btn.addEventListener('click',function(){
    const id=this.dataset.sec;
    document.querySelectorAll('.sec-page').forEach(s=>s.classList.remove('active'));
    document.querySelectorAll('#topNav .nav-btn').forEach(b=>b.classList.remove('active'));
    document.querySelectorAll('.sb-item').forEach(s=>s.classList.remove('active'));
    document.getElementById('sec-'+id).classList.add('active');
    this.classList.add('active');
    if(id==='inspect') setTimeout(()=>{nd();nc();ni_sim();nl_sim();},100);
  });
});

// ═══════════════════════════════════════════
// LIGHTBOX / CLOSE / TOAST
// ═══════════════════════════════════════════
function closeLb(){document.getElementById('lb').classList.remove('open');}
document.getElementById('add-modal').addEventListener('click',e=>{if(e.target===e.currentTarget)closeModal();});
document.getElementById('edit-modal').addEventListener('click',e=>{if(e.target===e.currentTarget)closeEditModal();});
document.getElementById('lb').addEventListener('click',e=>{if(e.target===e.currentTarget)closeLb();});
document.getElementById('quiz-modal').addEventListener('click',e=>{if(e.target===e.currentTarget)closeQuiz();});
document.addEventListener('keydown',e=>{if(e.key==='Escape'){closeModal();closeEditModal();closeLb();closeQuiz();}});
function toast(msg){const t=document.getElementById('toast');document.getElementById('toast-msg').textContent=msg;t.classList.add('show');clearTimeout(t._t);t._t=setTimeout(()=>t.classList.remove('show'),3200);}

// ═══════════════════════════════════════════
// CLOCK
// ═══════════════════════════════════════════
function tickClock(){const n=new Date();document.getElementById('tDate').textContent=n.toLocaleDateString('en-GB',{day:'2-digit',month:'short',year:'numeric'});document.getElementById('tTime').textContent=n.toLocaleTimeString('en-GB',{hour:'2-digit',minute:'2-digit',second:'2-digit'});}
tickClock();setInterval(tickClock,1000);

// ═══════════════════════════════════════════
// INSPECTPRO ENGINE
// ═══════════════════════════════════════════
// INSPECTPRO — stable simulator calibration
// Fixed-size training canvas. This avoids browser/DPI/zoom issues that can make
// the InspectPro simulator appear blank or make answer checking inaccurate.
const CANVAS_W_PX = 760;
const CANVAS_H_PX = 420;
let PX = 8; // simulator pixels per mm

// roundRect fallback for older embedded browsers
if (window.CanvasRenderingContext2D && !CanvasRenderingContext2D.prototype.roundRect) {
  CanvasRenderingContext2D.prototype.roundRect = function(x, y, w, h, r) {
    if (Array.isArray(r)) r = Math.max.apply(null, r);
    r = Math.min(Number(r) || 0, Math.abs(w) / 2, Math.abs(h) / 2);
    this.beginPath();
    this.moveTo(x + r, y);
    this.lineTo(x + w - r, y);
    this.quadraticCurveTo(x + w, y, x + w, y + r);
    this.lineTo(x + w, y + h - r);
    this.quadraticCurveTo(x + w, y + h, x + w - r, y + h);
    this.lineTo(x + r, y + h);
    this.quadraticCurveTo(x, y + h, x, y + h - r);
    this.lineTo(x, y + r);
    this.quadraticCurveTo(x, y, x + r, y);
    return this;
  };
}

function initCanvas(id){
  const cv=document.getElementById(id); if(!cv) return;
  cv.width = CANVAS_W_PX;
  cv.height = CANVAS_H_PX;
  cv.style.width = '100%';
  cv.style.maxWidth = CANVAS_W_PX + 'px';
  cv.style.height = 'auto';
  cv.style.display = 'block';
}

function initAllCanvases(){
  ['cDoor','cClip','cInsert','cLevel'].forEach(initCanvas);
}
const SC={door:[0,0],clip:[0,0],insert:[0,0],level:[0,0]};
let DS={},CS={},IS={},LS={};

function iswitch(id,el){
  document.querySelectorAll('.ipt-pane').forEach(p=>p.classList.remove('on'));
  document.querySelectorAll('.ipt-ni').forEach(n=>n.classList.remove('on'));
  document.getElementById('pane-'+id).classList.add('on');
  el.classList.add('on');
}
function ith(id){document.getElementById(id).classList.toggle('show');}
function irnd(a,b,s){s=s||1;return+(a+Math.round(Math.random()*(b-a)/s)*s).toFixed(s<1?1:0);}
function iclr(p){const a=document.getElementById(p+'-ans');if(a)a.value='';const fb=document.getElementById(p+'-fb');if(fb)fb.className='ipt-fb';}
function iUpdG(){
  const att=SC.door[1]+SC.clip[1]+SC.insert[1]+SC.level[1];
  const cor=SC.door[0]+SC.clip[0]+SC.insert[0]+SC.level[0];
  document.getElementById('tot-att').textContent=att;
  document.getElementById('tot-cor').textContent=cor;
  document.getElementById('tot-acc').textContent=att>0?Math.round(cor/att*100)+'%':'—';
  ['door','clip','insert','level'].forEach(m=>document.getElementById('nb-'+m).textContent=SC[m][0]+'/'+SC[m][1]);
}

function nd(){DS={gap:irnd(2,9,0.5)};paintDoor();iclr('d');}

function paintDoor(){
  const cv=document.getElementById('cDoor');if(!cv)return;
  const W=cv.width,H=cv.height,ctx=cv.getContext('2d');
  ctx.clearRect(0,0,W,H);ctx.fillStyle='#000';ctx.fillRect(0,0,W,H);
  const gMM=DS.gap,gPx=Math.round(gMM*PX),CX=W/2;
  const TOP=50,BOT=H-58,DH=BOT-TOP,FW=228,RW=188;
  const fX=CX-FW-gPx/2,rX=CX+gPx/2;
  function fillPaint(ctx,left,top,w,h){const g=ctx.createLinearGradient(left,top,left+w,top);g.addColorStop(0,'#b2b8c4');g.addColorStop(0.35,'#dce0ec');g.addColorStop(0.55,'#e4e8f2');g.addColorStop(1,'#b0b4c0');return g;}
  function shadePaint(ctx,x,y,w,h){const g=ctx.createLinearGradient(x,y,x,y+h);g.addColorStop(0,'rgba(255,255,255,0.15)');g.addColorStop(1,'rgba(0,0,0,0.22)');return g;}
  ;(()=>{const x=fX,w=FW,hingePad=48,bT=TOP+DH*0.415;
    ctx.save();ctx.beginPath();ctx.moveTo(x+12,BOT);ctx.lineTo(x+w,BOT);ctx.lineTo(x+w,TOP);ctx.lineTo(x+hingePad+10,TOP);ctx.quadraticCurveTo(x+hingePad-4,TOP+4,x+hingePad-8,TOP+18);ctx.lineTo(x+7,TOP+44);ctx.quadraticCurveTo(x,TOP+58,x,TOP+76);ctx.lineTo(x,BOT-12);ctx.quadraticCurveTo(x,BOT,x+12,BOT);ctx.closePath();
    ctx.fillStyle=fillPaint(ctx,x,TOP,w,DH);ctx.fill();ctx.fillStyle=shadePaint(ctx,x,TOP,w,DH);ctx.fill();ctx.strokeStyle='rgba(55,62,80,0.45)';ctx.lineWidth=1;ctx.stroke();ctx.restore();
    const wL=x+hingePad+2,wR=x+w-4,wT=TOP+7,wB=bT-2;
    ctx.save();ctx.beginPath();ctx.moveTo(wL,wB);ctx.lineTo(wL+2,wT+12);ctx.quadraticCurveTo(wL+5,wT+2,wL+16,wT);ctx.lineTo(wR,wT);ctx.lineTo(wR,wB);ctx.closePath();ctx.fillStyle='#07080f';ctx.fill();ctx.restore();
    const cY=TOP+DH*0.565;ctx.save();ctx.beginPath();ctx.moveTo(x+5,cY+2);ctx.lineTo(x+w,cY+2);ctx.strokeStyle='rgba(55,65,85,0.55)';ctx.lineWidth=1.8;ctx.stroke();ctx.restore();
    const hY=TOP+DH*0.527,hX=x+w*0.73;ctx.save();const hg=ctx.createLinearGradient(hX,hY-4,hX,hY+5);hg.addColorStop(0,'#dde0eb');hg.addColorStop(1,'#888c9a');ctx.fillStyle=hg;ctx.beginPath();ctx.roundRect(hX,hY-4,30,8,4);ctx.fill();ctx.restore();
  })();
  ;(()=>{const x=rX,w=RW,bT=TOP+DH*0.398;
    ctx.save();ctx.beginPath();ctx.moveTo(x,BOT);ctx.lineTo(x,TOP);ctx.lineTo(x+w*0.63,TOP);ctx.quadraticCurveTo(x+w*0.78,TOP+6,x+w*0.88,TOP+22);ctx.bezierCurveTo(x+w*0.96,TOP+55,x+w+12,TOP+128,x+w+14,TOP+196);ctx.bezierCurveTo(x+w+14,TOP+260,x+w+8,BOT-65,x+w-9,BOT-26);ctx.quadraticCurveTo(x+w-6,BOT-4,x+w-18,BOT);ctx.lineTo(x,BOT);ctx.closePath();
    ctx.fillStyle=fillPaint(ctx,x,TOP,w,DH);ctx.fill();ctx.fillStyle=shadePaint(ctx,x,TOP,w,DH);ctx.fill();ctx.strokeStyle='rgba(55,62,80,0.45)';ctx.lineWidth=1;ctx.stroke();ctx.restore();
    const wL=x+4,wR=x+w*0.85,wT=TOP+7,wB=bT-2;
    ctx.save();ctx.beginPath();ctx.moveTo(wL,wB);ctx.lineTo(wL,wT+3);ctx.lineTo(x+w*0.56,wT);ctx.quadraticCurveTo(x+w*0.74,wT+4,x+w*0.82,wT+18);ctx.lineTo(wR,wB);ctx.closePath();ctx.fillStyle='#07080f';ctx.fill();ctx.restore();
    const cY=TOP+DH*0.562;ctx.save();ctx.beginPath();ctx.moveTo(x,cY+2);ctx.lineTo(x+w*0.86,cY+2);ctx.strokeStyle='rgba(55,65,85,0.55)';ctx.lineWidth=1.8;ctx.stroke();ctx.restore();
    const hY=TOP+DH*0.525,hX=x+w*0.58;ctx.save();const hg=ctx.createLinearGradient(hX,hY-4,hX,hY+5);hg.addColorStop(0,'#dde0eb');hg.addColorStop(1,'#888c9a');ctx.fillStyle=hg;ctx.beginPath();ctx.roundRect(hX,hY-4,27,8,4);ctx.fill();ctx.restore();
  })();
  ctx.fillStyle='#000';ctx.fillRect(CX-gPx/2,TOP,gPx,DH);
  ctx.fillStyle='rgba(255,255,255,0.06)';ctx.fillRect(CX-gPx/2,TOP,1.5,DH);
  const arY=TOP+DH*0.62;
  if(gPx>=6){arrowH(ctx,CX-gPx/2+1,arY,CX+gPx/2-1,'? mm',arY-14);}
  else{ctx.fillStyle='#ff3333';ctx.font='bold 13px sans-serif';ctx.textAlign='center';ctx.fillText('? mm',CX,arY-12);}
  drawRuler(ctx,W-Math.round(28*PX)-16,H-40,28,PX,'#ffd700',5);
  ctx.font='10px monospace';ctx.fillStyle='rgba(255,215,0,0.65)';ctx.textAlign='left';ctx.fillText('CLEARANCE: Min 3.0mm ~ Max 7.0mm',14,H-8);
}

function studioBG(ctx,W,H){
  const bg=ctx.createRadialGradient(W*0.42,H*0.35,0,W*0.5,H*0.5,Math.max(W,H)*0.82);
  bg.addColorStop(0,'#2e3240');bg.addColorStop(0.55,'#1c2030');bg.addColorStop(1,'#0c1020');
  ctx.fillStyle=bg;ctx.fillRect(0,0,W,H);
  const v=ctx.createRadialGradient(W/2,H/2,H*0.2,W/2,H/2,H*0.8);
  v.addColorStop(0,'rgba(0,0,0,0)');v.addColorStop(1,'rgba(0,0,0,0.52)');
  ctx.fillStyle=v;ctx.fillRect(0,0,W,H);
}

function drawHose(ctx,x0,x1,cy,rTop,rBot,alpha){
  if(x1<=x0)return;alpha=alpha===undefined?1:alpha;
  const len=x1-x0,ribS=12;
  for(let rx=x0;rx<x1;rx+=ribS){const sw=Math.min(ribS,x1-rx),tval=(rx-x0)/len,rT=rTop*(1-tval*0.04),rB=rBot*(1-tval*0.04);const sg=ctx.createLinearGradient(0,cy-rT,0,cy+rB);sg.addColorStop(0,'#252830');sg.addColorStop(0.22,'#3e4248');sg.addColorStop(0.58,'#1e2025');sg.addColorStop(1,'#090a0c');ctx.save();ctx.globalAlpha=alpha;ctx.fillStyle=sg;ctx.fillRect(rx,cy-rT,sw+1,rT+rB);ctx.restore();}
  for(let rx=x0+ribS/2;rx<x1;rx+=ribS){const tval=(rx-x0)/len,rT=rTop*(1-tval*0.04),rB=rBot*(1-tval*0.04),rd=(rT+rB)/2*0.90;const rg=ctx.createLinearGradient(0,cy-rd,0,cy+rd);rg.addColorStop(0,'rgba(0,0,0,0.92)');rg.addColorStop(0.5,'rgba(0,0,0,0.28)');rg.addColorStop(1,'rgba(0,0,0,0.95)');ctx.save();ctx.globalAlpha=alpha;ctx.fillStyle=rg;ctx.beginPath();ctx.ellipse(rx,cy,4.2,rd,0,0,Math.PI*2);ctx.fill();ctx.restore();}
  ctx.save();ctx.globalAlpha=alpha;const sp=ctx.createLinearGradient(x0,0,x1,0);sp.addColorStop(0,'rgba(255,255,255,0)');sp.addColorStop(0.5,'rgba(255,255,255,0.32)');sp.addColorStop(1,'rgba(255,255,255,0)');ctx.beginPath();ctx.ellipse(x0+len/2,cy-rTop*0.80,len/2,4.5,0,0,Math.PI*2);ctx.fillStyle=sp;ctx.fill();ctx.restore();
}

function drawPipeStub(ctx,x0,x1,cy,r){
  const len=x1-x0;ctx.save();const pg=ctx.createLinearGradient(0,cy-r,0,cy+r);pg.addColorStop(0.18,'#a8b8c4');pg.addColorStop(0.50,'#b8c8d4');pg.addColorStop(1,'#2c3440');ctx.fillStyle=pg;ctx.fillRect(x0,cy-r,len,r*2);
  [x1-20,x1-7].forEach(rx=>{const cg=ctx.createLinearGradient(0,cy-r-3,0,cy+r+3);cg.addColorStop(0,'#5a6878');cg.addColorStop(0.6,'#7a8898');cg.addColorStop(1,'#363e4a');ctx.fillStyle=cg;ctx.fillRect(rx,cy-r-2,6,r*2+4);});
  ctx.fillStyle='rgba(30,35,45,0.8)';ctx.fillRect(x0,cy-r,3,r*2);ctx.restore();
}

function drawClamp(ctx,cx,hw,cy,hr){
  const cr=hr+5;ctx.save();
  const bg=ctx.createLinearGradient(0,cy-cr,0,cy+cr);bg.addColorStop(0,'#606878');bg.addColorStop(0.40,'#c0c8d8');bg.addColorStop(1,'#343840');ctx.fillStyle=bg;ctx.beginPath();ctx.rect(cx-hw,cy-cr,hw*2,cr*2);ctx.fill();
  ctx.fillStyle='rgba(0,0,0,0.30)';ctx.beginPath();ctx.rect(cx-hw,cy-hr,hw*2,hr*2);ctx.fill();
  const eT=cy-cr;const ehg=ctx.createLinearGradient(cx-14,eT-20,cx+14,eT+4);ehg.addColorStop(0,'#82889a');ehg.addColorStop(0.65,'#989fb0');ctx.fillStyle=ehg;ctx.beginPath();ctx.rect(cx-12,eT-19,24,21);ctx.fill();ctx.strokeStyle='rgba(0,0,0,0.28)';ctx.lineWidth=0.5;ctx.stroke();
  ctx.fillStyle='rgba(0,0,0,0.75)';ctx.fillRect(cx-2,eT-19,4,19);
  const bY=cy+cr;const clg=ctx.createLinearGradient(0,bY,0,bY+14);clg.addColorStop(0,'#6e7480');clg.addColorStop(1,'#505560');ctx.fillStyle=clg;ctx.beginPath();ctx.rect(cx-9,bY,18,14);ctx.fill();
  ctx.restore();
}

function floorShadow(ctx,cx,cy,rBot,len){const fy=cy+rBot+2;const fs=ctx.createRadialGradient(cx,fy+8,0,cx,fy+8,len*0.45);fs.addColorStop(0,'rgba(0,0,0,0.55)');fs.addColorStop(1,'rgba(0,0,0,0)');ctx.fillStyle=fs;ctx.fillRect(cx-len*0.48,fy,len*0.96,38);}

function nc(){
  const pools=[0,1,2,3,4,5,6,7,8,9,10,11,12];
  const weights=[1,1,2,3,3,3,3,3,2,1,1,1,1];
  let total=weights.reduce((a,b)=>a+b,0),r=Math.random()*total,cumul=0,pick=0;
  for(let i=0;i<weights.length;i++){cumul+=weights[i];if(r<cumul){pick=i;break;}}
  CS={dist:pools[pick]};paintClip();iclr('c');
}

function paintClip(){
  const cv=document.getElementById('cClip');if(!cv)return;
  const W=cv.width,H=cv.height,ctx=cv.getContext('2d');
  studioBG(ctx,W,H);
  const dist=CS.dist,dPx=Math.round(dist*PX),cy=H*0.46,rTop=52,rBot=49;
  const openEndX=W-90,farX=18;
  // clampCX is CENTRE of clamp band; clamp half-width hw=10
  // dist is from open end to START (left edge) of clamp, so centre = openEndX - dPx - 10
  const hw=10;
  const clampStartX=openEndX-dPx;       // start line of clip
  const clampCX=clampStartX-hw;         // centre of clamp (shifted left by hw)
  floorShadow(ctx,(farX+openEndX)/2,cy,rBot,openEndX-farX);
  drawHose(ctx,farX,openEndX,cy,rTop,rBot);
  ctx.save();const edg=ctx.createLinearGradient(0,cy-rTop,0,cy+rBot);edg.addColorStop(0,'#404548');edg.addColorStop(0.6,'#505458');edg.addColorStop(1,'#282c30');ctx.fillStyle=edg;ctx.fillRect(openEndX,cy-rTop,4,rTop+rBot);ctx.restore();
  drawClamp(ctx,clampCX,hw,cy,rTop);
  const s1=openEndX-Math.round(7*PX),s2=openEndX-Math.round(2*PX);
  ctx.fillStyle='rgba(0,230,118,0.055)';ctx.fillRect(s1,cy-rTop*2.0,s2-s1,rTop*4.0);
  ctx.strokeStyle='rgba(0,230,118,0.25)';ctx.lineWidth=0.5;ctx.setLineDash([4,3]);ctx.beginPath();ctx.moveTo(s1,cy-rTop*2.0);ctx.lineTo(s1,cy+rBot*2.0);ctx.moveTo(s2,cy-rTop*2.0);ctx.lineTo(s2,cy+rBot*2.0);ctx.stroke();ctx.setLineDash([]);
  ctx.font='9px monospace';ctx.textAlign='center';ctx.fillStyle='rgba(0,230,118,0.5)';ctx.fillText('SPEC',(s1+s2)/2,cy-rTop*2.0-6);
  // Arrow: from open end to START LINE of clip
  const ay=cy-rTop-30;arrowH(ctx,openEndX,ay,clampStartX,'? mm',ay-13);
  ctx.strokeStyle='#ff3333';ctx.lineWidth=1;[[openEndX],[clampStartX]].forEach(([x])=>{ctx.beginPath();ctx.moveTo(x,cy-rTop-10);ctx.lineTo(x,ay+3);ctx.stroke();});
  // Start-line marker on clip (bright tick at left edge)
  ctx.save();ctx.strokeStyle='#00e676';ctx.lineWidth=1.5;ctx.beginPath();ctx.moveTo(clampStartX,cy-rTop-8);ctx.lineTo(clampStartX,cy+rBot+8);ctx.stroke();ctx.restore();
  drawRuler(ctx,openEndX-Math.round(12*PX),H-40,12,PX,'#ffd700',1);
  ctx.font='10px monospace';ctx.fillStyle='rgba(255,215,0,0.65)';ctx.textAlign='left';ctx.fillText('CLIP: 2–7mm from open end to clip start line',14,H-8);
}

function ni_sim(){
  const pool=[0,0,0.5,0.5,1,1,1.5,2,2.5,3,3.5,4,4.5,5,6,7,8];
  IS={gap:pool[Math.floor(Math.random()*pool.length)]};paintInsert();iclr('i');
}

function paintInsert(){
  const cv=document.getElementById('cInsert');if(!cv)return;
  const W=cv.width,H=cv.height,ctx=cv.getContext('2d');
  studioBG(ctx,W,H);
  const gMM=IS.gap,gPx=Math.round(gMM*PX),cy=H*0.46,rTop=52,rBot=49,pipeR=rTop*0.80;
  const pipeX1=W-75,stopX=pipeX1-Math.round(28*PX),hoseEndX=stopX-gPx,farX=18;
  floorShadow(ctx,(farX+pipeX1)/2,cy,rBot,pipeX1-farX);
  drawHose(ctx,farX,hoseEndX,cy,rTop,rBot);
  ctx.save();const edg=ctx.createLinearGradient(0,cy-rTop,0,cy+rBot);edg.addColorStop(0,'#404548');edg.addColorStop(1,'#282c30');ctx.fillStyle=edg;ctx.fillRect(hoseEndX,cy-rTop,4,rTop+rBot);ctx.restore();
  drawPipeStub(ctx,hoseEndX-4,pipeX1,cy,pipeR);
  ctx.save();const scg=ctx.createLinearGradient(0,cy-pipeR-4,0,cy+pipeR+4);scg.addColorStop(0,'#505c6a');scg.addColorStop(0.55,'#707e8e');scg.addColorStop(1,'#303840');ctx.fillStyle=scg;ctx.fillRect(stopX-5,cy-pipeR-4,10,pipeR*2+8);ctx.restore();
  if(gPx>=Math.round(1.5*PX)){const ay=cy-rTop-30;arrowH(ctx,hoseEndX,ay,stopX,'? mm',ay-13);ctx.strokeStyle='#ff3333';ctx.lineWidth=1;[[hoseEndX],[stopX]].forEach(([x])=>{ctx.beginPath();ctx.moveTo(x,cy-rTop-10);ctx.lineTo(x,ay+3);ctx.stroke();});}
  else{ctx.save();ctx.fillStyle='#00e676';ctx.font='bold 13px sans-serif';ctx.textAlign='center';ctx.fillText('≈ FULLY SEATED',hoseEndX-18,cy-rTop-28);ctx.restore();}
  ctx.strokeStyle='rgba(255,180,0,0.45)';ctx.lineWidth=1;ctx.setLineDash([4,3]);ctx.beginPath();ctx.moveTo(stopX,cy-pipeR-20);ctx.lineTo(stopX,cy+pipeR+20);ctx.stroke();ctx.setLineDash([]);
  ctx.font='9px monospace';ctx.fillStyle='rgba(255,180,0,0.65)';ctx.textAlign='center';ctx.fillText('COLLAR',stopX,cy-pipeR-25);
  drawRuler(ctx,hoseEndX-Math.round(2*PX),H-40,12,PX,'#ffd700',1);
  ctx.font='10px monospace';ctx.fillStyle='rgba(255,215,0,0.65)';ctx.textAlign='left';ctx.fillText('INSERTION: Target 0mm to stopper',14,H-8);
}

function nl_sim(){LS={step:irnd(-4.5,4.5,0.5)};paintLevel();iclr('l');}

function paintLevel(){
  const cv=document.getElementById('cLevel');if(!cv)return;
  const W=cv.width,H=cv.height,ctx=cv.getContext('2d');
  ctx.fillStyle='#000';ctx.fillRect(0,0,W,H);
  const s=LS.step,sPx=Math.round(s*PX),MID=H/2,pW=210,pH=255;
  const bX=110,dX=bX+pW+24,bY=MID-pH/2,dY=bY+sPx;
  function panelG(x,y,w,h){const g=ctx.createLinearGradient(x,y,x+w,y);g.addColorStop(0,'#aeb5c2');g.addColorStop(0.50,'#e4e8f2');g.addColorStop(1,'#b0b4c0');return g;}
  ctx.save();ctx.beginPath();ctx.roundRect(bX,bY,pW,pH,[6,0,0,6]);ctx.fillStyle=panelG(bX,bY,pW,pH);ctx.fill();ctx.strokeStyle='rgba(55,62,80,0.45)';ctx.lineWidth=1;ctx.stroke();ctx.restore();
  ctx.save();ctx.beginPath();ctx.roundRect(dX,dY,pW,pH,[0,6,6,0]);ctx.fillStyle=panelG(dX,dY,pW,pH);ctx.fill();ctx.strokeStyle='rgba(55,62,80,0.45)';ctx.lineWidth=1;ctx.stroke();ctx.restore();
  ctx.fillStyle='#000';ctx.fillRect(bX+pW,Math.min(bY,dY)-4,24,pH+Math.abs(sPx)+8);
  ctx.strokeStyle='rgba(255,255,255,0.16)';ctx.lineWidth=1;ctx.setLineDash([7,5]);ctx.beginPath();ctx.moveTo(bX-22,bY);ctx.lineTo(dX+pW+75,bY);ctx.stroke();ctx.setLineDash([]);
  const sx=dX+pW+50,s2px=Math.round(2*PX);
  ctx.fillStyle='rgba(0,230,118,0.06)';ctx.fillRect(sx-18,bY-s2px,36,s2px*2);
  if(Math.abs(sPx)>3){ctx.fillStyle='rgba(255,51,51,0.1)';ctx.fillRect(sx-6,Math.min(bY,dY),12,Math.abs(sPx));ctx.strokeStyle='#ff3333';ctx.lineWidth=1.5;ctx.beginPath();ctx.moveTo(sx,bY);ctx.lineTo(sx,dY);ctx.stroke();ctx.fillStyle='#ff3333';ctx.font='bold 13px sans-serif';ctx.textAlign='left';ctx.fillText('? mm',sx+10,(bY+dY)/2+4);}
  else{ctx.fillStyle='#00e676';ctx.font='bold 12px sans-serif';ctx.textAlign='left';ctx.fillText('≈ FLUSH',sx+7,bY+5);}
  ctx.save();ctx.translate(sx+95,bY-5*PX);ctx.strokeStyle='#ffd700';ctx.lineWidth=0.8;ctx.beginPath();ctx.moveTo(0,0);ctx.lineTo(0,10*PX);ctx.stroke();for(let i=-5;i<=5;i++){const y=(i+5)*PX;ctx.beginPath();ctx.moveTo(0,y);ctx.lineTo(i%2===0?9:4,y);ctx.stroke();if(i%2===0){ctx.fillStyle='#ffd700';ctx.font='10px monospace';ctx.textAlign='left';ctx.fillText(i,12,y+3);}}ctx.restore();
  ctx.font='10px monospace';ctx.fillStyle='rgba(255,215,0,0.65)';ctx.textAlign='left';ctx.fillText('LEVELNESS: Max 0 +/- 2.00mm',14,H-8);
  ctx.font='bold 10px sans-serif';ctx.textAlign='center';ctx.fillStyle='rgba(255,255,255,0.32)';ctx.fillText('BODY',bX+pW/2,bY-7);ctx.fillText('DOOR',dX+pW/2,dY-7);
}

function drawRuler(ctx,ox,oy,mm,pxPerMm,col,maj){ctx.save();ctx.strokeStyle=col;ctx.lineWidth=0.8;ctx.beginPath();ctx.moveTo(ox,oy);ctx.lineTo(ox+mm*pxPerMm,oy);ctx.stroke();for(let i=0;i<=mm;i++){const tx=ox+i*pxPerMm,iM=i%maj===0;ctx.beginPath();ctx.moveTo(tx,oy);ctx.lineTo(tx,oy+(iM?9:5));ctx.stroke();if(iM){ctx.fillStyle=col;ctx.font='10px monospace';ctx.textAlign='center';ctx.fillText(i,tx,oy+19);}}ctx.restore();}

function arrowH(ctx,x1,y,x2,label,labelY){ctx.save();ctx.strokeStyle='#ff3333';ctx.lineWidth=1.6;ctx.setLineDash([5,3]);ctx.beginPath();ctx.moveTo(x1,y);ctx.lineTo(x2,y);ctx.stroke();ctx.setLineDash([]);[[x1,-1],[x2,1]].forEach(([ax,d])=>{ctx.beginPath();ctx.moveTo(ax,y);ctx.lineTo(ax+d*8,y-4);ctx.lineTo(ax+d*8,y+4);ctx.closePath();ctx.fillStyle='#ff3333';ctx.fill();});ctx.fillStyle='#ff3333';ctx.font='bold 14px sans-serif';ctx.textAlign='center';ctx.fillText(label,(x1+x2)/2,labelY||y-12);ctx.restore();}

function chk(mod){
  const ans=parseFloat(document.getElementById(mod[0]+'-ans').value);
  const fb=document.getElementById(mod[0]+'-fb');
  if(isNaN(ans)){fb.textContent='Enter your measurement estimate.';fb.className='ipt-fb f';return;}
  SC[mod][1]++;
  let actual,okFn,tol;
  switch(mod){case'door':actual=DS.gap;okFn=v=>v>=3&&v<=7;tol=1.0;break;case'clip':actual=CS.dist;okFn=v=>v>=2&&v<=7;tol=1.0;break;case'insert':actual=IS.gap;okFn=v=>v<=0.5;tol=0.5;break;case'level':actual=LS.step;okFn=v=>Math.abs(v)<=2;tol=0.5;break;}
  const specOk=okFn(actual),estOk=Math.abs(ans-actual)<=tol;
  const pass=estOk;
  if(pass)SC[mod][0]++;
  fb.textContent=(pass?'PASS ✓':'FAIL ✗')+'  Actual='+actual.toFixed(1)+'mm → Spec: '+(specOk?'OK ✓':'NG ✗')+'.  Your estimate: '+ans+'mm  (tolerance ±'+tol+'mm)';
  fb.className='ipt-fb '+(pass?'p':'f');
  const p=mod[0];
  document.getElementById(p+'-sc').textContent='Correct: '+SC[mod][0];
  document.getElementById(p+'-tot').textContent='Attempts: '+SC[mod][1];
  iUpdG();
}


// ═══════════════════════════════════════════
// SOS DATA (from PDF)
// ═══════════════════════════════════════════
// All SOS processes extracted from the PDF
const SOS_PROCESSES = [
  {
    id: 'engine_a_rh',
    name: 'Engine A – RH Encopa Common',
    model: '25MC',
    takt: '80 SEC',
    process: 'Engine A - Common Process',
    type: 'sequence',
    steps: [
      { sl: 1, step: 1, item: 'Brake reservoir tank cap (Only RHD)', checkItem: 'Coming off', standard: 'Not Allowed', method: 'Visual + Rotate' },
      { sl: 2, step: 1, item: 'Brake oil level sensor connector (Only RHD)', checkItem: 'Half Lock', standard: 'Not Allowed', method: 'Visual + Push' },
      { sl: 3, step: 1, item: 'Brake oil level sensor W/H routing clip #1 (Only RHD)', checkItem: 'Coming off', standard: 'Not Allowed', method: 'Visual + Pull' },
      { sl: 4, step: 1, item: 'Brake oil level sensor W/H routing clip #2 (Black) X Dash (Only RHD)', checkItem: 'Unlocked', standard: 'Not Allowed', method: 'Visual' },
      { sl: 1, step: 1, item: 'Camshaft Fr inlet valve sensor wire harness connector (only THS)', checkItem: 'Not Connected', standard: 'Not allowed', method: 'Visual' },
      { sl: 2, step: 1, item: 'Alternator N terminal connector (Except THS)', checkItem: 'Not Connected', standard: 'Not allowed', method: 'Visual' },
      { sl: 3, step: 1, item: 'Alternator B terminal cap (Except THS)', checkItem: 'Miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 4, step: 1, item: 'OPS (oil Pressure sensor) (grey) wire harness connector (Except THS)', checkItem: 'Half Lock', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 5, step: 1, item: 'Camshaft Rr exhaust (Black) wire harness connector (Except THS)', checkItem: 'Half Lock', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 6, step: 1, item: 'Air cleaner intake mounting rubber (Except THS)', checkItem: 'Insertion', standard: 'Securely locked', method: 'Visual + Pull' },
      { sl: 7, step: 1, item: 'Fuel injector Branch Connector #1 (Grey) (Only CNG)', checkItem: 'Half Lock', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 8, step: 1, item: 'Fuel injector Branch Connector #2 (Black) (Only CNG)', checkItem: 'Half Lock', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 9, step: 1, item: 'Fuel main hose X clamp white colour (Except THS)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 10, step: 1, item: 'Fuel main hose X clamp white colour clamp X Bracket (Except THS)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 11, step: 1, item: 'CNG common rail W/H routing clip (Only CNG)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 12, step: 1, item: 'Fuel main hose X Return hose', checkItem: 'Interference', standard: 'Not allowed', method: 'Visual' },
      { sl: 13, step: 1, item: 'Fuel return tube X hose Clip (Except THS)', checkItem: 'Miss', standard: 'Not Allowed', method: 'Visual' },
      { sl: 14, step: 1, item: 'Fuel return hose Clip X tube (Except THS)', checkItem: 'Miss', standard: 'Not Allowed', method: 'Visual' },
      { sl: 15, step: 1, item: 'Fuel main hose Clip X tube (Except THS)', checkItem: 'Miss', standard: 'Not Allowed', method: 'Visual' },
      { sl: 16, step: 1, item: 'Ignition W/H Routing cover locking clamp X E/G Fr side (Only THS)', checkItem: 'coming off', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 17, step: 1, item: 'Metal bracket X fender inner nut #1 (Except THS)', checkItem: 'Miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 18, step: 1, item: 'Metal bracket X fender inner nut #2 (Except THS)', checkItem: 'Miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 19, step: 1, item: 'White clamp #1 X Brake tube #1 (3 groove near RHD Below BMC)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 20, step: 1, item: 'White clamp #1 X Brake tube #2 (3 groove near RHD Below BMC)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 21, step: 1, item: 'White clamp #1 X Brake tube #3 (3 groove near RHD Below BMC)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 22, step: 1, item: 'White clamp #2 X BMC brake tube #1 (2 groove Rr)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 23, step: 1, item: 'White clamp #2 X BMC brake tube #2 (2 groove Rr)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 24, step: 1, item: 'White clamp #3 X BMC brake tube #1 (2 groove Fr)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 25, step: 1, item: 'White clamp #3 X BMC brake tube #2 (2 groove Fr)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      // RH Encopa 2
      { sl: 26, step: 2, item: 'White clamp #4 X Brake tube #1 (3 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 27, step: 2, item: 'White clamp #4 X Brake tube #2 (3 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 28, step: 2, item: 'White clamp #4 X Brake tube #3 (3 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 29, step: 2, item: 'White clamp #5 X Brake tube #1 (4 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 30, step: 2, item: 'White clamp #5 X Brake tube #2 (4 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 31, step: 2, item: 'White clamp #5 X Brake tube #3 (4 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 32, step: 2, item: 'White clamp #5 X Brake tube #4 (4 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 33, step: 2, item: 'White clamp #6 X Brake tube #1 (3 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 34, step: 2, item: 'White clamp #6 X Brake tube #2 (3 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 35, step: 2, item: 'White clamp #6 X Brake tube #3 (3 groove)', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      // RH Encopa 3
      { sl: 46, step: 3, item: 'A/c liquid pipe X fender inner Black clamp', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual' },
      { sl: 47, step: 3, item: 'A/C liquid pipe Black clamp X fender inner', checkItem: 'Unlocked', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 48, step: 3, item: 'Engine room W/H routing clip #2 X fender inner', checkItem: 'Not Connected', standard: 'Not allowed', method: 'Visual' },
      { sl: 49, step: 3, item: 'Engine room W/H routing clip #3 X Rh Suspension tower', checkItem: 'coming off', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 50, step: 3, item: 'Engine room W/H routing clip #4 X fender inner', checkItem: 'coming off', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 51, step: 3, item: 'Earth terminal bolt (Rr side) X E/G mounting (Only K15B)', checkItem: 'Looseness', standard: 'Not allowed', method: 'Visual + Shake' },
      { sl: 52, step: 3, item: 'Earth terminal W/H clamp X bracket mount (Only K15B)', checkItem: 'Coming off', standard: 'Not allowed', method: 'Visual + Pull' },
      { sl: 53, step: 3, item: 'Rh front brake tube grommet X fender inner', checkItem: 'Insertion', standard: 'Not allowed', method: 'Visual + Feel' },
      { sl: 54, step: 3, item: 'Plug seal X suspension tower', checkItem: 'Miss', standard: 'Not allowed', method: 'Visual' },
      // RH Encopa 4
      { sl: 61, step: 6, item: 'ABS actuator Main Mounting bracket X suspension tower upper bolt', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 62, step: 6, item: 'ABS actuator Main Mounting bracket X suspension tower Lower bolt', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 63, step: 6, item: 'ABS actuator Main Mounting bracket X Fender Apron bolt', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 64, step: 6, item: 'ABS Actuator Sub Bracket X Main Mounting bracket lower Bolt #1', checkItem: 'Miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 65, step: 6, item: 'ABS Actuator Sub Bracket X Main Mounting bracket lower Bolt #2', checkItem: 'Miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 66, step: 6, item: 'ABS Actuator Mounting Sub Bracket X Main bracket lower Bolt #3 (Thread)(Except THS)', checkItem: 'Miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 67, step: 6, item: 'ABS actuator break tube flare nut #1', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 68, step: 6, item: 'ABS actuator break tube flare nut #2', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 69, step: 6, item: 'ABS actuator break tube flare nut #3', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 70, step: 6, item: 'ABS actuator break tube flare nut #4', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 71, step: 6, item: 'ABS actuator break tube flare nut MC-1', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 72, step: 6, item: 'ABS actuator break tube flare nut MC-2', checkItem: 'mark miss', standard: 'Not allowed', method: 'Visual' },
      { sl: 73, step: 6, item: 'ABS actuator break tube 1 X tube 2', checkItem: 'Interference', standard: 'Not Allowed', method: 'Visual' },
      { sl: 74, step: 6, item: 'ABS actuator break tube 2 X tube 3', checkItem: 'Interference', standard: 'Not Allowed', method: 'Visual' },
      { sl: 75, step: 6, item: 'ABS actuator break tube 3 X tube 4', checkItem: 'Interference', standard: 'Not Allowed', method: 'Visual' },
      { sl: 76, step: 6, item: 'ABS actuator connector', checkItem: 'Half Lock', standard: 'Not allowed', method: 'Visual + Pull' }
    ]
  },
  {
    id: 'fr_ext_spec_ocr',
    name: 'FR EXT SPEC & OCR',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan vehicle GALC card by VDEM tab', checkItem: 'Scan', standard: 'NA', method: 'Visual + Touch' },
      { sl: 2, step: '', item: 'Compare color code in GALC card to body', checkItem: 'Mismatch / Wrong', standard: 'Must match with Vehicle', method: 'Visual' },
      { sl: 3, step: '', item: 'Rh side Cowl Louver X cowl End piece', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual+touch' },
      { sl: 4, step: '', item: 'Lh Side Fr windshield protector X A Piller', checkItem: 'Clearance', standard: '3.6+/-2.0mm', method: 'Visual' },
      { sl: 5, step: '', item: 'Lh side Cowl Louver X cowl End piece', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual+touch' },
      { sl: 6, step: '', item: 'FR Wiper arm cap 2 no s', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 7, step: 1, item: 'Frame number OCR Scan — Scan the vehicle CPTS by VDEM tab', checkItem: 'Scan', standard: '', method: 'Visual+Scan' },
      { sl: 8, step: 1, item: 'Scan GALC card by OCR Scanner', checkItem: 'Scan', standard: 'No abnormality', method: 'Visual+Scan' },
      { sl: 9, step: 1, item: 'Locate OCR scanner in home position', checkItem: 'Locate', standard: '', method: '' },
      { sl: 10, step: 1, item: 'Collect OCR jig and Locate OCR jig on cowl Louver', checkItem: 'Locate', standard: '', method: '' },
      { sl: 11, step: 1, item: 'Focus the camera and click the frame number image', checkItem: 'Capture', standard: 'No abnormality', method: 'Visual+Scan' },
      { sl: 12, step: 4, item: 'Locate OCR jig in home position', checkItem: '', standard: '', method: '' },
      { sl: 13, step: 4, item: 'Remove the OCR jig From cowl louver and locate in home position', checkItem: 'Remove', standard: '', method: '' },
      { sl: 14, step: '', item: 'If OCR not working - check Frame number 17 digit x frame number check sheet', checkItem: 'Mismatch', standard: 'Not Allowed', method: 'Visual' },
      { sl: 15, step: 7, item: 'Scan OCR result check — Scan OCR result QR code', checkItem: 'Mismatch / Wrong', standard: 'Mismatch not allowed', method: 'Visual+Scan' },
      { sl: 16, step: '', item: 'Lh Fr Dr Outer Spec — LH FR Door Frame sash Black-out', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 17, step: '', item: 'LH FR Front Door Glass', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 18, step: '', item: 'Lh Fr Dr Glass Approval mark', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 19, step: '', item: 'Lh Fr dr Belt Mould', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 20, step: '', item: 'LH FR Dr Outside Handle Cap', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 21, step: '', item: 'LH FR Dr Outside Handle & Cap Color', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 22, step: '', item: 'Lh Side Exterior Spec — LH ORVM Glass Font', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 23, step: '', item: 'Lh Orvm Camera', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 24, step: '', item: 'LH ORVM Mirror cover', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 25, step: '', item: 'CNG Label FR', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 26, step: '', item: 'Fr Windshield', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 27, step: '', item: 'Fr Windshield Approval mark', checkItem: 'Missing', standard: 'Not Allowed', method: 'Visual' },
      { sl: 28, step: 2, item: 'Visible vin label vin content scan', checkItem: 'Number miss match', standard: 'Not allowed', method: 'scan' },
      { sl: 29, step: 2, item: 'Visible vin label vin content scan App check', checkItem: 'reverse fit & Damage', standard: 'Not allowed', method: 'Visual' },
      { sl: 30, step: 6, item: 'Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 31, step: 6, item: 'Walk to home position', checkItem: '', standard: '', method: '' }
    ]
  },
  {
    id: 'lh_fr_int_fitment',
    name: 'LH Front Interior Fitment',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'LH fr door open', checkItem: '', standard: '', method: '' },
      { sl: 2, step: 1, item: 'Scan vehicle GALC card by VDEM tab', checkItem: 'Scan', standard: '', method: '' },
      { sl: 3, step: 1, item: 'LH fr door open & close', checkItem: 'Open', standard: '', method: '' },
      { sl: 4, step: 2, item: 'LH Fr Seat Operation — LH Fr seat sliding (power/manual)', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+touch' },
      { sl: 5, step: 2, item: 'LH Fr seat sliding stop/lock (power/manual)', checkItem: 'Operation', standard: 'Satisfactory', method: 'Visual+touch' },
      { sl: 6, step: 2, item: 'LHD-LH Fr seat Base up/down tilt (only power seat)', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+touch' },
      { sl: 7, step: 2, item: 'LHD-LH Fr seat height adjuster up/down (power/manual)', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+touch' },
      { sl: 8, step: 2, item: 'LH Fr seat backrest recling (power/manual)', checkItem: 'Operation', standard: 'Satisfactory', method: 'Visual+touch' },
      { sl: 9, step: 2, item: 'LH Fr seat backrest recling stop/lock (power/manual)', checkItem: 'Operation', standard: 'Satisfactory', method: 'Visual+touch' },
      { sl: 10, step: 3, item: 'LHD-All door lock knob manual switch lock', checkItem: 'Function', standard: 'All dr knobshould be locked', method: 'Visual+touch' },
      { sl: 11, step: 3, item: 'LHD-All door Lock knob manual switch unlock', checkItem: 'Function', standard: 'All dr knobshould be unlocked', method: 'Visual+touch' },
      { sl: 12, step: 4, item: 'LH Fr Seat Belt Operation — LH fr seat belt vertical adjuster anchor up and down', checkItem: 'Operation', standard: 'Operate Smoothly', method: 'Visual+touch' },
      { sl: 13, step: 4, item: 'LH fr seat belt vertical adjuster anchor Knob lock & unlock (3step)', checkItem: 'Function', standard: 'Must lock securely', method: 'Visual+touch' },
      { sl: 14, step: 4, item: 'LH fr seat belt drawing', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+Pull' },
      { sl: 15, step: 4, item: 'LH fr seat belt webbing lock', checkItem: 'Function', standard: 'must lock', method: 'Visual+Pull' },
      { sl: 16, step: 4, item: 'LH fr seat belt tongue X seat buckle lock', checkItem: 'Function', standard: 'must be lock', method: 'Visual+touch' },
      { sl: 17, step: 4, item: 'LH fr seat belt fitment', checkItem: 'Twist', standard: 'Twist not allowed', method: 'Visual+touch' },
      { sl: 18, step: 4, item: 'Passenger seat belt warning indicator in combimeter(RHD)', checkItem: 'Function', standard: 'Should light up/blink', method: 'Visual + touch' },
      { sl: 19, step: 5, item: 'LH fr dr inside handle function — LH fr door inside door lock knob lock', checkItem: 'Function', standard: 'safety lock shall not be released', method: 'Visual+touch' },
      { sl: 20, step: 5, item: 'LH fr door inside door lock knob unlock', checkItem: 'Function', standard: 'safety lock shall be unlocked', method: 'Visual+touch' },
      { sl: 21, step: 5, item: 'LH fr door inside handle operation', checkItem: 'Function', standard: 'Should be seculerly opened', method: 'Visual+touch' },
      { sl: 22, step: 5, item: 'LH fr dr open (door catcher and stricker split off)', checkItem: 'Function', standard: 'Door should be completely opened', method: 'Visual+touch' },
      { sl: 23, step: 5, item: 'LH fr door inside handle fitment', checkItem: 'Looseness', standard: 'No Looseness', method: 'Visual+touch' },
      { sl: 24, step: 6, item: 'LH Assist grip fitment — LH fr Assist grip open', checkItem: 'Operation', standard: 'No sticky', method: 'Touch+Pull' },
      { sl: 25, step: 6, item: 'LH fr Assist grip assembly condition', checkItem: 'Looseness', standard: 'Lock securely', method: 'Touch+Pull' },
      { sl: 26, step: 6, item: 'LH fr Assist grip Retract (pull down and release)', checkItem: 'Operation', standard: 'Auto return to normal position', method: 'Touch+Pull' },
      { sl: 27, step: 7, item: 'LH Sunvisor operation — LH sunvisor open (unlock) and left and right rotate', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+Pull' },
      { sl: 28, step: 7, item: 'LH sunvisor X roof (screw to roof)', checkItem: 'Looseness', standard: 'Lock securely', method: 'Visual' },
      { sl: 29, step: 7, item: 'LH sunvisor Holder X roof', checkItem: 'Looseness', standard: 'Lock securely', method: 'Visual+shake' },
      { sl: 30, step: 7, item: 'LH sunvisor up and down rotate', checkItem: 'Coming off', standard: 'should not come off', method: 'Visual+touch' },
      { sl: 31, step: 7, item: 'Spot lamp X Roof Head lining LH side', checkItem: 'Gap', standard: '1.0 mm', method: 'Visual' },
      { sl: 32, step: 8, item: 'LH A Pillar Garnish Fitment — LH A pillar Garnish X Roof head lining', checkItem: 'Clearance', standard: '1.0mm', method: 'Visual' },
      { sl: 33, step: 8, item: 'LH A pillar Garnish X IP upper fitment', checkItem: 'Unlock', standard: 'Should be fitted securely', method: 'Visual' },
      { sl: 34, step: 8, item: 'LH Side IP register knob updown and left right movement', checkItem: 'Operation', standard: 'Smoothly', method: 'Touch + Feel' },
      { sl: 35, step: 8, item: 'LH SIDE CENTER CLUSTER X CENTER CLUSTER BASE', checkItem: 'CLEARENCE', standard: '0.5 mm', method: 'VISUAL' },
      { sl: 36, step: 8, item: 'Set audio volume', checkItem: 'Set volume', standard: 'Level 25 to 30', method: 'Auxiliary' },
      { sl: 37, step: 8, item: 'Shift lever boot Bezel X Console Lh Side', checkItem: 'Unlock', standard: 'Locked securely', method: 'Visual' }
    ]
  },
  {
    id: 'rh_fr_int_spec',
    name: 'Rh Fr Int Spec',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan the vehicle CPTS by VDEM tab', checkItem: 'Scan', standard: 'NA', method: 'Visual + Touch' },
      { sl: 2, step: '', item: 'Rh Side Interior Spec — Rh Orvm Camera', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 3, step: '', item: 'RH Orvm Cover', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 4, step: '', item: 'RH Orvm Glass Font', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 5, step: '', item: 'RH FR Door Frame sash Black-out', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 6, step: '', item: 'Rh FR Front Door Glass', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 7, step: '', item: 'Rh FR Dr Glass Approval mark', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 8, step: '', item: 'Rh Fr dr Belt Mould', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 9, step: '', item: 'Rh FR dr Outside Door Handle Cap', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 10, step: '', item: 'Rh FR dr Outside Door Handle & Cap Color', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 11, step: '', item: 'Rh fr dr open', checkItem: 'open', standard: 'na', method: 'Visual + Touch' },
      { sl: 12, step: '', item: 'Ignition ON', checkItem: 'ON', standard: 'ANA', method: 'Visual + Touch' },
      { sl: 13, step: '', item: 'RH Fr seat Head Rest', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 14, step: '', item: 'RH FR Seat COLOR', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 15, step: '', item: 'RH FR Seat Fabric', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 16, step: '', item: 'RH Side Glove Box lamp (LHD)', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 17, step: '', item: 'ST Wheel', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 18, step: '', item: 'Stering wheel down', checkItem: 'pull down and lock', standard: 'ANA', method: 'Visual + Touch' },
      { sl: 19, step: '', item: 'Rh Register Bezel', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 20, step: '', item: 'Rh Push start Sw', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 21, step: '', item: 'RH Ip Garnish MATERIAL', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 22, step: '', item: 'RH Ip Ornament', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 23, step: '', item: 'RH Floor Console Ornament', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 24, step: '', item: 'Remote #1 Spl Process', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 25, step: '', item: 'Remote #2 Spl Process', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 26, step: '', item: 'Remote #1 Code', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 27, step: '', item: 'Remote #2 Code', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 28, step: '', item: 'Key number check — Collect the Key from console', checkItem: 'Collect', standard: '', method: '' },
      { sl: 29, step: '', item: 'RHD/LHD-Type the key number in VDEM tab / Check key number in key plate to CPTS', checkItem: 'Miss match', standard: 'Green in VDEM Must match with CPTS', method: 'Visual+touch' },
      { sl: 30, step: '', item: 'Keep the key in console box', checkItem: 'Keep', standard: '', method: '' },
      { sl: 31, step: '', item: 'PKB lever / EPB switch', checkItem: 'Wrong part / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 32, step: '', item: 'Rh sunvisor Label', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 33, step: '', item: 'RH Vanity Mirror lamp', checkItem: 'Wrong part / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 34, step: '', item: 'RH B piller garnish', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 35, step: '', item: 'RH FR DR Tweeter', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 36, step: '', item: 'RH Fr dr Trim CNG Label', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 37, step: '', item: 'RH Fr Dr Inside handle Lamp', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 38, step: '', item: 'RH Fr Dr Inside handle', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 39, step: '', item: 'Rh Front Door Trim Material', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 40, step: '', item: 'RH FR DR Window Master Switch Bezel', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 41, step: '', item: 'Rh Fr Dr', checkItem: 'Close', standard: 'ANA', method: 'Visual + Touch' },
      { sl: 42, step: 8, item: 'Defect entry — Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 43, step: 8, item: 'Walk to home position', checkItem: '', standard: '', method: '' }
    ]
  },
  {
    id: 'rh_fr_int_fitment',
    name: 'Rh Fr Int Fitment',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: 1, item: 'LHD - RH Assist grip fitment', checkItem: 'Scan', standard: '', method: '' },
      { sl: 2, step: 1, item: 'Scan vehicle GALC card by VDEM tab', checkItem: 'Open', standard: '', method: '' },
      { sl: 3, step: 1, item: 'Rh Fr dr open & close', checkItem: 'On', standard: '', method: '' },
      { sl: 4, step: 1, item: 'Ignition On & Audio volume', checkItem: 'Insert', standard: '', method: '' },
      { sl: 5, step: '', item: 'Rh fr seat operation — LHD-Lh fr seat belt buckle (D-side belt)', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+touch' },
      { sl: 6, step: '', item: 'RH Fr seat sliding (power/manual)', checkItem: 'Operation', standard: 'Satisfactory', method: 'Visual+touch' },
      { sl: 7, step: '', item: 'RH Fr seat sliding stop/lock (power/manual)', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+touch' },
      { sl: 8, step: 2, item: 'RHD-RH Fr seat height adjuster up/down (power/manual)', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+touch' },
      { sl: 9, step: 2, item: 'RHD-RH Fr seat Base up/down tilt (only power seat)', checkItem: 'Operation', standard: 'Satisfactory', method: 'Visual+touch' },
      { sl: 10, step: 2, item: 'RH Fr seat backrest recling (power/manual)', checkItem: 'Operation', standard: 'Satisfactory', method: 'Visual+touch' },
      { sl: 11, step: 2, item: 'RH Fr seat backrest recling stop/lock (power/manual)', checkItem: 'Operation', standard: 'Satisfactory', method: 'Visual+touch' },
      { sl: 12, step: 3, item: 'Rh fr seat Belt Operation — RH fr seat belt vertical adjuster anchor up and down', checkItem: 'Operation', standard: 'Operate Smoothly', method: 'Visual+touch' },
      { sl: 13, step: 3, item: 'RH fr seat belt vertical adjuster anchor Knob lock and Unlock (3step)', checkItem: 'Function', standard: 'Must lock securely', method: 'Visual+touch' },
      { sl: 14, step: 3, item: 'RH fr seat belt drawing', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+Pull' },
      { sl: 15, step: 3, item: 'RH fr seat belt webbing lock', checkItem: 'Function', standard: 'Must be locked', method: 'Visual+Pull' },
      { sl: 16, step: 3, item: 'RH fr seat belt tongue X seat buckle lock', checkItem: 'Function', standard: 'Must be locked', method: 'Visual+touch' },
      { sl: 17, step: 3, item: 'LHD-Passenger seat belt warning indicator in combimeter', checkItem: 'Function', standard: 'Should light up/blink', method: 'Visual+touch' },
      { sl: 18, step: 4, item: 'RHD-All door Lock knob Manual switch function — All door Lock knob Manual switch lock (RHD)', checkItem: 'Function', standard: 'All dr lock knob should be locked', method: 'Visual+touch' },
      { sl: 19, step: 4, item: 'All door Lock knob Manual switch unlock (RHD)', checkItem: 'Function', standard: 'All dr lock knob should be unlocked', method: 'Visual+touch' },
      { sl: 20, step: 5, item: 'RH fr dr inside handle function — RH fr door inside door lock knob lock', checkItem: 'Function', standard: 'safety lock shall not be released', method: 'Visual+touch' },
      { sl: 21, step: 5, item: 'RH fr door inside door lock knob unlock', checkItem: 'Function', standard: 'safety lock shall be unlocked', method: 'Visual+touch' },
      { sl: 22, step: 5, item: 'RH fr door inside handle operation (operating state)', checkItem: 'Function', standard: 'Should be seculerly opened', method: 'Visual+Pull' },
      { sl: 23, step: 5, item: 'RH fr dr open (door catcher and stricker split off)', checkItem: 'Function', standard: 'Door should be completely opened', method: 'Visual+touch' },
      { sl: 24, step: 5, item: 'RH fr door inside handle fitment', checkItem: 'Looseness', standard: 'No Looseness', method: 'Visual+touch' },
      { sl: 25, step: 6, item: 'RH Sunvisor operation — RH sunvisor open(unlock) and left and right rotate', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual+Pull' },
      { sl: 26, step: 6, item: 'RH sunvisor X roof (screw)', checkItem: 'Looseness', standard: 'Lock securely', method: 'Visual' },
      { sl: 27, step: 6, item: 'RH sunvisor Holder X roof', checkItem: 'Looseness', standard: 'Lock securely', method: 'Visual+shake' },
      { sl: 28, step: 6, item: 'RH sunvisor up and down rotate', checkItem: 'Coming off', standard: 'should not come off', method: 'Visual+touch' },
      { sl: 29, step: 7, item: 'Over head console and Spot lamp — Inner rear view mirror x fr windshield', checkItem: 'Looseness', standard: 'Lock securely', method: 'Visual+Pull' },
      { sl: 30, step: 7, item: 'Inner rear view mirror antiglare manual Knob up down', checkItem: 'Function', standard: 'Smoothly', method: 'Visual+touch' },
      { sl: 31, step: 7, item: 'Spot lamp X Roof head lining RH side', checkItem: 'Clearance', standard: '1.0 mm', method: 'Visual' },
      { sl: 32, step: 7, item: 'Over head console open and close', checkItem: 'Operation', standard: 'Close smoothly', method: 'Visual+touch' },
      { sl: 33, step: 7, item: 'Spot lamp switch On', checkItem: 'Function', standard: 'should light up', method: 'Visual+touch' },
      { sl: 34, step: 7, item: 'Spot lamp switch Off', checkItem: 'Function', standard: 'should light off', method: 'Visual+touch' },
      { sl: 35, step: 7, item: 'Spot lamp lense LH light On and Off', checkItem: 'Function', standard: 'should light up/off', method: 'Visual+touch' },
      { sl: 36, step: 7, item: 'Spot lamp lense RH light On and Off', checkItem: 'Function', standard: 'should light up/off', method: 'Visual+touch' },
      { sl: 37, step: 7, item: 'Switch the Spot lamp to door position', checkItem: 'Door Position', standard: '', method: '' },
      { sl: 38, step: 8, item: 'Rh A pillar garnish Fitment — RH A Pillar Garnish X Roof head lining', checkItem: 'Clearance', standard: '1.0 mm', method: 'Visual' },
      { sl: 39, step: 8, item: 'RH A pillar Garnish X IP upper fitment', checkItem: 'Unlock', standard: 'Should be fitted securely', method: 'Visual' },
      { sl: 40, step: 8, item: 'RH Side IP register knob updown and left right movement', checkItem: 'Operation', standard: 'Smoothly', method: 'Touch + Feel' }
    ]
  },
  {
    id: 'lh_door_fitment',
    name: 'LH Door Fitment',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: 1, item: 'Pick the CPTS sheet and paste on Lh Fender', checkItem: 'Paste', standard: 'Designated location', method: 'Visual+Touch' },
      { sl: 2, step: 1, item: 'Scan vehicle GALC card by VDEM tab', checkItem: 'Scan', standard: '', method: '' },
      { sl: 3, step: 1, item: 'Lh Fr Dr fitment — Lh fr dr open (outside handle stroke)', checkItem: 'Function', standard: 'should be smoothly open', method: 'Visual+Touch' },
      { sl: 4, step: 4, item: 'LH Rr Dr W/H grommet fitment — LH Rr Dr W/H Grommet (Door side)', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual+feel' },
      { sl: 5, step: 4, item: 'LH Rr Dr W/H Grommet (Body side)', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual+feel' },
      { sl: 6, step: 4, item: 'LH Fr Dr Stricker Bolt #1', checkItem: 'Looseness/ Bolt mark miss', standard: 'Mark miss not allowed', method: 'Visual' },
      { sl: 7, step: 4, item: 'LH Fr Dr Stricker Bolt #2', checkItem: 'Looseness/ Bolt mark miss', standard: 'Mark miss not allowed', method: 'Visual' },
      { sl: 8, step: 9, item: 'LH Fr Dr W/H grommet fitment — LH FR Dr W/H Grommet (Body side)', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual+feel' },
      { sl: 9, step: 9, item: 'LH FR Dr W/H Grommet (Door side)', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual+feel' },
      { sl: 10, step: 12, item: 'LH Fr dr checker arm fitment — Lh fr dr checker arm bolt #1', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 11, step: 12, item: 'Lh fr dr checker arm Nut #1', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 12, step: 12, item: 'Lh fr dr checker arm Nutt #2', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 13, step: 14, item: 'LHD-LH Fr Dr power window Function — LHD-LH Fr dr master switch All dr power window glass Down operation', checkItem: 'Function', standard: 'Should operate', method: 'Visual+touch' },
      { sl: 14, step: 14, item: 'LHD-LH Fr dr master switch All dr power window glass Stop operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+touch' },
      { sl: 15, step: 14, item: 'LHD-LH Fr dr master switch All dr power window glass Lock operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+touch' },
      { sl: 16, step: 14, item: 'LHD-Lh fr dr master switch All dr power window glass unlock operation', checkItem: 'Function', standard: 'Should operate', method: 'Visual+touch' },
      { sl: 17, step: 14, item: 'LH Fr dr master switch All dr power window glass up operation', checkItem: 'Function', standard: 'Should operate', method: 'Visual+touch' },
      { sl: 18, step: 14, item: 'LH Fr dr power window Glass manual Up operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+touch' },
      { sl: 19, step: 14, item: 'LH Fr dr power window switch manual stop operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+touch' },
      { sl: 20, step: 14, item: 'LH Fr dr Glass manual / Auto down operation', checkItem: 'Function', standard: 'Should operate', method: 'Visual+touch' },
      { sl: 21, step: 14, item: 'LH Fr dr power window glass Auto Up operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+touch' },
      { sl: 22, step: 14, item: 'LH Fr dr Glass Anti pinch', checkItem: 'Function', standard: 'Window should be auto roll down', method: 'Visual+touch' },
      { sl: 23, step: 25, item: 'LH Fr Dr power window Function — LH Fr dr power window glass Down operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+Touch' },
      { sl: 24, step: 25, item: 'LH Fr dr power window switch stop operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+Touch' },
      { sl: 25, step: 25, item: 'LH Fr dr power window glass Up operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+Touch' },
      { sl: 26, step: 29, item: 'LH Fr dr Catcher screw Fitment — LH Fr dr lock knob self cancel operation', checkItem: 'Function', standard: 'Knob should get unlocked', method: 'Visual+Touch' },
      { sl: 27, step: 29, item: 'LH Fr door catcher and striker Body fitting', checkItem: 'Touching', standard: 'Smoothly', method: 'Visual+Touch' },
      { sl: 28, step: 29, item: 'LH Fr Door and stricker closing condition', checkItem: 'Function', standard: 'door should be locked firmly', method: 'Visual+Touch' },
      { sl: 29, step: '', item: 'CLOSE LH FR DOOR', checkItem: 'Abnormal noise', standard: 'No abnormal noise', method: 'Push+Hear' },
      { sl: 30, step: 35, item: 'Lh Rear Seat fitment and Operation — Lh RR dr open', checkItem: 'Open', standard: '', method: '' },
      { sl: 31, step: 35, item: 'Lh Rear seat back rest unlock', checkItem: 'Function', standard: 'Operate smoothly', method: 'Visual + Pull' },
      { sl: 32, step: 35, item: 'Lh Rear seat backrest lock (1 step)', checkItem: 'Function', standard: 'Lock securely', method: 'Visual + Pull' },
      { sl: 33, step: 35, item: 'Lh Rear seat backrest reclining Lock (2 step)', checkItem: 'Function', standard: 'Lock securely', method: 'Visual + Push' }
    ]
  },
  {
    id: 'rh_door_fitment',
    name: 'Rh Door Fitment',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan vehicle GALC card by VDEM tab', checkItem: 'Scan', standard: '', method: '' },
      { sl: 2, step: '', item: 'Rh Fr dr', checkItem: 'Open', standard: '', method: '' },
      { sl: 3, step: 2, item: 'Rh Rr Dr W/H grommet fitment — RH Rr Dr W/H Grommet (Door side)', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual+feel' },
      { sl: 4, step: 2, item: 'RH Rr Dr W/H Grommet (Body side)', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual+feel' },
      { sl: 5, step: '', item: 'Rh Fr Dr Stricker Bolt #1', checkItem: 'Looseness/ Bolt mark miss', standard: 'Mark miss not allowed', method: 'Visual' },
      { sl: 6, step: '', item: 'Rh Fr Dr Stricker Bolt #2', checkItem: 'Looseness/ Bolt mark miss', standard: 'Mark miss not allowed', method: 'Visual' },
      { sl: 7, step: 4, item: 'Rh Fr Dr W/H grommet fitment — RH FR Dr W/H Grommet (Body side)', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual+feel' },
      { sl: 8, step: 4, item: 'RH FR Dr W/H Grommet (Door side)', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual+feel' },
      { sl: 9, step: 5, item: 'Rh Fr Dr checker arm fitment — Rh Fr dr Tweeter', checkItem: 'Function', standard: 'Should sound', method: 'Hear' },
      { sl: 10, step: 6, item: 'Rh Fr Dr power window Function — RH Fr dr master switch All dr power window glass Down operation', checkItem: 'Function', standard: 'Should operate', method: 'Visual+touch' },
      { sl: 11, step: 6, item: 'RH Fr dr master switch All dr power window glass Stop operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+touch' },
      { sl: 12, step: 6, item: 'RH Fr dr master switch All dr power window glass Lock operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+touch' },
      { sl: 13, step: 6, item: 'All dr power window master switch stop operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+touch' },
      { sl: 14, step: 6, item: 'RH Fr dr master switch All dr power window glass up operation', checkItem: 'Function', standard: 'Should operate', method: 'Visual+touch' },
      { sl: 15, step: 6, item: 'Rh Fr dr power window Glass manual Up operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+touch' },
      { sl: 16, step: 6, item: 'Rh Fr dr power window switch manual stop operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+touch' },
      { sl: 17, step: 6, item: 'Rh Fr dr Glass manual / Auto down operation', checkItem: 'Function', standard: 'Should operate', method: 'Visual+touch' },
      { sl: 18, step: 6, item: 'Rh Fr dr power window glass Auto Up operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+touch' },
      { sl: 19, step: 6, item: 'Rh Fr dr Glass Anti pinch', checkItem: 'Function', standard: 'Window should be auto roll down', method: 'Visual+touch' },
      { sl: 20, step: '', item: 'Close the Rh Fr dr window glass (auto up)', checkItem: 'Close', standard: '', method: '' },
      { sl: 21, step: 7, item: 'LHD-Rh Fr Dr power window Function — LHD-Rh Fr dr power window glass Down operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+Touch' },
      { sl: 22, step: 7, item: 'LHD-Rh Fr dr power window switch stop operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+Touch' },
      { sl: 23, step: 7, item: 'LHD-Rh Fr dr power window glass Up operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+Touch' },
      { sl: 24, step: 8, item: 'Rh Fr dr Catcher screw Fitment — Rh Fr dr lock knob self cancel operation', checkItem: 'Function', standard: 'Knob should get unlocked', method: 'Visual+Touch' },
      { sl: 25, step: 1, item: 'Rh Rear Seat fitment and Operation — Rh Rr dr', checkItem: 'Open', standard: '', method: '' },
      { sl: 26, step: '', item: 'Rh Rear seat back rest unlock', checkItem: 'Function', standard: 'Operate smoothly', method: 'Visual + Pull' },
      { sl: 27, step: '', item: 'Rh Rear seat backrest lock (1 step)', checkItem: 'Function', standard: 'Lock securely', method: 'Visual + Pull' },
      { sl: 28, step: '', item: 'Rh Rear seat backrest reclining Lock (2 step)', checkItem: 'Function', standard: 'Lock securely', method: 'Visual + Push' },
      { sl: 29, step: 2, item: 'Rh Rear seat head rest Operation — Rh Rear seat head rest up and down operation', checkItem: 'Function', standard: 'Should move smoothly', method: 'Visual+touch' },
      { sl: 30, step: 3, item: 'Rh Rear seat belt Operation — Rh Rear seat belt drawing function', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual + Pull' },
      { sl: 31, step: 3, item: 'Rh Rear seat belt Webbing lock', checkItem: 'Function', standard: 'Must lock securely', method: 'Visual + Pull' },
      { sl: 32, step: 3, item: 'RH Rear seat belt retractor', checkItem: 'Performance', standard: 'Return Smoothly', method: 'Visual+touch' },
      { sl: 33, step: 3, item: 'Rh Rear seat belt tongue x buckle lock function', checkItem: 'Operation', standard: 'Must lock securely', method: 'Visual + Push' },
      { sl: 34, step: 4, item: 'Rear center Seat belt operation — Rear seat center seat belt drawing function', checkItem: 'Operation', standard: 'Smoothly', method: 'Visual + Pull' },
      { sl: 35, step: 4, item: 'Rear seat center seat belt webbing Lock', checkItem: 'Operation', standard: 'Must lock securely', method: 'Visual + Pull' }
    ]
  },
  {
    id: 'back_door_ext_spec',
    name: 'Back Door Ext Spec',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan the vehicle CPTS by VDEM tab', checkItem: 'Scan', standard: 'NA', method: 'Visual + Touch' },
      { sl: 2, step: '', item: 'Roof Panel Spec — Shark Fin', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 3, step: '', item: 'Spoiler', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 4, step: '', item: 'Lh Qtr Panel Spec — Fuel Limitation Lable', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 5, step: '', item: 'CNG - ID Plate Scan', checkItem: 'Number Mismatch', standard: 'Not Allowed', method: 'Visual' },
      { sl: 6, step: 5, item: 'Fuel Lidinside Fitment — Fuel Filler cap', checkItem: 'Looseness', standard: 'Fitted securely', method: 'Visual+Touch' },
      { sl: 7, step: 5, item: 'Fuel inlet pipe bolt 2 nos', checkItem: 'Looseness', standard: 'Fitted securely', method: 'Visual' },
      { sl: 8, step: 5, item: 'Fuel inlet pipe neck cover', checkItem: 'Looseness', standard: 'Fitted securely', method: 'Visual+Pull' },
      { sl: 9, step: 5, item: 'Fuel Lid inside CNG filler tube bolt (Only CNG)', checkItem: 'Looseness', standard: 'Fitted securely', method: 'Visual' },
      { sl: 10, step: 5, item: 'Fuel Lid inside CNG filler cap (Only CNG)', checkItem: 'Looseness', standard: 'Fitted securely', method: 'Visual' },
      { sl: 11, step: 5, item: 'Fuel Lid curtesy switch (Only CNG)', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual+Touch' },
      { sl: 12, step: 5, item: 'Fuel Lid inside plug seal (2No)', checkItem: 'Missing', standard: 'Miss Not allowed', method: 'Visual' },
      { sl: 13, step: 5, item: 'Fuel Lid cushion rubber (2No)', checkItem: 'Missing', standard: 'Miss Not allowed', method: 'Visual' },
      { sl: 14, step: 5, item: 'Fuel Lid Lock (Use Jig to lock check)', checkItem: 'Function', standard: 'Lock securly', method: 'Visual+Touch' },
      { sl: 15, step: '', item: 'Rear Bumper Spec — Back Center Sonar LH', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 16, step: '', item: 'Back Center Sonar RH', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 17, step: '', item: 'Back Dr Inner Spec — Luggage room board (Except CNG)', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 18, step: '', item: 'Theft Deterrent Label Scan', checkItem: 'Number Mismatch', standard: 'Not Allowed', method: 'Visual+Scan' },
      { sl: 19, step: '', item: 'Theft Deterrent Label appearance check', checkItem: 'Reverse check &', standard: 'Not Allowed', method: 'Visual' },
      { sl: 20, step: '', item: 'Luggage Lamp', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 21, step: '', item: 'Rh side Damper Stay', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 22, step: '', item: 'Package tray', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 23, step: '', item: 'LH side Damper Stay', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 24, step: 3, item: 'Back door Grommet Fitment — Backdoor W/H grommet Door side', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual + Feel' },
      { sl: 25, step: 3, item: 'Backdoor W/H grommet Body side', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual + Feel' },
      { sl: 26, step: 3, item: 'Back door window washer hose grommet/dummy grommet Door side', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual + Feel' },
      { sl: 27, step: 3, item: 'Back door window washer hose grommet/dummy grommet Body side', checkItem: 'Insertion', standard: 'Inserted firmly', method: 'Visual + Feel' },
      { sl: 28, step: 2, item: 'Back door room lamp check — Luggage room lamp S/W OFF', checkItem: 'Function', standard: 'Light should be OFF', method: 'Visual + Push' },
      { sl: 29, step: 2, item: 'Luggage room lamp S/W ON (Door position)', checkItem: 'Function', standard: 'Light should be ON', method: 'Visual + Push' },
      { sl: 30, step: 5, item: 'Back door Rr bumper sonar fitment — Back door stricker Bolt #1', checkItem: 'Looseness', standard: 'No looseness', method: 'Visual' },
      { sl: 31, step: 5, item: 'Back door stricker Bolt #2', checkItem: 'Looseness', standard: 'No looseness', method: 'Visual' },
      { sl: 32, step: 7, item: 'Back door closing — Back door closing function', checkItem: 'Lock Function', standard: 'should lock certainly with out looseness', method: 'Visual + Push' },
      { sl: 33, step: 7, item: 'Back door closing', checkItem: 'Abnormal noise', standard: 'No abnormal', method: 'Hear' },
      { sl: 34, step: '', item: 'Rh Back door Tail lamp X Stop Lamp', checkItem: 'Levelness', standard: 'Plus 0.5 ~ minus 3.5', method: 'Visual+touch' },
      { sl: 35, step: '', item: 'Lh Back door Tail lamp X Stop Lamp', checkItem: 'Levelness', standard: 'Plus 0.5 ~ minus 3.5', method: 'Visual+touch' },
      { sl: 36, step: '', item: 'Back Dr Outer Spec — Back Door Glass', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 37, step: '', item: 'BD Glass Approval mark', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 38, step: '', item: 'CNG Label RR', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 39, step: '', item: 'Back dr Glass Nexa name', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 40, step: '', item: 'Tail Gate Garnish', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 41, step: '', item: 'RR Camera', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 42, step: '', item: 'Back door Garnish', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 43, step: '', item: 'Rear Car Name Tag', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 44, step: 8, item: 'Defect entry — Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 45, step: 8, item: 'Walk to home position', checkItem: '', standard: '', method: '' }
    ]
  },
  {
    id: 'eg_room_spec',
    name: 'EG Room Spec',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan the vehicle CPTS by VDEM tab', checkItem: 'Scan', standard: 'NA', method: 'Visual + Touch' },
      { sl: 2, step: '', item: 'Fr Ext Spec — RH Headlamp Bezel', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 3, step: '', item: 'RH Fog Lamp Cover', checkItem: 'Missing / Extra part/ Wrong Color', standard: 'Not Allowed', method: 'Visual' },
      { sl: 4, step: '', item: 'Fr Bumper Lower garnish', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 5, step: '', item: 'LH Fog Lamp Cover', checkItem: 'Missing / Extra part/ Wrong Color', standard: 'Not Allowed', method: 'Visual' },
      { sl: 6, step: '', item: 'LH Headlamp Bezel', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 7, step: '', item: 'FR Camera', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 8, step: '', item: 'Front Grill Type colour #1', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 9, step: '', item: 'Front Grill Type colour #2', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 10, step: '', item: 'Front Grill Type colour #3', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 11, step: '', item: 'Hood Inner Caution Lables — Cooling Fan lable', checkItem: 'Missing / Extra part/ Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 12, step: '', item: 'AC LABEL', checkItem: 'Missing / Extra part/ Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 13, step: '', item: 'Battery Information Lable', checkItem: 'Missing / Extra part/ Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 14, step: '', item: 'Battery Notice Lable / Ignition Warning label', checkItem: 'Missing / Extra part/ Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 15, step: '', item: 'E/G Room Spec — Scan Engine Number Label in Engine', checkItem: 'Mismatch / Wrong', standard: 'Mismatch not allowed', method: 'Visual+Scan' },
      { sl: 16, step: '', item: 'RH Fender Cover', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 17, step: '', item: 'Brake Booster', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 18, step: '', item: 'Alternator', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 19, step: '', item: 'Engine Type', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 20, step: '', item: 'Air Cleanner Resonator', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 21, step: '', item: 'Transaxle (Transmission)', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 22, step: '', item: 'Battery Cover', checkItem: 'Missing / Extra part/ Wrong part', standard: 'Not Allowed', method: 'Visual + Touch' },
      { sl: 23, step: '', item: 'Fuse box', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 24, step: '', item: 'LH Fender Cover', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 25, step: 1, item: 'THS - Spec check — Inverer Deg tank hose X Inverter upper side (THS)', checkItem: 'Hose mark', standard: 'Yellow', method: 'Visual' },
      { sl: 26, step: 1, item: 'Heater outlet hose no.1 X pipe component heater (small) (THS)', checkItem: 'Hose mark', standard: 'White', method: 'Visual' },
      { sl: 27, step: 1, item: 'Heater outlet hose no.2 X pipe component heater (Big) (THS)', checkItem: 'Hose mark', standard: 'Green', method: 'Visual' },
      { sl: 28, step: '', item: 'E/G Room Spec — Reservoir hose X Reservoir (THS)', checkItem: 'Hose mark', standard: 'White', method: 'Visual' },
      { sl: 29, step: '', item: 'Reservoir hose X BMC (THS)', checkItem: 'Hose mark', standard: 'Purple', method: 'Visual' },
      { sl: 30, step: '', item: 'Reservoir hose (towards brake booster pump) X Reservoir (THS)', checkItem: 'Hose mark', standard: 'White', method: 'Visual' },
      { sl: 31, step: '', item: 'Reservoir hose X Reservoir pipe (THS)', checkItem: 'Hose mark', standard: 'Blue', method: 'Visual' },
      { sl: 32, step: '', item: 'Inverter deg Tank hose #2 X Tank assy degassing (THS)', checkItem: 'Hose mark', standard: 'White', method: 'Visual' },
      { sl: 33, step: '', item: 'Deg tank pump hose X Tank assy degassing (THS)', checkItem: 'Hose mark', standard: 'Yellow', method: 'Visual' },
      { sl: 34, step: 2, item: 'Hood Operation — Hood auxilary lock secondory lock (safety lock)', checkItem: 'Function', standard: 'Shall be securely locked', method: 'Visual+touch' },
      { sl: 35, step: 2, item: 'Hood auxilary lock secondory unlock (safety lock)', checkItem: 'Function', standard: 'Should Unlock when locked', method: 'Visual+touch' },
      { sl: 36, step: 2, item: 'Hood lock function (Hood close function)', checkItem: 'Function', standard: 'Shall be securely locked', method: 'Visual+touch' },
      { sl: 37, step: 8, item: 'Defect entry — Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 38, step: 8, item: 'Walk to home position', checkItem: '', standard: '', method: '' }
    ]
  },
  {
    id: 'lh_surface',
    name: 'Lh Surface',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan the vehicle CPTS by VDEM tab', checkItem: 'Scan', standard: 'NA', method: 'Visual + Touch' },
      { sl: 2, step: '', item: 'LH FENDER APPEARANCE (D&B) — LH Fender Appearance', checkItem: 'Dent', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 3, step: '', item: 'LH Fender Appearance', checkItem: 'Bump', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 4, step: '', item: 'LH FRONT DOOR APPEARANCE (D&B) — LH Fr A Pillar & Side Member Appearance', checkItem: 'Dent', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 5, step: '', item: 'LH Fr A Pillar & Side Member Appearance', checkItem: 'Bump', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 6, step: '', item: 'LH Fr Door Appearance', checkItem: 'Dent', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 7, step: '', item: 'LH Fr Door Appearance', checkItem: 'Bump', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 8, step: '', item: 'LH FENDER & FRONT DOOR SCRATCH CHECK — LH Fender Appearance', checkItem: 'Scratch', standard: '6 MMNG', method: 'Visual' },
      { sl: 9, step: '', item: 'LH Fr Door Outer Panel Appearance', checkItem: 'Scratch', standard: '6 MM NG', method: 'Visual' },
      { sl: 10, step: '', item: 'Fr A Pillar Side Member Appearance', checkItem: 'Scratch', standard: 'Zone A < 6.0, MM NG', method: 'Visual' },
      { sl: 11, step: '', item: 'LH Fr Door Tape', checkItem: 'Scratch/ Bubble', standard: 'Zone A < 6.0, / 1.5Ø X 3 Pcs', method: 'Visual' },
      { sl: 12, step: '', item: 'LH RR DR & QTR PANEL SCRATCH CHECK — LH Rr Door Appearance', checkItem: 'Scartch', standard: 'A> Rank 6 MMNG', method: 'Visual/Hand' },
      { sl: 13, step: '', item: 'LH Rr Dr Tape & Rr Side Member Apperence', checkItem: 'Scartch/Bubble', standard: 'Zone A < 6.0, / 1.5Ø X 3 Pcs', method: 'Visual' },
      { sl: 14, step: '', item: 'Side Member outer LH Rr side Appearance', checkItem: 'Scartch', standard: 'A> Rank 6MM NG', method: 'Visual' },
      { sl: 15, step: '', item: 'LH Rr side QTR panel Appearance', checkItem: 'Scartch', standard: 'A> Rank 6MM NG', method: 'Visual' },
      { sl: 16, step: '', item: 'LH RR DR & QTR PANEL APPEARANCE (D&B) — LH Side Member Outer Appearance', checkItem: 'Dent', standard: 'A < Rank 4 NG', method: 'Visual' },
      { sl: 17, step: '', item: 'LH Side Member Outer Appearance', checkItem: 'Bump', standard: 'A < Rank 4 NG', method: 'Visual' },
      { sl: 18, step: '', item: 'LH Rr Dr Outer Panel Appearance', checkItem: 'Dent', standard: 'A ≤ Rank 4 NG', method: 'Visual' },
      { sl: 19, step: '', item: 'LH Rr Dr Outer Panel Appearance', checkItem: 'Bump', standard: 'A ≤ Rank 4 NG', method: 'Visual' },
      { sl: 20, step: '', item: 'LH QTR Pannel', checkItem: 'Dent', standard: 'A ≤ Rank 4 NG', method: 'Visual' },
      { sl: 21, step: '', item: 'LH QTR Pannel', checkItem: 'Bump', standard: 'A ≤ Rank 4 NG', method: 'Visual' }
    ]
  },
  {
    id: 'hood_surface',
    name: 'Hood Surface',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan the vehicle CPTS by VDEM tab', checkItem: 'Scan', standard: 'NA', method: 'Visual + Touch' },
      { sl: 2, step: '', item: 'Collect the CPTS and Paste on Rh Side Fr Bumper', checkItem: 'Collect and Stick', standard: '', method: '' },
      { sl: 3, step: '', item: 'LH ROOF PANEL APPEARANCE (D&B) — LH Fr Side Roof (A Zone)', checkItem: 'Dent', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 4, step: '', item: 'LH Fr Side Roof (A Zone)', checkItem: 'Bump', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 5, step: '', item: 'LH HOOD APPEARANCE — LH Hood Outer Panel Appearance', checkItem: 'Dent', standard: 'Zone A < Rank 4 NG', method: 'Visual' },
      { sl: 6, step: '', item: 'LH Hood Outer Panel Appearance', checkItem: 'Bump', standard: 'Zone A < Rank 4 NG', method: 'Visual' },
      { sl: 7, step: '', item: 'LH Hood Outer Panel Appearance', checkItem: 'Scratch', standard: 'A> Rank 6MM NG', method: 'Visual' },
      { sl: 8, step: '', item: 'RH HOOD APPEARANCE — RH Hood Outer Panel Appearance', checkItem: 'Scratch', standard: 'A> Rank 6MM NG', method: 'Visual' },
      { sl: 9, step: '', item: 'RH Hood Outer Panel Appearance', checkItem: 'Dent', standard: 'Zone A < Rank 4 NG', method: 'Visual' },
      { sl: 10, step: '', item: 'RH Hood Outer Panel Appearance', checkItem: 'Bump', standard: 'Zone A < Rank 4 NG', method: 'Visual' },
      { sl: 11, step: '', item: 'RH ROOF APPEARANCE — RH Fr Side Roof (A Zone)', checkItem: 'Dent', standard: 'Zone A< Rank 4 NG', method: 'Visual' },
      { sl: 12, step: '', item: 'RH Fr Side Roof (A Zone)', checkItem: 'Bump', standard: 'Zone A< Rank 4 NG', method: 'Visual' }
    ]
  },
  {
    id: 'rh_pit_fitment',
    name: 'Rh Pit Fitment',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: 1, item: 'Fr Bumper fitment — RH side front bumper X Fender', checkItem: 'Levelness', standard: 'plus 0.8 ~ minus2.0', method: 'Visual + Feel' },
      { sl: 2, step: 1, item: 'Rh fr wheel hub nut tightening mark', checkItem: 'white Paint mark', standard: 'Mark miss NG', method: 'Visual' },
      { sl: 3, step: '', item: 'Scan vehicle GALC card by VDEM tab', checkItem: 'Scan', standard: '', method: '' },
      { sl: 4, step: '', item: 'Front Bumper Spec check', checkItem: 'Wrong Color', standard: 'Body Color', method: 'Visual' },
      { sl: 5, step: '', item: 'RH Fr bumper Lower', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 6, step: '', item: 'RH Fr Wheel Arch Molding', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 7, step: '', item: 'RH Fr Tyre make', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 8, step: '', item: 'RH Fr Wheel Disc', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 9, step: '', item: 'RH Fr dr Name mark', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 10, step: 2, item: 'Vin Plate and Engine number check — RH B Pillar Vin label Manufacture Spec check', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 11, step: 2, item: 'Vin label Frame number 17 digit and Engine number 12 digit Content in Rh B Pillar', checkItem: 'Mismatch', standard: 'Green in VDEM Must match with CPTS', method: 'Visual+Scan' },
      { sl: 12, step: 2, item: 'Vin label Appearance (Rh B pillar)', checkItem: 'Damage', standard: 'No Tear or Cut', method: 'Visual' },
      { sl: 13, step: 2, item: 'Vin label frame number Print content (Rh B Pillar)', checkItem: 'Reverse Fit', standard: 'Should be readable', method: 'Visual' },
      { sl: 14, step: '', item: 'Rh B Pillar SIDE AIRBAG', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 15, step: '', item: 'Rh B Plr Tyre information Lable (RHD)', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 16, step: '', item: 'Rh Fr seat (Power / manual)', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 17, step: 3, item: 'Rh Fr dr scuffplate fitment — RH Fr dr Scuff plate X B pillar lower garnish', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual + Feel' },
      { sl: 18, step: 3, item: 'RH Fr dr Scuff plate X Cowl board trim (CBT)', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual + Feel' },
      { sl: 19, step: 3, item: 'RH Foot Lamp Spec check', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 20, step: 3, item: 'RH Fr dr speaker', checkItem: 'Function', standard: 'should sound', method: 'Hear' },
      { sl: 21, step: 3, item: 'RH Fr dr trim Lamp Spec check', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 22, step: 3, item: 'Rh Fr Dr Cushion rubber 2 nos', checkItem: 'Missing', standard: 'Miss part not allowed', method: 'Visual' },
      { sl: 23, step: 4, item: 'Rh Rr dr scuffplate and rocker mould fitment — Rh Rr dr open', checkItem: 'Open', standard: '', method: '' },
      { sl: 24, step: 4, item: 'Rh Rr dr Scuffplate X Qtr trim', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual + Feel' },
      { sl: 25, step: 4, item: 'Rh Fr Seat Belt Tongue (label-R) Spec check', checkItem: 'Wrong Part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 26, step: 4, item: 'RH Rr dr speaker', checkItem: 'Function', standard: 'should sound', method: 'Hear' },
      { sl: 27, step: 4, item: 'Rh Rr Dr Speaker Spec check', checkItem: 'Missing', standard: 'Not Allowed', method: 'Visual +Hear' },
      { sl: 28, step: 4, item: 'Rh Rr Dr Cushion rubber 2 nos', checkItem: 'Missing', standard: 'Miss part not allowed', method: 'Visual' },
      { sl: 29, step: 5, item: 'Rh Rr wheel area fitment — Rh Rr wheel hub nut tightening mark', checkItem: 'white Paint mark', standard: 'Mark miss NG', method: 'Visual' },
      { sl: 30, step: 5, item: 'Rh Rr Wheel Disc', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 31, step: 5, item: 'Rh Rr Tyre Make', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 32, step: 5, item: 'Rh Rr Wheel Arch Molding', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 33, step: 5, item: 'Rh Rr bumper Lower', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 34, step: '', item: 'Rear Bumper Spec check', checkItem: 'Wrong Color', standard: 'Body Color', method: 'Visual' },
      { sl: 35, step: '', item: 'Rh Side Back Sonar spec check', checkItem: 'Wrong Part', standard: 'Bumper color', method: 'Visual' },
      { sl: 36, step: '', item: 'Rr Bumper Lower Garnish Color', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 37, step: '', item: 'Rr Bumper Lower Garnish Type (T-1 / T-2)', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 38, step: '', item: 'Rear Engine Tag (Hybrid/Smart Hybrid/Neo Drive)', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 39, step: '', item: 'Rear Tags (All Grip)', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 40, step: '', item: 'Rear Grade Tag (G,V,S,E)', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 41, step: 6, item: 'Defect entry — Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 42, step: 6, item: 'Walk to home position', checkItem: '', standard: '', method: '' }
    ]
  },
  {
    id: 'lh_pit_fitment',
    name: 'Lh Pit Fitment',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: 1, item: 'Fr Bumper fitment — Lh side front bumper X Fender', checkItem: 'Levelness', standard: 'plus 0.8 ~ minus2.0', method: 'Visual + Feel' },
      { sl: 2, step: 1, item: 'Lh fr wheel hub nut tightening mark', checkItem: 'White Paint mark', standard: 'Mark miss NG', method: 'Visual' },
      { sl: 3, step: '', item: 'Scan vehicle GALC card by VDEM tab', checkItem: 'Scan', standard: '', method: '' },
      { sl: 4, step: '', item: 'Remove the CPTS from Lh Arch mould and stick it on Fr bumber Lh side', checkItem: 'Remove and stick', standard: '', method: '' },
      { sl: 5, step: 2, item: 'Lh Fr Dr inner Spec check — LH Fr Tyre make', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 6, step: 2, item: 'Lh Fr Wheel Disc', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 7, step: 2, item: 'LH Fr Wheel Arch Molding', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 8, step: 2, item: 'LH Fr bumper Lower', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 9, step: 2, item: 'LH Fr dr Name mark', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 10, step: 2, item: 'LHD-Arabic Vin label Frame number 17 digit Content in Lh B Pillar X CPTS', checkItem: 'Mismatch', standard: 'Green in VDEM Must match with CPTS', method: 'Visual+Scan' },
      { sl: 11, step: 2, item: 'LHD-Arabic Vin label Frame number (Lh B Pillar)', checkItem: 'Reverse Fit', standard: 'Should be readable', method: 'Visual' },
      { sl: 12, step: 2, item: 'LHD-Arabic Vin label appearance (Lh B Pillar)', checkItem: 'Damage', standard: 'No Tear or Cut', method: 'Visual' },
      { sl: 13, step: '', item: 'Lh Opening Area Spec — LH B Pillar Label Vin (Arabic Vin Label)', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 14, step: '', item: 'Lh fr seat (Power / Manual)', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 15, step: '', item: 'ISG Battery cover(Seat below) / Extinguisher (CNG) (Seat below)', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 16, step: 3, item: 'Lh Fr dr scuffplate fitment — Lh Fr dr Scuff plate X B pillar lower garnish', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual + feel' },
      { sl: 17, step: 3, item: 'Lh Fr dr Scuff plate X Cowl Board Trim (CBT)', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual + feel' },
      { sl: 18, step: 3, item: 'LH Foot Lamp Spec check', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 19, step: 3, item: 'Floor carpet material type Speck check', checkItem: 'Wrong Part', standard: 'White / Black', method: 'Visual+Touch' },
      { sl: 20, step: 3, item: 'Lh Fr Dr Speaker (only for with audio)', checkItem: 'Function', standard: 'should sound', method: 'Hear' },
      { sl: 21, step: 3, item: 'LH Fr Dr trim Lamp Spec check', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 22, step: 3, item: 'Lh Fr Dr Cushion rubber 2 nos', checkItem: 'Missing', standard: 'Miss part not allowed', method: 'Visual' },
      { sl: 23, step: 4, item: 'Lh Rr dr scuffplate and rocker mould fitment — Lh Rr dr open', checkItem: 'Open', standard: '', method: '' },
      { sl: 24, step: 4, item: 'Lh Rr dr Scuffplate X Qtr trim', checkItem: 'Unlock', standard: 'Fitted securely', method: 'Visual + feel' },
      { sl: 25, step: 4, item: 'Lh Fr Seat Belt Tongue (label -L) Spec check', checkItem: 'Wrong Part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 26, step: 4, item: 'LH Rr dr speaker', checkItem: 'Function', standard: 'should sound', method: 'Hear' },
      { sl: 27, step: 4, item: 'Lh Rr Dr Speaker Spec check', checkItem: 'Missing', standard: 'Not Allowed', method: 'Visual +Hear' },
      { sl: 28, step: 4, item: 'Lh Rr Dr Cushion rubber 2nos', checkItem: 'Missing', standard: 'Miss part not allowed', method: 'Visual' },
      { sl: 29, step: 6, item: 'Lh Rr wheel area fitment — Lh Rr wheel hub nut tightening mark', checkItem: 'White Paint mark', standard: 'Mark miss NG', method: 'Visual' },
      { sl: 30, step: 6, item: 'Lh Rr Name mark', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 31, step: 6, item: 'Lh Rocker mould', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 32, step: 6, item: 'Lh Rr Wheel Disc', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 33, step: 6, item: 'Lh Rr Tyre make', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 34, step: 6, item: 'LH Rr Wheel Arch Molding', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 35, step: 6, item: 'LH Rr bumper Lower', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 36, step: 6, item: 'Lh Side Back Sonar Spec check', checkItem: 'Wrong Part', standard: 'Bumper color', method: 'Visual' },
      { sl: 37, step: 7, item: 'Defect entry — Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 38, step: 7, item: 'Walk to home position', checkItem: '', standard: '', method: '' }
    ]
  },
  {
    id: 'rh_dynamic',
    name: 'Rh Dynamic',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: 1, item: 'RH FR DR FITMENT — Scan vehicle GALC card by VDEM tab', checkItem: 'Scan', standard: '', method: '' },
      { sl: 2, step: 2, item: 'DR FITMENT — RH Side Fr windshield protector X A Piller', checkItem: 'Clearance', standard: '3.6+/-2.0mm.', method: 'Visual' },
      { sl: 3, step: 1, item: 'Rh Fr Dr fitment — RH Fr Door and stricker closing condition', checkItem: 'Function', standard: 'door should be locked firmly', method: 'Visual+Touch' },
      { sl: 4, step: 1, item: 'Rh fr dr open (outside handle stroke)', checkItem: 'Function', standard: 'should be smoothly open', method: 'Visual+Touch' },
      { sl: 5, step: 1, item: 'Rh Fr door catcher and striker Body fitting', checkItem: 'Touching', standard: 'Smoothly', method: 'Visual+Touch' },
      { sl: 6, step: '', item: 'CLOSE THE RH FR DOOR', checkItem: 'Abnormal noise', standard: 'No abnormal noise', method: 'Push+Hear' },
      { sl: 7, step: '', item: 'LHD-RH fr Assist grip open', checkItem: 'Operation', standard: 'No sticky', method: 'Touch' },
      { sl: 8, step: '', item: 'LHD-RH fr Assist grip assembly condition', checkItem: 'Looseness', standard: 'Lock securely', method: 'Touch + Feel' },
      { sl: 9, step: '', item: 'LHD-RH fr Assist grip Retract (pull down and release)', checkItem: 'Operation', standard: 'Auto return to normal position', method: 'Visual + Touch' },
      { sl: 10, step: '', item: 'LHD-Glove box door Fitment — LHD-Glove box lock knob unlock', checkItem: 'Function', standard: 'Should be unlock', method: 'Touch + Feel' },
      { sl: 11, step: '', item: 'LHD-Glove box door open and close', checkItem: 'Operation', standard: 'Smoothly', method: 'Touch + Feel' },
      { sl: 12, step: '', item: 'LHD-Glove box lock knob lock', checkItem: 'Function', standard: 'Should be lock', method: 'Touch + Feel' },
      { sl: 13, step: 7, item: 'RHD-Outer view Mirror operation — RH door outer rear view mirror Folding', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 14, step: 7, item: 'LH door outer rear view mirror Folding', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 15, step: 7, item: 'LH door outer rear view mirror Retract', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 16, step: 7, item: 'RH door outer rear view mirror Retract', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 17, step: 7, item: 'RH door outer rear view mirror angle adjust up', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 18, step: 7, item: 'RH door outer rear view mirror angle adjust down', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 19, step: 7, item: 'RH door outer rear view mirror angle adjust left', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 20, step: 7, item: 'RH door outer rear view mirror angle adjust right', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 21, step: 7, item: 'LH door outer rear view mirror angle adjust up', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 22, step: 7, item: 'LH door outer rear view mirror angle adust down', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 23, step: 7, item: 'LH door outer rear view mirror angle adjust left', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 24, step: 7, item: 'LH door outer rear view mirror angle adjust right', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 25, step: '', item: 'Rh fr dr cather screw #1', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 26, step: '', item: 'Rh fr dr cather screw #2', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 27, step: '', item: 'Rh fr dr cather screw #3', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 28, step: '', item: 'Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 29, step: 4, item: 'VDEM Web system process — Place the cursor on the VIN number box on the computer screen', checkItem: 'Click the mouse', standard: '', method: '' }
    ]
  },
  {
    id: 'rh_rr_ext_spec',
    name: 'Rh Rr Ext Spec',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan the vehicle CPTS by VDEM tab', checkItem: 'Scan', standard: 'NA', method: 'Visual + Touch' },
      { sl: 2, step: '', item: 'Rh Rr DR Ext Spec — Rh Roof Rail', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 3, step: '', item: 'Rh Rr Dr sash Black-out', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 4, step: '', item: 'Rh Rear Dr Glass', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 5, step: '', item: 'Rh Rr Dr Glass Approval mark', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 6, step: '', item: 'Rh Rr dr Belt Mould', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 7, step: '', item: 'Rh Rr Dr out side Handle', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 8, step: '', item: 'Rh Rr Dr Name mark', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 9, step: '', item: 'Rh Rocker mould', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 10, step: '', item: 'Rh Rr Dr Child Lock Stamping', checkItem: 'Miss part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 11, step: '', item: 'Rh Rr Dr Trim Spec — Rh Rear Dr Sunshade Hook', checkItem: 'Missing part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 12, step: '', item: 'Rh Rear Dr Sunshade', checkItem: 'Missing part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 13, step: '', item: 'Rh Rear Dr Trim material', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 14, step: '', item: 'Rh Rr Dr Inside Handle lamp', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 15, step: '', item: 'Rh Rr Dr Inside Handle', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 16, step: '', item: 'Rh Rr Dr Window Switch bezel', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 17, step: '', item: 'Rh Rr Dr opening Spec — Lh Rr Dr Reading lamp', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 18, step: '', item: 'Console Rear Vent', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 19, step: '', item: 'Rh Rr Seat Fabric', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 20, step: '', item: 'Rh Rr Seat color', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 21, step: '', item: 'Rh Rr Seat belt indicator', checkItem: 'Missing / extra', standard: 'Not Allowed', method: 'Visual' },
      { sl: 22, step: '', item: 'Rh Qtr trim Cooling Duct', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 23, step: 10, item: 'Rh Rr dr Striker fitment — Rh Rr Dr Stricker Bolt #1', checkItem: 'Looseness/ Bolt mark miss', standard: 'Mark miss not allowed', method: 'Visual' },
      { sl: 24, step: 10, item: 'Rh Rr Dr Stricker Bolt #2', checkItem: 'Looseness/ Bolt mark miss', standard: 'Mark miss not allowed', method: 'Visual' },
      { sl: 25, step: 11, item: 'Rh Rr dr Glass operation — Rh Rr dr power window glass down operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+Touch' },
      { sl: 26, step: 11, item: 'Rh Rr dr power window switch stop operation', checkItem: 'Function', standard: 'Operation should stop', method: 'Visual+Touch' },
      { sl: 27, step: 11, item: 'Rh Rr dr power window glass up operation', checkItem: 'Function', standard: 'Should be satisfactory', method: 'Visual+Touch' },
      { sl: 28, step: 11, item: 'Rh Rr Dr Sunshade — Rh Rr Dr Sunshade up', checkItem: 'Operation', standard: 'Should be satisfactory', method: 'Visual+Touch' },
      { sl: 29, step: 11, item: 'Rh Rr Dr Sunshade X Dr Frame Hook', checkItem: 'Function', standard: 'should be locked firmly', method: 'Visual+Touch' },
      { sl: 30, step: 11, item: 'Rh Rr Dr Sunshade Hook position 2 nos', checkItem: 'Fitment', standard: 'Reverse fit not allowed', method: 'Visual' },
      { sl: 31, step: 11, item: 'Rh Rr Dr Sunshade down', checkItem: 'Operation', standard: 'Should be satisfactory', method: 'Visual+Touch' },
      { sl: 32, step: '', item: 'RH Rr dr child proof lock', checkItem: 'Function', standard: 'Door shall not be open from inside', method: 'Visual+Touch' },
      { sl: 33, step: '', item: 'Rh Rr dr catcher Screw #1', checkItem: 'Miss', standard: 'Miss not allow', method: 'Visual' },
      { sl: 34, step: '', item: 'Rh Rr dr catcher Screw #2', checkItem: 'Miss', standard: 'Miss not allow', method: 'Visual' },
      { sl: 35, step: '', item: 'Rh Rr dr catcher Screw #3', checkItem: 'Miss', standard: 'Miss not allow', method: 'Visual' },
      { sl: 36, step: '', item: 'Rh Rr dr checker arm bolt #1', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 37, step: '', item: 'Rh Rr dr checker arm bolt #2', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 38, step: '', item: 'Rh Rr dr checker arm bolt #3', checkItem: 'Miss', standard: 'Miss not allowed', method: 'Visual' },
      { sl: 39, step: '', item: 'RH Rr dr child proof lock unlock', checkItem: 'Function', standard: 'Door can open by inside handle', method: 'Visual+Touch' },
      { sl: 40, step: '', item: 'RH Rr door catcher and striker Body fitting', checkItem: 'Touching', standard: 'Smoothly', method: 'Visual+Touch' },
      { sl: 41, step: '', item: 'RH Rr dr open(outside handle stroke)', checkItem: 'Function', standard: 'should smoothly open', method: 'Visual+Touch' },
      { sl: 42, step: '', item: 'RH Rr Door and stricker closing condition', checkItem: 'Function', standard: 'door should be locked firmly', method: 'Visual+Touch' },
      { sl: 43, step: '', item: 'RH Rr Dr closing', checkItem: 'Abnormal noise', standard: 'No abnormal noise', method: 'Push+Hear' },
      { sl: 44, step: '', item: 'Rh Qtr glass Spec — Rh QTR Pillar Garnish', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 45, step: '', item: 'Rh Qtr Window Glass Approval mark', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 46, step: '', item: 'Rh Quarter Window Glass & Belt mould', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 47, step: 8, item: 'Defect entry — Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 48, step: 8, item: 'Walk to home position', checkItem: '', standard: '', method: '' }
    ]
  },
  {
    id: 'lh_fr_int_spec',
    name: 'Lh Fr Int Spec',
    model: '25MC',
    takt: '80 Sec',
    process: 'Trim inspection-P2',
    type: 'standard',
    steps: [
      { sl: 1, step: '', item: 'Scan the vehicle CPTS by VDEM tab', checkItem: 'Scan', standard: 'NA', method: 'Visual + Touch' },
      { sl: 2, step: '', item: 'Lh Opening Area Spec — Lh FR DR', checkItem: 'Open', standard: 'ANA', method: 'Visual + Touch' },
      { sl: 3, step: '', item: 'Lh B Plr Tyre information Lable', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 4, step: '', item: 'Lh B Pillar SIDE AIRBAG', checkItem: 'Missing / Extra part / Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 5, step: '', item: 'LH FR seat Head rest', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 6, step: '', item: 'LH FR Seat Color', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 7, step: '', item: 'LH FR Seat Fabric', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 8, step: '', item: 'Lh Fr Int Spec — LH Side Glove Box lamp', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 9, step: '', item: 'Steering Wheel (LHD)', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 10, step: '', item: 'LH Side Register bezel', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 11, step: '', item: 'LH Ip Garnish material', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 12, step: '', item: 'LH Ip Ornament', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 13, step: '', item: 'Ip Center Louver Garnish', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 14, step: '', item: 'Driver inner garnish (RHD)', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 15, step: '', item: 'Lh floor console ornament', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 16, step: '', item: 'Remote #1', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 17, step: '', item: 'Remote #2', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 18, step: '', item: 'Shift Lever Knob (M/T)', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 19, step: '', item: 'Shift Lever Boot Garnish', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 20, step: '', item: 'RHL Spec & Sunvisor Spec — Over Head Console', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 21, step: '', item: 'Over Head Console lamp', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 22, step: '', item: 'IRVM Anti-glare', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 23, step: '', item: 'Lh Sunvisor Label', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 24, step: '', item: 'LH Vanity Mirror Lamp', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 25, step: '', item: 'LH B Pilar garnish', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 26, step: '', item: 'Lh Fr Dr Inner Spec — LH FR DR Tweeter Cover', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 27, step: '', item: 'LH Fr Dr Inside handle Lamp', checkItem: 'Missing / Extra part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 28, step: '', item: 'LH Fr Dr Inside handle', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 29, step: '', item: 'Lh Front Door Trim Material', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 30, step: '', item: 'LH FR DR Window Switch bezzel', checkItem: 'Wrong part', standard: 'Not Allowed', method: 'Visual' },
      { sl: 31, step: '', item: 'Lh FR DR', checkItem: 'Close', standard: 'ANA', method: 'Visual + Touch' },
      { sl: 32, step: 3, item: 'LHD-Outer view Mirror operation — LHD-RH door outer rear view mirror Folding', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 33, step: 3, item: 'LHD-LH door outer rear view mirror Folding', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 34, step: 3, item: 'LHD-RH door outer rear view mirror Retract', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 35, step: 3, item: 'LHD-LH door outer rear view mirror Retract', checkItem: 'Function', standard: 'Sync with s/w', method: 'Visual + Touch' },
      { sl: 36, step: 6, item: 'Glove box door Fitment — RHD — Glove box lock knob unlock', checkItem: 'Function', standard: 'Should be unlock', method: 'Touch + Pull' },
      { sl: 37, step: 6, item: 'Glove box door open and close', checkItem: 'Operation', standard: 'Smoothly', method: 'Touch + Feel' },
      { sl: 38, step: 6, item: 'Glove box lock knob lock', checkItem: 'Function', standard: 'Should be lock', method: 'Touch + Push' },
      { sl: 39, step: 6, item: 'Ip Center register knob updown and left right (Rh and Lh)', checkItem: 'Operation', standard: 'Smoothly', method: 'Touch + Feel' },
      { sl: 40, step: '', item: 'Lh FR DR', checkItem: 'Open', standard: 'ANA', method: 'Visual + Touch' },
      { sl: 41, step: 8, item: 'Defect entry — Defect Entry and VDEM submit', checkItem: '', standard: '', method: '' },
      { sl: 42, step: 8, item: 'Walk to home position', checkItem: '', standard: '', method: '' }
    ]
  }
];


// SOS runtime state
let activeSosProcess = null;
// Each process can have custom added items stored separately
const SOS_CUSTOM = {};

// ═══════════════════════════════════════════════════════════════
// COMPREHENSIVE SOS ITEM WORD TRANSLITERATION
// Full word-by-word translation into native script for all 4 languages
// Example: "Brake oil reservoir tank cap" →
//   KN: ಬ್ರೇಕ್ ಆಯಿಲ್ ರಿಸರ್ವಾಯರ್ ಟ್ಯಾಂಕ್ ಕ್ಯಾಪ್
//   HI: ब्रेक तेल जलाशय टैंक ढक्कन
// ═══════════════════════════════════════════════════════════════
const SOS_WORD_DICT = {
  kn: {
    'brake':'ಬ್ರೇಕ್','oil':'ಆಯಿಲ್','reservoir':'ರಿಸರ್ವಾಯರ್','tank':'ಟ್ಯಾಂಕ್',
    'cap':'ಕ್ಯಾಪ್','level':'ಲೆವೆಲ್','sensor':'ಸೆನ್ಸರ್','connector':'ಕನೆಕ್ಟರ್',
    'wire':'ವೈರ್','harness':'ಹಾರ್ನೆಸ್','routing':'ರೂಟಿಂಗ್','clip':'ಕ್ಲಿಪ್',
    'clamp':'ಕ್ಲ್ಯಾಂಪ್','camshaft':'ಕ್ಯಾಮ್‌ಶಾಫ್ಟ್','inlet':'ಇನ್‌ಲೆಟ್','valve':'ವಾಲ್ವ್',
    'alternator':'ಆಲ್ಟರ್ನೇಟರ್','terminal':'ಟರ್ಮಿನಲ್','pressure':'ಪ್ರೆಶರ್',
    'exhaust':'ಎಕ್ಸಾಸ್ಟ್','air':'ಏರ್','cleaner':'ಕ್ಲೀನರ್','intake':'ಇನ್‌ಟೇಕ್',
    'mounting':'ಮೌಂಟಿಂಗ್','rubber':'ರಬ್ಬರ್','fuel':'ಇಂಧನ','injector':'ಇಂಜೆಕ್ಟರ್',
    'branch':'ಬ್ರಾಂಚ್','hose':'ಹೋಸ್','pipe':'ಪೈಪ್','tube':'ಟ್ಯೂಬ್',
    'return':'ರಿಟರ್ನ್','metal':'ಮೆಟಲ್','bracket':'ಬ್ರ್ಯಾಕೆಟ್','fender':'ಫೆಂಡರ್',
    'inner':'ಇನ್ನರ್','nut':'ನಟ್','nutt':'ನಟ್','abs':'ಎ.ಬಿ.ಎಸ್',
    'actuator':'ಆಕ್ಚುವೇಟರ್','suspension':'ಸಸ್ಪೆನ್ಷನ್','tower':'ಟವರ್',
    'bolt':'ಬೋಲ್ಟ್','apron':'ಏಪ್ರನ್','flare':'ಫ್ಲೇರ್','earth':'ಅರ್ಥ್',
    'engine':'ಎಂಜಿನ್','room':'ರೂಮ್','plug':'ಪ್ಲಗ್','seal':'ಸೀಲ್',
    'grommet':'ಗ್ರಾಮೆಟ್','liquid':'ಲಿಕ್ವಿಡ್','door':'ಬಾಗಿಲು','seat':'ಆಸನ',
    'belt':'ಬೆಲ್ಟ್','glass':'ಗಾಜು','lock':'ಬೀಗ','handle':'ಹ್ಯಾಂಡಲ್',
    'mirror':'ಕನ್ನಡಿ','cover':'ಕವರ್','label':'ಲೇಬಲ್','lable':'ಲೇಬಲ್',
    'window':'ಕಿಟಕಿ','wheel':'ವ್ಹೀಲ್','disc':'ಡಿಸ್ಕ್','tyre':'ಟೈರ್',
    'bumper':'ಬಂಪರ್','bumber':'ಬಂಪರ್','hood':'ಬಾನೆಟ್',
    'roof':'ರೂಫ್','pillar':'ಪಿಲ್ಲರ್','pilar':'ಪಿಲ್ಲರ್','piller':'ಪಿಲ್ಲರ್','plr':'ಪಿಲ್ಲರ್',
    'garnish':'ಗಾರ್ನಿಷ್','trim':'ಟ್ರಿಮ್','panel':'ಪ್ಯಾನೆಲ್','pannel':'ಪ್ಯಾನೆಲ್',
    'lamp':'ಲ್ಯಾಂಪ್','light':'ದೀಪ','switch':'ಸ್ವಿಚ್','sw':'ಸ್ವಿಚ್',
    'knob':'ನಾಬ್','lever':'ಲಿವರ್','pedal':'ಪೆಡಲ್',
    'steering':'ಸ್ಟೀರಿಂಗ್','stering':'ಸ್ಟೀರಿಂಗ್','gear':'ಗೇರ್',
    'shift':'ಶಿಫ್ಟ್','console':'ಕನ್ಸೋಲ್','ip':'ಐ.ಪಿ',
    'register':'ರಿಜಿಸ್ಟರ್','bezel':'ಬೆಜೆಲ್','bezzel':'ಬೆಜೆಲ್',
    'ornament':'ಆಭರಣ','speaker':'ಸ್ಪೀಕರ್','audio':'ಆಡಿಯೊ','volume':'ವಾಲ್ಯೂಮ್',
    'fuse':'ಫ್ಯೂಸ್','box':'ಬಾಕ್ಸ್','battery':'ಬ್ಯಾಟರಿ',
    'wiper':'ವೈಪರ್','arm':'ಆರ್ಮ್','washer':'ವಾಷರ್','pump':'ಪಂಪ್',
    'cooling':'ಕೂಲಿಂಗ್','fan':'ಫ್ಯಾನ್','radiator':'ರೇಡಿಯೇಟರ್','grill':'ಗ್ರಿಲ್',
    'head':'ಹೆಡ್','tail':'ಟೈಲ್','fog':'ಫಾಗ್','indicator':'ಇಂಡಿಕೇಟರ್',
    'spoiler':'ಸ್ಪಾಯಿಲರ್','molding':'ಮೋಲ್ಡಿಂಗ್','mould':'ಮೋಲ್ಡ್',
    'scuff':'ಸ್ಕಫ್','scuffplate':'ಸ್ಕಫ್‌ಪ್ಲೇಟ್','plate':'ಪ್ಲೇಟ್',
    'rocker':'ರಾಕರ್','sill':'ಸಿಲ್',
    'sunvisor':'ಸನ್‌ವೈಸರ್','vanity':'ವ್ಯಾನಿಟಿ',
    'assist':'ಅಸಿಸ್ಟ್','grip':'ಗ್ರಿಪ್','hook':'ಹುಕ್',
    'tray':'ಟ್ರೇ','holder':'ಹೋಲ್ಡರ್','pocket':'ಪಾಕೆಟ್',
    'vin':'ವಿ.ಐ.ಎನ್','number':'ನಂಬರ್','frame':'ಫ್ರೇಮ್','chassis':'ಚಾಸಿಸ್',
    'key':'ಕೀ','remote':'ರಿಮೋಟ್','ignition':'ಇಗ್ನಿಷನ್','start':'ಸ್ಟಾರ್ಟ್',
    'push':'ಪುಶ್','pull':'ಪುಲ್',
    'open':'ತೆರೆಯಿರಿ','close':'ಮುಚ್ಚಿರಿ','closing':'ಮುಚ್ಚುವಿಕೆ',
    'front':'ಮುಂಭಾಗ','rear':'ಹಿಂಭಾಗ','left':'ಎಡ','right':'ಬಲ',
    'upper':'ಮೇಲಿನ','lower':'ಕೆಳಗಿನ','side':'ಬದಿ',
    'outer':'ಹೊರ','outside':'ಹೊರಗಡೆ','inside':'ಒಳಗಡೆ',
    'center':'ಮಧ್ಯ','main':'ಮುಖ್ಯ','sub':'ಸಬ್',
    'small':'ಸಣ್ಣ','big':'ದೊಡ್ಡ','body':'ಬಾಡಿ',
    'color':'ಬಣ್ಣ','colour':'ಬಣ್ಣ','black':'ಕಪ್ಪು','white':'ಬಿಳಿ',
    'grey':'ಬೂದು','silver':'ಬೆಳ್ಳಿ','grey':'ಬೂದು',
    'safety':'ಸುರಕ್ಷತೆ','warning':'ಎಚ್ಚರಿಕೆ','caution':'ಎಚ್ಚರಿಕೆ','notice':'ಸೂಚನೆ',
    'check':'ಪರಿಶೀಲನೆ','checker':'ಪರಿಶೀಲಕ','scan':'ಸ್ಕ್ಯಾನ್',
    'defect':'ದೋಷ','entry':'ಎಂಟ್ರಿ','submit':'ಸಬ್ಮಿಟ್',
    'walk':'ನಡೆಯಿರಿ','home':'ಹೋಮ್','position':'ಪೊಸಿಷನ್',
    'collect':'ಸಂಗ್ರಹಿಸಿ','remove':'ತೆಗೆಯಿರಿ','locate':'ಇರಿಸಿ',
    'set':'ಸೆಟ್','keep':'ಇರಿಸಿ','stick':'ಅಂಟಿಸಿ','paste':'ಅಂಟಿಸಿ',
    'focus':'ಫೋಕಸ್','click':'ಕ್ಲಿಕ್','capture':'ಕ್ಯಾಪ್ಚರ್',
    'image':'ಚಿತ್ರ','result':'ಫಲಿತಾಂಶ','compare':'ಹೋಲಿಕೆ',
    'operation':'ಕಾರ್ಯಾಚರಣೆ','operating':'ನಿರ್ವಹಣೆ','function':'ಕಾರ್ಯ',
    'fitment':'ಫಿಟ್‌ಮೆಂಟ್','fitting':'ಫಿಟ್ಟಿಂಗ್',
    'spec':'ಸ್ಪೆಕ್','speck':'ಸ್ಪೆಕ್','appearance':'ನೋಟ','apperence':'ನೋಟ',
    'condition':'ಸ್ಥಿತಿ','assembly':'ಅಸೆಂಬ್ಲಿ','assy':'ಅಸೆಂಬ್ಲಿ',
    'tightening':'ಬಿಗಿಗೊಳಿಸುವಿಕೆ','sliding':'ಸ್ಲೈಡಿಂಗ್',
    'reclining':'ರಿಕ್ಲೈನಿಂಗ್','recling':'ರಿಕ್ಲೈನಿಂಗ್',
    'height':'ಎತ್ತರ','adjuster':'ಅಡ್ಜಸ್ಟರ್','adust':'ಅಡ್ಜಸ್ಟ್','adjust':'ಅಡ್ಜಸ್ಟ್',
    'backrest':'ಬ್ಯಾಕ್‌ರೆಸ್ಟ್','headrest':'ಹೆಡ್‌ರೆಸ್ಟ್','rest':'ರೆಸ್ಟ್',
    'cushion':'ಕುಶನ್','material':'ವಸ್ತು','fabric':'ಫ್ಯಾಬ್ರಿಕ್',
    'leather':'ಚರ್ಮ','carpet':'ಕಾರ್ಪೆಟ್','lining':'ಲೈನಿಂಗ್',
    'quarter':'ಕ್ವಾರ್ಟರ್','qtr':'ಕ್ವಾರ್ಟರ್','trunk':'ಟ್ರಂಕ್',
    'luggage':'ಲಗ್ಗೇಜ್','boot':'ಬೂಟ್',
    'windshield':'ವಿಂಡ್‌ಶೀಲ್ಡ್','cowl':'ಕೌಲ್','louver':'ಲೂವರ್',
    'protector':'ಪ್ರೊಟೆಕ್ಟರ್','sash':'ಸ್ಯಾಶ್',
    'striker':'ಸ್ಟ್ರೈಕರ್','stricker':'ಸ್ಟ್ರೈಕರ್','catcher':'ಕ್ಯಾಚರ್','cather':'ಕ್ಯಾಚರ್',
    'hinge':'ಹಿಂಜ್','power':'ಪವರ್','manual':'ಮ್ಯಾನ್ಯುಅಲ್',
    'electric':'ಎಲೆಕ್ಟ್ರಿಕ್','motor':'ಮೋಟರ್',
    'transmission':'ಟ್ರಾನ್ಸ್‌ಮಿಷನ್','transaxle':'ಟ್ರಾನ್ಸ್‌ಆಕ್ಸಲ್',
    'inverter':'ಇನ್ವರ್ಟರ್','inverer':'ಇನ್ವರ್ಟರ್',
    'hybrid':'ಹೈಬ್ರಿಡ್','smart':'ಸ್ಮಾರ್ಟ್','neo':'ನಿಯೊ',
    'cng':'ಸಿ.ಎನ್.ಜಿ','ths':'ಟಿ.ಎಚ್.ಎಸ್','isg':'ಐ.ಎಸ್.ಜಿ',
    'lh':'ಎಲ್.ಎಚ್','rh':'ಆರ್.ಎಚ್','fr':'ಮುಂ','rr':'ಹಿಂ','dr':'ಡಾ',
    'lhd':'ಎಲ್.ಎಚ್.ಡಿ','rhd':'ಆರ್.ಎಚ್.ಡಿ',
    'orvm':'ಒ.ಆರ್.ವಿ.ಎಂ','irvm':'ಐ.ಆರ್.ವಿ.ಎಂ',
    'airbag':'ಏರ್‌ಬ್ಯಾಗ್','ab':'ಏರ್‌ಬ್ಯಾಗ್','curtain':'ಕರ್ಟನ್',
    'pkb':'ಪಿ.ಕೆ.ಬಿ','epb':'ಇ.ಪಿ.ಬಿ','parking':'ಪಾರ್ಕಿಂಗ್',
    'tongue':'ಟಂಗ್','buckle':'ಬಕಲ್','webbing':'ವೆಬ್ಬಿಂಗ್',
    'retractor':'ರಿಟ್ರ್ಯಾಕ್ಟರ್','anchor':'ಆಂಕರ್','vertical':'ವರ್ಟಿಕಲ್',
    'dent':'ಗುಳಿ','bump':'ಉಬ್ಬು','scratch':'ಗೀರು','rust':'ತುಕ್ಕು',
    'damage':'ಹಾನಿ','crack':'ಬಿರುಕು','gap':'ಅಂತರ',
    'clearance':'ಕ್ಲಿಯರೆನ್ಸ','clearence':'ಕ್ಲಿಯರೆನ್ಸ',
    'flush':'ಫ್ಲಶ್','mark':'ಗುರುತು','paint':'ಬಣ್ಣ',
    'tightening':'ಬಿಗಿ','torque':'ಟಾರ್ಕ್',
    'grade':'ಗ್ರೇಡ್','model':'ಮಾದರಿ','part':'ಭಾಗ',
    'damper':'ಡ್ಯಾಂಪರ್','stay':'ಸ್ಟೇ','stopper':'ಸ್ಟಾಪರ್',
    'anti':'ಆಂಟಿ','theft':'ಕಳ್ಳತನ','deterrent':'ತಡೆ',
    'resonator':'ರಿಸೊನೇಟರ್','duct':'ಡಕ್ಟ','booster':'ಬೂಸ್ಟರ್',
    'degassing':'ಡಿಗ್ಯಾಸಿಂಗ್','spot':'ಸ್ಪಾಟ್',
    'sunshade':'ಸನ್‌ಶೇಡ್','curtesy':'ಕರ್ಟೆಸಿ','courtesy':'ಕರ್ಟೆಸಿ',
    'tweeter':'ಟ್ವೀಟರ್','sonar':'ಸೋನಾರ್',
    'foot':'ಪಾದ','neck':'ನೆಕ್','back':'ಹಿಂ','backdoor':'ಹಿಂಬಾಗಿಲು',
    'folding':'ಮಡಚಿ','retract':'ಹಿಂಪಡೆ','retract':'ಹಿಂಪಡೆ',
    'up':'ಮೇಲಿಗೆ','down':'ಕೆಳಗೆ','updown':'ಮೇಲು-ಕೆಳ','angle':'ಕೋನ',
    'speed':'ವೇಗ','vehicle':'ವಾಹನ','car':'ಕಾರ್',
    'ocr':'ಒ.ಸಿ.ಆರ್','vin':'ವಿ.ಐ.ಎನ್','vdem':'ವಿ.ಡಿ.ಇ.ಎಂ',
    'cpts':'ಸಿ.ಪಿ.ಟಿ.ಎಸ್','galc':'ಜಿ.ಎ.ಎಲ್.ಸಿ',
    'card':'ಕಾರ್ಡ್','tab':'ಟ್ಯಾಬ್','jig':'ಜಿಗ್',
    'zone':'ವಲಯ','rank':'ಶ್ರೇಣಿ',
    'dent':'ಗುಳಿ','scratch':'ಗೀರು','bump':'ಉಬ್ಬು',
    'information':'ಮಾಹಿತಿ','content':'ವಿಷಯ',
    'tilt':'ತಿರುಗು','rotate':'ತಿರುಗಿಸಿ','retract':'ಹಿಂಪಡೆ',
    'cancel':'ರದ್ದು','release':'ಬಿಡುಗಡೆ',
    'cbt':'ಸಿ.ಬಿ.ಟಿ','bd':'ಬಿ.ಡಿ',
  },
  hi: {
    'brake':'ब्रेक','oil':'तेल','reservoir':'जलाशय','tank':'टैंक',
    'cap':'ढक्कन','level':'स्तर','sensor':'सेंसर','connector':'कनेक्टर',
    'wire':'तार','harness':'हार्नेस','routing':'रूटिंग','clip':'क्लिप',
    'clamp':'क्लैंप','camshaft':'कैमशाफ्ट','inlet':'इनलेट','valve':'वाल्व',
    'alternator':'अल्टरनेटर','terminal':'टर्मिनल','pressure':'दबाव',
    'exhaust':'एग्जॉस्ट','air':'हवा','cleaner':'क्लीनर','intake':'इनटेक',
    'mounting':'माउंटिंग','rubber':'रबर','fuel':'ईंधन','injector':'इंजेक्टर',
    'branch':'शाखा','hose':'होस','pipe':'पाइप','tube':'ट्यूब',
    'return':'वापसी','metal':'धातु','bracket':'ब्रैकेट','fender':'फेंडर',
    'inner':'अंदरूनी','nut':'नट','nutt':'नट','abs':'ए.बी.एस',
    'actuator':'एक्चुएटर','suspension':'सस्पेंशन','tower':'टावर',
    'bolt':'बोल्ट','apron':'एप्रन','flare':'फ्लेयर','earth':'अर्थ',
    'engine':'इंजन','room':'कमरा','plug':'प्लग','seal':'सील',
    'grommet':'ग्रोमेट','liquid':'तरल','door':'दरवाज़ा','seat':'सीट',
    'belt':'बेल्ट','glass':'कांच','lock':'ताला','handle':'हैंडल',
    'mirror':'दर्पण','cover':'आवरण','label':'लेबल','lable':'लेबल',
    'window':'खिड़की','wheel':'पहिया','disc':'डिस्क','tyre':'टायर',
    'bumper':'बम्पर','bumber':'बम्पर','hood':'बोनट','roof':'छत',
    'pillar':'खंभा','pilar':'खंभा','piller':'खंभा','plr':'खंभा',
    'garnish':'गार्निश','trim':'ट्रिम','panel':'पैनल','pannel':'पैनल',
    'lamp':'लैंप','light':'लाइट','switch':'स्विच','sw':'स्विच',
    'knob':'नॉब','lever':'लीवर','pedal':'पेडल',
    'steering':'स्टीयरिंग','stering':'स्टीयरिंग','gear':'गियर',
    'shift':'शिफ्ट','console':'कंसोल','ip':'आई.पी',
    'register':'रजिस्टर','bezel':'बेज़ल','bezzel':'बेज़ल',
    'ornament':'अलंकार','speaker':'स्पीकर','audio':'ऑडियो','volume':'वॉल्यूम',
    'fuse':'फ्यूज','box':'बॉक्स','battery':'बैटरी',
    'wiper':'वाइपर','arm':'बांह','washer':'वॉशर','pump':'पंप',
    'cooling':'कूलिंग','fan':'पंखा','radiator':'रेडिएटर','grill':'ग्रिल',
    'head':'हेड','tail':'टेल','fog':'कोहरा','indicator':'इंडिकेटर',
    'spoiler':'स्पॉइलर','molding':'मोल्डिंग','mould':'मोल्ड',
    'scuff':'स्कफ','scuffplate':'स्कफप्लेट','plate':'प्लेट','rocker':'रॉकर',
    'sunvisor':'सनवाइज़र','vanity':'वैनिटी',
    'assist':'सहायता','grip':'पकड़','hook':'हुक',
    'tray':'ट्रे','holder':'धारक','pocket':'जेब',
    'vin':'वी.आई.एन','number':'नंबर','frame':'फ्रेम',
    'key':'चाबी','remote':'रिमोट','ignition':'इग्निशन','start':'स्टार्ट',
    'push':'धकेलें','pull':'खींचें',
    'open':'खोलें','close':'बंद करें','closing':'बंद करना',
    'front':'आगे','rear':'पीछे','left':'बाएं','right':'दाएं',
    'upper':'ऊपरी','lower':'निचला','side':'बाजू',
    'outer':'बाहरी','outside':'बाहर','inside':'अंदर',
    'center':'केंद्र','main':'मुख्य','sub':'उप',
    'small':'छोटा','big':'बड़ा','body':'बॉडी',
    'color':'रंग','colour':'रंग','black':'काला','white':'सफेद',
    'grey':'भूरा','silver':'चांदी',
    'safety':'सुरक्षा','warning':'चेतावनी','caution':'सावधानी','notice':'नोटिस',
    'check':'जांच','checker':'चेकर','scan':'स्कैन',
    'defect':'दोष','entry':'प्रविष्टि','submit':'सबमिट',
    'walk':'चलें','home':'होम','position':'स्थिति',
    'collect':'इकट्ठा करें','remove':'हटाएं','locate':'रखें',
    'set':'सेट','keep':'रखें','stick':'चिपकाएं','paste':'चिपकाएं',
    'focus':'फोकस','click':'क्लिक','capture':'कैप्चर',
    'image':'चित्र','result':'परिणाम','compare':'तुलना',
    'operation':'संचालन','operating':'संचालन','function':'कार्य',
    'fitment':'फिटमेंट','fitting':'फिटिंग',
    'spec':'स्पेक','speck':'स्पेक','appearance':'दिखावट','apperence':'दिखावट',
    'condition':'स्थिति','assembly':'असेंबली','assy':'असेंबली',
    'tightening':'कसाई','sliding':'स्लाइडिंग',
    'reclining':'रिक्लाइनिंग','recling':'रिक्लाइनिंग',
    'height':'ऊंचाई','adjuster':'एडजस्टर','adust':'एडजस्ट','adjust':'एडजस्ट',
    'backrest':'बैकरेस्ट','headrest':'हेडरेस्ट','rest':'रेस्ट',
    'cushion':'गद्दी','material':'सामग्री','fabric':'कपड़ा',
    'leather':'चमड़ा','carpet':'कालीन','lining':'लाइनिंग',
    'quarter':'क्वार्टर','qtr':'क्वार्टर','trunk':'ट्रंक',
    'luggage':'सामान','boot':'ट्रंक',
    'windshield':'विंडशील्ड','cowl':'काउल','louver':'लूवर',
    'protector':'सुरक्षक','sash':'सैश',
    'striker':'स्ट्राइकर','stricker':'स्ट्राइकर',
    'catcher':'कैचर','cather':'कैचर','hinge':'टिका',
    'power':'पावर','manual':'मैनुअल','electric':'विद्युत','motor':'मोटर',
    'transmission':'ट्रांसमिशन','transaxle':'ट्रांसएक्सल',
    'inverter':'इन्वर्टर','inverer':'इन्वर्टर',
    'hybrid':'हाइब्रिड','smart':'स्मार्ट','neo':'नियो',
    'cng':'सी.एन.जी','ths':'टी.एच.एस','isg':'आई.एस.जी',
    'lh':'एल.एच','rh':'आर.एच','fr':'अगला','rr':'पिछला','dr':'डॉ',
    'lhd':'एल.एच.डी','rhd':'आर.एच.डी',
    'orvm':'ओ.आर.वी.एम','irvm':'आई.आर.वी.एम',
    'airbag':'एयरबैग','ab':'एयरबैग','curtain':'पर्दा',
    'pkb':'पी.के.बी','epb':'ई.पी.बी','parking':'पार्किंग',
    'tongue':'टंग','buckle':'बकल','webbing':'वेबिंग',
    'retractor':'रिट्रेक्टर','anchor':'एंकर','vertical':'लंबवत',
    'dent':'डेंट','bump':'उभार','scratch':'खरोंच','rust':'जंग',
    'damage':'नुकसान','crack':'दरार','gap':'अंतर',
    'clearance':'निकासी','clearence':'निकासी',
    'flush':'फ्लश','mark':'निशान','paint':'पेंट','torque':'टॉर्क',
    'grade':'ग्रेड','model':'मॉडल','part':'भाग',
    'damper':'डैम्पर','stay':'स्टे','stopper':'स्टॉपर',
    'anti':'एंटी','theft':'चोरी','deterrent':'तडे',
    'resonator':'रेजोनेटर','duct':'डक्ट','booster':'बूस्टर',
    'degassing':'डिगैसिंग','spot':'स्पॉट',
    'sunshade':'सनशेड','curtesy':'कर्टेसी','courtesy':'कर्टेसी',
    'tweeter':'ट्वीटर','sonar':'सोनार',
    'foot':'पैर','neck':'गर्दन','back':'पीछे','backdoor':'पीछे का दरवाज़ा',
    'folding':'मोड़ना','retract':'वापस लेना',
    'up':'ऊपर','down':'नीचे','updown':'ऊपर-नीचे','angle':'कोण',
    'vehicle':'वाहन','car':'कार',
    'ocr':'ओ.सी.आर','vdem':'वी.डी.ई.एम',
    'cpts':'सी.पी.टी.एस','galc':'जी.ए.एल.सी',
    'card':'कार्ड','tab':'टैब','jig':'जिग',
    'zone':'क्षेत्र','rank':'रैंक',
    'information':'जानकारी','content':'सामग्री',
    'tilt':'झुकाव','rotate':'घुमाएं','cancel':'रद्द','release':'रिलीज़',
    'cbt':'सी.बी.टी','bd':'बी.डी',
  },
  mr: {
    'brake':'ब्रेक','oil':'तेल','reservoir':'जलाशय','tank':'टाकी',
    'cap':'झाकण','level':'पातळी','sensor':'सेन्सर','connector':'कनेक्टर',
    'wire':'तार','harness':'हार्नेस','routing':'रुटिंग','clip':'क्लिप',
    'clamp':'क्लॅम्प','camshaft':'कॅमशाफ्ट','inlet':'इनलेट','valve':'व्हाल्व',
    'alternator':'अल्टरनेटर','terminal':'टर्मिनल','pressure':'दाब',
    'exhaust':'एक्झॉस्ट','air':'हवा','cleaner':'क्लीनर','intake':'इनटेक',
    'mounting':'माउंटिंग','rubber':'रबर','fuel':'इंधन','injector':'इंजेक्टर',
    'branch':'शाखा','hose':'होज','pipe':'पाईप','tube':'ट्यूब',
    'return':'परतीचा','metal':'धातू','bracket':'ब्रॅकेट','fender':'फेंडर',
    'inner':'आतील','nut':'नट','nutt':'नट','abs':'ए.बी.एस',
    'actuator':'ॲक्च्युएटर','suspension':'सस्पेन्शन','tower':'टॉवर',
    'bolt':'बोल्ट','apron':'एप्रन','flare':'फ्लेअर','earth':'अर्थ',
    'engine':'इंजिन','room':'खोली','plug':'प्लग','seal':'सील',
    'grommet':'ग्रॉमेट','liquid':'द्रव','door':'दरवाजा','seat':'आसन',
    'belt':'पट्टा','glass':'काच','lock':'कुलूप','handle':'हँडल',
    'mirror':'आरसा','cover':'आवरण','label':'लेबल','lable':'लेबल',
    'window':'खिडकी','wheel':'चाक','disc':'डिस्क','tyre':'टायर',
    'bumper':'बम्पर','bumber':'बम्पर','hood':'बोनेट','roof':'छत',
    'pillar':'खांब','pilar':'खांब','piller':'खांब','plr':'खांब',
    'garnish':'गार्निश','trim':'ट्रिम','panel':'पॅनेल','pannel':'पॅनेल',
    'lamp':'दिवा','light':'दिवा','switch':'स्विच','sw':'स्विच',
    'knob':'नॉब','lever':'लीव्हर','pedal':'पेडल',
    'steering':'स्टीयरिंग','stering':'स्टीयरिंग','gear':'गियर',
    'shift':'शिफ्ट','console':'कन्सोल','ip':'आय.पी',
    'register':'रजिस्टर','bezel':'बेझेल','bezzel':'बेझेल',
    'ornament':'अलंकार','speaker':'स्पीकर','audio':'ऑडिओ','volume':'व्हॉल्यूम',
    'fuse':'फ्यूज','box':'बॉक्स','battery':'बॅटरी',
    'wiper':'वायपर','arm':'हात','washer':'वॉशर','pump':'पंप',
    'cooling':'कूलिंग','fan':'पंखा','radiator':'रेडिएटर','grill':'ग्रिल',
    'head':'हेड','tail':'टेल','fog':'धुके','indicator':'इंडिकेटर',
    'spoiler':'स्पॉयलर','molding':'मोल्डिंग','mould':'मोल्ड',
    'scuff':'स्कफ','scuffplate':'स्कफप्लेट','plate':'प्लेट','rocker':'रॉकर',
    'sunvisor':'सनव्हायझर','vanity':'व्हॅनिटी',
    'assist':'सहाय्य','grip':'पकड','hook':'हुक',
    'tray':'ट्रे','holder':'धारक','pocket':'खिसा',
    'vin':'व्ही.आय.एन','number':'नंबर','frame':'फ्रेम',
    'key':'चावी','remote':'रिमोट','ignition':'इग्निशन','start':'सुरू',
    'push':'ढकला','pull':'ओढा',
    'open':'उघडा','close':'बंद करा','closing':'बंद करणे',
    'front':'पुढे','rear':'मागे','left':'डावे','right':'उजवे',
    'upper':'वरचा','lower':'खालचा','side':'बाजू',
    'outer':'बाहेरील','outside':'बाहेर','inside':'आत',
    'center':'मध्य','main':'मुख्य','sub':'उप',
    'small':'लहान','big':'मोठा','body':'बॉडी',
    'color':'रंग','colour':'रंग','black':'काळा','white':'पांढरा',
    'grey':'करडा','silver':'चांदी',
    'safety':'सुरक्षा','warning':'इशारा','caution':'काळजी','notice':'नोटीस',
    'check':'तपासणी','checker':'तपासक','scan':'स्कॅन',
    'defect':'दोष','entry':'नोंद','submit':'सबमिट',
    'walk':'चाला','home':'होम','position':'स्थान',
    'collect':'गोळा करा','remove':'काढा','locate':'ठेवा',
    'set':'सेट','keep':'ठेवा','stick':'चिकटवा','paste':'चिकटवा',
    'focus':'फोकस','click':'क्लिक','capture':'कॅप्चर',
    'image':'चित्र','result':'निकाल','compare':'तुलना',
    'operation':'संचालन','operating':'संचालन','function':'कार्य',
    'fitment':'बसवणी','fitting':'फिटिंग',
    'spec':'स्पेक','speck':'स्पेक','appearance':'देखावा','apperence':'देखावा',
    'condition':'स्थिती','assembly':'असेंब्ली','assy':'असेंब्ली',
    'tightening':'घट्ट करणे','sliding':'सरकणे',
    'reclining':'मागे झुकणे','recling':'मागे झुकणे',
    'height':'उंची','adjuster':'अॅडजस्टर','adust':'अॅडजस्ट','adjust':'अॅडजस्ट',
    'backrest':'पाठीचा आधार','headrest':'डोक्याचा आधार','rest':'आधार',
    'cushion':'उशी','material':'साहित्य','fabric':'कापड',
    'leather':'चामडे','carpet':'गालिचा','lining':'लायनिंग',
    'quarter':'क्वार्टर','qtr':'क्वार्टर','trunk':'ट्रंक',
    'luggage':'सामान','boot':'ट्रंक',
    'windshield':'विंडशील्ड','cowl':'काउल','louver':'लूव्हर',
    'protector':'रक्षक','sash':'सॅश',
    'striker':'स्ट्रायकर','stricker':'स्ट्रायकर',
    'catcher':'कॅचर','cather':'कॅचर','hinge':'टिका',
    'power':'पॉवर','manual':'मॅन्युअल','electric':'विद्युत','motor':'मोटर',
    'transmission':'ट्रांसमिशन','transaxle':'ट्रांसएक्सल',
    'inverter':'इन्व्हर्टर','inverer':'इन्व्हर्टर',
    'hybrid':'हायब्रिड','smart':'स्मार्ट','neo':'नियो',
    'cng':'सी.एन.जी','ths':'टी.एच.एस','isg':'आय.एस.जी',
    'lh':'एल.एच','rh':'आर.एच','fr':'पुढील','rr':'मागील','dr':'डॉ',
    'lhd':'एल.एच.डी','rhd':'आर.एच.डी',
    'orvm':'ओ.आर.व्ही.एम','irvm':'आय.आर.व्ही.एम',
    'airbag':'एअरबॅग','ab':'एअरबॅग','curtain':'पडदा',
    'pkb':'पी.के.बी','epb':'ई.पी.बी','parking':'पार्किंग',
    'tongue':'टंग','buckle':'बकल','webbing':'वेबिंग',
    'retractor':'रिट्रॅक्टर','anchor':'अँकर','vertical':'उभ्या',
    'dent':'खळगा','bump':'उभार','scratch':'ओरखडा','rust':'गंज',
    'damage':'नुकसान','crack':'भेग','gap':'अंतर',
    'clearance':'क्लिअरन्स','clearence':'क्लिअरन्स',
    'flush':'फ्लश','mark':'खूण','paint':'रंग','torque':'टॉर्क',
    'grade':'ग्रेड','model':'मॉडेल','part':'भाग',
    'damper':'डॅम्पर','stay':'स्टे','stopper':'स्टॉपर',
    'anti':'अँटी','theft':'चोरी','deterrent':'प्रतिबंध',
    'resonator':'रेझोनेटर','duct':'डक्ट','booster':'बूस्टर',
    'degassing':'डिगॅसिंग','spot':'स्पॉट',
    'sunshade':'सनशेड','curtesy':'सौजन्य','courtesy':'सौजन्य',
    'tweeter':'ट्वीटर','sonar':'सोनार',
    'foot':'पाय','neck':'मान','back':'मागे','backdoor':'मागचे दार',
    'folding':'दुमडणे','retract':'मागे घेणे',
    'up':'वर','down':'खाली','updown':'वर-खाली','angle':'कोन',
    'vehicle':'वाहन','car':'कार',
    'ocr':'ओ.सी.आर','vdem':'व्ही.डी.ई.एम',
    'cpts':'सी.पी.टी.एस','galc':'जी.ए.एल.सी',
    'card':'कार्ड','tab':'टॅब','jig':'जिग',
    'zone':'क्षेत्र','rank':'श्रेणी',
    'information':'माहिती','content':'मजकूर',
    'tilt':'कोनात','rotate':'फिरवा','cancel':'रद्द करा','release':'सोडा',
    'cbt':'सी.बी.टी','bd':'बी.डी',
  },
  ja: {
    'brake':'ブレーキ','oil':'オイル','reservoir':'リザーバー','tank':'タンク',
    'cap':'キャップ','level':'レベル','sensor':'センサー','connector':'コネクター',
    'wire':'ワイヤー','harness':'ハーネス','routing':'ルーティング','clip':'クリップ',
    'clamp':'クランプ','camshaft':'カムシャフト','inlet':'インレット','valve':'バルブ',
    'alternator':'オルタネーター','terminal':'ターミナル','pressure':'圧力',
    'exhaust':'エキゾースト','air':'エア','cleaner':'クリーナー','intake':'インテーク',
    'mounting':'マウント','rubber':'ゴム','fuel':'燃料','injector':'インジェクター',
    'branch':'ブランチ','hose':'ホース','pipe':'パイプ','tube':'チューブ',
    'return':'リターン','metal':'メタル','bracket':'ブラケット','fender':'フェンダー',
    'inner':'インナー','nut':'ナット','nutt':'ナット','abs':'ABS',
    'actuator':'アクチュエーター','suspension':'サスペンション','tower':'タワー',
    'bolt':'ボルト','apron':'エプロン','flare':'フレア','earth':'アース',
    'engine':'エンジン','room':'ルーム','plug':'プラグ','seal':'シール',
    'grommet':'グロメット','liquid':'液体','door':'ドア','seat':'シート',
    'belt':'ベルト','glass':'ガラス','lock':'ロック','handle':'ハンドル',
    'mirror':'ミラー','cover':'カバー','label':'ラベル','lable':'ラベル',
    'window':'ウィンドウ','wheel':'ホイール','disc':'ディスク','tyre':'タイヤ',
    'bumper':'バンパー','bumber':'バンパー','hood':'ボンネット','roof':'ルーフ',
    'pillar':'ピラー','pilar':'ピラー','piller':'ピラー','plr':'ピラー',
    'garnish':'ガーニッシュ','trim':'トリム','panel':'パネル','pannel':'パネル',
    'lamp':'ランプ','light':'ライト','switch':'スイッチ','sw':'スイッチ',
    'knob':'ノブ','lever':'レバー','pedal':'ペダル',
    'steering':'ステアリング','stering':'ステアリング','gear':'ギア',
    'shift':'シフト','console':'コンソール','ip':'インパネ',
    'register':'レジスター','bezel':'ベゼル','bezzel':'ベゼル',
    'ornament':'オーナメント','speaker':'スピーカー','audio':'オーディオ','volume':'ボリューム',
    'fuse':'ヒューズ','box':'ボックス','battery':'バッテリー',
    'wiper':'ワイパー','arm':'アーム','washer':'ウォッシャー','pump':'ポンプ',
    'cooling':'冷却','fan':'ファン','radiator':'ラジエーター','grill':'グリル',
    'head':'ヘッド','tail':'テール','fog':'フォグ','indicator':'インジケーター',
    'spoiler':'スポイラー','molding':'モール','mould':'モール',
    'scuff':'スカッフ','scuffplate':'スカッフプレート','plate':'プレート','rocker':'ロッカー',
    'sunvisor':'サンバイザー','vanity':'バニティ',
    'assist':'アシスト','grip':'グリップ','hook':'フック',
    'tray':'トレー','holder':'ホルダー','pocket':'ポケット',
    'vin':'VIN','number':'番号','frame':'フレーム',
    'key':'キー','remote':'リモコン','ignition':'イグニッション','start':'スタート',
    'push':'プッシュ','pull':'プル',
    'open':'オープン','close':'クローズ','closing':'クロージング',
    'front':'フロント','rear':'リア','left':'左','right':'右',
    'upper':'アッパー','lower':'ロアー','side':'サイド',
    'outer':'アウター','outside':'外側','inside':'内側',
    'center':'センター','main':'メイン','sub':'サブ',
    'small':'小','big':'大','body':'ボディ',
    'color':'色','colour':'色','black':'ブラック','white':'ホワイト',
    'grey':'グレー','silver':'シルバー',
    'safety':'安全','warning':'警告','caution':'注意','notice':'通知',
    'check':'確認','checker':'チェッカー','scan':'スキャン',
    'defect':'不良','entry':'記入','submit':'送信',
    'walk':'移動','home':'ホーム','position':'ポジション',
    'collect':'収集','remove':'取外し','locate':'配置',
    'set':'セット','keep':'保持','stick':'貼付','paste':'貼付',
    'focus':'フォーカス','click':'クリック','capture':'キャプチャ',
    'image':'画像','result':'結果','compare':'比較',
    'operation':'操作','operating':'操作','function':'機能',
    'fitment':'取付','fitting':'組付',
    'spec':'仕様','speck':'仕様','appearance':'外観','apperence':'外観',
    'condition':'状態','assembly':'組立','assy':'組立',
    'tightening':'締付','sliding':'スライド',
    'reclining':'リクライニング','recling':'リクライニング',
    'height':'高さ','adjuster':'アジャスター','adust':'調整','adjust':'調整',
    'backrest':'バックレスト','headrest':'ヘッドレスト','rest':'レスト',
    'cushion':'クッション','material':'材質','fabric':'生地',
    'leather':'レザー','carpet':'カーペット','lining':'ライニング',
    'quarter':'クォーター','qtr':'クォーター','trunk':'トランク',
    'luggage':'荷物','boot':'トランク',
    'windshield':'ウィンドシールド','cowl':'カウル','louver':'ルーバー',
    'protector':'プロテクター','sash':'サッシ',
    'striker':'ストライカー','stricker':'ストライカー',
    'catcher':'キャッチャー','cather':'キャッチャー','hinge':'ヒンジ',
    'power':'パワー','manual':'マニュアル','electric':'電動','motor':'モーター',
    'transmission':'トランスミッション','transaxle':'トランスアクスル',
    'inverter':'インバーター','inverer':'インバーター',
    'hybrid':'ハイブリッド','smart':'スマート','neo':'ネオ',
    'cng':'CNG','ths':'THS','isg':'ISG',
    'lh':'LH','rh':'RH','fr':'フロント','rr':'リア','dr':'ドア',
    'lhd':'左ハンドル','rhd':'右ハンドル',
    'orvm':'ドアミラー','irvm':'ルームミラー',
    'airbag':'エアバッグ','ab':'エアバッグ','curtain':'カーテン',
    'pkb':'PKB','epb':'EPB','parking':'パーキング',
    'tongue':'タング','buckle':'バックル','webbing':'ウェビング',
    'retractor':'リトラクター','anchor':'アンカー','vertical':'垂直',
    'dent':'へこみ','bump':'膨らみ','scratch':'傷','rust':'錆',
    'damage':'損傷','crack':'亀裂','gap':'隙間',
    'clearance':'クリアランス','clearence':'クリアランス',
    'flush':'面一','mark':'マーク','paint':'塗装','torque':'トルク',
    'grade':'グレード','model':'モデル','part':'部品',
    'damper':'ダンパー','stay':'ステー','stopper':'ストッパー',
    'anti':'アンチ','theft':'盗難','deterrent':'防止',
    'resonator':'レゾネーター','duct':'ダクト','booster':'ブースター',
    'degassing':'デガッシング','spot':'スポット',
    'sunshade':'サンシェード','curtesy':'カーテシー','courtesy':'カーテシー',
    'tweeter':'ツイーター','sonar':'ソナー',
    'foot':'フット','neck':'ネック','back':'バック','backdoor':'バックドア',
    'folding':'折畳','retract':'格納',
    'up':'上','down':'下','updown':'上下','angle':'角度',
    'vehicle':'車両','car':'車',
    'ocr':'OCR','vdem':'VDEM',
    'cpts':'CPTS','galc':'GALC',
    'card':'カード','tab':'タブ','jig':'治具',
    'zone':'ゾーン','rank':'ランク',
    'information':'情報','content':'内容',
    'tilt':'チルト','rotate':'回転','cancel':'キャンセル','release':'解除',
    'cbt':'CBT','bd':'BD',
  }
};

// Transliterate a full SOS inspection item text word-by-word into native script
function tSOSItemFull(text) {
  if (!text || currentLang === 'en') return text;
  const dict = SOS_WORD_DICT[currentLang];
  if (!dict) return text;

  // Split into segments: words vs delimiters/numbers/specials
  // We preserve #N, (Only XXX), X as connector, numbers
  const result = text.replace(/(\w+)/g, (word) => {
    const key = word.toLowerCase();
    return dict[key] || word;
  });
  return result;
}

function getSOSCheckClass(checkItem) {
  const ci = (checkItem || '').toLowerCase();
  if (ci.includes('miss')) return 'miss';
  if (ci.includes('half lock') || ci.includes('half-lock')) return 'half';
  if (ci.includes('unlock') || ci.includes('unlocked')) return 'unlock';
  if (ci.includes('coming off') || ci.includes('coming-off')) return 'coming';
  if (ci.includes('interference')) return 'interference';
  if (ci.includes('looseness') || ci.includes('loose')) return 'looseness';
  return 'default';
}

function renderSOSProcs(filter = '') {
  const list = document.getElementById('sos-proc-list');
  if (!list) return;
  const fl = filter.toLowerCase();
  const filtered = SOS_PROCESSES.filter(p =>
    p.name.toLowerCase().includes(fl) || p.process.toLowerCase().includes(fl)
  );
  list.innerHTML = filtered.map(p => {
    const allItems = [...p.steps, ...(SOS_CUSTOM[p.id] || [])];
    const active = activeSosProcess === p.id ? ' active' : '';
    return `<div class="sos-proc-row${active}" onclick="selectSOSProcess('${p.id}')">
      <span class="sos-proc-name">${p.name}</span>
      <span class="sos-proc-meta">${p.model} · ${p.takt} · ${p.process}</span>
      <span class="sos-proc-cnt">${allItems.length} ${t('sos_items_label')}</span>
    </div>`;
  }).join('');
  document.getElementById('sos-proc-count').textContent = filtered.length;
}

function filterSOSProcs(val) { renderSOSProcs(val); }

function selectSOSProcess(id) {
  activeSosProcess = id;
  renderSOSProcs(document.getElementById('sos-proc-search')?.value || '');
  if(typeof renderSpecProcesses==='function') renderSpecProcesses();
  if(typeof renderJTProcs==='function') renderJTProcs();
  renderSOSTable(id);
  document.getElementById('sos-detail-empty').style.display = 'none';
  document.getElementById('sos-table-container').style.display = 'block';
}

function renderSOSTable(id, filterText = '', filterMethod = '') {
  const proc = SOS_PROCESSES.find(p => p.id === id);
  if (!proc) return;

  // Proc info bar
  document.getElementById('sos-proc-info').innerHTML = `
    <span style="font-size:13px;font-weight:700;color:#e6f1ff;margin-right:8px;">${proc.name}</span>
    <span class="sos-info-tag model">${t('sos_model_label')}: ${proc.model}</span>
    <span class="sos-info-tag takt">⏱ ${t('sos_takt_label')}: ${proc.takt}</span>
    <span class="sos-info-tag process">${proc.process}</span>
    <button class="btn btn-ghost" style="margin-left:auto;font-size:10px;padding:3px 8px;" onclick="showAddSOSRow()">${t('sos_add_row')}</button>
    <button class="btn btn-danger" style="font-size:10px;padding:3px 8px;" onclick="clearCustomSOSItems('${id}')">${t('sos_clear_added')}</button>
  `;

  const allItems = [...proc.steps, ...(SOS_CUSTOM[id] || [])];
  const ft = (filterText || '').toLowerCase();
  const fm = (filterMethod || '').toLowerCase();

  const filtered = allItems.filter(s => {
    const matchText = !ft || s.item.toLowerCase().includes(ft) || (s.checkItem || '').toLowerCase().includes(ft);
    const matchMethod = !fm || (s.method || '').toLowerCase().includes(fm);
    return matchText && matchMethod;
  });

  const tbody = document.getElementById('sos-table-body');
  tbody.innerHTML = filtered.map((s, idx) => {
    const localFull = tSOSItemFull(s.item);
    const checkClass = getSOSCheckClass(s.checkItem);
    const isCustom = (SOS_CUSTOM[id] || []).includes(s);
    const imgKey = sosImgKey(id, s.sl || idx+1);
    const okCount = (SOS_IMAGES[imgKey] && SOS_IMAGES[imgKey].ok) ? SOS_IMAGES[imgKey].ok.length : 0;
    const ngCount = (SOS_IMAGES[imgKey] && SOS_IMAGES[imgKey].ng) ? SOS_IMAGES[imgKey].ng.length : 0;
    const hasImages = okCount > 0 || ngCount > 0;
    return `<tr class="${isCustom ? 'new-item' : ''}">
      <td class="sos-sl">${s.sl || idx + 1}</td>
      <td class="sos-step">${s.step || ''}</td>
      <td class="sos-item">
        ${s.item}
        ${localFull && localFull !== s.item ? `<span class="sos-item-local">${localFull}</span>` : ''}
      </td>
      <td><span class="sos-check ${checkClass}">${tSOSCheck(s.checkItem) || '—'}</span></td>
      <td class="sos-standard">${s.standard || '—'}</td>
      <td><span class="sos-method">${tSOSMethod(s.method) || '—'}</span></td>
      <td class="sos-actions" style="white-space:nowrap;">
        <button class="sos-view-btn" onclick="openJudgementTrainerFor('${id}', ${s.sl || idx+1}, '${escQ(s.item)}')" title="View in Judgement Trainer">🏅${hasImages ? ' <span style=\'color:#c084fc;font-size:8px;\'>'+(okCount+ngCount)+'</span>' : ''}</button>
        <button class="sos-del-btn" onclick="deleteSOSItem('${id}', ${idx}, ${isCustom})" title="Remove">✕</button>
      </td>
    </tr>`;
  }).join('');

  // Show language note
  const langNote = document.querySelector('.sos-lang-note');
  if (langNote) {
    if (currentLang !== 'en') {
      langNote.style.display = 'block';
      const langNames = {hi:'Hindi / हिंदी',kn:'Kannada / ಕನ್ನಡ',mr:'Marathi / मराठी',ja:'Japanese / 日本語'};
      langNote.innerHTML = '🌐 <b>Bilingual Mode:</b> Displaying in <b>' + (langNames[currentLang]||currentLang) + '</b> — Full item translation shown in <span style="color:rgba(255,180,0,0.9);">amber</span> below each English item';
    } else {
      langNote.style.display = 'none';
    }
  }
}

function filterSOS(text) {
  if (!activeSosProcess) return;
  const method = document.getElementById('sos-method-filter')?.value || '';
  renderSOSTable(activeSosProcess, text, method);
}

function showAddSOSRow() {
  const row = document.getElementById('sos-add-row');
  if (row) row.style.display = 'flex';
}

function addSOSRowItem() {
  if (!activeSosProcess) return;
  const name = document.getElementById('sos-new-item-name')?.value?.trim();
  const check = document.getElementById('sos-new-check')?.value?.trim();
  const standard = document.getElementById('sos-new-standard')?.value?.trim();
  const method = document.getElementById('sos-new-method')?.value || 'Visual';
  if (!name) { toast('Enter an inspection item name'); return; }
  if (!SOS_CUSTOM[activeSosProcess]) SOS_CUSTOM[activeSosProcess] = [];
  const proc = SOS_PROCESSES.find(p => p.id === activeSosProcess);
  const newSl = (proc ? proc.steps.length : 0) + SOS_CUSTOM[activeSosProcess].length + 1;
  SOS_CUSTOM[activeSosProcess].push({ sl: newSl, step: '', item: name, checkItem: check || '', standard: standard || '', method: method });
  document.getElementById('sos-new-item-name').value = '';
  document.getElementById('sos-new-check').value = '';
  document.getElementById('sos-new-standard').value = '';
  renderSOSTable(activeSosProcess);
  renderSOSProcs(document.getElementById('sos-proc-search')?.value || '');
  if(typeof renderSpecProcesses==='function') renderSpecProcesses();
  if(typeof renderJTProcs==='function') renderJTProcs();
  toast('Check item added ✓');
}

function deleteSOSItem(procId, idx, isCustom) {
  const proc = SOS_PROCESSES.find(p => p.id === procId);
  if (!proc) return;
  if (isCustom) {
    // It's in custom, find correct index
    const allItems = [...proc.steps, ...(SOS_CUSTOM[procId] || [])];
    const item = allItems[idx];
    const ci = (SOS_CUSTOM[procId] || []).indexOf(item);
    if (ci > -1) { SOS_CUSTOM[procId].splice(ci, 1); }
  } else {
    // Remove from original steps (mark as hidden)
    if (!proc._hidden) proc._hidden = [];
    proc._hidden.push(idx);
    proc.steps.splice(idx, 1);
  }
  renderSOSTable(procId);
  renderSOSProcs(document.getElementById('sos-proc-search')?.value || '');
  if(typeof renderSpecProcesses==='function') renderSpecProcesses();
  if(typeof renderJTProcs==='function') renderJTProcs();
  toast('Item removed');
}

function clearCustomSOSItems(procId) {
  SOS_CUSTOM[procId] = [];
  renderSOSTable(procId);
  renderSOSProcs(document.getElementById('sos-proc-search')?.value || '');
  if(typeof renderSpecProcesses==='function') renderSpecProcesses();
  if(typeof renderJTProcs==='function') renderJTProcs();
  toast('Custom items cleared');
}

function openAddSOSItemModal() {
  if (!activeSosProcess) {
    toast('Select a process first');
    return;
  }
  showAddSOSRow();
}

// Add sos-lang-note element to table area
(function addLangNote() {
  document.addEventListener('DOMContentLoaded', () => {
    const tc = document.getElementById('sos-table-container');
    if (tc) {
      const note = document.createElement('div');
      note.className = 'sos-lang-note';
      note.style.display = 'none';
      tc.appendChild(note);
    }
  });
})();

// ═══════════════════════════════════════════
// SOS OK/NG IMAGE STORE
// ═══════════════════════════════════════════
const SOS_IMAGES = {};
// Key: "procId__slNo" → { ok: [{src, caption}...], ng: [{src, caption}...] }

function sosImgKey(procId, sl) {
  return (procId + '__' + sl).replace(/[^a-zA-Z0-9_]/g,'_');
}

let activeOKNGKey = '';
let activeOKNGTitle = '';
let activeOKNGProcId = '';
let activeOKNGSl = 0;

function openOKNGModal(procId, sl, itemName) {
  activeOKNGProcId = procId;
  activeOKNGSl = sl;
  activeOKNGKey = sosImgKey(procId, sl);
  activeOKNGTitle = itemName;
  if (!SOS_IMAGES[activeOKNGKey]) SOS_IMAGES[activeOKNGKey] = { ok: [], ng: [] };
  document.getElementById('okng-title').textContent = '👁 ' + itemName;
  document.getElementById('okng-ok-label').textContent = t('okng_ok_label');
  document.getElementById('okng-ng-label').textContent = t('okng_ng_label');
  document.getElementById('okng-add-ok-label').textContent = t('okng_add_ok');
  document.getElementById('okng-add-ng-label').textContent = t('okng_add_ng');
  document.getElementById('okng-note').textContent = t('okng_note');
  document.getElementById('okng-quiz-btn-label').textContent = t('okng_quiz_btn');
  renderOKNGLists();
  document.getElementById('okng-modal').classList.add('open');
}

function closeOKNGModal() {
  document.getElementById('okng-modal').classList.remove('open');
  // Re-render to update image counts
  if (activeSosProcess) renderSOSTable(activeSosProcess,
    document.getElementById('sos-search')?.value||'',
    document.getElementById('sos-method-filter')?.value||'');
}

function renderOKNGLists() {
  const data = SOS_IMAGES[activeOKNGKey] || { ok:[], ng:[] };
  document.getElementById('okng-ok-count').textContent = data.ok.length ? `(${data.ok.length})` : '';
  document.getElementById('okng-ng-count').textContent = data.ng.length ? `(${data.ng.length})` : '';
  
  ['ok','ng'].forEach(type => {
    const list = document.getElementById(`okng-${type}-list`);
    const imgs = data[type] || [];
    list.innerHTML = imgs.map((img, i) => `
      <div class="okng-img-card">
        <img src="${img.src}" alt="${img.caption || type.toUpperCase()+' '+(i+1)}" />
        <div class="okng-img-lbl">
          <span>${img.caption || (type.toUpperCase()+' Image '+(i+1))}</span>
          <button class="okng-img-del" onclick="deleteOKNGImage('${type}',${i})">✕</button>
        </div>
      </div>`).join('');
  });
}

function triggerOKNGUpload(type) {
  document.getElementById(`okng-${type}-input`).click();
}

function onOKNGUpload(input, type) {
  if (!input.files.length) return;
  if (!SOS_IMAGES[activeOKNGKey]) SOS_IMAGES[activeOKNGKey] = { ok:[], ng:[] };
  const files = Array.from(input.files);
  let loaded = 0;
  files.forEach((file, fi) => {
    const r = new FileReader();
    r.onload = e => {
      SOS_IMAGES[activeOKNGKey][type].push({ src: e.target.result, caption: type.toUpperCase()+' '+(SOS_IMAGES[activeOKNGKey][type].length) });
      loaded++;
      if (loaded === files.length) { renderOKNGLists(); toast(files.length + ' image(s) uploaded'); }
    };
    r.readAsDataURL(file);
  });
  input.value = '';
}

function deleteOKNGImage(type, idx) {
  if (!SOS_IMAGES[activeOKNGKey]) return;
  SOS_IMAGES[activeOKNGKey][type].splice(idx, 1);
  renderOKNGLists();
  saveSpecData(true);
  toast('Image removed and saved');
}

function openNGQuizFromViewer() {
  closeOKNGModal();
  setTimeout(() => openNGQuiz(activeOKNGProcId, activeOKNGSl, activeOKNGTitle), 200);
}

// ═══════════════════════════════════════════
// NG PUZZLE QUIZ ENGINE
// ═══════════════════════════════════════════
const NG_QUIZ = { questions:[], idx:0, correct:0, total:0, answered:false, procId:'', items:[] };

function openNGQuiz(procId, sl, itemName) {
  // Build quiz questions from this check item's images
  const key = sosImgKey(procId, sl);
  const data = SOS_IMAGES[key] || { ok:[], ng:[] };
  
  if (data.ok.length === 0 && data.ng.length === 0) {
    // No images — build quiz from all items in this process
    const proc = SOS_PROCESSES.find(p => p.id === procId);
    const allItems = proc ? [...proc.steps, ...(SOS_CUSTOM[procId]||[])] : [];
    const allKeys = allItems.map(s => sosImgKey(procId, s.sl || 0));
    const hasAny = allKeys.some(k => SOS_IMAGES[k] && (SOS_IMAGES[k].ok.length || SOS_IMAGES[k].ng.length));
    if (!hasAny) {
      // Show no-images state
      document.getElementById('ng-quiz-title-text').textContent = t('ng_quiz_title');
      document.getElementById('ng-quiz-body').innerHTML = `
        <div class="ng-quiz-no-images">
          <div style="font-size:36px;">📷</div>
          <div>${t('ng_quiz_no_images')}</div>
          <button class="btn btn-accent" style="margin-top:8px;" onclick="closeNGQuiz();setTimeout(()=>openOKNGModal('${procId}',${sl},'${escQ(itemName)}'),200)">👁 ${t('okng_quiz_btn')}</button>
        </div>`;
      document.getElementById('ng-quiz-submit-btn').style.display='none';
      document.getElementById('ng-quiz-next-btn').style.display='none';
      document.getElementById('ng-quiz-restart-btn').style.display='none';
      document.getElementById('ng-quiz-score-line').textContent = '';
      document.getElementById('ng-quiz-modal').classList.add('open');
      return;
    }
    // Build multi-item quiz
    buildNGQuizMulti(procId, itemName);
  } else {
    // Build quiz for single check item
    buildNGQuizSingle(key, itemName, procId, sl);
  }
}

function buildNGQuizSingle(imgKey, title, procId, sl) {
  const data = SOS_IMAGES[imgKey] || { ok:[], ng:[] };
  // Combine all images and ask user to select NG ones
  const allImgs = [
    ...data.ok.map((img, i) => ({ ...img, type:'ok', idx:i })),
    ...data.ng.map((img, i) => ({ ...img, type:'ng', idx:i }))
  ];
  // Shuffle
  for (let i = allImgs.length-1; i>0; i--) {
    const j = Math.floor(Math.random()*(i+1));
    [allImgs[i],allImgs[j]] = [allImgs[j],allImgs[i]];
  }
  NG_QUIZ.questions = [{ title, allImgs, ngCount: data.ng.length }];
  NG_QUIZ.idx = 0;
  NG_QUIZ.correct = 0;
  NG_QUIZ.total = 1;
  NG_QUIZ.answered = false;
  document.getElementById('ng-quiz-title-text').textContent = '🧩 ' + t('ng_quiz_title') + ' — ' + title;
  document.getElementById('ng-quiz-modal').classList.add('open');
  renderNGQuizQuestion();
}

function buildNGQuizMulti(procId, filterTitle) {
  const proc = SOS_PROCESSES.find(p => p.id === procId);
  if (!proc) return;
  const allItems = [...proc.steps, ...(SOS_CUSTOM[procId]||[])];
  const questions = [];
  allItems.forEach(s => {
    const k = sosImgKey(procId, s.sl || 0);
    const data = SOS_IMAGES[k];
    if (!data || (data.ok.length === 0 && data.ng.length === 0)) return;
    const allImgs = [
      ...data.ok.map((img, i) => ({ ...img, type:'ok', idx:i })),
      ...data.ng.map((img, i) => ({ ...img, type:'ng', idx:i }))
    ];
    for (let i = allImgs.length-1; i>0; i--) {
      const j = Math.floor(Math.random()*(i+1));
      [allImgs[i],allImgs[j]] = [allImgs[j],allImgs[i]];
    }
    questions.push({ title: s.item, allImgs, ngCount: data.ng.length });
  });
  NG_QUIZ.questions = questions;
  NG_QUIZ.idx = 0;
  NG_QUIZ.correct = 0;
  NG_QUIZ.total = questions.length;
  NG_QUIZ.answered = false;
  document.getElementById('ng-quiz-title-text').textContent = '🧩 ' + t('ng_quiz_title') + ' — ' + proc.name;
  document.getElementById('ng-quiz-modal').classList.add('open');
  renderNGQuizQuestion();
}

function renderNGQuizQuestion() {
  const q = NG_QUIZ.questions[NG_QUIZ.idx];
  if (!q) { showNGQuizResult(); return; }
  NG_QUIZ.answered = false;
  const total = NG_QUIZ.questions.length;
  const pct = (NG_QUIZ.idx/total*100).toFixed(0);
  
  const submitBtn = document.getElementById('ng-quiz-submit-btn');
  const nextBtn = document.getElementById('ng-quiz-next-btn');
  const restartBtn = document.getElementById('ng-quiz-restart-btn');
  submitBtn.textContent = t('ng_quiz_submit');
  nextBtn.textContent = t('ng_quiz_next');
  restartBtn.textContent = t('ng_quiz_restart');
  submitBtn.style.display = '';
  nextBtn.style.display = 'none';
  restartBtn.style.display = 'none';

  document.getElementById('ng-quiz-score-line').innerHTML = `Q${NG_QUIZ.idx+1}/${total} · Score: <b>${NG_QUIZ.correct}</b>`;
  
  const hasImages = q.allImgs.length > 0;
  document.getElementById('ng-quiz-body').innerHTML = `
    <div style="display:flex;align-items:center;gap:10px;margin-bottom:12px;">
      <div style="flex:1;height:4px;background:rgba(0,255,136,0.1);border-radius:2px;overflow:hidden;">
        <div style="height:100%;background:var(--ok);border-radius:2px;width:${pct}%;transition:width 0.4s;"></div>
      </div>
      <div style="font-size:10px;color:var(--muted);">${NG_QUIZ.idx+1}/${total}</div>
    </div>
    <div style="font-size:13px;font-weight:700;color:#e6f1ff;margin-bottom:4px;">${q.title}</div>
    <div class="ng-quiz-instr">${t('ng_quiz_instr')} ${q.ngCount > 0 ? `<b style="color:var(--danger);">(${q.ngCount} NG)</b>` : ''}</div>
    ${hasImages ? `<div class="ng-quiz-grid" id="ng-quiz-grid">
      ${q.allImgs.map((img, i) => `
        <div class="ng-quiz-img-card" id="ng-qcard-${i}" onclick="toggleNGSelection(${i})">
          <div class="ng-quiz-card-check">✓</div>
          <img src="${img.src}" alt="" onerror="this.style.display='none'" />
          <div class="ng-quiz-img-label" style="color:var(--muted);">Image ${i+1}</div>
        </div>`).join('')}
    </div>` : `<div class="ng-quiz-no-images"><div>No images for this item.</div></div>`}
    <div id="ng-quiz-feedback" style="display:none;margin-top:12px;padding:10px 12px;border-radius:6px;font-size:11px;line-height:1.6;"></div>
  `;
  q._selected = new Set();
}

function toggleNGSelection(i) {
  if (NG_QUIZ.answered) return;
  const q = NG_QUIZ.questions[NG_QUIZ.idx];
  const card = document.getElementById('ng-qcard-'+i);
  if (!card) return;
  if (q._selected.has(i)) {
    q._selected.delete(i);
    card.classList.remove('selected');
  } else {
    q._selected.add(i);
    card.classList.add('selected');
  }
}

function submitNGQuiz() {
  const q = NG_QUIZ.questions[NG_QUIZ.idx];
  if (!q || NG_QUIZ.answered) return;
  NG_QUIZ.answered = true;
  
  const selected = q._selected || new Set();
  const correctNGIndices = new Set(
    q.allImgs.map((img, i) => img.type === 'ng' ? i : -1).filter(i => i >= 0)
  );
  
  // Score: selected all NG and no OK
  const selectedArr = Array.from(selected);
  const correctArr = Array.from(correctNGIndices);
  const allCorrectSelected = correctArr.every(i => selected.has(i));
  const noFalsePositives = selectedArr.every(i => correctNGIndices.has(i));
  const isFullyCorrect = allCorrectSelected && noFalsePositives;
  if (isFullyCorrect) NG_QUIZ.correct++;

  // Color cards
  q.allImgs.forEach((img, i) => {
    const card = document.getElementById('ng-qcard-'+i);
    if (!card) return;
    card.style.cursor = 'default';
    if (img.type === 'ng') {
      // Should have been selected
      if (selected.has(i)) {
        card.classList.remove('selected');
        card.classList.add('correct');
        card.querySelector('.ng-quiz-img-label').textContent = '✅ NG (Correct)';
        card.querySelector('.ng-quiz-img-label').style.color = 'var(--ok)';
      } else {
        card.classList.add('missed');
        card.querySelector('.ng-quiz-img-label').textContent = '⚠ NG (Missed)';
        card.querySelector('.ng-quiz-img-label').style.color = 'var(--danger)';
      }
    } else {
      // OK image
      if (selected.has(i)) {
        card.classList.remove('selected');
        card.classList.add('wrong');
        card.querySelector('.ng-quiz-img-label').textContent = '✗ OK (Wrong Pick)';
        card.querySelector('.ng-quiz-img-label').style.color = 'var(--warn)';
      } else {
        card.querySelector('.ng-quiz-img-label').textContent = '✓ OK';
        card.querySelector('.ng-quiz-img-label').style.color = 'var(--ok)';
      }
    }
  });

  const fb = document.getElementById('ng-quiz-feedback');
  fb.style.display = 'block';
  if (isFullyCorrect) {
    fb.style.background = 'rgba(0,255,136,0.08)';
    fb.style.border = '1px solid rgba(0,255,136,0.2)';
    fb.style.color = 'var(--ok)';
    fb.innerHTML = `✅ <b>Correct!</b> You identified all ${correctArr.length} NG image(s) correctly.`;
  } else {
    fb.style.background = 'rgba(255,46,99,0.08)';
    fb.style.border = '1px solid rgba(255,46,99,0.2)';
    fb.style.color = 'var(--danger)';
    const missed = correctArr.filter(i => !selected.has(i)).length;
    const wrong = selectedArr.filter(i => !correctNGIndices.has(i)).length;
    fb.innerHTML = `✗ <b>Incorrect.</b>${missed > 0 ? ` Missed ${missed} NG image(s).` : ''}${wrong > 0 ? ` Selected ${wrong} OK image(s) as NG.` : ''} Review the highlighted images above.`;
  }

  document.getElementById('ng-quiz-score-line').innerHTML = `Q${NG_QUIZ.idx+1}/${NG_QUIZ.questions.length} · Score: <b>${NG_QUIZ.correct}</b>`;
  document.getElementById('ng-quiz-submit-btn').style.display = 'none';
  
  if (NG_QUIZ.idx + 1 >= NG_QUIZ.questions.length) {
    setTimeout(showNGQuizResult, 1500);
  } else {
    document.getElementById('ng-quiz-next-btn').style.display = '';
  }
}

function nextNGQuiz() {
  NG_QUIZ.idx++;
  if (NG_QUIZ.idx >= NG_QUIZ.questions.length) { showNGQuizResult(); return; }
  renderNGQuizQuestion();
}

function showNGQuizResult() {
  const total = NG_QUIZ.questions.length;
  const pct = total > 0 ? Math.round(NG_QUIZ.correct/total*100) : 0;
  const grade = pct>=90?'🏆 Excellent!':pct>=70?'✅ Good Job!':pct>=50?'📚 Keep Practicing':'🔁 Review Needed';
  document.getElementById('ng-quiz-body').innerHTML = `
    <div class="ng-quiz-result">
      <div class="ng-quiz-result-score">${NG_QUIZ.correct}/${total}</div>
      <div class="ng-quiz-result-label">${pct}% — ${grade}</div>
      <div class="ng-quiz-result-detail">
        ${pct>=70 ? 'Great work! You can reliably identify NG conditions for this inspection item.' : 'Review the OK/NG reference images and practice again to improve defect recognition.'}
      </div>
    </div>`;
  document.getElementById('ng-quiz-submit-btn').style.display = 'none';
  document.getElementById('ng-quiz-next-btn').style.display = 'none';
  document.getElementById('ng-quiz-restart-btn').style.display = '';
  document.getElementById('ng-quiz-score-line').innerHTML = `Final: <b>${NG_QUIZ.correct}</b>/${total}`;
}

function restartNGQuiz() {
  NG_QUIZ.idx = 0;
  NG_QUIZ.correct = 0;
  NG_QUIZ.answered = false;
  // Re-shuffle each question's images
  NG_QUIZ.questions.forEach(q => {
    for (let i = q.allImgs.length-1; i>0; i--) {
      const j = Math.floor(Math.random()*(i+1));
      [q.allImgs[i],q.allImgs[j]] = [q.allImgs[j],q.allImgs[i]];
    }
  });
  renderNGQuizQuestion();
}

function closeNGQuiz() {
  document.getElementById('ng-quiz-modal').classList.remove('open');
}

// ═══════════════════════════════════════════
// JUDGEMENT TRAINER ENGINE - ITEM BASED
// ═══════════════════════════════════════════

// Judgement item types. User can add/remove; process names are intentionally removed.
const JT_ITEM_LIST_KEY = 'toyota_judgement_trainer_item_list_v1';
let JT_CHECK_ITEMS = [
  { sl: 1,  name: 'Hose Insertion', icon: '🔧' },
  { sl: 2,  name: 'Clip Position', icon: '📎' },
  { sl: 3,  name: 'W/H Clip Come off/Unlock', icon: '⚡' },
  { sl: 4,  name: 'Bolt Looseness', icon: '🔩' },
  { sl: 5,  name: 'Clamp Come off/Unlock', icon: '🔗' },
  { sl: 6,  name: 'Part Interference', icon: '⚠️' },
  { sl: 7,  name: 'Mark Miss', icon: '🔴' },
  { sl: 8,  name: 'Connector Half lock/Not connected', icon: '🔌' },
  { sl: 9,  name: 'Part damage', icon: '💥' },
  { sl: 10, name: 'Hose/Tube Unlock', icon: '💧' },
];
try { const savedJTList = JSON.parse(localStorage.getItem(JT_ITEM_LIST_KEY)||'null'); if(Array.isArray(savedJTList) && savedJTList.length) JT_CHECK_ITEMS = savedJTList; } catch(e){}
function saveJTItemsList(){ try{ localStorage.setItem(JT_ITEM_LIST_KEY, JSON.stringify(JT_CHECK_ITEMS)); }catch(e){} }
function nextJTSl(){ return JT_CHECK_ITEMS.reduce((m,x)=>Math.max(m, Number(x.sl)||0),0)+1; }

const JT_STORAGE_KEY = 'toyota_judgement_trainer_item_images_v2';
let JT_ITEM_IMAGES = {};
try { JT_ITEM_IMAGES = JSON.parse(localStorage.getItem(JT_STORAGE_KEY) || '{}'); } catch(e) { JT_ITEM_IMAGES = {}; }

let JT_ACTIVE_SL = 0;
let JT_ACTIVE_TITLE = '';
let JT_UPLOAD_SL = 0;
let JT_UPLOAD_TITLE = '';
let JT_UPLOAD_TYPE = 'ok';
let JT_QUIZ_STATE = { questions:[], idx:0, correct:0, answered:false, mode:'single' };

function jtImgKey(procId, sl) { return 'jt_item_' + sl; }
function getJTData(sl){ const k=jtImgKey('',sl); if(!JT_ITEM_IMAGES[k]) JT_ITEM_IMAGES[k]={ok:[],ng:[]}; return JT_ITEM_IMAGES[k]; }
function saveJTData(){
  try { localStorage.setItem(JT_STORAGE_KEY, JSON.stringify(JT_ITEM_IMAGES)); toast('Judgement Trainer data saved ✓'); }
  catch(e){ alert('Unable to save. Browser storage may be full because images are large. Please reduce image size or delete old images.'); }
}

function renderJTProcs(filterVal) {
  const q=(filterVal||'').toLowerCase();
  const filtered=JT_CHECK_ITEMS.filter(ci=>!q||ci.name.toLowerCase().includes(q)||jtName(ci).toLowerCase().includes(q));
  const list=document.getElementById('jt-item-list'); if(!list) return;
  list.innerHTML=filtered.map(ci=>{ const data=getJTData(ci.sl); const okTot=data.ok.length, ngTot=data.ng.length; const isActive=JT_ACTIVE_SL===ci.sl; return `<div class="jt-proc-row${isActive?' active':''}" onclick="selectJTProcess('${ci.sl}')"><div style="display:flex;align-items:flex-start;gap:4px;"><div class="jt-proc-name" style="flex:1;">${ci.icon||'🏅'} ${escHtml(jtName(ci))}${currentLang==='en'?'':`<span style="display:block;font-size:9px;color:var(--muted);margin-top:1px;">${escHtml(ci.name)}</span>`}</div><button class="jt-mini-btn" title="${t('delete_label')}" onclick="event.stopPropagation();deleteJTItem(${ci.sl})">✕</button></div><div class="jt-proc-meta">${t('jt_meta')}</div>${(okTot+ngTot)>0?`<div class="jt-proc-img-cnt">✅ ${okTot} OK &nbsp; ❌ ${ngTot} NG</div>`:''}</div>`; }).join('');
  const cnt=document.getElementById('jt-proc-count'); if(cnt) cnt.textContent=filtered.length;
}
function addJTItem(){ const inp=document.getElementById('new-jt-item-name'); const name=(inp&&inp.value||'').trim(); if(!name){toast(t('jt_new_item_ph'));return;} if(JT_CHECK_ITEMS.some(x=>x.name.toLowerCase()===name.toLowerCase())){toast('Item already exists');return;} const icons=['🔧','📎','⚡','🔩','🔗','⚠️','🔴','🔌','💥','💧','✅','🛠️']; const sl=nextJTSl(); JT_CHECK_ITEMS.push({sl,name,icon:icons[(sl-1)%icons.length]}); if(inp) inp.value=''; saveJTItemsList(); saveJTData(); JT_ACTIVE_SL=sl; renderJTProcs(document.getElementById('jt-proc-search')?.value||''); renderJTDetail(sl); toast('Judgement item added, translated and saved'); }
function deleteJTItem(sl){ if(!confirm(t('jt_delete_item_confirm'))) return; const idx=JT_CHECK_ITEMS.findIndex(x=>Number(x.sl)===Number(sl)); if(idx<0) return; JT_CHECK_ITEMS.splice(idx,1); delete JT_ITEM_IMAGES[jtImgKey('',sl)]; if(JT_ACTIVE_SL===Number(sl)){ JT_ACTIVE_SL=0; const body=document.getElementById('jt-detail-body'); if(body) body.innerHTML=`<div class="jt-detail-empty"><span>${t('jt_empty')}</span></div>`; const act=document.getElementById('jt-detail-actions'); if(act) act.style.display='none'; document.getElementById('jt-detail-title').textContent=t('jt_select_prompt'); document.getElementById('jt-detail-sub').textContent=t('jt_detail_sub'); } saveJTItemsList(); saveJTData(); renderJTProcs(document.getElementById('jt-proc-search')?.value||''); toast(t('remove_label')+' ✓'); }

function filterJTProcs(val){ renderJTProcs(val); }

function selectJTProcess(sl) {
  JT_ACTIVE_SL = Number(sl);
  renderJTProcs(document.getElementById('jt-proc-search')?.value||'');
  renderJTDetail(JT_ACTIVE_SL);
}

function renderJTDetail(sl) {
  const ci=JT_CHECK_ITEMS.find(c=>c.sl===Number(sl)); if(!ci) return; JT_ACTIVE_TITLE=ci.name; const displayName=jtName(ci);
  document.getElementById('jt-detail-title').innerHTML=(ci.icon||'🏅')+' '+escHtml(displayName)+(currentLang==='en'?'':`<span style="display:block;font-size:10px;color:var(--muted);margin-top:2px;">${escHtml(ci.name)}</span>`);
  document.getElementById('jt-detail-sub').textContent=t('jt_detail_sub'); document.getElementById('jt-detail-actions').style.display='flex';
  const btns=document.getElementById('jt-detail-actions'); if(btns) btns.innerHTML=`<button class="btn btn-ghost" style="font-size:10px;border-color:rgba(192,132,252,0.3);color:#c084fc;" onclick="openJTUpload()">📷 ${t('jt_upload_images')}</button><button class="btn btn-ok" style="font-size:10px;" onclick="startJTQuiz()" id="jt-start-quiz-btn">🧩 ${t('jt_start_mixed')}</button>`;
  const body=document.getElementById('jt-detail-body'); body.innerHTML=`<div class="jt-check-list" id="jt-check-list"><div class="jt-check-item" id="jtci-${ci.sl}"><div class="jt-check-hdr"><span class="jt-check-sl">${ci.sl}</span><span class="jt-check-name">${ci.icon||'🏅'} ${escHtml(displayName)}</span><div class="jt-check-badges"><button class="jt-btn-upload" onclick="openJTItemUpload('',${ci.sl},'${escJS(ci.name)}','ok')">📷 ${t('add_ok')}</button><button class="jt-btn-upload" onclick="openJTItemUpload('',${ci.sl},'${escJS(ci.name)}','ng')">📷 ${t('add_ng')}</button><button class="jt-btn-quiz" onclick="startJTItemQuiz('',${ci.sl},'${escJS(ci.name)}')">🧩 ${t('puzzle_test')}</button></div></div><div class="jt-check-body open" id="jtcb-${ci.sl}">${renderJTItemImages('',ci.sl,ci.name)}</div></div></div><input type="file" id="jt-ok-input" accept="image/*" multiple style="display:none;" onchange="onJTUpload(this,'ok')"/><input type="file" id="jt-ng-input" accept="image/*" multiple style="display:none;" onchange="onJTUpload(this,'ng')"/><div id="jt-quiz-zone"></div>`;
}

function renderJTItemImages(procId, sl, title) {
  const data=getJTData(sl); const capTitle=tAnyText(title);
  return `<div class="jt-okng-cols"><div><div class="jt-col-hdr ok">✅ ${t('jt_ok_good')} (${data.ok.length})</div><div class="jt-img-grid">${data.ok.map((img,i)=>`<div class="jt-img-card"><img src="${img.src}" alt="OK ${i+1}" onclick="openLbImg('${img.src}','${escJS(capTitle)} — OK Image ${i+1}')"/><div class="jt-img-lbl"><span>OK ${i+1}</span><button class="jt-img-del" onclick="deleteJTImage('',${sl},'ok',${i})">✕</button></div></div>`).join('')}<div class="jt-add-zone ok" onclick="openJTItemUpload('',${sl},'${escJS(title)}','ok')"><span style="font-size:18px;">📷</span><span>${t('jt_add_ok_images')}</span><span style="font-size:9px;opacity:0.7;">${t('jt_multiple')}</span></div></div></div><div><div class="jt-col-hdr ng">❌ ${t('jt_ng_defect')} (${data.ng.length})</div><div class="jt-img-grid">${data.ng.map((img,i)=>`<div class="jt-img-card"><img src="${img.src}" alt="NG ${i+1}" onclick="openLbImg('${img.src}','${escJS(capTitle)} — NG Image ${i+1}')"/><div class="jt-img-lbl"><span>NG ${i+1}</span><button class="jt-img-del" onclick="deleteJTImage('',${sl},'ng',${i})">✕</button></div></div>`).join('')}<div class="jt-add-zone ng" onclick="openJTItemUpload('',${sl},'${escJS(title)}','ng')"><span style="font-size:18px;">📷</span><span>${t('jt_add_ng_images')}</span><span style="font-size:9px;opacity:0.7;">${t('jt_multiple')}</span></div></div></div></div>`;
}

function openLbImg(src, cap){
  document.getElementById('lb-img').src=src;
  document.getElementById('lb-cap').textContent=cap;
  document.getElementById('lb').classList.add('open');
}

function toggleJTItem(procId, sl) {
  const body = document.getElementById('jtcb-'+sl);
  if(body) body.classList.toggle('open');
}

function openJTItemUpload(procId, sl, title, type) {
  JT_UPLOAD_SL=Number(sl); JT_UPLOAD_TITLE=title; JT_UPLOAD_TYPE = type || 'ok';
  const ok=document.getElementById('jt-ok-input'), ng=document.getElementById('jt-ng-input');
  if(ok) ok.value=''; if(ng) ng.value='';
  if(JT_UPLOAD_TYPE==='ng') ng?.click(); else ok?.click();
}

function openJTUpload(){
  if(!JT_ACTIVE_SL){toast('Select a judgement item first');return;}
  openJTItemUpload('', JT_ACTIVE_SL, JT_ACTIVE_TITLE || 'Judgement Item', 'ok');
}

function onJTUpload(input, type) {
  if(!input.files.length) return;
  const data = getJTData(JT_UPLOAD_SL);
  const files=Array.from(input.files);
  let loaded=0;
  files.forEach(file => {
    const r=new FileReader();
    r.onload=e=>{
      data[type].push({src:e.target.result, caption:type.toUpperCase()+' '+(data[type].length+1)});
      loaded++;
      if(loaded===files.length){
        saveJTData();
        if(JT_ACTIVE_SL) renderJTDetail(JT_ACTIVE_SL);
        renderJTProcs(document.getElementById('jt-proc-search')?.value||'');
        toast(files.length+' '+type.toUpperCase()+' image(s) uploaded ✓');
      }
    };
    r.readAsDataURL(file);
  });
  input.value='';
}

function deleteJTImage(procId, sl, type, idx) {
  const data=getJTData(sl);
  data[type].splice(idx,1);
  saveJTData();
  if(JT_ACTIVE_SL) renderJTDetail(JT_ACTIVE_SL);
  renderJTProcs(document.getElementById('jt-proc-search')?.value||'');
  saveSpecData(true);
  toast('Image removed and saved');
}

function buildJTQuestion(sl, title) {
  const data=getJTData(sl);
  const allImgs=[...data.ok.map((img,i)=>({...img,type:'ok',idx:i})), ...data.ng.map((img,i)=>({...img,type:'ng',idx:i}))];
  if(!allImgs.length) return null;
  for(let i=allImgs.length-1;i>0;i--){const j=Math.floor(Math.random()*(i+1));[allImgs[i],allImgs[j]]=[allImgs[j],allImgs[i]];}
  const quizMode = (data.ok.length>0 && data.ng.length>0) ? (Math.random()<0.5?'select_ok':'select_ng') : (data.ok.length>0?'select_ok':'select_ng');
  return {sl, title, allImgs, okCount:data.ok.length, ngCount:data.ng.length, quizMode, _selected:new Set()};
}

function startJTItemQuiz(procId, sl, title) {
  const q=buildJTQuestion(Number(sl), title);
  if(!q){toast('No images uploaded for this item');return;}
  JT_QUIZ_STATE={questions:[q],idx:0,correct:0,answered:false,mode:'single',sl:Number(sl)};
  const body=document.getElementById('jtcb-'+sl);
  if(body) body.classList.add('open');
  renderJTInlineQuiz('jtcb-'+sl, '', Number(sl));
}

function startJTQuiz() {
  const questions=[];
  JT_CHECK_ITEMS.forEach(ci=>{ const q=buildJTQuestion(ci.sl, (ci.icon||'🏅')+' '+jtName(ci)); if(q) questions.push(q); });
  if(!questions.length){toast('No images uploaded yet. Upload OK/NG images first.');return;}
  JT_QUIZ_STATE={questions,idx:0,correct:0,answered:false,mode:'multi',sl:0};
  renderJTFullQuiz();
}
function startJTProcessQuiz(){ startJTQuiz(); }

function renderJTFullQuiz(){
  const body=document.getElementById('jt-detail-body');
  document.getElementById('jt-detail-title').textContent='🧩 '+t('jt_mixed_title');
  document.getElementById('jt-detail-sub').textContent=t('jt_mixed_sub');
  document.getElementById('jt-detail-actions').style.display='flex';
  body.innerHTML=`<div id="jt-quiz-full-zone"></div>`;
  renderJTInlineQuiz('jt-quiz-full-zone', '', 0);
}

function renderJTInlineQuiz(containerId, procId, sl) {
  const q=JT_QUIZ_STATE.questions[JT_QUIZ_STATE.idx];
  if(!q){renderJTQuizResult(containerId);return;}
  JT_QUIZ_STATE.answered=false;
  const total=JT_QUIZ_STATE.questions.length;
  const pct=(JT_QUIZ_STATE.idx/total*100).toFixed(0);
  const qzId='jt-quiz-inline-'+containerId.replace(/[^a-z0-9]/gi,'_');
  const container=document.getElementById(containerId);
  if(!container) return;
  const zone=(containerId==='jt-quiz-full-zone')?container:(document.getElementById('jt-quiz-zone')||container);
  const isNGMode = q.quizMode === 'select_ng';
  const modeLabel = isNGMode ? `<span style="color:var(--danger);font-weight:700;">❌ ${t('jt_select_ng')}</span>` : `<span style="color:var(--ok);font-weight:700;">✅ ${t('jt_select_ok')}</span>`;
  const targetCount = isNGMode ? q.ngCount : q.okCount;
  zone.innerHTML=`
    <div class="jt-quiz-panel" id="${qzId}">
      <div class="jt-quiz-panel-hdr">
        <div class="jt-quiz-panel-title">🧩 ${t('puzzle_test')} ${total>1?`— Q${JT_QUIZ_STATE.idx+1}/${total}`:''}</div>
        <button class="btn btn-ghost" style="font-size:10px;" onclick="closeJTQuiz('${containerId}')">✕ ${t('jt_close')}</button>
      </div>
      ${total>1?`<div style="height:4px;background:rgba(0,212,255,0.08);border-radius:2px;overflow:hidden;margin-bottom:10px;"><div style="height:100%;background:${isNGMode?'var(--danger)':'var(--ok)'};width:${pct}%;transition:width 0.4s;border-radius:2px;"></div></div>`:''}
      <div style="font-size:12px;font-weight:700;color:#e6f1ff;margin-bottom:6px;">${q.title}</div>
      <div style="padding:8px 12px;border-radius:6px;margin-bottom:10px;font-size:11px;line-height:1.5;${isNGMode?'background:rgba(255,46,99,0.07);border:1px solid rgba(255,46,99,0.2);':'background:rgba(0,255,136,0.07);border:1px solid rgba(0,255,136,0.2);'}">
        ${modeLabel}<br/><span style="color:var(--muted);">${t('jt_target_count')}: <b>${targetCount}</b>. ${t('jt_click_all')}</span>
      </div>
      <div class="jt-puzzle-grid" id="${qzId}-grid">
        ${q.allImgs.map((img,i)=>`
          <div class="jt-puzzle-card" id="${qzId}-card-${i}" onclick="toggleJTPuzzleCard('${qzId}',${i})">
            <div class="jt-puzzle-card-check" style="background:${isNGMode?'var(--danger)':'var(--ok)'};">✓</div>
            <img src="${img.src}" alt="" onerror="this.style.display='none'"/>
            <div class="jt-puzzle-card-label">Image ${i+1}</div>
          </div>`).join('')}
      </div>
      <div id="${qzId}-feedback" class="jt-quiz-feedback"></div>
      <div class="jt-quiz-actions">
        <div class="jt-quiz-score" id="${qzId}-score">${t('jt_score')}: <b>${JT_QUIZ_STATE.correct}</b>${total>1?'/'+JT_QUIZ_STATE.idx:''}</div>
        <button class="btn btn-accent" id="${qzId}-submit" onclick="submitJTPuzzle('${qzId}','${containerId}')">${t('jt_submit')}</button>
        <button class="btn btn-ok" id="${qzId}-next" style="display:none;" onclick="nextJTPuzzle('${qzId}','${containerId}')">${t('jt_next')}</button>
      </div>
    </div>`;
}

function toggleJTPuzzleCard(qzId, i) {
  if(JT_QUIZ_STATE.answered) return;
  const q=JT_QUIZ_STATE.questions[JT_QUIZ_STATE.idx];
  const card=document.getElementById(qzId+'-card-'+i);
  if(!card) return;
  if(q._selected.has(i)){q._selected.delete(i);card.classList.remove('selected');}
  else{q._selected.add(i);card.classList.add('selected');}
}

function submitJTPuzzle(qzId, containerId) {
  if(JT_QUIZ_STATE.answered) return;
  JT_QUIZ_STATE.answered=true;
  const q=JT_QUIZ_STATE.questions[JT_QUIZ_STATE.idx];
  const selected=q._selected||new Set();
  const isNGMode = q.quizMode === 'select_ng';
  const correctIndices = new Set(q.allImgs.map((img,i)=>(isNGMode?img.type==='ng':img.type==='ok')?i:-1).filter(i=>i>=0));
  const selectedArr=Array.from(selected), correctArr=Array.from(correctIndices);
  const isFullyCorrect=correctArr.every(i=>selected.has(i))&&selectedArr.every(i=>correctIndices.has(i));
  if(isFullyCorrect) JT_QUIZ_STATE.correct++;
  q.allImgs.forEach((img,i)=>{
    const card=document.getElementById(qzId+'-card-'+i); if(!card) return;
    card.style.cursor='default'; const lbl=card.querySelector('.jt-puzzle-card-label');
    const isTarget = isNGMode ? img.type==='ng' : img.type==='ok';
    const targetLabel = isNGMode ? 'NG' : 'OK'; const otherLabel = isNGMode ? 'OK' : 'NG';
    if(isTarget){
      if(selected.has(i)){card.classList.remove('selected');card.classList.add('correct'); if(lbl){lbl.textContent=`✅ ${targetLabel} Correct`;lbl.style.color='var(--ok)';}}
      else{card.classList.add('missed'); if(lbl){lbl.textContent=`⚠ ${targetLabel} Missed`;lbl.style.color='var(--danger)';}}
    }else{
      if(selected.has(i)){card.classList.remove('selected');card.classList.add('wrong'); if(lbl){lbl.textContent=`✗ ${otherLabel} Wrong`;lbl.style.color='var(--warn)';}}
      else{ if(lbl){lbl.textContent=`✓ ${otherLabel}`;lbl.style.color='var(--ok)';} }
    }
  });
  const fb=document.getElementById(qzId+'-feedback');
  if(fb){
    fb.style.display='block';
    if(isFullyCorrect){fb.style.background='rgba(0,255,136,0.08)';fb.style.border='1px solid rgba(0,255,136,0.2)';fb.style.color='var(--ok)';fb.innerHTML=`✅ <b>Correct!</b> You selected all ${correctArr.length} ${isNGMode?'NG':'OK'} image(s).`;}
    else{fb.style.background='rgba(255,46,99,0.08)';fb.style.border='1px solid rgba(255,46,99,0.2)';fb.style.color='var(--danger)';fb.innerHTML=`✗ <b>Incorrect.</b> Correct images are highlighted. Review and continue.`;}
  }
  const sc=document.getElementById(qzId+'-score'); if(sc) sc.innerHTML=`${t('jt_score')}: <b>${JT_QUIZ_STATE.correct}</b>`;
  document.getElementById(qzId+'-submit').style.display='none';
  const total=JT_QUIZ_STATE.questions.length;
  if(JT_QUIZ_STATE.idx+1>=total){setTimeout(()=>renderJTQuizResult(containerId),1500);} else {const nb=document.getElementById(qzId+'-next');if(nb)nb.style.display='';}
}

function nextJTPuzzle(qzId, containerId) {
  JT_QUIZ_STATE.idx++;
  if(JT_QUIZ_STATE.idx>=JT_QUIZ_STATE.questions.length){renderJTQuizResult(containerId);return;}
  JT_QUIZ_STATE.questions[JT_QUIZ_STATE.idx]._selected=new Set();
  renderJTInlineQuiz(containerId, '', 0);
}

function renderJTQuizResult(containerId) {
  const total=JT_QUIZ_STATE.questions.length;
  const pct=total>0?Math.round(JT_QUIZ_STATE.correct/total*100):0;
  const grade=pct>=90?'🏆 Excellent!':pct>=70?'✅ Good Job!':pct>=50?'📚 Keep Practicing':'🔁 Review Needed';
  const zone=(containerId==='jt-quiz-full-zone')?document.getElementById(containerId):(document.getElementById('jt-quiz-zone')||document.getElementById(containerId));
  if(!zone) return;
  zone.innerHTML=`<div class="jt-quiz-panel"><div class="jt-quiz-result">
    <div class="jt-quiz-result-score">${JT_QUIZ_STATE.correct}/${total}</div>
    <div class="jt-quiz-result-label">${pct}% — ${grade}</div>
    <div class="jt-quiz-result-detail">${pct>=70?'Great work! You can identify the requested OK/NG images.':'Review the reference images and practice again.'}</div>
    <div style="margin-top:14px;display:flex;gap:8px;justify-content:center;">
      <button class="btn btn-ghost" onclick="restartJTQuiz('${containerId}')">↺ Restart Quiz</button>
      <button class="btn btn-ghost" onclick="closeJTQuiz('${containerId}')">✕ ${t('jt_close')}</button>
    </div>
  </div></div>`;
}

function restartJTQuiz(containerId) {
  JT_QUIZ_STATE.idx=0; JT_QUIZ_STATE.correct=0; JT_QUIZ_STATE.answered=false;
  JT_QUIZ_STATE.questions.forEach(q=>{ q._selected=new Set(); if(q.okCount>0&&q.ngCount>0) q.quizMode=Math.random()<0.5?'select_ok':'select_ng'; for(let i=q.allImgs.length-1;i>0;i--){const j=Math.floor(Math.random()*(i+1));[q.allImgs[i],q.allImgs[j]]=[q.allImgs[j],q.allImgs[i]];} });
  renderJTInlineQuiz(containerId, '', 0);
}

function closeJTQuiz(containerId) { if(JT_ACTIVE_SL) renderJTDetail(JT_ACTIVE_SL); else { document.getElementById('jt-detail-body').innerHTML='<div class="jt-detail-empty"><span>← Select a judgement item to begin</span></div>'; } }

function openJudgementTrainerFor(procId, sl, itemName) {
  showSec('judgement', document.querySelector('.sb-item[onclick*="judgement"]'));
  document.querySelector('.nav-btn[data-sec="judgement"]')?.classList.add('active');
  document.querySelectorAll('.nav-btn').forEach(b=>{if(b.dataset.sec!=='judgement')b.classList.remove('active');});
  const match = JT_CHECK_ITEMS.find(ci => ci.name.toLowerCase() === String(itemName||'').toLowerCase()) || JT_CHECK_ITEMS.find(ci=>ci.sl===Number(sl)) || JT_CHECK_ITEMS[0];
  setTimeout(()=>{ selectJTProcess(match.sl); },100);
}



// Robust InspectPro opener: repaint canvases after tab becomes visible.
function ensureInspectProVisible(){
  try{
    initAllCanvases();
    if(!DS || DS.gap===undefined) nd(); else paintDoor();
    if(!CS || CS.dist===undefined) nc(); else paintClip();
    if(!IS || IS.gap===undefined) ni_sim(); else paintInsert();
    if(!LS || LS.step===undefined) nl_sim(); else paintLevel();
    iUpdG();
  }catch(e){ console.error('InspectPro init error', e); }
}
document.addEventListener('click', function(e){
  const t=e.target.closest('[data-sec="inspect"], .sb-item[onclick*="inspect"]');
  if(t) setTimeout(ensureInspectProVisible, 80);
});

// ═══════════════════════════════════════════
// INIT
// ═══════════════════════════════════════════
loadSpecData();
loadVideoData();
renderAll();
applyTranslations();
renderSpecProcesses();
renderJTProcs();
setTimeout(()=>{
  ensureInspectProVisible();
  // Re-init if screen DPI changes (e.g. window move to another monitor)
  try{const mq=window.matchMedia&&window.matchMedia('screen'); if(mq&&mq.addEventListener) mq.addEventListener('change',()=>{initAllCanvases();nd();nc();ni_sim();nl_sim();});}catch(e){}
},200);
</script>
</body>
</html>
