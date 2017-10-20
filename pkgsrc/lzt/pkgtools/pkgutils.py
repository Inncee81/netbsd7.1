#!/usr/bin/env python2.7

import os,sys,sqlite3

class progs:
	def __init__(self,DB="/var/db/pkgmaster.sqlite3"):
		self.conn=sqlite3.connect(DB)
		self.cursor=self.conn.cursor()
		self.cursor.execute("PRAGMA foreign_keys = ON");
		self.conn.commit()


	def pkg_installed(self,pkgname):
		if not os.system("pkg_info -qe %s" %(pname)):
			return True
		return False

	def pkgpath2pkgname(self,path):
		if not "/" in path:
			return path
		pkgpath="/usr/pkgsrc/%s" % (path)
		if not os.path.isdir(pkgpath):
			print "no directory for:",pkgpath
			return None
		ifile=os.popen("cd %s;make show-var VARNAME=PKGNAME" % (pkgpath),"r")
		pkgname=ifile.readline()
		ifile.close
		return pkgname.strip()

	def getdepends(self,pkgpath):
		v=[]
		ifile=os.popen("cd /usr/pkgsrc/%s;make show-depends-dirs" % (pkgpath),"r")
		for i in ifile.readlines():
			v.append(i.strip())
		ifile.close
		return v

	def builddeps(self,pkgpath):
		pkgname=self.pkgpath2pkgname(pkgpath)
		if not pkgname:
			print "no pkgname for...",pkgpath
			sys.exit(1)
			return None
		try:
			self.cursor.execute("insert into pkg (pkgname,pkgpath) values (?,?)",(pkgname,pkgpath))
		except:
			return
		print "insert:",pkgname
		depv=self.getdepends(pkgpath)
		for i in depv:
			self.builddeps(i)
			try:
				self.cursor.execute("insert into pkgdep(pkgname,pkgdep) values (?,?)", (pkgname,self.pkgname(i)))
			except:
				print "errrorrrrrrrrrrrrrr, insert:",pkgname,self.pkgname(i)
				self.mostra()
				self.close()
				sys.exit(0)
		return pkgname

	def removepackage(self,pkgname):
		if "/" in pkgname:
			self.cursor.execute("delete from pkg where pkgpath=?" ,(pkgname,))
			return True
		self.cursor.execute("delete from pkg where pkgname=?" ,(pkgname,))
		return True

	def makedb(self):
		ifile=os.popen("pkg_info | awk '{print $1}'","r")
		for i in ifile.readlines():
			try:
				self.cursor.execute("insert into pkg (pkgname,pkgpath) values (?,?)",
				(i.strip(),self.pkgorigin(i)))
				print "+",
			except:
				pass
		ifile.close()
		self.cursor.execute("select * from pkg")
		for (name,origin) in self.cursor.fetchall():
			ifile=os.popen("cd /usr/pkgsrc/%s;make show-depends-dirs" % (origin), "r" )
			print "insert %s" % (name) 
			for i in ifile.readlines():
				print "    %s" % (i.strip())
				try:
					self.cursor.execute("insert into pkgdep(pkgname,pkgdep) values (?,?)",
					(name,self.pkgname(i)))
				except:
					pass
			ifile.close()

	def pkgname(self,pkgpath):
		self.cursor.execute("select pkgname from pkg where pkgpath=?",(pkgpath.strip(),))
		r=self.cursor.fetchone()
		if r:
			return r[0]
		return self.pkgname("lzt/%s" % (pkgpath.split('/')[1]))
		
	def pkgorigin(self,pkgname):
		self.cursor.execute("select pkgpath from pkg where pkgname=?",(pkgname,))
		origin=self.cursor.fetchone()
		if not origin:
			return None
		return origin[0]

	def walk(self,name,ident=0):
		if "/" in name:	
			name=self.pkgpath2pkgname(name)
		if not ident:
			self.seq=0
			self.walked=[]
			self.buildorder=open("/tmp/buildorder","w")
			self.buildorder.write("set -ex\n")
			self.buildorder.write("unset PKG_PATH\n")
		if name in self.walked:
			return
		self.walked.append(name)
		self.cursor.execute("select pkgdep from pkgdep where pkgname=?", (name,))
		for lista in self.cursor.fetchall():
			self.walk(lista[0],ident+1);
		self.seq+=1
		rc=os.system("pkg_info -qe %s" % (name))
		if not rc:
			self.buildorder.write("#")
		self.buildorder.write("cd /usr/pkgsrc/%s;make install || make replace;make clean\n" % (self.pkgorigin(name)))
		print "%.3d %.2d"%(self.seq,ident), " " * ident,name,self.pkgorigin(name)

	def mostra(self):
		print "=========mostra==============="
		self.cursor.execute("select * from pkg")
		for (name,origin) in self.cursor.fetchall():
			print "%-30s %s" % (name,origin)

	def close(self):
		self.conn.commit()
		self.conn.close()
		print "================"
		print "CLOSED"

if __name__ == "__main__":
	x=progs()
	x.builddeps(sys.argv[1])
	x.walk(sys.argv[1])
	x.close()
