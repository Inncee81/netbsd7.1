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
# XXX	BUILDLINK_DEPMETHOD.netbsd-extras?=	build

BUILDLINK_TREE+=	netbsd-extras

.if !defined(NETBSD_EXTRAS_BUILDLINK3_MK)
NETBSD_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netbsd-extras+=	netbsd-extras>=1.0nb1
BUILDLINK_PKGSRCDIR.netbsd-extras?=	../../lzt/netbsd-extras
.endif	# NETBSD_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-netbsd-extras
