$NetBSD$

--- toolkit/mozapps/installer/packager.mk.orig	2016-06-01 04:11:43.000000000 +0000
+++ toolkit/mozapps/installer/packager.mk
@@ -134,7 +134,7 @@ endif
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
 	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
-ifdef INSTALL_SDK # Here comes the hard part
+ifeq ($(MOZ_APP_NAME),xulrunner)
 	$(NSINSTALL) -D $(DESTDIR)$(includedir)
 	(cd $(DIST)/include && $(TAR) $(TAR_CREATE_FLAGS) - .) | \
 	  (cd $(DESTDIR)$(includedir) && tar -xf -)
