$NetBSD$

--- lib-src/lv2/sratom/waflib/extras/autowaf.py.orig	2017-07-19 01:17:26.000000000 +0000
+++ lib-src/lv2/sratom/waflib/extras/autowaf.py
@@ -327,7 +327,7 @@ def make_simple_dox(name):
 		if not os.path.exists(page):
 			return
 		for i in[['%s_API '%NAME,''],['%s_DEPRECATED '%NAME,''],['group__%s.html'%name,''],['&#160;',''],['<script.*><\/script>',''],['<hr\/><a name="details" id="details"><\/a><h2>.*<\/h2>',''],['<link href=\"tabs.css\" rel=\"stylesheet\" type=\"text\/css\"\/>',''],['<img class=\"footer\" src=\"doxygen.png\" alt=\"doxygen\"\/>','Doxygen']]:
-			os.system("sed -i 's/%s/%s/g' %s"%(i[0],i[1],page))
+			os.system("gsed -i 's/%s/%s/g' %s"%(i[0],i[1],page))
 		os.rename('group__%s.html'%name,'index.html')
 		for i in(glob.glob('*.png')+glob.glob('*.html')+glob.glob('*.js')+glob.glob('*.css')):
 			if i!='index.html'and i!='style.css':
@@ -335,7 +335,7 @@ def make_simple_dox(name):
 		os.chdir(top)
 		os.chdir(build_dir(name,'doc/man/man3'))
 		for i in glob.glob('*.3'):
-			os.system("sed -i 's/%s_API //' %s"%(NAME,i))
+			os.system("gsed -i 's/%s_API //' %s"%(NAME,i))
 		for i in glob.glob('_*'):
 			os.remove(i)
 		os.chdir(top)
