all:
	true

install:
	mkdir -p /etc/pkgtools
	cp *.sh /etc/pkgtools
	install -m 755 pkglztadmin /etc/pkgtools
	sh fixpkgtools

cvs:
	cvs up
	cvs commit
