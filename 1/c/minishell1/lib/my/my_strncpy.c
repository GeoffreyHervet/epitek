/*
** my_strncpy.c for my in /home/hervet_g//work/projets/minishel/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Dec 30 08:42:27 2010 geoffrey hervet
** Last update Fri Dec 31 10:50:41 2010 geoffrey hervet
*/

#include		"libmy.h"

char			*my_strncpy(char *dest,
				    const char *src,
				    unsigned int length)
{
  unsigned int		idx;

  idx = 0;
  while (length-- && src[idx])
    {
      dest[idx] = src[idx];
      ++idx;
    }
  while (length--)
    dest[idx++] = '\0';
  return (dest);
}
