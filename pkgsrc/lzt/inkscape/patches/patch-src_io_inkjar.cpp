$NetBSD$

--- src/io/inkjar.cpp.orig	2014-11-30 18:45:32.000000000 +0000
+++ src/io/inkjar.cpp
@@ -42,6 +42,8 @@
 #include <fcntl.h>
 //#endif
 
+#include <unistd.h>
+
 #include <cstring>
 #include <string>
 #include <cstdlib>
