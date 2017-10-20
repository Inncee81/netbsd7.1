diff -up solenv/gbuild/Gallery.mk.orig solenv/gbuild/Gallery.mk
--- solenv/gbuild/Gallery.mk.orig	2017-07-18 01:21:03.000000000 -0300
+++ solenv/gbuild/Gallery.mk	2017-07-18 01:21:22.000000000 -0300
@@ -10,28 +10,29 @@
 # class Gallery
 
 # Handles creation of image galleries.
+# solenv/gbuild/Gallery.mk
 
 gb_Gallery_TRANSLATE := $(SRCDIR)/solenv/bin/desktop-translate.pl
 gb_Gallery_INSTDIR := $(LIBO_SHARE_FOLDER)/gallery
 
 define gb_Gallery__command
 $(call gb_Output_announce,$(2),$(true),GAL,1)
+#echo GALLERY COMMAND	rm -f $(call gb_Gallery_get_workdir,$(2))/* 
+#echo GALLERY BASEDIR	$(GALLERY_BASEDIR)
+#echo GALLERY NAME	$(GALLERY_NAME)
+#echo ICECREAM_RUN	$(ICECREAM_RUN)
+#echo GETWORKDIR		$(call gb_Gallery_get_workdir,$(2))
+#echo PWD		$(shell pwd)
+#echo GALLERY_FILES	$(GALLERY_FILES)
 $(call gb_Helper_abbreviate_dirs,\
 	rm -f $(call gb_Gallery_get_workdir,$(2))/* && \
 	RESPONSEFILE=$(call var2file,$(shell $(call gb_MKTEMP)),100,$(GALLERY_FILES)) && \
-	$(call gb_Helper_print_on_error,\
-		$(if $(filter-out MACOSX WNT,$(OS_FOR_BUILD)),$(if $(ENABLE_HEADLESS),, \
-			SAL_USE_VCLPLUGIN=svp \
-		)) \
-		$(call gb_Executable_get_command,gengal,$(ICECREAM_RUN)) \
+	/bin/sh gengal.sh \
 			--build-tree \
 			--destdir $(GALLERY_BASEDIR) \
 			--name "$(GALLERY_NAME)" \
 			--path $(call gb_Gallery_get_workdir,$(2)) \
-			--filenames $(call gb_Helper_make_url,$$RESPONSEFILE),\
-		$@.log \
-	) && \
-	rm $$RESPONSEFILE && \
+			--filenames $$RESPONSEFILE && \
 	touch $@ \
 )
 endef
