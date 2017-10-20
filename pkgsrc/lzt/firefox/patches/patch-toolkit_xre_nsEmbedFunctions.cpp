$NetBSD$

--- toolkit/xre/nsEmbedFunctions.cpp.orig	2016-10-31 20:15:38.000000000 +0000
+++ toolkit/xre/nsEmbedFunctions.cpp
@@ -263,7 +263,7 @@ XRE_SetRemoteExceptionHandler(const char
 {
 #if defined(XP_WIN) || defined(XP_MACOSX)
   return CrashReporter::SetRemoteExceptionHandler(nsDependentCString(aPipe));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   return CrashReporter::SetRemoteExceptionHandler();
 #else
 #  error "OOP crash reporter unsupported on this platform"
@@ -481,7 +481,7 @@ XRE_InitChildProcess(int aArgc,
     // Bug 684322 will add better visibility into this condition
     NS_WARNING("Could not setup crash reporting\n");
   }
-#  elif defined(OS_LINUX)
+#  elif defined(OS_LINUX) || defined(OS_SOLARIS)
   // on POSIX, |crashReporterArg| is "true" if crash reporting is
   // enabled, false otherwise
   if (0 != strcmp("false", crashReporterArg) && 
