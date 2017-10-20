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
# XXX	BUILDLINK_DEPMETHOD.v8?=	build

BUILDLINK_TREE+=	v8

.if !defined(V8_BUILDLINK3_MK)
V8_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.v8+=	v8>=3.29.9.1
BUILDLINK_PKGSRCDIR.v8?=	../../lang/v8

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# V8_BUILDLINK3_MK

BUILDLINK_TREE+=	-v8
