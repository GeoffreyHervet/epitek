/*
** my_strlen.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 19:42:38 2011 geoffrey hervet
** Last update Tue May 17 19:42:38 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"my_strlen.h"

int		my_strlen(const char *str)
{
  int		idx;

  idx = 0;
  while (str != NULL && str[idx])
    idx++;
  return (idx);
}
