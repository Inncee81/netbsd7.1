import pygtk
import glib,gtk,gtk.glade
import gnome
from bs4 import BeautifulSoup

class lzt_entry(gtk.Entry):
	def __init__(self):
		gtk.Entry.__init__(self)
		self.properties()
		self.show()

	def properties(self,conn=None,query=None):
		self.conn=conn
		self.query=query
		if conn and query:
			self.timeout_id=None	
			self.connect("changed",self.entrychanged)

	def entrychanged(self,e):
		if self.timeout_id:
			glib.source_remove(self.timeout_id)
		self.timeout_id=gtk.timeout_add(1000,self.timeout)

	def timeout(self):
		x="%%%s%%" % (self.get_text())
		if self.conn:
			c=self.conn.cursor()
			#print "QUERY=",c.mogrify(self.query,(x,))
			c.execute(self.query,(x,))
			try:
				self.set_text(c.fetchone()[0])
			except:
				pass
			
			c.close()
		return False

class lzt_entrydialog(gtk.Window):
	def __init__(self,msg,altmsg="",password=False):
    		dialog = gtk.MessageDialog(
        		None,
        		gtk.DIALOG_MODAL | gtk.DIALOG_DESTROY_WITH_PARENT,
        		gtk.MESSAGE_QUESTION,
        		gtk.BUTTONS_OK,
        		None)
    		dialog.set_markup(msg)
    		entry = gtk.Entry()
		entry.set_visibility(not password)
    		#allow the user to press enter to do ok
    		entry.connect("activate", self.activate, dialog, gtk.RESPONSE_OK)
    		#create a horizontal box to pack the entry and a label
    		hbox = gtk.HBox()
    		hbox.pack_start(gtk.Label(altmsg), False, 5, 5)
    		hbox.pack_end(entry)
    		dialog.vbox.pack_end(hbox, True, True, 0)
    		dialog.show_all()
    		dialog.run()
    		self.text = entry.get_text()
    		dialog.destroy()

	def activate(self,entry,dialog,response):
		dialog.response(response)

	def getdata(self):
    		return self.text

	def responseToDialog(entry, dialog, response):
    		dialog.response(response)
		
class lzt_messageinfo(gtk.Window):
	def __init__(self,msg,tv=0,bt=gtk.BUTTONS_OK,f=None):
		if not bt:
			md=gtk.MessageDialog(self,
				gtk.DIALOG_DESTROY_WITH_PARENT,
				gtk.MESSAGE_INFO,
				gtk.BUTTONS_CLOSE)
			md.set_markup(msg)
			if tv:
				self.tid=gtk.timeout_add(tv,self.timeout2,msg,md.destroy)
			self.result=md.run()
			return
		if tv == 0:
			md=gtk.MessageDialog(self,
				gtk.DIALOG_DESTROY_WITH_PARENT,
				gtk.MESSAGE_INFO,
				bt)
			md.set_markup(msg)
			self.result=md.run()
			md.destroy()
		else:
			self.tid=gtk.timeout_add(tv,self.timeout1,msg,f)

	def timeout2(self,msg,f=None):
		if f:
			f()
		return False

	def timeout1(self,msg,f=None):
		x=lzt_messageinfo(msg)
		if f:
			f()
		return False
		

class lzt_messagedialog(gtk.Window):
	def __init__(self,msg):
		md=gtk.MessageDialog(self,
			gtk.DIALOG_DESTROY_WITH_PARENT,
			gtk.MESSAGE_QUESTION,
			gtk.BUTTONS_YES_NO)
		md.set_markup(msg)
		self.result=md.run()
		md.destroy()

	def getresult(self):
		if self.result == gtk.RESPONSE_YES:
			return gtk.TRUE
		return gtk.FALSE

class lzt_comboboxentry(gtk.Window):
	def __init__(self,xml,wname):
		self.cb=xml.get_widget(wname)
	
	def putlist(self,list,idx=0):
		model=self.cb.get_model()
		if not model:
			return
		model.clear()
		for i in list:
			if type(i) is tuple:
				i=i[0]
			self.cb.append_text(i)
		self.cb.set_active(idx)

	def set_active(self,idx):
		self.cb.set_active(idx)

	def getdata(self,idx=0):
		return self.cb.get_active_text()

class lzt_treeview(gtk.Window):
	def __init__(self,tv,columns,markup=False):
		self.columns=columns
		self.tv=tv
		pos=0
		for i in columns:
			cell=gtk.CellRendererText()
			if markup:
				c=gtk.TreeViewColumn(i,cell,markup=pos)
			else:
				c=gtk.TreeViewColumn(i,cell,text=pos)
			c.set_min_width(len(i) * 10)
			c.set_reorderable(True)
			tv.append_column(c)
			pos+=1
		colset=[str] * len(self.columns)
		self.listmodel=gtk.ListStore(*colset)
		self.tv.set_model(self.listmodel)
		self.autoclear=True
		self.tv.get_selection().set_mode(gtk.SELECTION_MULTIPLE)

	def foreach(self,model,path,iter,selected):
		selected.append(model.get_value(iter,self.selcolumn))

	def getselection(self,col=0):
		self.selcolumn=col
		l=[]
		self.tv.get_selection().selected_foreach(self.foreach,l)
		return l

	def clear(self):
		self.listmodel.clear()

	def show(self,data):
		if self.autoclear:
			self.clear()
		for i in data:
			self.listmodel.append(i)

	def get_data(self,idx=0):
		ts=self.tv.get_selection()
		ts.set_mode(gtk.SELECTION_SINGLE)
		(model,iter)=ts.get_selected()
		soup=BeautifulSoup(model.get_value(iter,idx),"lxml")
		ts.set_mode(gtk.SELECTION_MULTIPLE)
		return ''.join(soup.findAll(text=True))


gtk.glade.set_custom_widget_callbacks({"lzt_entry":lzt_entry})
