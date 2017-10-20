begin;
drop schema if exists lenzi2 cascade;
create schema lenzi2;
set search_path to lenzi2,public;

create table package (
	id		serial primary key,
	OS_VERSION	varchar,
	MACHINE_ARCH	varchar,
	PKGNAME		varchar,
	PKGPATH		varchar,
	ts		timestamptz default now(),
	unique		(OS_VERSION,MACHINE_ARCH,PKGNAME)
);

create table  deptable (
	OS_VERSION	varchar,
	pkgid		int references package(id)
				on update cascade
				on delete cascade,
	pkgdep		int references package(id)
				on update cascade
				on delete cascade,
	primary key	(OS_VERSION,pkgid,pkgdep)
);

create table  pkgrequires (
	OS_VERSION	varchar,
	pkgid		int references package(id)
				on update cascade
				on delete cascade,
	data	varchar
);

create table  pkgprovides (
	OS_VERSION	varchar,
	pkgid		int references package(id)
				on update cascade
				on delete cascade,
	data	varchar
);
\i triggers.sql
\d
commit;
