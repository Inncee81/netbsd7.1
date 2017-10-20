# $NetBSD$

DISTNAME=	wifimgr-1.11
CATEGORIES=	lzt
MASTER_SITES=	http://opal.com/freebsd/ports/net-mgmt/wifimgr/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://opal.com/freebsd/ports/net-mgmt/wifimgr/
COMMENT=	wifi manager for BSD
#LICENSE=	# TODO: (see mk/license.mk)

pre-install:
	mkdir -p \
		${DESTDIR}${LOCALBASE}/bin \
		${DESTDIR}${LOCALBASE}/libexec \
		${DESTDIR}${LOCALBASE}/man/man8 \
		${DESTDIR}${LOCALBASE}/share/locale/bg/LC_MESSAGES \
		${DESTDIR}${LOCALBASE}/share/locale/de/LC_MESSAGES \
		${DESTDIR}${LOCALBASE}/share/locale/fr/LC_MESSAGES \
		${DESTDIR}${LOCALBASE}/share/locale/ja/LC_MESSAGES \
		${DESTDIR}${LOCALBASE}/share/locale/nl/LC_MESSAGES \
		${DESTDIR}${LOCALBASE}/share/locale/ru/LC_MESSAGES \
		${DESTDIR}${LOCALBASE}/share/applications

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
