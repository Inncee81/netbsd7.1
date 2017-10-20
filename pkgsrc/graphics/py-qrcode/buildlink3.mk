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
# XXX	BUILDLINK_DEPMETHOD.py27-qrcode?=	build

BUILDLINK_TREE+=	py27-qrcode

.if !defined(PY27_QRCODE_BUILDLINK3_MK)
PY27_QRCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-qrcode+=	py27-qrcode>=5.3
BUILDLINK_PKGSRCDIR.py27-qrcode?=	../../graphics/py-qrcode
.endif	# PY27_QRCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-qrcode
