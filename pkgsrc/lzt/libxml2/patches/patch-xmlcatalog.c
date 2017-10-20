$NetBSD$

--- xmlcatalog.c.orig	2016-05-22 01:49:02.000000000 +0000
+++ xmlcatalog.c
@@ -43,7 +43,7 @@ static char *filename = NULL;
 
 
 #ifndef XML_SGML_DEFAULT_CATALOG
-#define XML_SGML_DEFAULT_CATALOG "/etc/sgml/catalog"
+#define XML_SGML_DEFAULT_CATALOG "@@SGML_DEFAULT_CATALOG@@"
 #endif
 
 /************************************************************************
