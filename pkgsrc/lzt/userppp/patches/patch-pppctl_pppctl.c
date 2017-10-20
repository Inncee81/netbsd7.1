$NetBSD$

--- pppctl/pppctl.c.orig	2000-09-02 02:01:18.000000000 +0000
+++ pppctl/pppctl.c
@@ -389,6 +389,7 @@ main(int argc, char **argv)
                 History *hist;
                 const char *l, *env;
                 int size;
+                HistEvent hev = { 0, "" };
 
                 hist = history_init();
                 if ((env = getenv("EL_SIZE"))) {
@@ -398,7 +399,7 @@ main(int argc, char **argv)
                 } else
                     size = 20;
 #ifdef __NetBSD__
-                history(hist, NULL, H_SETSIZE, size);
+                history(hist, &hev, H_SETSIZE, size);
                 edit = el_init("pppctl", stdin, stdout, stderr);
 #else
                 history(hist, H_EVENT, size);
@@ -417,7 +418,7 @@ main(int argc, char **argv)
                 while ((l = smartgets(edit, &len, fd))) {
                     if (len > 1)
 #ifdef __NetBSD__
-                        history(hist, NULL, H_ENTER, l);
+                        history(hist, &hev, H_ENTER, l);
 #else
                         history(hist, H_ENTER, l);
 #endif
