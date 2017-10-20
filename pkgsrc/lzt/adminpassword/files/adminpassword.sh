#!/bin/sh
#
# $NetBSD: adminpassword.in,v 1.1 2008/12/05 18:55:22 cube Exp $
#

# PROVIDE: adminpassword
# REQUIRE: mountcritlocal
# BEFORE:  LOGIN

$_rc_subr_loaded . /etc/rc.subr

name="adminpassword"
start_cmd="adminpassword_start"
stop_cmd="adminpassword_stop"

adminpassword_start() {
	if [ -x /usr/pkg/etc/adminpassword/makeadminpassword ]
	then
		/usr/pkg/etc/adminpassword/makeadminpassword
	fi
}
adminpassword_stop() {
	true
}

load_rc_config $name
run_rc_command "$1"
