/*
** my_strdup.c for my in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Dec 23 11:33:08 2010 geoffrey hervet
** Last update Sun Jan  2 11:32:11 2011 geoffrey hervet
*/

#include		<stdlib.h>

#include		"libmy.h"

char			*my_strdup(const char *str)
{
  char			*ret;
  unsigned int		idx;

  if ((ret = malloc(sizeof(*ret) * (1 + my_strlen(str)))) == NULL)
    return (NULL);
  idx = 0;
  while (str[idx])
    {
      ret[idx] = str[idx];
      ++idx;
    }
  ret[idx] = '\0';
  return (ret);
}
