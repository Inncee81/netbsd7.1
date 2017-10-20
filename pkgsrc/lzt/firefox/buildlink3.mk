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
# XXX	BUILDLINK_DEPMETHOD.firefox?=	build

BUILDLINK_TREE+=	firefox

.if !defined(FIREFOX_BUILDLINK3_MK)
FIREFOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firefox+=	firefox>=50.1.0
BUILDLINK_PKGSRCDIR.firefox?=	../../lzt/firefox
.endif	# FIREFOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-firefox
