/*
** my_strlen.c for  in /u/all/hervet_g/public/opt_get/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 19:36:54 2011 tracy nelcha
** Last update Mon May  9 21:26:00 2011 tracy nelcha
*/

#include	<stdlib.h>

int		my_strlen(const char *str)
{
  int		idx;

  while (str[idx] && str != NULL)
    idx++;
  return (idx);
}
