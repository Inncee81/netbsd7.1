$NetBSD$

--- media/libstagefright/system/core/liblog/logprint.c.orig	2016-07-25 20:22:04.000000000 +0000
+++ media/libstagefright/system/core/liblog/logprint.c
@@ -103,7 +103,7 @@ static android_LogPriority filterCharToP
 {
     android_LogPriority pri;
 
-    c = tolower(c);
+    c = tolower((unsigned char)c);
 
     if (c >= '0' && c <= '9') {
         if (c >= ('0'+ANDROID_LOG_SILENT)) {
@@ -371,7 +371,7 @@ static inline char * strip_end(char *str
 {
     char *end = str + strlen(str) - 1;
 
-    while (end >= str && isspace(*end))
+    while (end >= str && isspace((unsigned char)*end))
         *end-- = '\0';
     return str;
 }
