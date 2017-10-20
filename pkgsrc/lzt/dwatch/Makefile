# $NetBSD$

DISTNAME=	dwatch-0.1.1
CATEGORIES=	lzt
MASTER_SITES=	http://siag.nu/pub/dwatch/

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://siag.nu/pub/dwatch/
COMMENT=	TODO: Short description of the package

CFLAGS+=	-DETCDIR="\"${LOCALBASE}/etc/\"" \
		-DPS="\"/bin/ps -ax\""


EGDIR=			share/examples/dwatch

INSTALLATION_DIRS=	${PKGMANDIR}/man1 bin etc ${EGDIR}

do-build:
	(cd ${WRKSRC};${MAKE_ENV} ${CC} ${CFLAGS} -o dwatch dwatch.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dwatch \
		${DESTDIR}${LOCALBASE}/bin
	${INSTALL_MAN} ${WRKSRC}/dwatch.1 \
		${DESTDIR}${LOCALBASE}/${PKGMANDIR}/man1

	cd ${FILESDIR}; tar --exclude CVS -cf - share | \
		tar xpvf - -C ${DESTDIR}${LOCALBASE}

CONF_FILES+=	${LOCALBASE}/${EGDIR}/dwatch.conf ${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
