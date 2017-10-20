$NetBSD$

--- toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js.orig	2016-10-31 20:15:37.000000000 +0000
+++ toolkit/mozapps/extensions/test/browser/browser_gmpProvider.js
@@ -390,6 +390,7 @@ add_task(function* testEmeSupport() {
     } else if (addon.id == GMPScope.WIDEVINE_ID) {
       if (AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
           AppConstants.platform == "macosx" ||
+          AppConstants.platform == "netbsd" ||
           AppConstants.platform == "linux") {
         Assert.ok(item, "Widevine supported, found add-on element.");
       } else {
