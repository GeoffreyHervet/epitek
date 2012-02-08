/*
** update_digit.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat May 07 02:19:05 2011 geoffrey hervet
** Last update Sat May 07 02:19:05 2011 geoffrey hervet
*/

#include		"update_digit.h"

static void			update_row(unsigned short grid[9][9],
					   const unsigned char row,
					   const unsigned short val)
{
  grid[row][0] &= val;
  grid[row][1] &= val;
  grid[row][2] &= val;
  grid[row][3] &= val;
  grid[row][4] &= val;
  grid[row][5] &= val;
  grid[row][6] &= val;
  grid[row][7] &= val;
  grid[row][8] &= val;
}

static void			update_col(unsigned short grid[9][9],
					   const unsigned char col,
					   const unsigned short val)
{
  grid[0][col] &= val;
  grid[1][col] &= val;
  grid[2][col] &= val;
  grid[3][col] &= val;
  grid[4][col] &= val;
  grid[5][col] &= val;
  grid[6][col] &= val;
  grid[7][col] &= val;
  grid[8][col] &= val;
}

static void 			update_square(unsigned short grid[9][9],
					      const unsigned char row,
					      const unsigned char col,
					      const unsigned short val)
{
  grid[row][col] &= val;
  grid[row][col + 1] &= val;
  grid[row][col + 2] &= val;
  grid[row + 1][col] &= val;
  grid[row + 1][col + 1] &= val;
  grid[row + 1][col + 2] &= val;
  grid[row + 2][col] &= val;
  grid[row + 2][col + 1] &= val;
  grid[row + 2][col + 2] &= val;
}

void				update_digit(unsigned short grid[9][9],
					     const unsigned char row,
					     const unsigned char col,
					     unsigned short val)
{
  val = 1 << (val - 1);
  update_col(grid, col, ~val);
  update_row(grid, row, ~val);
  update_square(grid, row / 3 * 3, col / 3 * 3, ~val);
  grid[row][col] = val;
}
