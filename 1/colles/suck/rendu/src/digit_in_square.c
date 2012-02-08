/*
** digit_in_square.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat May 07 00:16:50 2011 geoffrey hervet
** Last update Sun May  8 14:10:53 2011 vincent caggiari
*/

#include		"digit_in_square.h"

int			digit_in_square(const unsigned short grid[9][9],
					unsigned char coo_col,
					unsigned char coo_row,
					const unsigned short digit)
{
  coo_row = coo_row / 3 * 3;
  coo_col = coo_col / 3 * 3;
  return (
	  ((grid[coo_row][coo_col] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1) ||
	  ((grid[coo_row][coo_col + 1] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1) ||
	  ((grid[coo_row][coo_col + 2] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1) ||
	  ((grid[coo_row + 1][coo_col] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1) ||
	  ((grid[coo_row + 1][coo_col + 1] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1) ||
	  ((grid[coo_row + 1][coo_col + 2] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1) ||
	  ((grid[coo_row + 2][coo_col] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1) ||
	  ((grid[coo_row + 2][coo_col + 1] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1) ||
	  ((grid[coo_row + 2][coo_col + 2] & digit) &&
	   __builtin_popcount(grid[coo_row][coo_col]) == 1));
}
