$NetBSD$

--- libgnomevfs/xdgmimealias.h.orig	2010-02-09 12:16:14.000000000 +0000
+++ libgnomevfs/xdgmimealias.h
@@ -46,6 +46,7 @@ XdgAliasList *_xdg_mime_alias_list_new  
 void          _xdg_mime_alias_list_free      (XdgAliasList *list);
 const char   *_xdg_mime_alias_list_lookup    (XdgAliasList *list,
 					      const char  *alias);
+#define _xdg_mime_alias_list_dump _gnomevfs_xdg_mime_alias_list_dump
 void          _xdg_mime_alias_list_dump      (XdgAliasList *list);
 
 #endif /* __XDG_MIME_ALIAS_H__ */
