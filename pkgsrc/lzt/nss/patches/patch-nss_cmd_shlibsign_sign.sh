$NetBSD$

--- nss/cmd/shlibsign/sign.sh.orig	2016-11-29 01:03:38.000000000 +0000
+++ nss/cmd/shlibsign/sign.sh
@@ -37,7 +37,7 @@ WIN*)
     export LIBPATH
     SHLIB_PATH=${1}/lib:${4}:$SHLIB_PATH
     export SHLIB_PATH
-    LD_LIBRARY_PATH=${1}/lib:${4}:$LD_LIBRARY_PATH
+    LD_LIBRARY_PATH=${1}/lib:${4}:${PREFIX}/lib:$LD_LIBRARY_PATH
     export LD_LIBRARY_PATH
     DYLD_LIBRARY_PATH=${1}/lib:${4}:$DYLD_LIBRARY_PATH
     export DYLD_LIBRARY_PATH
