
-- Toyota LineFlow Supabase setup
-- Run this once in Supabase > SQL Editor.

create table if not exists storage_items (
  key text primary key,
  value text,
  updated_at timestamptz default now()
);

create table if not exists module_data (
  module text primary key,
  data jsonb default '{}'::jsonb,
  updated_at timestamptz default now()
);

create table if not exists named_records (
  id bigserial primary key,
  module text not null,
  record_type text not null,
  data jsonb default '{}'::jsonb,
  created_at timestamptz default now(),
  updated_at timestamptz default now()
);

create table if not exists users (
  id bigserial primary key,
  username text unique not null,
  password_hash text not null,
  display_name text,
  role text default 'operator',
  is_active boolean default true,
  created_at timestamptz default now(),
  updated_at timestamptz default now()
);

create table if not exists sessions (
  id bigserial primary key,
  user_id bigint references users(id) on delete cascade,
  token text unique not null,
  expires_at timestamptz not null,
  created_at timestamptz default now()
);

create table if not exists audit_log (
  id bigserial primary key,
  action text not null,
  details jsonb default '{}'::jsonb,
  created_at timestamptz default now()
);

insert into module_data(module, data) values
('fmds','{}'),('glKpi','{}'),('tlKpi','{}'),('processAllocation','{}'),('trainingHub','{}'),('unifiedPortal','{}'),('shared','{}')
on conflict (module) do nothing;

-- Keep RLS disabled for these backend-managed tables.
-- Only the server-side SUPABASE_SERVICE_ROLE_KEY should access them.
