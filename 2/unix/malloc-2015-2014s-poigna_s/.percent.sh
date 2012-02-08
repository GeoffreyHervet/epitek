#!/bin/sh

if test $# -eq 1 ;then
  exit
fi

idx="2"
while test $idx -le $#
do
  #echo "idx : $idx // # : $#"
  str="eval echo \$`echo $idx`"
  str=`$str`
  if test $str = $1 ;then
    echo "($idx - 1) * 100 / $#" | bc
    exit
  fi
  idx=`expr $idx + 1`
done

