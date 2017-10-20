$NetBSD$

--- python/mozbuild/mozbuild/configure/options.py.orig	2016-09-05 20:12:51.000000000 +0000
+++ python/mozbuild/mozbuild/configure/options.py
@@ -144,9 +144,6 @@ class Option(object):
             if not isinstance(env, types.StringTypes):
                 raise InvalidOptionError(
                     'Environment variable name must be a string')
-            if not env.isupper():
-                raise InvalidOptionError(
-                    'Environment variable name must be all uppercase')
         if nargs not in (None, '?', '*', '+') and not (
                 isinstance(nargs, int) and nargs >= 0):
             raise InvalidOptionError(
@@ -257,9 +254,6 @@ class Option(object):
             if name.startswith('-'):
                 raise InvalidOptionError(
                     'Option must start with two dashes instead of one')
-            if name.islower():
-                raise InvalidOptionError(
-                    'Environment variable name must be all uppercase')
         return '', name, values
 
     @staticmethod
