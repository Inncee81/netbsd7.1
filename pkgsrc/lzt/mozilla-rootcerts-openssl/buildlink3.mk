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
# XXX	BUILDLINK_DEPMETHOD.mozilla-rootcerts-openssl?=	build

BUILDLINK_TREE+=	mozilla-rootcerts-openssl

.if !defined(MOZILLA_ROOTCERTS_OPENSSL_BUILDLINK3_MK)
MOZILLA_ROOTCERTS_OPENSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mozilla-rootcerts-openssl+=	mozilla-rootcerts-openssl>=2
BUILDLINK_PKGSRCDIR.mozilla-rootcerts-openssl?=	../../security/mozilla-rootcerts-openssl
.endif	# MOZILLA_ROOTCERTS_OPENSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-mozilla-rootcerts-openssl
