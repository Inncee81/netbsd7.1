DISTNAME=	glade3-3.8.5
CATEGORIES=	lzt
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/glade3/3.8/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://ftp.gnome.org/pub/GNOME/sources/glade3/3.8/
COMMENT=	GLADE 3 LAST stable version

#MORECPPFLAGS!=	pkg-config --cflags python-2.7 pygobject-2.0
#MORELDFLAGS!=	pkg-config --libs python-2.7 pygobject-2.0

LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -lpython2.7
CPPFLAGS+=	-I${LOCALBASE}/include/python2.7

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config autoconf autoreconf gmake intltool msgfmt
CONFIGURE_ARGS+=	--enable-compile-warnings=no

pre-configure:
	cd ${WRKSRC};autoreconf

PKGCONFIG_OVERRIDE+=	data/gladeui-2.0.pc.in

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/rarian/buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
