/*
** my_putstr.c for  in /u/all/hervet_g/public/opt_get/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 20:38:07 2011 tracy nelcha
** Last update Mon May  9 21:17:55 2011 tracy nelcha
*/

#include	"xfunc.h"

void		my_putstr(const char *str)
{
  int		idx;

  idx = 0;
  while (str[idx])
    xwrite(1, &str[idx++], 1);
}
