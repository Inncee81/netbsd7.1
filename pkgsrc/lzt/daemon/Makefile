DISTNAME=
PKGNAME=	daemon-1.0
CATEGORIES=	lzt
MASTER_SITES=

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://www.k1.com.br/
COMMENT=	invoke a program and become a daemon

WRKSRC=		${WRKDIR}/${PKGNAME}

pre-configure:
	mkdir -p ${WRKSRC}
	cp -rpf ${FILESDIR}/* ${WRKSRC}

pre-install:
	mkdir -p ${DESTDIR}${PREFIX}/bin \
		${DESTDIR}${PREFIX}/man/man8 \
		${DESTDIR}${PREFIX}/man/html8

.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
