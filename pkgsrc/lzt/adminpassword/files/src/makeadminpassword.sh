#!/bin/sh

export TERM=nsterm
export PATH=/sbin:/usr/sbin:/bin:/usr/bin:/usr/pkg/sbin:/usr/pkg/bin

PWFILE=PWFILE

t=/tmp/$$

cd /usr/pkg/etc/adminpassword || exit 0

if id admin > /dev/null 2>&1
then
	if [ ! -s "${PWFILE}" ]
	then
		touch ${PWFILE}
		if dialog --inputbox "SENHA DO ADMINISTRADOR" \
			0 0 2> $t
		then
			mv $t ${PWFILE}
			P="$(cat ${PWFILE})"
			usermod -p "$(pwhash "$P")" admin
		fi
		clear
	fi
fi
