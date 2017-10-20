#!/bin/sh
#
# $NetBSD: runbatch.in,v 1.1 2008/12/05 18:55:22 cube Exp $
#

# PROVIDE: runbatch
# REQUIRE: DAEMON 
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="runbatch"
#pidfile="/var/run/${name}.pid"
start_cmd="runbatch_start"
stop_cmd="runbatch_stop"
timer=${runbatch_timer:-10}

runbatch_start() {
	/usr/pkg/bin/runbatch ${timer}
	echo $name STARTED
}
runbatch_stop() {
	/usr/pkg/bin/runbatch -k
}

load_rc_config $name
run_rc_command "$1"
