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
# XXX	BUILDLINK_DEPMETHOD.docbook-xsl?=	build

BUILDLINK_TREE+=	docbook-xsl

.if !defined(DOCBOOK_XSL_BUILDLINK3_MK)
DOCBOOK_XSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.docbook-xsl+=	docbook-xsl>=1.79.1nb2
BUILDLINK_PKGSRCDIR.docbook-xsl?=	../../textproc/docbook-xsl
.endif	# DOCBOOK_XSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-docbook-xsl
