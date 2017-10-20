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
# XXX	BUILDLINK_DEPMETHOD.py27-ptyprocess?=	build

BUILDLINK_TREE+=	py27-ptyprocess

.if !defined(PY27_PTYPROCESS_BUILDLINK3_MK)
PY27_PTYPROCESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-ptyprocess+=	py27-ptyprocess>=0.5.1
BUILDLINK_PKGSRCDIR.py27-ptyprocess?=	../../lzt/py-ptyprocess
.endif	# PY27_PTYPROCESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-ptyprocess
