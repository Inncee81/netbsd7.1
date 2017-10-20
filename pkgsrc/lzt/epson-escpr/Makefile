# $NetBSD$

PKGNAME=	epson-escpr-1.6.9
DISTNAME=	epson-inkjet-printer-escpr-1.6.9-1lsb3.2
CATEGORIES=	print
MASTER_SITES=	http://distcache.FreeBSD.org/local-distfiles/pi/

MAINTAINER=	nervoso@k1.com.br
COMMENT=	printer driver for epson ink tank generic

WRKSRC=		${WRKDIR}/epson-inkjet-printer-escpr-1.6.9
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
DOCSDIR=	${LOCALBASE}/share/doc/${PKGNAME}
INSTALLATION_DIRS+=share/doc/${PKGNAME}

CFLAGS+=	-Dunix

USE_TOOLS+=	gmake autoconf autoreconf

pre-patch:
	cd ${WRKSRC};\
	dos2unix -ic $$(find * -type f) | xargs dos2unix

pre-configure:
	cd ${WRKSRC} && autoreconf -vi ${AUTORECONF_ARGS}

PORTDOCS=	AUTHORS COPYING NEWS README README.ja

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} \
		${DESTDIR}${DOCSDIR}

BUILDLINK_DEPMETHOD.dos2unix?=	build

.include "../../print/cups/buildlink3.mk"
#.include "../../converters/dos2unix/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
