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
# XXX	BUILDLINK_DEPMETHOD.py27-aes?=	build

BUILDLINK_TREE+=	py27-aes

.if !defined(PY27_AES_BUILDLINK3_MK)
PY27_AES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-aes+=	py27-aes>=1.6.0
BUILDLINK_PKGSRCDIR.py27-aes?=	../../security/py-aes
.endif	# PY27_AES_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-aes
