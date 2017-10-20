#!/bin/sh
export PATH=/sbin:/usr/sbin:/bin:/usr/bin:/usr/pkg/sbin:/usr/pkg/bin:/usr/X11R7/bin

CONF=/usr/pkg/etc/cups/client.conf

PRINTER=${1:-printer}

if nc -z localhost ipp
then
	rm -f ${CONF}
	exit 0
fi
IP=$(
	ping -c 1 ${PRINTER} 2>/dev/null | \
	grep "64 bytes" | \
	grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b"
)

if [ -z "$IP" ]
then
	rm -f ${CONF}
	exit 0
fi
if ! nc -z ${IP} ipp
then
	rm -f ${CONF}
	exit 0
fi
echo "ServerName $IP" > ${CONF}.new
mv ${CONF}.new ${CONF}
exit 0
