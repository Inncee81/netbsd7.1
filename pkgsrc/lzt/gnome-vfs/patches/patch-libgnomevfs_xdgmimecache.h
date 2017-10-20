$NetBSD$

--- libgnomevfs/xdgmimecache.h.orig	2010-02-09 12:16:14.000000000 +0000
+++ libgnomevfs/xdgmimecache.h
@@ -48,6 +48,7 @@ typedef struct _XdgMimeCache XdgMimeCach
 #define _xdg_mime_cache_glob_dump                     XDG_RESERVED_ENTRY(cache_glob_dump)
 #endif
 
+#define _caches _gnomevfs_caches
 extern XdgMimeCache **_caches;
 
 XdgMimeCache *_xdg_mime_cache_new_from_file (const char   *file_name);
