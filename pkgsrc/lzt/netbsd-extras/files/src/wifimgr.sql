drop 	table	if exists	networks;
create	table	networks (
	id		integer primary key,
	interface	varchar not null,
	bssid		varchar not null,
	ssid		varchar,
	flags		varchar,
	key_mgmt	varchar,
	psk		varchar default NULL,
	scanned		int default 0,
	active		char default '',
	unique		(bssid)
);
