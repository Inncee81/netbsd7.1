# $NetBSD: Makefile,v 1.26.2.1 2016/11/29 17:49:51 bsiegert Exp $

DISTNAME=	wpa_supplicant-2.6
PKGNAME=	${DISTNAME:S/supplicant/gui/}
CATEGORIES=	net
MASTER_SITES=	http://hostap.epitest.fi/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hostap.epitest.fi/wpa_supplicant/
COMMENT=	QT GUI for wpa_supplicant(8)
LICENSE=	gnu-gpl-v2


USE_LANGUAGES=	c c++
BUILD_DIRS=	wpa_supplicant
BUILD_TARGET=	wpa_gui-qt4
USE_TOOLS+=	gmake

LRELEASE=	${QTDIR}/bin/lrelease
MAKE_ENV+=	LRELEASE=${LRELEASE}

ICONDIR=	share/icons/hicolor/64x64/apps
APPDIR=		share/applications

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 ${ICONDIR} ${APPDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wpa_supplicant/wpa_gui-qt4/wpa_gui \
		${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/wpa_supplicant/doc/docbook/wpa_gui.8 \
                ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	$(INSTALL_DATA) ${FILESDIR}/wpa_gui.png ${DESTDIR}${PREFIX}/${ICONDIR}
	$(INSTALL_DATA) ${FILESDIR}/wpa_gui.desktop ${DESTDIR}${PREFIX}/${APPDIR}

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
