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
# XXX	BUILDLINK_DEPMETHOD.aqbanking?=	build

BUILDLINK_TREE+=	aqbanking

.if !defined(AQBANKING_BUILDLINK3_MK)
AQBANKING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aqbanking+=	aqbanking>=5.6.12
BUILDLINK_PKGSRCDIR.aqbanking?=	../../lzt/aqbanking

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../lzt/gwenhywfar/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.endif	# AQBANKING_BUILDLINK3_MK

BUILDLINK_TREE+=	-aqbanking
