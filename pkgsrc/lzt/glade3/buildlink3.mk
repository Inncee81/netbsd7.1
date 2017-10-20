# $NetBSD$

BUILDLINK_TREE+=	glade3

.if !defined(GLADE3_BUILDLINK3_MK)
GLADE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glade3+=	glade3>=3.8.5
BUILDLINK_PKGSRCDIR.glade3?=	../../lzt/glade3

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.endif	# GLADE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-glade3
