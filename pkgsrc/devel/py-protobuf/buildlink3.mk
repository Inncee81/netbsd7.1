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
# XXX	BUILDLINK_DEPMETHOD.py27-protobuf?=	build

BUILDLINK_TREE+=	py27-protobuf

.if !defined(PY27_PROTOBUF_BUILDLINK3_MK)
PY27_PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-protobuf+=	py27-protobuf>=3.2.0
BUILDLINK_PKGSRCDIR.py27-protobuf?=	../../devel/py-protobuf

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/protobuf/buildlink3.mk"
.endif	# PY27_PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-protobuf
