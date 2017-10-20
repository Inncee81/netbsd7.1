$NetBSD$

--- ppp/atm.c.orig	2000-11-07 05:45:45.000000000 +0000
+++ ppp/atm.c
@@ -80,7 +80,7 @@ atm_Sendto(struct physical *p, const voi
 {
   ssize_t ret = write(p->fd, v, n);
   if (ret < 0) {
-    log_Printf(LogDEBUG, "atm_Sendto(%d): %s\n", n, strerror(errno));
+    log_Printf(LogDEBUG, "atm_Sendto(%ld): %s\n", (long)n, strerror(errno));
     return ret;
   }
   return ret;
@@ -91,7 +91,7 @@ atm_Recvfrom(struct physical *p, void *v
 {
     ssize_t ret = read(p->fd, (char*)v, n);
     if (ret < 0) {
-      log_Printf(LogDEBUG, "atm_Recvfrom(%d): %s\n", n, strerror(errno));
+      log_Printf(LogDEBUG, "atm_Recvfrom(%ld): %s\n", (long)n, strerror(errno));
       return ret;
     }
     return ret;
