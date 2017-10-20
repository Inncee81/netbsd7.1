# $NetBSD$

PKGNAME=	gwenhywfar-4.5.3
DISTNAME=	gwenhywfar.4.5.3
CATEGORIES=	lzt
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=01&release=201&file=01&dummy=/

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	https://github.com/cstim/gwenhywfar/
COMMENT=	 multi-platform helper library for networking and secure application
#LICENSE=	# TODO: (see mk/license.mk)

MAKE_JOBS=	1

WRKSRC=		${WRKDIR}/gwenhywfar-4.15.3
USE_TOOLS+=	pkg-config gmake iconv gettext
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	gui/fox16/gwengui-fox16.pc.in
PKGCONFIG_OVERRIDE+=	gui/gtk2/gwengui-gtk2.pc.in
PKGCONFIG_OVERRIDE+=	gui/qt4/gwengui-qt4.pc.in
PKGCONFIG_OVERRIDE+=	gui/qt5/gwengui-qt5.pc.in
PKGCONFIG_OVERRIDE+=	gwenhywfar.pc.in

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
