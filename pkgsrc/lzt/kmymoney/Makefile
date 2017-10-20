# $NetBSD$

PKGNAME=	kmymoney-4.8.0
GITHUB_PROJECT=	kmymoney
DISTNAME=	4.8.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	lzt
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDE/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://github.com/KDE/kmymoney/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/kmymoney-4.8.0
USE_CMAKE=	yes
USE_LANGUAGES=	c++

MAKE_JOBS=	1

USE_CMAKE+=		yes
CMAKE_ARGS+=		-Wno-dev
CMAKE_ARGS+=		-DENABLE_KBANKING:BOOL=OFF
CMAKE_ARGS+=		-DKDE4_BUILD_TESTS:BOOL=OFF
USE_TOOLS+=		msgfmt pkg-config perl
USE_TOOLS+=		gsed
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

REPLACE_PERL+=	contrib/splitup-kde-chunk-online
REPLACE_PERL+=	kmymoney/misc/financequote.pl

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../lzt/libalkimia/buildlink3.mk"
.include "../../lzt/sqlcipher/buildlink3.mk"
.include "../../lzt/aqbanking/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../misc/kdepim4/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
