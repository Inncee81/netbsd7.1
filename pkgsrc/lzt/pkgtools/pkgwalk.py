#!/usr/bin/env python2.7
import os,sys,string
import pkgutils

x=pkgutils.progs()
x.walk(sys.argv[1])
x.close()
