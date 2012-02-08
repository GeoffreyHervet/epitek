/*
** xstrdup.c for xfunc in /home/igix/42sh/src/xfunc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  ven. avril 29 13:17:47 2011 geoffrey hervet
** Last update ven. avril 29 13:17:47 2011 geoffrey hervet
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

char	*xstrdup(const char *s)
{
  char	*ret;

  if ((ret = strdup(s)) == NULL)
  {
    fprintf(stderr, "Can't perform strdup\n");
    exit(EXIT_FAILURE);
  }
  return (ret);
}
