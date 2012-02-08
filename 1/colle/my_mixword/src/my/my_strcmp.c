/*
** my_strcmp.c for  in /u/all/hervet_g/public/KHOL/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May  4 19:33:54 2011 tracy nelcha
** Last update Wed May  4 19:39:27 2011 tracy nelcha
*/

#include	<stdlib.h>

#include	"my_strcmp.h"

int		my_strcmp(char *str1, char *str2)
{
  while (str1 != NULL && str2 != NULL &&
	 *str1 == *str2)
  {
    if (!*str1)
      return (0);
    str1++;
    str2++;
  }
  return ((str1 > str2) ? 1 : -1);
}
