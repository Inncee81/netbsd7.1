import psycopg2

class bancos:
	def __init__(self,dbconn=None):
		if not dbconn:
			self.dbconn=psycopg2.connect("host=dist64.k1.com.br dbname=impd user=impd password=188881")
		else:
			self.dbconn=dbconn

	def getbyname(self,name):
		name="%%%s%%" %(name)
		c=self.dbconn.cursor()
		c.execute("select codigo from bancos where nome ilike %s",(name,))
		r=c.fetchone()
		c.close()
		return r[0]

	def getbycod(self,numero):
		c=self.dbconn.cursor()
		c.execute("select nome from bancos where codigo =  %s",(numero,))
		r=c.fetchone()
		c.close()
		return r[0]

	def getallcodes(self):
		c=self.dbconn.cursor()
		c.execute("select codigo from bancos order by codigo")
		r=[]
		for i in c.fetchall():
			r.append(i[0])
		c.close()
		return r

	def getallnames(self):
		c=self.dbconn.cursor()
		c.execute("select nome from bancos order by nome")
		r=[]
		for i in c.fetchall():
			r.append(i[0])
		c.close()
		return r

if __name__ == "__main__":
	x=bancos()
	print x.getbyname("banco do brasil")
	print x.getbycod("001")
	print x.getallnames()
	print x.getallcodes()
