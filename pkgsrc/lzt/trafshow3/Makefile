DISTNAME=	trafshow-3.1
CATEGORIES=	net
MASTER_SITES=	http://distcache.FreeBSD.org/local-distfiles/sem/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://distcache.FreeBSD.org/local-distfiles/sem/
COMMENT=	trafshow version 3
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
BUILD_TARGET=   trafshow
CFLAGS+=	-Wno-implicit-int

CONF_FILES+=	${PREFIX}/etc/trafshow.sample ${PREFIX}/etc/trafshow

post-install:
	mkdir -p ${DESTDIR}${PREFIX}/etc
	install -c ${WRKSRC}/.trafshow ${DESTDIR}${PREFIX}/etc/trafshow.sample

.include "../../devel/libslang2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
