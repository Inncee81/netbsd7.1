#!/bin/sh

if [ ! -s /tmp/buildorder ]
then
	echo buildpackage not run, do nothing
	exit 1
fi
cat /tmp/buildorder

echo hit enter to build ctrl-c to arbort
read x
sh < /tmp/buildorder
