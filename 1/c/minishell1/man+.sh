#!/bin/sh
## man+.sh for my_sh in /home/hervet_g//work/projets/minishel
## 
## Made by geoffrey hervet
## Login   <hervet_g@epitech.net>
## 
## Started on  Wed Dec 22 11:01:47 2010 geoffrey hervet
## Last update Wed Dec 22 11:06:55 2010 geoffrey hervet
##

for (( nb = 2 ; nb <= 9 ; nb++ ))
do
    man $nb $1
done
