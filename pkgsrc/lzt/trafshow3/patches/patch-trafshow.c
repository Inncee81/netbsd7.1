$NetBSD$

--- trafshow.c.orig	1998-08-28 07:15:57.000000000 +0000
+++ trafshow.c
@@ -33,6 +33,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <pcap.h>
+#include <ctype.h>
 
 #include "trafshow.h"
 
@@ -48,6 +49,7 @@ int Oflag = 1;		/* don't run filter code
 int pflag = 0;		/* don't put the interface into promiscuous mode */
 int kflag = 1;		/* disable keyboard input checking */
 int eflag = 0;		/* show ethernet traffic rather than ip */
+struct t_entry t_mask;	/* traffic mask */
 
 /* global variables */
 char *program_name;		/* myself */
@@ -78,6 +80,12 @@ main(argc, argv)
 	extern int abort_on_misalignment();
 	extern pcap_handler lookup_if();
 
+	t_mask.src.s_addr = 0xffffffff;	/* all bits valid */
+	t_mask.dst.s_addr = 0xffffffff;	/* all bits valid */
+	t_mask.sport = 0xffff;		/* all bits valid */
+	t_mask.dport = 0xffff;		/* all bits valid */
+	t_mask.proto = 0xffff;		/* all bits valid */
+
 	cnt = -1;
 	device_name = NULL;
 	infile = NULL;
@@ -87,7 +95,7 @@ main(argc, argv)
 
 	if (abort_on_misalignment(ebuf) < 0) error(0, ebuf);
 
-	while ((op = getopt(argc, argv, "c:CefF:i:knNOpr:t:vh?")) != EOF)
+	while ((op = getopt(argc, argv, "c:CefF:i:kmnNOpr:t:vh?")) != EOF)
 		switch (op) {
 		case 'C':
 #ifdef	HAVE_SLCURSES
@@ -115,6 +123,40 @@ main(argc, argv)
 		case 'k':
 			kflag = 0;
 			break;
+		case 'm':
+			t_mask.src.s_addr = 0;
+			t_mask.dst.s_addr = 0;
+			t_mask.sport = 0;
+			t_mask.dport = 0;
+			t_mask.proto = 0;
+			for (;optind + 1 <= argc;) {
+			    char *s = argv[optind];
+			    u_int32_t arg = 0xffffffff;
+			    int save=optind;
+			    
+			    optind++;
+			    if (optind + 1 <= argc &&
+				    isdigit(*(argv[optind])) ) {
+				arg = strtoul(argv[optind], NULL, 0);
+				optind++;
+			    }
+				
+			    if (!strcmp(s, "src-ip"))
+				t_mask.src.s_addr = htonl(arg);
+			    else if (!strcmp(s, "dst-ip"))
+				t_mask.dst.s_addr = htonl(arg);
+			    else if (!strcmp(s, "src-port"))
+				t_mask.sport = htons((u_short)(arg));
+			    else if (!strcmp(s, "dst-port"))
+				t_mask.dport = htons((u_short)(arg));
+			    else if (!strcmp(s, "proto"))
+				t_mask.proto = arg;
+			    else {
+				optind = save;
+				break;
+			    }
+			}
+			break;
 		case 'n':
 			++nflag;
 			break;
