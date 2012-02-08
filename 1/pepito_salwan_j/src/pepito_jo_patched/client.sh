#!/bin/sh

if [ $# -gt 0 ]
then
  echo "$*" | nc localhost 31337
fi
