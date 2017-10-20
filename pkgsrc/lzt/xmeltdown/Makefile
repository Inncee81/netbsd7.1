# $NetBSD$

PKGNAME=	xmeltdown-1.0
GITHUB_PROJECT=	xmeltdown
DISTNAME=	master
CATEGORIES=	lzt
MASTER_SITES=	${MASTER_SITE_GITHUB:=veltzer/xmeltdown/archive/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	https://github.com/veltzer/xmeltdown/
COMMENT=	ancient xmeltdown
WRKSRC=		${WRKDIR}/xmeltdown-${DISTNAME}
LFLAGS!=	pkg-config --libs x11
LDFLAGS+=	-lm ${LFLAGS}

USE_TOOLS+=	gmake

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
