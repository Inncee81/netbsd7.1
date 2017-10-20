$NetBSD$

--- ipc/chromium/src/base/process_util_bsd.cc.orig	2016-09-05 20:12:53.000000000 +0000
+++ ipc/chromium/src/base/process_util_bsd.cc
@@ -12,6 +12,10 @@
 #include <spawn.h>
 #include <sys/wait.h>
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#endif
+
 #include <string>
 
 #include "nspr.h"
