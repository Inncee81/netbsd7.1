$NetBSD$

--- gnomevfs/vfsmodule.c.orig	2009-05-04 10:24:36.000000000 +0000
+++ gnomevfs/vfsmodule.c
@@ -1,6 +1,7 @@
 /* -*- mode: C; c-basic-offset: 4 -*- */
 #include <pygobject.h>
 #include "pygnomevfs-private.h"
+#include <bonobo-activation/bonobo-activation.h>
 #include <libgnomevfs/gnome-vfs-utils.h>
 #include <libgnomevfs/gnome-vfs-find-directory.h>
 #include <libgnomevfs/gnome-vfs-address.h>
