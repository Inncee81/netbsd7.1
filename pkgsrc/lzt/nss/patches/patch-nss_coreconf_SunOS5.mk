$NetBSD$

--- nss/coreconf/SunOS5.mk.orig	2016-11-29 01:03:38.000000000 +0000
+++ nss/coreconf/SunOS5.mk
@@ -119,6 +119,10 @@ endif
 endif
 DSO_LDOPTS += -z combreloc -z defs -z ignore
 
+ifdef LIBRUNPATH
+DSO_LDOPTS += -R$(LIBRUNPATH)
+endif
+
 # -KPIC generates position independent code for use in shared libraries.
 # (Similarly for -fPIC in case of gcc.)
 ifdef NS_USE_GCC
