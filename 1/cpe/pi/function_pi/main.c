/*
** main.c for  in /u/all/hervet_g/public/Pi/function_pi
**
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
**
** Started on  Wed Apr 27 22:15:50 2011 tracy nelcha
** Last update Wed Apr 27 22:38:34 2011 tracy nelcha
*/

#include	<stdlib.h>
#include	"main.h"
#include	"my_putstr.h"

int		main(int ac, char **av)
{
  int		idx;
  int		idx2;

  idx = 0;
  idx2 = 0;
  if (ac < 3)
  {
    my_putstr("<USAGE> ./exe -[a, s or d] [nb1 nb2]\n");
    exit(EXIT_FAILURE);
  }
  add(av[2], av[3]);
  return (0);
}
