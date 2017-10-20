$NetBSD$

--- daemon/slave.c.orig	2007-07-30 20:06:57.000000000 +0000
+++ daemon/slave.c
@@ -3249,13 +3249,13 @@ find_prog (const char *name)
 	char *path;
 	int i;
 	char *try[] = {
-		"/usr/bin/X11/",
-		"/usr/X11R6/bin/",
-		"/opt/X11R6/bin/",
+		"/sbin/",
+		"/bin/",
+		"/usr/sbin/",
 		"/usr/bin/",
-		"/usr/openwin/bin/",
-		"/usr/local/bin/",
-		"/opt/gnome/bin/",
+		"/usr/X11R7/bin/",
+		"/usr/pkg/sbin/",
+		"/usr/pkg/bin/",
 		BINDIR "/",
 		NULL
 	};
