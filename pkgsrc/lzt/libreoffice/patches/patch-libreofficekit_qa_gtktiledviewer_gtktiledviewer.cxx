$NetBSD$

--- libreofficekit/qa/gtktiledviewer/gtktiledviewer.cxx.orig	2017-01-11 04:44:46.000000000 +0000
+++ libreofficekit/qa/gtktiledviewer/gtktiledviewer.cxx
@@ -30,6 +30,12 @@
 #define g_info(...) g_log(G_LOG_DOMAIN, G_LOG_LEVEL_INFO, __VA_ARGS__)
 #endif
 
+static char * to_string_i(int i) {
+	static char area[64];
+	snprintf(area,sizeof(area),"%d",i);
+	return area;
+}
+
 static int help()
 {
     fprintf(stderr, "Usage: gtktiledviewer <absolute-path-to-libreoffice-install's-program-directory> <path-to-document> [<options> ... ]\n\n");
@@ -421,7 +427,7 @@ static void changeZoom( GtkWidget* pButt
             lok_doc_view_set_zoom( LOK_DOC_VIEW(pDocView), fZoom );
         }
     }
-    std::string aZoom = std::to_string(int(fZoom * 100)) + std::string("%");
+    std::string aZoom = to_string_i(int(fZoom * 100)) + std::string("%");
     gtk_label_set_text(GTK_LABEL(rWindow.m_pZoomLabel), aZoom.c_str());
 }
 
