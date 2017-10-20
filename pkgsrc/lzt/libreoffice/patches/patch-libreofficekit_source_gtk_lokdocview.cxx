$NetBSD$

--- libreofficekit/source/gtk/lokdocview.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ libreofficekit/source/gtk/lokdocview.cxx
@@ -243,6 +243,12 @@ G_DEFINE_TYPE_WITH_CODE (LOKDocView, lok
 #pragma GCC diagnostic pop
 #endif
 
+static char * to_string_i(int i) {
+	static char area[64];
+	snprintf(area,sizeof(area),"%d",i);
+	return area;
+}
+
 static LOKDocViewPrivate& getPrivate(LOKDocView* pDocView)
 {
     LOKDocViewPrivate* priv = static_cast<LOKDocViewPrivate*>(lok_doc_view_get_instance_private(pDocView));
@@ -1061,7 +1067,7 @@ callback (gpointer pData)
         std::stringstream aStream(pCallback->m_aPayload);
         boost::property_tree::read_json(aStream, aTree);
         int nCount = aTree.get_child("searchResultSelection").size();
-        searchResultCount(pDocView, std::to_string(nCount));
+        searchResultCount(pDocView, to_string_i(nCount));
     }
     break;
     case LOK_CALLBACK_UNO_COMMAND_RESULT:
