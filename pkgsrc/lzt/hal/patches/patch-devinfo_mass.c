diff -up hald/netbsd/devinfo_mass.c.orig hald/netbsd/devinfo_mass.c
--- hald/netbsd/devinfo_mass.c.orig	2017-09-19 10:09:22.830765000 -0300
+++ hald/netbsd/devinfo_mass.c	2017-09-19 10:09:58.351815000 -0300
@@ -41,6 +41,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <paths.h>
+#include <sys/stat.h>
 #include <unistd.h>
 
 #include "../osspec.h"
