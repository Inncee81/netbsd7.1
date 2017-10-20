$NetBSD$

--- toolkit/modules/GMPUtils.jsm.orig	2016-10-31 20:15:37.000000000 +0000
+++ toolkit/modules/GMPUtils.jsm
@@ -82,6 +82,7 @@ this.GMPUtils = {
       // Mac OSX, and Linux.
       return AppConstants.isPlatformAndVersionAtLeast("win", "6") ||
              AppConstants.platform == "macosx" ||
+             AppConstants.platform == "netbsd" ||
              AppConstants.platform == "linux";
     }
 
