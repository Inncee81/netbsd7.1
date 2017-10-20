# $NetBSD$
PKGNAME=	aqbanking-5.6.12
DISTNAME=	aqbanking-5.6.12
CATEGORIES=	lzt
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=03&release=208&file=01&dummy=/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://www.aquamaniac.de/sites/download/download.php?package=03&release=208&file=01&dummy=/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/aqbanking-5.6.12

MAKE_JOBS=	1

USE_TOOLS+=	pkg-config gmake iconv gettext
USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-backends="aqhbci aqnone aqofxconnect"

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../lzt/gwenhywfar/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
