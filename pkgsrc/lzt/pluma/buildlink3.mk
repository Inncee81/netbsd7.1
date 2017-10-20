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
# XXX	BUILDLINK_DEPMETHOD.pluma?=	build

BUILDLINK_TREE+=	pluma

.if !defined(PLUMA_BUILDLINK3_MK)
PLUMA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pluma+=	pluma>=1.14.0nb1
BUILDLINK_PKGSRCDIR.pluma?=	../../editors/pluma

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../sysutils/gvfs/buildlink3.mk"
.endif	# PLUMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-pluma
