#!/bin/sh

if /usr/sbin/pkg_create.bin "$@"
then
	eval PNAME=\${$#}
	case "${PNAME}" in
	*.tmp.tgz)
		exit 0
	;;
	*.tgz)
		PNAME="$(basename "$PNAME" .tgz)"
	;;
	esac
	if pkg_info -qe "$PNAME"
	then
		. /usr/pkg//pkgtools/profile
		/usr/pkg/pkgtools/pkglztadmin add "${PNAME}"
		logger ADD $PNAME
	fi
fi
