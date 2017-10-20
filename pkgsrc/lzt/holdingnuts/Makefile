# $NetBSD$

DISTNAME=	holdingnuts-0.0.5
CATEGORIES=	lzt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=holdingnuts/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://holdingnuts.sourceforge.net/
COMMENT=	ONLINE POKER GAME server & client
#LICENSE=	# TODO: (see mk/license.mk)

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkgconfig
USE_LIBTOOL=	yes

post-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/64x64/apps \
		${DESTDIR}${PREFIX}/share/applications
	cp ${WRKSRC}/holdingnuts.desktop ${DESTDIR}${PREFIX}/share/applications
	cp ${WRKSRC}/holdingnuts.png ${DESTDIR}${PREFIX}/share/icons/hicolor/64x64/apps
	mv ${DESTDIR}${PREFIX}/bin/holding* ${DESTDIR}/${PREFIX}/share/holdingnuts
	install -m 755 ${FILESDIR}/bin/holding* ${DESTDIR}${PREFIX}/bin

.include 	"../../devel/SDL/buildlink3.mk"
.include 	"../../x11/qt4-tools/buildlink3.mk"
.include 	"../../x11/qt4-libs/buildlink3.mk"

.include        "../../sysutils/desktop-file-utils/desktopdb.mk"
.include        "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
