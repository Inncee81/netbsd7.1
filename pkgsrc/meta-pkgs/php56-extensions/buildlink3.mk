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
# XXX	BUILDLINK_DEPMETHOD.php56-extensions?=	build

BUILDLINK_TREE+=	php56-extensions

.if !defined(PHP56_EXTENSIONS_BUILDLINK3_MK)
PHP56_EXTENSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php56-extensions+=	php56-extensions>=5.6.30nb1
BUILDLINK_PKGSRCDIR.php56-extensions?=	../../meta-pkgs/php56-extensions
.endif	# PHP56_EXTENSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-php56-extensions
