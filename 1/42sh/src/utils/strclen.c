/*
** strclen.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/utils
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Apr 16 23:10:36 2011 tom-brent yau
** Last update Sun Apr 17 16:10:05 2011 tom-brent yau
*/

#include	<stdlib.h>

int		strclen(char *str, char *stop)
{
  int	i;
  int	i2;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      i2 = 0;
      while (str[i] != stop[i2] && stop[i2])
	i2++;
      if (str[i] == stop[i2])
	return (i);
      i++;
    }
  return (i);
}
