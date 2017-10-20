$NetBSD$

--- libgnomevfs/xdgmimeparent.h.orig	2010-02-09 12:16:14.000000000 +0000
+++ libgnomevfs/xdgmimeparent.h
@@ -46,6 +46,7 @@ XdgParentList *_xdg_mime_parent_list_new
 void           _xdg_mime_parent_list_free      (XdgParentList *list);
 const char   **_xdg_mime_parent_list_lookup    (XdgParentList *list,
 						const char    *mime);
+#define _xdg_mime_parent_list_dump _gnomevfs_xdg_mime_parent_list_dump
 void           _xdg_mime_parent_list_dump      (XdgParentList *list);
 
 #endif /* __XDG_MIME_PARENT_H__ */
