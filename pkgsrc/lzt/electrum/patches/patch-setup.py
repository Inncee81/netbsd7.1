$NetBSD$

--- setup.py.orig	2017-01-05 20:55:44.000000000 +0000
+++ setup.py
@@ -16,7 +16,7 @@ if sys.version_info[:3] < (2, 7, 0):
 
 data_files = []
 
-if platform.system() in ['Linux', 'FreeBSD', 'DragonFly']:
+if platform.system() in ['Linux', 'FreeBSD', 'DragonFly','NetBSD']:
     parser = argparse.ArgumentParser()
     parser.add_argument('--root=', dest='root_path', metavar='dir', default='/')
     opts, _ = parser.parse_known_args(sys.argv[1:])
