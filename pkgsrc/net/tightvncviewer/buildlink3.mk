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
# XXX	BUILDLINK_DEPMETHOD.tightvncviewer?=	build

BUILDLINK_TREE+=	tightvncviewer

.if !defined(TIGHTVNCVIEWER_BUILDLINK3_MK)
TIGHTVNCVIEWER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tightvncviewer+=	tightvncviewer>=1.3.10nb2
BUILDLINK_PKGSRCDIR.tightvncviewer?=	../../net/tightvncviewer

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif	# TIGHTVNCVIEWER_BUILDLINK3_MK

BUILDLINK_TREE+=	-tightvncviewer
