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
# XXX	BUILDLINK_DEPMETHOD.py27-pexpect?=	build

BUILDLINK_TREE+=	py27-pexpect

.if !defined(PY27_PEXPECT_BUILDLINK3_MK)
PY27_PEXPECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-pexpect+=	py27-pexpect>=4.2.1
BUILDLINK_PKGSRCDIR.py27-pexpect?=	../../lzt/py-pexpect

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../lzt/py-ptyprocess/buildlink3.mk"
.endif	# PY27_PEXPECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-pexpect
