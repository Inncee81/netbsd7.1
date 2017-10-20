#!/bin/sh
#
# $NetBSD: fixhostname.in,v 1.1 2008/12/05 18:55:22 cube Exp $
#

# PROVIDE: fixhostname
# REQUIRE: network 
# BEFORE: dhclient

$_rc_subr_loaded . /etc/rc.subr

name="fixhostname"
start_cmd="fixhostname_start"

fixhostname_start () {
	echo "FIX HOSTNAME $(hostname) in /etc/hosts ..."
	sed -e "/^127\.0\.0\.1/s/127.0.0.1.*/127.0.0.1	localhost $(hostname)/" /etc/hosts  > /etc/hosts.new && \
	mv /etc/hosts.new /etc/hosts
	echo DONE
}

load_rc_config $name
run_rc_command "$1"
