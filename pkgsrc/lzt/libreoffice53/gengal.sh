#!/bin/sh

export PATH=/root/bin:/sbin:/usr/sbin:/bin:/usr/bin:/usr/pkg/sbin:/usr/pkg/bin:/usr/X11R7/bin:/usr/X11R6/bin:/usr/local/sbin:/usr/local/bin
/usr/bin/logger EXEC $0 args $@

while [ $# -gt 0 ]
do
	case $1 in
	--build-tree)
		BT=1
	;;
	--destdir)
		DEST="$(echo $2 | /usr/bin/sed 's;file://;;')"
		shift
	;;
	--name)
		NAME="$2"
		shift
	;;
	--filenames)
		if [ -z "$2" ]
		then
			echo NO FILENAMES
			exit 98
		fi
		if [ ! -s $2 ]
		then
			echo $2 not found
			shift
			continue
		fi
		FILENAMES="$(/bin/cat $2 | /usr/bin/sed 's;file://;;g')"
		shift
	;;
	--path)
		PATH="$(echo $2 | /usr/bin/sed 's;file//;;')"
		shift
	;;
	esac
	shift
done
/bin/mkdir -p ${PATH}
for i in ${FILENAMES}
do
	/bin/cp ${i} ${PATH} 
done
###  stop, for test
exit 99
