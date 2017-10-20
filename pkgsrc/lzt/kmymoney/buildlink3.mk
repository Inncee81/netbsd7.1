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
# XXX	BUILDLINK_DEPMETHOD.kmymoney?=	build

BUILDLINK_TREE+=	kmymoney

.if !defined(KMYMONEY_BUILDLINK3_MK)
KMYMONEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmymoney+=	kmymoney>=4.8.0
BUILDLINK_PKGSRCDIR.kmymoney?=	../../lzt/kmymoney

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../lzt/libalkimia/buildlink3.mk"
.include "../../lzt/sqlcipher/buildlink3.mk"
.include "../../lzt/aqbanking/buildlink3.mk"
.include "../../misc/kdepim4/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.endif	# KMYMONEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmymoney
