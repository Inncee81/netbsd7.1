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
# XXX	BUILDLINK_DEPMETHOD.mate-notification-daemon?=	build

BUILDLINK_TREE+=	mate-notification-daemon

.if !defined(MATE_NOTIFICATION_DAEMON_BUILDLINK3_MK)
MATE_NOTIFICATION_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-notification-daemon+=	mate-notification-daemon>=1.14.0nb1
BUILDLINK_PKGSRCDIR.mate-notification-daemon?=	../../sysutils/mate-notification-daemon

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.endif	# MATE_NOTIFICATION_DAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-notification-daemon
