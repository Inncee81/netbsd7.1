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
# XXX	BUILDLINK_DEPMETHOD.modular-xorg-fonts?=	build

BUILDLINK_TREE+=	modular-xorg-fonts

.if !defined(MODULAR_XORG_FONTS_BUILDLINK3_MK)
MODULAR_XORG_FONTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.modular-xorg-fonts+=	modular-xorg-fonts>=1.1
BUILDLINK_PKGSRCDIR.modular-xorg-fonts?=	../../meta-pkgs/modular-xorg-fonts
.endif	# MODULAR_XORG_FONTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-modular-xorg-fonts
