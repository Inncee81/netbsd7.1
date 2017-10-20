#!/bin/sh
#
# $NetBSD: pulseaudio.in,v 1.1 2008/12/05 18:55:22 cube Exp $
#

# PROVIDE: pulseaudio
# REQUIRE: DAEMON LOGIN dbus hal
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="pulseaudio"
rcvar="pulseaudio"
pidfile="/var/run/pulse/pid"
start_cmd="pulseaudio_start"
stop_cmd="pulseaudio_stop"
timer=${pulseaudio_timer:-10}

pulseaudio_start() {
	mkdir -p /var/run/pulse
	chown pulse:pulse /var/run/pulse
	usermod -d /var/run/pulse pulse || true
	/usr/pkg/bin/pulseaudio --system -D
	echo $name STARTED
}
pulseaudio_stop() {
	if [ -s $pidfile ]
	then
		kill $(cat $pidfile)
	fi
	echo $name STOPPED
}

load_rc_config $name
run_rc_command "$1"
