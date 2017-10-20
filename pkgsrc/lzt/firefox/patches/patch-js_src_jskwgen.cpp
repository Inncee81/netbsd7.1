$NetBSD$

--- js/src/jskwgen.cpp.orig	2016-05-12 17:13:19.000000000 +0000
+++ js/src/jskwgen.cpp
@@ -181,7 +181,7 @@ qchar(char c, char* quoted_buffer)
         *s++ = '\\';
         break;
       default:
-        if (!isprint(c)) {
+        if (!isprint(((unsigned char)c))) {
             *s++ = '\\';
             *s++ = (char)('0' + (0x3 & (((unsigned char)c) >> 6)));
             *s++ = (char)('0' + (0x7 & (((unsigned char)c) >> 3)));
