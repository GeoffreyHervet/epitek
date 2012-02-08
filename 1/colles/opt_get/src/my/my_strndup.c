/*
** my_strndup.c for  in /u/all/hervet_g/public/opt_get/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 20:50:52 2011 tracy nelcha
** Last update Mon May  9 21:23:46 2011 tracy nelcha
*/

#include	"xfunc.h"
#include	"my_strlen.h"

char            *my_strndup(const char *s, int nb)
{
  int		size;
  char          *copy;
  int           i;
  int           j;

  i = 0;
  j = 0;
  size = my_strlen(s);
  copy = xmalloc(sizeof(*s) * size);
  while (i < nb)
    copy[j++] = s[i++];
  copy[j + 1] = '\0';
  return (copy);
}
