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
# XXX	BUILDLINK_DEPMETHOD.pulseaudio-tools?=	build

BUILDLINK_TREE+=	pulseaudio-tools

.if !defined(PULSEAUDIO_TOOLS_BUILDLINK3_MK)
PULSEAUDIO_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pulseaudio-tools+=	pulseaudio-tools>=1.0
BUILDLINK_PKGSRCDIR.pulseaudio-tools?=	../../meta-pkgs/pulseaudio-tools
.endif	# PULSEAUDIO_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pulseaudio-tools
