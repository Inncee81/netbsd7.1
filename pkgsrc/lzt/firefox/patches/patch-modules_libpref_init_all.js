$NetBSD$

--- modules/libpref/init/all.js.orig	2016-10-31 20:15:26.000000000 +0000
+++ modules/libpref/init/all.js
@@ -4621,7 +4621,7 @@ pref("device.sensors.enabled", true);
 pref("device.storage.enabled", false);
 
 // Toggle which thread the HTML5 parser uses for stream parsing
-pref("html5.offmainthread", true);
+pref("html5.offmainthread", false);
 // Time in milliseconds between the time a network buffer is seen and the
 // timer firing when the timer hasn't fired previously in this parse in the
 // off-the-main-thread HTML5 parser.
