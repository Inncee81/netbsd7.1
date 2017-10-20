$NetBSD$

--- js/src/jsnativestack.cpp.orig	2016-05-12 17:13:19.000000000 +0000
+++ js/src/jsnativestack.cpp
@@ -102,7 +102,7 @@ js::GetNativeStackBaseImpl()
     pthread_attr_init(&sattr);
 #  if defined(__OpenBSD__)
     stack_t ss;
-#  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(NETBSD)
+#  elif defined(PTHREAD_NP_H) || defined(_PTHREAD_NP_H_) || defined(__DragonFly__) || defined(NETBSD) || defined(__NetBSD__) /* XXX tnn not sure why NETBSD isn't defined, it looks like it should be ... */
     /* e.g. on FreeBSD 4.8 or newer, neundorf@kde.org */
     pthread_attr_get_np(thread, &sattr);
 #  else
