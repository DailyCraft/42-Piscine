#!/bin/sh
echo $FT_NBR1 + $FT_NBR2 | tr "'\"?\!" '0234' | tr '\\' '1' | tr 'mrdoc' '01234' | sed 's/^/obase=10;ibase=5; /' | bc | sed 's/^/ibase=10;obase=13;/' | bc | tr '0123456789ABC' 'gtaio luSnemf'
