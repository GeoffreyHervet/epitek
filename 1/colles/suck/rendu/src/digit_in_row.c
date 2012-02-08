/*
** digit_in_row.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri May 06 23:31:30 2011 geoffrey hervet
** Last update Sat May  7 02:45:21 2011 vincent caggiari
*/

#include	"digit_in_row.h"

int		digit_in_row(const unsigned short grid[9][9],
			     const unsigned char row,
			     const unsigned char num)
{
  return ((grid[row][0] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1) ||
          (grid[row][1] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1) ||
          (grid[row][2] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1) ||
          (grid[row][3] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1) ||
          (grid[row][4] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1) ||
          (grid[row][5] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1) ||
          (grid[row][6] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1) ||
          (grid[row][7] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1) ||
          (grid[row][8] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[row][0]) == 1));
}
