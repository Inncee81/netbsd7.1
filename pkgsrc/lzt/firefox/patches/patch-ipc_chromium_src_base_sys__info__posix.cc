$NetBSD$

--- ipc/chromium/src/base/sys_info_posix.cc.orig	2016-09-05 20:12:53.000000000 +0000
+++ ipc/chromium/src/base/sys_info_posix.cc
@@ -121,7 +121,11 @@ std::wstring SysInfo::GetEnvVar(const wc
 
 // static
 std::string SysInfo::OperatingSystemName() {
+#ifdef OS_SOLARIS
+  struct utsname info;
+#else
   utsname info;
+#endif
   if (uname(&info) < 0) {
     NOTREACHED();
     return "";
