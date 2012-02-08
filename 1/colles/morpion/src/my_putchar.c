/*
** my_putchar.c for  in /u/all/hervet_g/public/morpion/src
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 21:57:21 2011 tracy nelcha
** Last update Wed May 25 21:57:22 2011 tracy nelcha
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"my_putchar.h"

void		my_putchar(const char c)
{
  if (write(1, &c, 1) == -1)
    if (write(2, &c, 1) == -1)
      exit(EXIT_FAILURE);
}
