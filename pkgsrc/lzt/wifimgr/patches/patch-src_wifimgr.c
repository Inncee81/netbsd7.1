$NetBSD$

--- src/wifimgr.c.orig	2014-05-10 20:53:59.000000000 +0000
+++ src/wifimgr.c
@@ -436,7 +436,7 @@ read_networks_file(char * file) {
 		char		save_file[256];
 
 		sprintf(save_file, "%s.save", file);
-		if (eaccess(save_file, F_OK) == 0) {
+		if (access(save_file, F_OK) == 0) {
 			fprintf(sucmd, "diff_netfile\n");
 			fgets(resp, sizeof(resp), sucmd);
 			chop(resp);
@@ -779,8 +779,8 @@ restart_intf() {
 	}
 
 	/* loop up to 10 seconds for interface to re-associate */
-	while (!ifconfig_associated_network(wifi_if) && count++ < 20)
-		usleep(500000);
+	while (!ifconfig_associated_network(wifi_if) && count++ < 3)
+		sleep(1);
 
 	return 1;
 }
@@ -1052,10 +1052,7 @@ wifimgrsu_init()
 	char *			pass;
 	char			resp[256];
 
-	if (gui_message(gettext("Enter Administrator password:"), MSG_INPUT) != MSG_RESPONSE_OK)
-		exit(1);
-
-	pass = gui_response;
+	pass = "XXX";
 
 	if ((sucmd = popen(PATH_WIFIMGRSU, "r+")) == NULL) {
 		char		buf[256];
