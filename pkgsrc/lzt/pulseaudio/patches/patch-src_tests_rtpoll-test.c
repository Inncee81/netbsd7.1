$NetBSD$

--- src/tests/rtpoll-test.c.orig	2016-08-24 14:23:41.000000000 +0000
+++ src/tests/rtpoll-test.c
@@ -83,6 +83,7 @@ START_TEST (rtpoll_test) {
 END_TEST
 
 int main(int argc, char *argv[]) {
+#ifdef SIGRTMIN
     int failed = 0;
     Suite *s;
     TCase *tc;
@@ -103,4 +104,7 @@ int main(int argc, char *argv[]) {
     srunner_free(sr);
 
     return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
+#else
+    return 0
+#endif
 }
