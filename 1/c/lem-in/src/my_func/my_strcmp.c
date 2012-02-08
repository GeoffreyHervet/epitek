/*
** my_strcmp.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Apr 11 17:28:09 2011 geoffrey hervet
** Last update Mon Apr 11 17:28:09 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"my_strcmp.h"

int	my_strcmp(const char *s1,
		  const char *s2)
{
  if (s1 == NULL)
    return (-1);
  if (s2 == NULL)
    return (1);
  while (*s1 == *s2)
  {
    if (!*s1)
      return (0);
    s1++;
    s2++;
  }
  return ((*s1 > *s2) ? 1 : -1);
}
