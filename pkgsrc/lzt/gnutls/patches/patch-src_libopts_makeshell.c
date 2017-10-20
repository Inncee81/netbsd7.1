$NetBSD$

--- src/libopts/makeshell.c.orig	2015-11-25 18:23:34.000000000 +0000
+++ src/libopts/makeshell.c
@@ -73,7 +73,7 @@ static void
 open_out(char const * fname, char const * pname);
 /* = = = END-STATIC-FORWARD = = = */
 
-LOCAL noreturn void
+LOCAL void
 option_exits(int exit_code)
 {
     if (print_exit)
@@ -81,7 +81,7 @@ option_exits(int exit_code)
     exit(exit_code);
 }
 
-LOCAL noreturn void
+LOCAL void
 ao_bug(char const * msg)
 {
     fprintf(stderr, zao_bug_msg, msg);
@@ -95,7 +95,7 @@ fserr_warn(char const * prog, char const
             op, fname);
 }
 
-LOCAL noreturn void
+LOCAL void
 fserr_exit(char const * prog, char const * op, char const * fname)
 {
     fserr_warn(prog, op, fname);
