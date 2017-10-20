#!/bin/sh
#
# $NetBSD: findprinter.in,v 1.1 2008/12/05 18:55:22 cube Exp $
#

# PROVIDE: findprinter
# REQUIRE: DAEMON 
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="findprinter"
pidfile="/var/run/${name}.pid"
start_cmd="findprinter_start"
stop_cmd="findprinter_stop"
timer=${findprinter_timer:-10}

findprinter_start() {
	/usr/pkg/bin/daemon -p $pidfile /usr/bin/bin/findprinter
	echo $! > $pidfile
	echo $name STARTED
}
findprinter_stop() {
	if [ -s $pidfile ]
	then
		kill $(cat $pidfile)
	fi
}

load_rc_config $name
run_rc_command "$1"
