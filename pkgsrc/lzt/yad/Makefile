# $NetBSD$

DISTNAME=	yad-0.38.0
CATEGORIES=	lzt
MASTER_SITES=	https://sourceforge.net/projects/yad-dialog/files/latest/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	https://sourceforge.net/projects/yad-dialog/files/latest/
COMMENT=	another script display 
#LICENSE=	# TODO: (see mk/license.mk)


USE_TOOLS=	gmake intltool msgfmt perl pkg-config auroreconf autoconf automake

WRKSRC=		${WRKDIR}/yad-0.38.0
GNU_CONFIGURE=	yes

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
