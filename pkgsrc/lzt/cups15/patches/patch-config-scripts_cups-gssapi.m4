$NetBSD$

--- config-scripts/cups-gssapi.m4.orig	2011-10-19 20:21:16.000000000 +0000
+++ config-scripts/cups-gssapi.m4
@@ -36,19 +36,18 @@ if test x$enable_gssapi != xno; then
 					AC_MSG_RESULT(no)
 				fi
 				;;
-			SunOS*)
-				# Solaris has a non-standard krb5-config, don't use it!
-				AC_CHECK_LIB(gss, gss_display_status,
-					AC_DEFINE(HAVE_GSSAPI, 1, [Whether GSSAPI is available])
+			*)
+				# make sure krb5-config supports gssapi option
+				if $KRB5CONFIG --cflags gssapi 2>&1 | grep "Unknown option" > /dev/null ; then
 					CFLAGS="`$KRB5CONFIG --cflags` $CFLAGS"
 					CPPFLAGS="`$KRB5CONFIG --cflags` $CPPFLAGS"
-					LIBGSSAPI="-lgss `$KRB5CONFIG --libs`")
-				;;
-			*)
+					LIBGSSAPI="-lgss `$KRB5CONFIG --libs`"
+				else
 				# Other platforms just ask for GSSAPI
-				CFLAGS="`$KRB5CONFIG --cflags gssapi` $CFLAGS"
-				CPPFLAGS="`$KRB5CONFIG --cflags gssapi` $CPPFLAGS"
-				LIBGSSAPI="`$KRB5CONFIG --libs gssapi`"
+					CFLAGS="`$KRB5CONFIG --cflags gssapi` $CFLAGS"
+					CPPFLAGS="`$KRB5CONFIG --cflags gssapi` $CPPFLAGS"
+					LIBGSSAPI="`$KRB5CONFIG --libs gssapi`"
+				fi
 				;;
 		esac
 		AC_DEFINE(HAVE_GSSAPI, 1, [Whether GSSAPI is available])
@@ -105,7 +104,7 @@ if test x$enable_gssapi != xno; then
 				fi
 			else
 				AC_MSG_RESULT(no)
-				if test $uversion -ge 110; then
+				if test $uversion -ge 999110; then
 					# Broken public headers in 10.7...
 					AC_MSG_ERROR(Run 'sudo mkdir -p $gssdir/PrivateHeaders' and 'sudo touch $gssdir/PrivateHeaders/gssapi_spi.h' to build CUPS.)
 				fi
