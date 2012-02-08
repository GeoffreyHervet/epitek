/*
** digit_in_col.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri May 06 23:16:36 2011 geoffrey hervet
** Last update Sat May  7 02:45:30 2011 vincent caggiari
*/

#include	"digit_in_col.h"

int		digit_in_col(const unsigned short grid[9][9],
			     const unsigned char col,
			     const unsigned char num)
{
  return ((grid[0][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[0][col]) == 1) ||
          (grid[1][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[1][col]) == 1) ||
          (grid[2][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[2][col]) == 1) ||
          (grid[3][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[3][col]) == 1) ||
          (grid[4][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[4][col]) == 1) ||
          (grid[5][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[5][col]) == 1) ||
          (grid[6][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[6][col]) == 1) ||
          (grid[7][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[7][col]) == 1) ||
          (grid[8][col] & (1 << (num - 1)) &&
	   __builtin_popcount(grid[8][col]) == 1));
}
