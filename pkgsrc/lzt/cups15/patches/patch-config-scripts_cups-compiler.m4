$NetBSD$

--- config-scripts/cups-compiler.m4.orig	2011-09-09 17:28:58.000000000 +0000
+++ config-scripts/cups-compiler.m4
@@ -125,8 +125,9 @@ if test -n "$GCC"; then
 	AC_MSG_CHECKING(if GCC supports -fstack-protector)
 	OLDCFLAGS="$CFLAGS"
 	CFLAGS="$CFLAGS -fstack-protector"
-	AC_TRY_LINK(,,
+	AC_TRY_LINK(, [return 0;],
 		OPTIM="$OPTIM -fstack-protector"
+		LIBS="$LIBS $LIBS_SSP"
 		AC_MSG_RESULT(yes),
 		AC_MSG_RESULT(no))
 	CFLAGS="$OLDCFLAGS"
