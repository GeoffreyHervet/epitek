/*
** my_strdup.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Apr 12 15:18:15 2011 geoffrey hervet
** Last update Tue Apr 12 15:18:15 2011 geoffrey hervet
*/

#include		<stdlib.h>

#include		"my_strdup.h"
#include		"my_strlen.h"

char			*my_strdup(const char *s1)
{
  int			idx;
  char			*str;

  idx = 0;
  if (s1 == NULL)
    return (NULL);
  if ((str = malloc(sizeof(*s1) * (my_strlen(s1) + 1))) == NULL)
    return (NULL);
  while (*s1)
    str[idx++] = *s1++;
  str[idx] = 0;
  return (str);
}
