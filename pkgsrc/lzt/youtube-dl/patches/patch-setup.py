$NetBSD$

--- setup.py.orig	2017-03-16 01:22:58.000000000 +0000
+++ setup.py
@@ -62,7 +62,7 @@ else:
         ('etc/bash_completion.d', ['youtube-dl.bash-completion']),
         ('etc/fish/completions', ['youtube-dl.fish']),
         ('share/doc/youtube_dl', ['README.txt']),
-        ('share/man/man1', ['youtube-dl.1'])
+        ('man/man1', ['youtube-dl.1'])
     ]
     root = os.path.dirname(os.path.abspath(__file__))
     data_files = []
