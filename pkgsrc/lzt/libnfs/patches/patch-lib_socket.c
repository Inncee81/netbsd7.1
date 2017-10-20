$NetBSD$

--- lib/socket.c.orig	2017-06-16 19:48:10.000000000 +0000
+++ lib/socket.c
@@ -140,7 +140,7 @@ static int set_tcp_sockopt(int sockfd, i
 {
 	int level;
 
-	#if defined(__FreeBSD__) || defined(__sun) || (defined(__APPLE__) && defined(__MACH__))
+	#if defined(__FreeBSD__) || defined(__sun) || defined(__NetBSD__) || (defined(__APPLE__) && defined(__MACH__))
 	struct protoent *buf;
 
 	if ((buf = getprotobyname("tcp")) != NULL)
