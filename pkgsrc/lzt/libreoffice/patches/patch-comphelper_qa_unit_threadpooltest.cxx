$NetBSD$

--- comphelper/qa/unit/threadpooltest.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ comphelper/qa/unit/threadpooltest.cxx
@@ -16,6 +16,12 @@
 #include <stdlib.h>
 #include <thread>
 
+static char * to_string_i(int i) {
+	static char area[64];
+	snprintf(area,sizeof(area),"%d",i);
+	return area;
+}
+
 class ThreadPoolTest : public CppUnit::TestFixture
 {
 public:
@@ -36,7 +42,7 @@ void ThreadPoolTest::testPreferredConcur
 #ifndef _WIN32_WINNT
     // The result should be cached, so this should change anything.
     nThreads = std::thread::hardware_concurrency() * 2;
-    setenv("MAX_CONCURRENCY", std::to_string(nThreads).c_str(), true);
+    setenv("MAX_CONCURRENCY", to_string_i(nThreads).c_str(), true);
     nThreads = comphelper::ThreadPool::getPreferredConcurrency();
     CPPUNIT_ASSERT_MESSAGE("Expected no more than hardware threads",
                            nThreads <= (sal_Int32)std::thread::hardware_concurrency());
