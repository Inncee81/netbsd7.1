$NetBSD$

--- browser/components/nsBrowserGlue.js.orig	2016-10-31 20:15:25.000000000 +0000
+++ browser/components/nsBrowserGlue.js
@@ -1054,7 +1054,9 @@ BrowserGlue.prototype = {
     }
     if (SCALING_PROBE_NAME) {
       let scaling = aWindow.devicePixelRatio * 100;
-      Services.telemetry.getHistogramById(SCALING_PROBE_NAME).add(scaling);
+      try {
+        Services.telemetry.getHistogramById(SCALING_PROBE_NAME).add(scaling);
+      } catch (ex) {}
     }
   },
 
