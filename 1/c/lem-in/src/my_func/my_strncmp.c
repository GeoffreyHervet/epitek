/*
** my_strncmp.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Apr 12 09:27:44 2011 geoffrey hervet
** Last update Tue Apr 12 09:27:44 2011 geoffrey hervet
*/

#include	<unistd.h>

#include	"my_strncmp.h"

int	my_strncmp(const char *s1,
		   const char *s2,
		   int length)
{
  while (*s1 == *s2 && length-- > 0)
  {
    if (!*s1)
      return (0);
    s1++;
    s2++;
  }
  if (length == 0)
    return (0);
  return ((*s1 > *s2) ? 1 : -1);
}
