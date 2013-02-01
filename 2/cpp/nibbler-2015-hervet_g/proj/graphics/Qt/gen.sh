#!/bin/sh

rm Makefile && qmake-qt4 && make clean && make
