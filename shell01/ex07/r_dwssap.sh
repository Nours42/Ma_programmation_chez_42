#!/bin/sh

FT_LINE2=$FT_LINE2+1
FT_DIFF=$(($FT_LINE2-$FT_LINE1))

cat /etc/passwd | rev | cut -d ":" -f7 | sort -r | sed -n '1~2p' | tr "\n" ", " | cut -d "," -f1-$FT_DIFF | tr "\n" "."
