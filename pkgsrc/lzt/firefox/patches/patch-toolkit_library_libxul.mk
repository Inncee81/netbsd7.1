$NetBSD$

--- toolkit/library/libxul.mk.orig	2016-05-12 17:13:30.000000000 +0000
+++ toolkit/library/libxul.mk
@@ -55,7 +55,7 @@ endif
 ifdef _MSC_VER
 get_first_and_last = dumpbin -exports $1 | grep _NSModule@@ | sort -k 3 | sed -n 's/^.*?\([^@]*\)@@.*$$/\1/;1p;$$p'
 else
-get_first_and_last = $(TOOLCHAIN_PREFIX)nm -g $1 | grep _NSModule$$ | grep -vw refptr | sort | sed -n 's/^.* _*\([^ ]*\)$$/\1/;1p;$$p'
+get_first_and_last = $(TOOLCHAIN_PREFIX)nm $1 | grep _NSModule$$ | grep -vw refptr | sort | sed -n 's/^.* _*\([^ ]*\)$$/\1/;1p;$$p'
 endif
 
 LOCAL_CHECKS = test "$$($(get_first_and_last) | xargs echo)" != "start_kPStaticModules_NSModule end_kPStaticModules_NSModule" && echo "NSModules are not ordered appropriately" && exit 1 || exit 0
