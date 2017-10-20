$NetBSD$

--- ucb/source/ucp/ftp/ftploaderthread.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ ucb/source/ucp/ftp/ftploaderthread.cxx
@@ -79,7 +79,7 @@ FTPLoaderThread::~FTPLoaderThread() {
 
 
 CURL* FTPLoaderThread::handle() {
-    CURL* ret = osl_getThreadKeyData(m_threadKey);
+    CURL* ret = static_cast<CURL*>(osl_getThreadKeyData(m_threadKey));
     if(!ret) {
         ret = curl_easy_init();
         if (ret != nullptr) {
