#!/bin/sh

/usr/sbin/pkg_add.bin $@
eval  P=\${$#}
logger ADD $(basename $P .tgz)
