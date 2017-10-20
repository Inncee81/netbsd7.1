$NetBSD$

--- libretroshare/src/util/rsthreads.cc.orig	2016-08-31 11:24:02.000000000 +0000
+++ libretroshare/src/util/rsthreads.cc
@@ -1,2 +1 @@
-
 /*
@@ -32,4 +31,2 @@
 
-int __attribute__((weak)) pthread_setname_np(pthread_t __target_thread, const char *__buf) ;
-
 #ifdef RSMUTEX_DEBUG
@@ -177,5 +174,5 @@ void RsThread::start(const std::string &
 #endif
-				pthread_setname_np(mTid, threadName.substr(0, 15).c_str());
+				pthread_setname_np(mTid, threadName.substr(0, 15).c_str(),(void *)"");
 			} else {
-				pthread_setname_np(mTid, threadName.c_str());
+				pthread_setname_np(mTid, threadName.c_str(),(void *)"");
 			}
