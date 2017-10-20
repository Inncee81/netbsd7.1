$NetBSD$

--- dom/plugins/ipc/PluginModuleChild.cpp.orig	2016-10-31 20:15:35.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.cpp
@@ -284,7 +284,7 @@ PluginModuleChild::InitForChrome(const s
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1846,7 +1846,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     AssertPluginThread();
     MOZ_ASSERT(mIsChrome);
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1891,7 +1891,7 @@ PluginModuleChild::DoNP_Initialize(const
 #endif
 
     NPError result;
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     result = mInitializeFunc(&sBrowserFuncs, &mFunctions);
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     result = mInitializeFunc(&sBrowserFuncs);
