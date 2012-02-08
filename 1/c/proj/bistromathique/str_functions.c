/*
** str_functions.c for bistro in /home/hervet_g//work/projets/c/bistro
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct 29 23:51:08 2010 geoffrey hervet
** Last update Sat Oct 30 16:45:54 2010 geoffrey hervet
*/

#include	"bistromathique.h"
#include	<stdlib.h>

char		*str_cpy_delimit(char *str, int start, int end)
{
  char		*res;
  int		res_pos;

  res = malloc(sizeof(*str) * (start - end + 1));
  if (res == NULL)
    return (NULL);
  res_pos = 0;
  while ((start <= end) && (str[start]))
      res[res_pos++] = str[start++];
  res[res_pos] = '\0';
  return (res);
}
