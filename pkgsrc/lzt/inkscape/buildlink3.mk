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
# XXX	BUILDLINK_DEPMETHOD.inkscape?=	build

BUILDLINK_TREE+=	inkscape

.if !defined(INKSCAPE_BUILDLINK3_MK)
INKSCAPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.inkscape+=	inkscape>=0.91nb18
BUILDLINK_PKGSRCDIR.inkscape?=	../../graphics/inkscape

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../converters/libcdr/buildlink3.mk"
.include "../../converters/libvisio/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif	# INKSCAPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-inkscape
