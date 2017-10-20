$NetBSD$

--- notifyd/notifyd.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ notifyd/notifyd.c
@@ -98,7 +98,7 @@ char *fetch_arg(char *head, char* tail)
 
 #define NOTIFY_MAXSIZE 8192
 
-int do_notify()
+static int do_notify()
 {
     struct sockaddr_un sun_data;
     socklen_t sunlen = sizeof(sun_data);
