/*
** header for norme in /
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
** 
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Wed May 25 23:43:00 2011 tracy nelcha
*/

#include	"is_win.h"

static int	check_grid3(char grid[3][3])
{
  if ((grid[1][1] && grid[1][1] == grid[2][1] && grid[1][1] == grid[0][1]) ||
      (grid[1][2] && grid[1][2] == grid[2][2] && grid[1][2] == grid[0][2]) ||
      (grid[1][0] && grid[1][0] == grid[2][0] && grid[1][0] == grid[0][0]))
    return (1);
  return (0);
}

static int	check_grid2(char grid[3][3])
{
  if ((grid[2][0] && grid[2][0] == grid[2][1] && grid[2][2] == grid[2][1]) ||
      (grid[1][0] && grid[1][0] == grid[1][1] && grid[1][2] == grid[1][1]) ||
      (grid[0][0] && grid[0][0] == grid[0][1] && grid[0][2] == grid[0][1]))
    return (1);
  return (0);
}

static int	check_grid(char grid[3][3])
{
  if ((grid[0][2] && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) ||
      (grid[0][0] && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]))
    return (1);
  return (check_grid2(grid) || check_grid3(grid));
}

int		is_win(char grid[3][3])
{
  return (check_grid(grid));
}
