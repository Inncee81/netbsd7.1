--- dxf_thumbnailer.c.orig	2016-07-11 19:05:09 UTC
+++ dxf_thumbnailer.c
@@ -0,0 +1,43 @@
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <glib.h>
+
+int             main (int argc, char **argv)
+{
+    gchar          *ipath = NULL, *opath = NULL, *p = NULL;
+    int             ch, thumbsize = 128;
+
+    opterr = 0;
+    while ((ch = getopt (argc, argv, "i:o:s:")) != -1) {
+        switch (ch) {
+        case 'i':
+            ipath = g_strdup (optarg);
+            break;
+        case 'o':
+            opath = g_strdup (optarg);
+            break;
+        case 's':
+            thumbsize = atoi (optarg);
+            break;
+        case '?':
+            printf ("error ch[%c]\n", ch);
+            abort ();
+            break;
+        default:
+	    return 1;
+        }
+    }
+    if (!ipath)
+	return 2;
+
+    if (!opath)
+	return 3;
+
+    system ((p = g_strdup_printf ("/usr/pkg/bin/dia -t png \"%s\" -e \"%s\" -s \"%d\" > /dev/null 2>&1",
+                                  ipath, opath, thumbsize)));
+    g_free (p);
+    g_free (ipath);
+    g_free (opath);
+    return 0;
+}
