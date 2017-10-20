$NetBSD$

--- ipc/chromium/src/base/time_posix.cc.orig	2016-09-05 20:12:53.000000000 +0000
+++ ipc/chromium/src/base/time_posix.cc
@@ -67,8 +67,10 @@ Time Time::FromExploded(bool is_local, c
   timestruct.tm_wday   = exploded.day_of_week;  // mktime/timegm ignore this
   timestruct.tm_yday   = 0;     // mktime/timegm ignore this
   timestruct.tm_isdst  = -1;    // attempt to figure it out
+#ifndef OS_SOLARIS
   timestruct.tm_gmtoff = 0;     // not a POSIX field, so mktime/timegm ignore
   timestruct.tm_zone   = NULL;  // not a POSIX field, so mktime/timegm ignore
+#endif
 
   time_t seconds;
 #ifdef ANDROID
