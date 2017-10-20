$NetBSD$

--- nss/lib/freebl/blapi.h.orig	2016-11-29 01:03:38.000000000 +0000
+++ nss/lib/freebl/blapi.h
@@ -1212,6 +1212,8 @@ extern void SHA1_DestroyContext(SHA1Cont
 */
 extern void SHA1_Begin(SHA1Context *cx);
 
+#define SHA1_Update NSS_SHA1_Update
+
 /*
 ** Update the SHA-1 hash function with more data.
 **  "cx" the context
