#!/bin/sh

# Just set this variable if you want to write into a specified file
logfile="./log"
bin="../avm"
avmdir=".samples"
color1="\033[1;31m"
color2="\033[1;32m"
defcol="\033[0;m"

# private:
default="/tmp/defout-$$"
defaulterr="/tmp/deferr-$$"
output="/tmp/bin-$$"
output="ok"
errput="/tmp/err-$$"

log()
{
  if [ -z $logfile ];
  then
    logfile=$( date '+%H:%M.log' | sed 's/\//#/g' )
    rm $logfile 2> /dev/null
    touch $logfile
  fi
  if [ "$2" == "OK" ];
  then
    printf "%-25s: $color2%s$defcol\n" "$1" "$2"
    printf "%-25s: %s\n" "$1" "$2" >> $logfile
  else
    printf "%-25s: $color1%s$defcol\n" "$1" "$2"
    printf "%-25s: %s\n" "$1" "$2" >> $logfile
  fi
}

get_outputs()
{
  cat $1 | grep -E "^;" | sed 's/;//' > $default
  cat $1 | grep -E "^ ;" | sed 's/ ;//' > $defaulterr
  ./$bin $1 > $output 2> /dev/null
  echo $? > $errput
}

get_diffs()
{
  diff $default $output > /dev/null
  tmp=$?
  diff $defaulterr $errput > /dev/null
  if [ $? == 0 ] && [ $tmp == 0 ];
  then
    echo "OK"
    return
  fi
  echo "KO"
}

if [ ! -f $bin ];
then
  echo "$bin doesn't exist."
  exit 1
fi

for file in $( ls $avmdir )
do
  if [ -f $avmdir/$file ];
  then
    get_outputs $avmdir/$file
    log "$file" "$( get_diffs )"
  fi
done

rm $default $defaulterr $errput 2> /dev/null
