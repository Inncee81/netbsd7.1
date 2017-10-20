$NetBSD$

--- src/ui/clipboard.cpp.orig	2015-01-28 03:32:28.000000000 +0000
+++ src/ui/clipboard.cpp
@@ -1402,7 +1402,7 @@ void ClipboardManagerImpl::_inkscape_wai
 
         Glib::ustring target;
         if (atom_name) {
-            target = Glib::ScopedPtr<char>(atom_name).get(); //This frees the gchar*.
+            target = Glib::make_unique_ptr_gfree(atom_name).get(); //This frees the gchar*.
         }
 
         listTargets.push_back(target);
