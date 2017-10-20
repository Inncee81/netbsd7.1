$NetBSD$

--- ipc/chromium/src/base/process_util_posix.cc.orig	2016-09-05 20:12:53.000000000 +0000
+++ ipc/chromium/src/base/process_util_posix.cc
@@ -122,7 +122,7 @@ void CloseSuperfluousFds(const base::Inj
 #if defined(ANDROID)
   static const rlim_t kSystemDefaultMaxFds = 1024;
   static const char kFDDir[] = "/proc/self/fd";
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   static const rlim_t kSystemDefaultMaxFds = 8192;
   static const char kFDDir[] = "/proc/self/fd";
 #elif defined(OS_MACOSX)
@@ -214,7 +214,7 @@ void CloseSuperfluousFds(const base::Inj
 // TODO(agl): Remove this function. It's fundamentally broken for multithreaded
 // apps.
 void SetAllFDsToCloseOnExec() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_SOLARIS)
   const char fd_dir[] = "/proc/self/fd";
 #elif defined(OS_MACOSX) || defined(OS_BSD)
   const char fd_dir[] = "/dev/fd";
