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
# XXX	BUILDLINK_DEPMETHOD.mate-applets?=	build

BUILDLINK_TREE+=	mate-applets

.if !defined(MATE_APPLETS_BUILDLINK3_MK)
MATE_APPLETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-applets+=	mate-applets>=1.14.0nb2
BUILDLINK_PKGSRCDIR.mate-applets?=	../../x11/mate-applets

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/mate-panel/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-settings-daemon/buildlink3.mk"
.include "../../misc/libmateweather/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.endif	# MATE_APPLETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-applets
