. ./profile

rm -f $DB
cat << % | sqlite3 $DB
PRAGMA foreign_keys = ON;
create table if not exists pkg (
	pkgname varchar primary key,
	pkgpath varchar
);

create table if not exists pkgdep (
	pkgname	varchar references pkg
		on update cascade
		on delete cascade,
	pkgdep 	varchar references pkg
		on update cascade
		on delete cascade,
	unique (pkgname,pkgdep)
);
delete from pkg;
delete from pkgdep;
%

sqlite3 $DB ".schema"
sqlite3 $DB "select * from pkg"
