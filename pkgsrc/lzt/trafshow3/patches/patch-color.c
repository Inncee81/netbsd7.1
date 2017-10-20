$NetBSD$

--- color.c.orig	1997-11-15 09:22:08.000000000 +0000
+++ color.c
@@ -336,7 +336,7 @@ init_colormask()
 		error(1, "init_color_mask: getpwuid");
 	(void) sprintf(buf, "%s/.%s", pw->pw_dir, program_name);
 	if ((fp = fopen(buf, "r")) == NULL) {
-		(void) strcpy(buf, "/etc/");
+		(void) strcpy(buf, "/usr/pkg/etc/");
 		(void) strcat(buf, program_name);
 		if ((fp = fopen(buf, "r")) == NULL) return 0;
 	}
