BUILDLINK_TREE+=	mozilla-rootcerts

.if !defined(MOZILLA_ROOTCERTS_BUILDLINK3_MK)
MOZILLA_ROOTCERTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mozilla-rootcerts+=	mozilla-rootcerts>=1.0.20160610
BUILDLINK_PKGSRCDIR.mozilla-rootcerts?=	../../security/mozilla-rootcerts
.endif	# MOZILLA_ROOTCERTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mozilla-rootcerts
