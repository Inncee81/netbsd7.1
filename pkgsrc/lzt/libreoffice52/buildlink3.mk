# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libreoffice?=	build

BUILDLINK_TREE+=	libreoffice

.if !defined(LIBREOFFICE_BUILDLINK3_MK)
LIBREOFFICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libreoffice+=	libreoffice>=5.2.4.2
BUILDLINK_PKGSRCDIR.libreoffice?=	../../lzt/libreoffice52

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libabw/buildlink3.mk"
.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/libe-book/buildlink3.mk"
.include "../../converters/libetonyek/buildlink3.mk"
.include "../../converters/libfreehand/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../converters/libmspub/buildlink3.mk"
.include "../../converters/libpagemaker/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libwps/buildlink3.mk"
.include "../../converters/libmwaw/buildlink3.mk"
.include "../../lzt/orcus/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../databases/postgresql94-client/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/liblangtag/buildlink3.mk"
.include "../../devel/mdds1.2/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/lp_solve/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/libcmis/buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/hyphen/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../textproc/libodfgen/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../textproc/libexttextcat/buildlink3.mk"
.include "../../textproc/mythes/buildlink3.mk"
.include "../../textproc/raptor2/buildlink3.mk"
.include "../../textproc/rasqal/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../www/serf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.endif	# LIBREOFFICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libreoffice
