# $NetBSD$

GITHUB_PROJECT=	RetroShare
DISTNAME=	0.6.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	lzt
MASTER_SITES=	${MASTER_SITE_GITHUB:=RetroShare/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	https://github.com/RetroShare/RetroShare/
COMMENT=	P2P extremely secure communicator

WRKSRC=		${WRKDIR}/RetroShare-0.6.1

#MAKE_JOBS=	1

USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake 
USE_LIBTOOL=	yes

QMAKE=		${QTDIR}/bin/qmake

INSTALL_ENV+=   INSTALL_ROOT=${DESTDIR}

pre-configure:
	dos2unix ${WRKSRC}/retroshare-nogui/src/retroshare-nogui.pro

post-configure:
	cd ${WRKSRC};PKG_CONFIG_PATH=${_PKG_CONFIG_LIBDIR} ${QMAKE}

.include 	"../../lzt/sqlcipher/buildlink3.mk"
.include 	"../../devel/glib2/buildlink3.mk"
.include 	"../../devel/GConf/buildlink3.mk"
.include 	"../../sysutils/dbus/buildlink3.mk"
.include 	"../../audio/speex/buildlink3.mk"
.include 	"../../audio/speexdsp/buildlink3.mk"
.include 	"../../security/openssl/buildlink3.mk"
.include 	"../../security/libgnome-keyring/buildlink3.mk"
.include 	"../../security/gpgme/buildlink3.mk"
.include 	"../../security/libgcrypt/buildlink3.mk"
.include 	"../../security/seahorse/buildlink3.mk"
.include 	"../../graphics/opencv2/buildlink3.mk"
.include 	"../../multimedia/ffmpeg2/buildlink3.mk"
.include 	"../../www/curl/buildlink3.mk"
.include 	"../../www/libmicrohttpd/buildlink3.mk"
.include 	"../../devel/libexecinfo/buildlink3.mk"
.include 	"../../converters/dos2unix/buildlink3.mk"
.include 	"../../net/libupnp/buildlink3.mk"
.include 	"../../textproc/libxslt/buildlink3.mk"
.include 	"../../x11/qt4-tools/buildlink3.mk"
.include 	"../../x11/qt4-libs/buildlink3.mk"

.include        "../../sysutils/desktop-file-utils/desktopdb.mk"
.include        "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
