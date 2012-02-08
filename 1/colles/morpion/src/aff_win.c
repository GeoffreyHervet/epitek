/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Wed May 25 22:45:07 2011 tracy nelcha
*/

#include	"aff_win.h"
#include	"my_putstr.h"
#include	"my_putchar.h"

static void	update_grid3(char grid[3][3])
{
  if (grid[1][1] == grid[2][1] && grid[1][1] == grid[0][1])
  {
    grid[1][1] |= 1 << 5;
    grid[2][1] |= 1 << 5;
    grid[0][1] |= 1 << 5;
  }
  if (grid[1][2] == grid[2][2] && grid[1][2] == grid[0][2])
  {
    grid[1][2] |= 1 << 5;
    grid[2][2] |= 1 << 5;
    grid[0][2] |= 1 << 5;
  }
  if (grid[1][0] == grid[2][0] && grid[1][0] == grid[0][0])
  {
    grid[1][0] |= 1 << 5;
    grid[2][0] |= 1 << 5;
    grid[0][0] |= 1 << 5;
  }
}

static void	update_grid2(char grid[3][3])
{
  if (grid[2][0] == grid[2][1] && grid[2][2] == grid[2][1])
  {
    grid[2][0] |= 1 << 5;
    grid[2][1] |= 1 << 5;
    grid[2][2] |= 1 << 5;
  }
  if (grid[1][0] == grid[1][1] && grid[1][2] == grid[1][1])
  {
    grid[1][0] |= 1 << 5;
    grid[1][1] |= 1 << 5;
    grid[1][2] |= 1 << 5;
  }
  if (grid[0][0] == grid[0][1] && grid[0][2] == grid[0][1])
  {
    grid[0][0] |= 1 << 5;
    grid[0][1] |= 1 << 5;
    grid[0][2] |= 1 << 5;
  }
}

static void	update_grid(char grid[3][3])
{
  if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
  {
    grid[0][2] |= 1 << 5;
    grid[1][1] |= 1 << 5;
    grid[0][2] |= 1 << 5;
  }
  if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
  {
    grid[0][0] |= 1 << 5;
    grid[1][1] |= 1 << 5;
    grid[2][2] |= 1 << 5;
  }
  update_grid2(grid);
  update_grid3(grid);
}

static void	print_line(char grid[3])
{
  int		idx;

  idx = 0;
  my_putstr("| ");
  while (idx < 3)
  {
    if (grid[idx] & (1 << 5))
      my_putstr("\033[31m");
    if (!grid[idx])
      my_putchar(' ');
    else
      my_putchar(((grid[idx]) & (1 << 1)) ? 'O' : 'X');
    if (grid[idx] & (1 << 5))
      my_putstr("\033[0m");
    my_putchar(' ');
    idx++;
  }
  my_putstr("|\n");
}

void		aff_win(char grid[3][3], int sign)
{
  int		idx;

  sign = 0;
  update_grid(grid);
  idx = 0;
  my_putstr("+-------+\n");
  while (idx < 3)
    print_line(grid[idx++]);
  my_putstr("+-------+\n");
}
