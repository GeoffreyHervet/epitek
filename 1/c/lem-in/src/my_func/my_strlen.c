/*
** my_strlen.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Apr 11 17:11:08 2011 geoffrey hervet
** Last update Mon Apr 11 17:11:08 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"my_strlen.h"

int		my_strlen(const char *str)
{
  int		size;

  size = 0;
  while (str != NULL && str[size])
    size++;
  return (size);
}
