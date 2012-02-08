/*
** main.c for  in /u/all/hervet_g/public/morpion/src
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 21:26:22 2011 tracy nelcha
** Last update Wed May 25 21:26:34 2011 tracy nelcha
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>

#include	"morpion.h"
#include	"get_name.h"
#include	"init_grid.h"
#include	"play.h"
#include	"my_putstr.h"

int		main(int ac, char **av)
{
  char		name[256];
  char		grid[3][3];
  char		b[5];

  get_name(ac, av, DEF_NAME1, name);
  my_putstr("Hello \033[01m");
  my_putstr(name);
  my_putstr("\033[0m.\n");
  init_grid(grid);
  play(grid, (int)time(NULL));
  my_putstr("Try again ? [y/n]\n");
  while (read(0, &b, 4) != -1 && *b == 'y')
  {
    init_grid(grid);
    play(grid, (int)time(NULL));
    my_putstr("Try again ? [y/n]\n");
  }
  return (EXIT_SUCCESS);
}
