/*
** my_strcmp.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 19:22:49 2011 geoffrey hervet
** Last update Tue May 17 19:22:49 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"my_strcmp.h"

int		my_strcmp(const char *s1, const char *s2)
{
  if (s1 == NULL || s2 == NULL)
    return ((s1 == NULL) ? -1 : 1);
  while (*s1 || *s2)
  {
    if (*s1 != *s2)
      return ((*s1 > *s2) ? 1 : -1);
    s1++;
    s2++;
  }
  return (0);
}
