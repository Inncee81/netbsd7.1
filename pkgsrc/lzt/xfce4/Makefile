# $NetBSD: Makefile,v 1.76 2016/08/03 10:23:07 adam Exp $

PKGREVISION= 5
.include "Makefile.common"

PKGNAME=	xfce4-${XFCE4_VERSION}
CATEGORIES=	meta-pkgs
COMMENT=	Xfce

DEPENDS+=	xfce4-tumbler>=0.1.27:../../x11/xfce4-tumbler
DEPENDS+=	xfce4-appfinder>=4.10.0:../../sysutils/xfce4-appfinder
DEPENDS+=	xfce4-desktop>=4.10.0:../../x11/xfce4-desktop
DEPENDS+=	xfce4-gtk2-engine>=3.0.1:../../x11/xfce4-gtk2-engine
DEPENDS+=	xfce4-mousepad>=0.3.0:../../editors/xfce4-mousepad
DEPENDS+=	xfce4-panel>=4.10.0:../../x11/xfce4-panel
DEPENDS+=	xfce4-orage>=4.8.4:../../time/xfce4-orage
DEPENDS+=	xfce4-settings>=4.10.0:../../x11/xfce4-settings
DEPENDS+=	xfce4-session>=4.10.0:../../x11/xfce4-session
DEPENDS+=	xfce4-terminal>=0.6.1:../../x11/xfce4-terminal
DEPENDS+=	xfce4-thunar>=1.6.0:../../sysutils/xfce4-thunar
DEPENDS+=	xfce4-wm>=4.10.0:../../wm/xfce4-wm
DEPENDS+=	xfce4-wm-themes>=4.10.0:../../wm/xfce4-wm-themes
DEPENDS+=	xfce4-xarchiver>=0.5.2:../../sysutils/xfce4-xarchiver
DEPENDS+=	elementary-xfce-icon-theme>=0.5:../../graphics/elementary-xfce-icon-theme
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils
DEPENDS+=	xfce4-extras:../../meta-pkgs/xfce4-extras
DEPENDS+=	xfce4-gvfs-mount-plugin:../../sysutils/xfce4-gvfs-mount-plugin

pre-extract:
	${MKDIR} ${WRKSRC}

do-configure:
	true

do-build:
	true

do-install:
	mkdir -p ${DESTDIR}${LOCALBASE}
	cd ${FILESDIR};find share | cpio -pdvmu ${DESTDIR}${LOCALBASE}

.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
