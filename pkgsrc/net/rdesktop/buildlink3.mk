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
# XXX	BUILDLINK_DEPMETHOD.rdesktop?=	build

BUILDLINK_TREE+=	rdesktop

.if !defined(RDESKTOP_BUILDLINK3_MK)
RDESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rdesktop+=	rdesktop>=1.8.3nb1
BUILDLINK_PKGSRCDIR.rdesktop?=	../../net/rdesktop

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif	# RDESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-rdesktop
