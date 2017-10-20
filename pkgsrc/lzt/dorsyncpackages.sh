#!/bin/sh

set -e
case $# in
2)
	OPT=""
	case $1 in
	-*)
		OPT=$1
		shift
	;;
	esac
	SRC="$1"
	DST="$2"
;;
1)
	SRC="$1"
	cd ${SRC}
	CAT=$(make show-var VARNAME=CATEGORIES)
	if [ -z "${CAT}" ]
	then
		echo "missing categories"
		exit 2
	fi
	set ${CAT}
	if [ "$1" = "$(basename $(dirname $(pwd)))" ]
	then
		echo "error, invalid destination"
		exit 3
	fi
	DST=../$1
	cd -
;;
*)
	echo "use $0 pkg SRC [DST]"
	exit 1
esac
set -x
SRC=$(echo $SRC | sed 's,/$,,')
rsync --exclude CVS -avzHx --delete ${OPT} "${SRC}" "${DST}"
