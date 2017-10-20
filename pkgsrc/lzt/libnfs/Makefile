DISTNAME=	libnfs-2.0.0
PKGREVISION=	1
CATEGORIES=	lzt
MASTER_SITES=	ftp://192.168.34.1/NetBSD/distfiles/

MAINTAINER=	nervoso@k1.com.br
COMMENT=	Utilities to read cat list nfs files from command line

WRKSRC=		${WRKDIR}/libnfs-${DISTNAME}

USE_TOOLS=	aclocal autoheader autoconf automake gmake intltool msgfmt

GNU_CONFIGURE=	yes

pre-configure:
	set -e; cd ${WRKSRC}; \
	autoreconf -vif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
