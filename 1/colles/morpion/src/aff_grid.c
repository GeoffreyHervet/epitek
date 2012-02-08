/*
** aff_grid.c for  in /u/all/hervet_g/public/morpion/src
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 21:56:03 2011 tracy nelcha
** Last update Wed May 25 21:56:44 2011 tracy nelcha
*/

#include	"aff_grid.h"
#include	"my_putstr.h"
#include	"my_putchar.h"

static char	get_sign(char c)
{
  if (!c)
    return (' ');
  return (((c) & (1 << 1)) ? 'O' : 'X');
}

static void	print_line(char grid[3])
{
  int		idx;

  idx = 0;
  my_putstr("| ");
  while (idx < 3)
  {
    my_putchar(get_sign(grid[idx++]));
    my_putchar(' ');
  }
  my_putstr("|\n");
}

void		aff_grid(char grid[3][3])
{
  int		idx;

  idx = 0;
  my_putstr("+-------+\n");
  while (idx < 3)
    print_line(grid[idx++]);
  my_putstr("+-------+\n");
}
