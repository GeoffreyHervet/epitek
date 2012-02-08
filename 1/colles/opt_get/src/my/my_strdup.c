/*
** my_strdup.c for  in /u/all/hervet_g/public/opt_get/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 20:28:07 2011 tracy nelcha
** Last update Mon May  9 21:22:21 2011 tracy nelcha
*/

#include	"my_strlen.h"
#include	"xfunc.h"

char		*my_strdup(const char *s)
{
  int		size;
  char		*copy;
  int		i;
  int		j;

  i = 0;
  j = 0;
  size = my_strlen(s);
  copy = xmalloc(sizeof(*s) * size);
  while (s[i])
    copy[j++] = s[i++];
  copy[j + 1] = '\0';
  return (copy);
}
