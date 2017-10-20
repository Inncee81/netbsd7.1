$NetBSD$

--- media/libstagefright/system/core/liblog/fake_log_device.c.orig	2016-05-12 17:13:17.000000000 +0000
+++ media/libstagefright/system/core/liblog/fake_log_device.c
@@ -231,11 +231,11 @@ static void configureInitialState(const 
             char tagName[kMaxTagLen];
             int i, minPrio;
 
-            while (isspace(*tags))
+            while (isspace((unsigned char)*tags))
                 tags++;
 
             i = 0;
-            while (*tags != '\0' && !isspace(*tags) && *tags != ':' &&
+            while (*tags != '\0' && !isspace((unsigned char)*tags) && *tags != ':' &&
                 i < kMaxTagLen)
             {
                 tagName[i++] = *tags++;
@@ -274,7 +274,7 @@ static void configureInitialState(const 
                 }
 
                 tags++;
-                if (*tags != '\0' && !isspace(*tags)) {
+                if (*tags != '\0' && !isspace((unsigned char)*tags)) {
                     TRACE("ERROR: garbage in tag env; expected whitespace\n");
                     TRACE("       env='%s'\n", tags);
                     return;
