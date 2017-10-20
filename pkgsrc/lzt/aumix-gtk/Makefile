# $NetBSD: Makefile,v 1.29 2016/08/03 10:22:26 adam Exp $

.include "../../audio/aumix/Makefile.common"

PKGNAME=	${DISTNAME:S/aumix/aumix-gtk/}
PKGREVISION=	12

COMMENT+=	(curses and GTK+ 2.0 interfaces)

CONFLICTS=	aumix-[0-9]*

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/^--without-gtk$//}

ICONDIR=		share/icons/hicolor/128x128/apps
APPDIR=			share/applications
PLIST_SRC=		PLIST

INSTALLATION_DIRS+=	${APPDIR} ${ICONDIR}

post-install:
	cd ${DESTDIR}${LOCALBASE}/${ICONDIR};\
		uudecode < ${FILESDIR}/aumix.png.uu
	$(INSTALL_DATA) ${FILESDIR}/aumix.desktop \
		${DESTDIR}${LOCALBASE}/${APPDIR};\

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
