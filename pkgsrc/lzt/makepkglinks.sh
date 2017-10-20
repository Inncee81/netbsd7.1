#!/bin/sh

set -e

while [ $# -gt 0 ]
do
	(
	SRC="$1"
	echo working on $SRC
	cd ${SRC}
	CAT=$(make show-var VARNAME=CATEGORIES)
	if [ -z "${CAT}" ]
	then
		echo "missing categories"
		exit 2
	fi
	set ${CAT}
	CAT=$1
	if [ "$1" = "$(basename $(dirname $(pwd)))" ]
	then
		echo "error, invalid destination"
		exit 3
	fi
	DST="../$1"
	SRC=$(echo $SRC | sed 's,/$,,')
	echo SRC=../lzt/$SRC
	cd ../../$CAT
	pwd
	if [ ! -L $SRC ]
	then
		echo SAVE $SRC to /usr/tmp
		mv $SRC /usr/tmp || true
	else
		rm -f $SRC
		echo LINK $SRC to ../pkgsrc/lzt
	fi
	ln -s ../lzt/$SRC .
	echo $SRC DONE
	)
	shift
done
