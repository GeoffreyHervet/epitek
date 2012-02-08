/*
** my_cpystr_xtoy.c for my in /home/hervet_g//work/rush/marvin
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Nov 27 15:33:59 2010 geoffrey hervet
** Last update Sat Nov 27 15:44:32 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"lib.h"

char		*my_cpystr_xtoy(char *str, int start, int end)
{
  char		*ret;
  int		idx;

  if ((ret = malloc(end - start + 2)) == NULL)
    return (NULL);
  idx = 0;
  while (start <= end)
    ret[idx++] = str[start++];
  ret[idx] = 0;
  return (ret);
}
