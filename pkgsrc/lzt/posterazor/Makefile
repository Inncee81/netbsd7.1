# $NetBSD$

PKGNAME=	PosteRazor-1.5.1
DISTNAME=	PosteRazor-1.5.1-Source
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=posterazor/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	ftp://sipgate.k1.com.br/NetBSD/Downloads/
COMMENT=	Poster Make for image files

WRKSRC=		${WRKDIR}/src # More than one possibility -- please check manually.
USE_LANGUAGES=	c c++

USE_CMAKE=	yes

CMAKE_ARGS=	-Wno-dev
CFLAGS+=	-Wno-write-strings
CFLAGS+=	-Wno-deprecated-declarations

BUILDLINK_TRANSFORM+=	rm:-Wwrite-strings

APPDIR=		share/applications
ICONDIR=	share/icons/hicolor/128x128/apps

INSTALLATION_DIRS+=	bin ${APPDIR} ${ICONDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/PosteRazor ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/posterazor.desktop ${DESTDIR}${PREFIX}/${APPDIR}
	cd ${DESTDIR}${PREFIX}/${ICONDIR};uudecode < ${FILESDIR}/posterazor.png.uu
	
.include 	"../../x11/fltk/buildlink3.mk"
.include 	"../../graphics/freeimage/buildlink3.mk"
.include 	"../../mk/x11.buildlink3.mk"

.include        "../../sysutils/desktop-file-utils/desktopdb.mk"
.include        "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
