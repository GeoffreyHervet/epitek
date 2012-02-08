/*
** my_strcmp.c for  in /u/all/hervet_g/public/morpion/src
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 19:23:34 2011 tracy nelcha
** Last update Wed May 25 19:41:25 2011 tracy nelcha
*/

#include	<stdio.h>
#include	<stdlib.h>

int		my_strcmp(char *s1, char *s2)
{
  while ((s1 != NULL && s2 != NULL) && (*s1 || *s2))
  {
    if (*s1 != *s2)
      return ((*s1) > (*s2) ? 1 : -1);
    s1++;
    s2++;
  }
  return (0);
}
