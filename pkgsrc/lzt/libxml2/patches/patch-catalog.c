$NetBSD$

--- catalog.c.orig	2016-05-23 07:25:25.000000000 +0000
+++ catalog.c
@@ -70,10 +70,10 @@
 #define XML_URN_PUBID "urn:publicid:"
 #define XML_CATAL_BREAK ((xmlChar *) -1)
 #ifndef XML_XML_DEFAULT_CATALOG
-#define XML_XML_DEFAULT_CATALOG "file:///etc/xml/catalog"
+#define XML_XML_DEFAULT_CATALOG "file://@@XML_DEFAULT_CATALOG@@"
 #endif
 #ifndef XML_SGML_DEFAULT_CATALOG
-#define XML_SGML_DEFAULT_CATALOG "file:///etc/sgml/catalog"
+#define XML_SGML_DEFAULT_CATALOG "file://@@SGML_DEFAULT_CATALOG@@"
 #endif
 
 #if defined(_WIN32) && defined(_MSC_VER)
