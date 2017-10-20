$NetBSD$

--- ipc/chromium/src/base/atomicops.h.orig	2016-09-05 20:12:53.000000000 +0000
+++ ipc/chromium/src/base/atomicops.h
@@ -47,7 +47,7 @@ typedef int64_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
-#ifdef OS_OPENBSD
+#if defined(OS_OPENBSD) || (defined(OS_NETBSD) && defined(ARCH_CPU_ARM_FAMILY))
 #ifdef ARCH_CPU_64_BITS
 typedef Atomic64 AtomicWord;
 #else
