$NetBSD$

--- src/effects/VST/VSTEffect.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/effects/VST/VSTEffect.cpp
@@ -2129,7 +2129,11 @@ bool VSTEffect::Load()
    // symbols.
    //
    // Once we define a proper external API, the flags can be removed.
+# if defined(RTLD_DEEPBIND)
    void *lib = dlopen((const char *)wxString(realPath).ToUTF8(), RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
+# else
+   void *lib = dlopen((const char *)wxString(realPath).ToUTF8(), RTLD_NOW | RTLD_LOCAL);
+# endif
    if (!lib) 
    {
       return false;
