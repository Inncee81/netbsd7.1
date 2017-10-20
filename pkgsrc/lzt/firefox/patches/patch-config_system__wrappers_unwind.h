$NetBSD$

--- config/system_wrappers/unwind.h.orig	2017-01-16 13:12:35.000000000 +0000
+++ config/system_wrappers/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
