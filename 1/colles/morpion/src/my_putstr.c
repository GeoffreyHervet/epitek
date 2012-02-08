/*
** my_putstr.c for  in /u/all/hervet_g/public/morpion
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 19:57:59 2011 tracy nelcha
** Last update Wed May 25 19:59:46 2011 tracy nelcha
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"my_putstr.h"
#include	"my_strlen.h"

void		my_putstr(const char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    if (write(2, str, my_strlen(str)) == -1)
      exit(EXIT_FAILURE);
}
