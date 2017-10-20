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
# XXX	BUILDLINK_DEPMETHOD.py27-ecdsa?=	build

BUILDLINK_TREE+=	py27-ecdsa

.if !defined(PY27_ECDSA_BUILDLINK3_MK)
PY27_ECDSA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-ecdsa+=	py27-ecdsa>=0.13
BUILDLINK_PKGSRCDIR.py27-ecdsa?=	../../security/py-ecdsa
.endif	# PY27_ECDSA_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-ecdsa
