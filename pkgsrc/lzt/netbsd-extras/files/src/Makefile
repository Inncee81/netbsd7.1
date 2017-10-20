all: truncate daemon runbatch findprinter xtermtitle

install: all
	install -m 775 pkgtools/pkglztadmin ${DESTDIR}${PREFIX}/pkgtools
	install -m 644 pkgtools/*.sh ${DESTDIR}${PREFIX}/pkgtools
	install -m 755 runbatch truncate daemon xtermtitle ${DESTDIR}${PREFIX}/bin
	install -m 755 findprinter ${DESTDIR}${PREFIX}/bin
	install -m 755 wifimgr ${DESTDIR}${PREFIX}/bin
	install -m 644 daemon.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	install -m 644 truncate.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	install -m 644 wifimgr.glade ${DESTDIR}${PKG_SYSCONFDIR}/glade/wifimgr
	install -m 644 wifimgr.sql ${DESTDIR}${PREFIX}/share/examples/wifimgr
	install -m 644 sudoers.d/wifimgr ${DESTDIR}${PREFIX}/etc/sudoers.d
	rsync --exclude CVS/ -avzHx etc ${DESTDIR}${PREFIX}/share/examples/netbsd-extras
	rm -f truncate expand_number.o daemon runbatch

truncate: truncate.c expand_number.o
	cc truncate.c expand_number.o -o $@

clean:
	rm -f truncate expand_number.o daemon runbatch xtermtitle
