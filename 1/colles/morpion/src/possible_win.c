/*
** possible_win.c for  in /u/all/hervet_g/public/morpion/src
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed May 25 21:55:41 2011 tracy nelcha
** Last update Wed May 25 23:40:27 2011 tracy nelcha
*/

#include	"possible_win.h"

#define		OWN_CASE(x)	((x) & (1 << (sign + 1)))

static int	win_row(char grid[3][3], int row, int sign)
{

  if ((OWN_CASE(grid[0][row]) && OWN_CASE(grid[1][row]) && !grid[2][row]) ||
      (OWN_CASE(grid[0][row]) && OWN_CASE(grid[2][row]) && !grid[1][row]) ||
      (OWN_CASE(grid[1][row]) && OWN_CASE(grid[2][row]) && !grid[0][row]))
  {
    grid[0][row] = 1 << 5 | 1 << (sign + 1);
    grid[1][row] = grid[0][row];
    grid[2][row] = grid[0][row];
  }
  return (0);
}

static int	win_line(char grid[3][3], int col, int sign)
{

  if ((OWN_CASE(grid[col][0]) && OWN_CASE(grid[col][1]) && !grid[col][2]) ||
      (OWN_CASE(grid[col][0]) && OWN_CASE(grid[col][2]) && !grid[col][1]) ||
      (OWN_CASE(grid[col][1]) && OWN_CASE(grid[col][2]) && !grid[col][0]))
  {
    grid[col][0] = 1 << 5 | 1 << (sign + 1);
    grid[col][1] = grid[col][0];
    grid[col][2] = grid[col][0];
  }
  return (0);
}

int		win_diag(char grid[3][3], int sign)
{
  int		nb_free;

  nb_free = 0;
  if ((OWN_CASE(grid[0][0]) && OWN_CASE(grid[1][1]) && !grid[2][2]) ||
      (OWN_CASE(grid[0][0]) && OWN_CASE(grid[2][2]) && !grid[1][1]) ||
      (OWN_CASE(grid[1][1]) && OWN_CASE(grid[2][2]) && !grid[0][0]))
  {
    grid[0][0] = 1 << 5 | 1 << (sign + 1);
    grid[1][1] = grid[0][0];
    grid[2][2] = grid[0][0];
    return (1);
  }
  if ((OWN_CASE(grid[0][2]) && OWN_CASE(grid[1][1]) && !grid[2][0]) ||
      (OWN_CASE(grid[0][2]) && OWN_CASE(grid[2][0]) && !grid[1][1]) ||
      (OWN_CASE(grid[1][1]) && OWN_CASE(grid[2][0]) && !grid[0][2]))
  {
    grid[0][2] = 1 << 5 | 1 << (sign + 1);
    grid[1][1] = grid[0][2];
    grid[2][0] = grid[0][2];
    return (1);
  }
  return (0);
}

int		possible_win(char grid[3][3], int sign)
{
  int		count;

  if (win_diag(grid, sign))
    return (1);
  count = 0;
  while (count < 3)
    if (win_line(grid, count, sign) || win_row(grid, count, sign))
      return (1);
    else
      count++;
  return (0);
}