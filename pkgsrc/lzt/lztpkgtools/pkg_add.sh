#!/bin/sh

exec /usr/sbin/pkg_add.bin $@
eval  P=\${$#}
logger ADD $(basename $P .tgz)
