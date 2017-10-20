$NetBSD$

--- libhack/alias_db.c.orig	2000-10-30 17:24:12.000000000 +0000
+++ libhack/alias_db.c
@@ -141,6 +141,13 @@
 #include "alias_local.h"
 
 
+#ifndef LIST_FOREACH
+#define LIST_FOREACH(var, head, field)					\
+	for ((var) = ((head)->lh_first);				\
+		(var);							\
+		(var) = ((var)->field.le_next))
+
+#endif
 
 /*
    Constants (note: constants are also defined
