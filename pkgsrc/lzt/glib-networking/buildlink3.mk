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
# XXX	BUILDLINK_DEPMETHOD.glib-networking?=	build

BUILDLINK_TREE+=	glib-networking

.if !defined(GLIB_NETWORKING_BUILDLINK3_MK)
GLIB_NETWORKING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glib-networking+=	glib-networking>=2.48.0nb1
BUILDLINK_PKGSRCDIR.glib-networking?=	../../net/glib-networking

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../www/libproxy/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/mozilla-rootcerts-openssl/buildlink3.mk"
.endif	# GLIB_NETWORKING_BUILDLINK3_MK

BUILDLINK_TREE+=	-glib-networking
