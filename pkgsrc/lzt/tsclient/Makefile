# $NetBSD: Makefile,v 1.103 2017/02/12 06:25:53 ryoon Exp $
#

DISTNAME=		tsclient-0.150
PKGREVISION=		1
CATEGORIES=		lzt
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tsclient/}


MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnomepro.com/tsclient/
COMMENT=		GNOME2 Frontend for rdesktop

LICENSE=	gnu-gpl-v2


USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
AUTO_MKDIRS=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-gnome

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/tsclient.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tsclient.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/rdesktop/buildlink3.mk"
.include "../../net/tightvncviewer/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
