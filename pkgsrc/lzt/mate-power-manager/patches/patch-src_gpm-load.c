--- src/gpm-load.c.orig	2012-07-28 22:37:47.000000000 -0500
+++ src/gpm-load.c	2012-07-28 22:39:40.000000000 -0500
--- src/gpm-load.c.orig	2016-04-07 08:50:21.000000000 +0000
+++ src/gpm-load.c
@@ -33,6 +33,10 @@
 #include <kstat.h>
 #include <sys/sysinfo.h>
 #endif
+#if defined(__NetBSD__)
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif /* HAVE_UNISTD_H */
@@ -151,6 +155,34 @@ out:
 	return FALSE;
 }
 
+#elif defined(__NetBSD__)
+
+/**
+ * gpm_load_get_cpu_values:
+ * @cpu_idle: The idle time reported by the CPU
+ * @cpu_total: The total time reported by the CPU
+ * Return value: Success of reading of the kern.cp_time sysctl.
+ **/
+static gboolean gpm_load_get_cpu_values (long unsigned *cpu_idle, long unsigned *cpu_total) {
+	long *cpts;
+	size_t length=0;
+
+	if (sysctlbyname ("kern.cp_time", NULL, &length, NULL, 0))
+		return FALSE;
+	cpts=calloc(length,sizeof(*cpts));
+	if (sysctlbyname ("kern.cp_time", cpts, &length, NULL, 0)) {
+		free(cpts);
+		return FALSE;
+	}
+
+	*cpu_idle = (unsigned long) cpts[CP_IDLE * 2];
+	*cpu_total = (unsigned long) (cpts[CP_USER * 2] + cpts[CP_NICE * 2] + \
+			cpts[CP_SYS *2] + cpts[CP_IDLE * 2] + cpts[CP_INTR] * 2);
+
+	free(cpts);
+	return TRUE;
+}
+
 #else
 
 /**
