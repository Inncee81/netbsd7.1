from lztlib import *

import datetime

class lzt_entry(gtk.Entry):
	def __init__(self,xml):
		self.setxml(xml)

	def setxml(self,xml):
		self.xml=xml;

	def get_data_from_entry(self,widget_name,ty=str,msg='',sz=0,capitalize=False,title=False,func=None):
		v=self.xml.get_widget(widget_name).get_text()
		if msg:
			if not v:
				lzt_messageinfo(msg)
				raise ValueError(msg)
			if sz > 0:
				if len(v) != sz:
					msg="%s, tamanho invalido" % (msg)
					lzt_messageinfo(msg)
					raise ValueError(msg)
		if func:
			v=func(v)
		if not v:
			return None
		if ty is int:
			return int(v)
		elif ty is float:
			return float(v)
		elif ty is str:
			if title:
				return v.title()
			if capitalize:
				return v.capitalize()
		return v

	def set_data_into_entry(self,widget_name,value):
		if value is None:
			value=""
		if type(value) is int:
			value="%s" % (value)
		elif type(value) is float:
			value="%s" % (value)
		elif type(value) is datetime.date:
			value="%.4d-%.2d-%.2d" % (value.year,value.month,value.day)
		return self.xml.get_widget(widget_name).set_text(value)

	def clear(self,widget_name):
		return self.xml.get_widget(widget_name).set_text("")
	
	def set_data_from_dic(self,d):
		for i in d.keys():
			v=d[i]
			self.set_data_into_entry(v[0],v[1])

	def set_status_bar_message(self,msg,w="appbar1"):
		self.appbar=self.xml.get_widget(w)
		self.appbar.set_status(msg)

	def set_status_bar_percentage(self,v):
		self.appbar.set_progress_percentage(v)

