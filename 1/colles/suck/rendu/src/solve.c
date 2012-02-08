/*
** solve.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun May 08 08:57:35 2011 geoffrey hervet
** Last update Sun May  8 22:51:41 2011 vincent caggiari
*/

#include	"change_map.h"
#include	"get_digit.h"
#include	"is_alone.h"
#include	"update_digit.h"
#include	"solve.h"
#include	"bruteforce.h"

static unsigned char		check_alone(unsigned short grid[9][9],
					    const unsigned short y,
                                            const unsigned short x)
{
  register unsigned short	val;

  val = 0;
  while (val < 9)
    {
      if ((grid[y][x] & (1 << val)) &&
	  is_alone(grid, y, x, (1 << val)))
	{
	  update_digit(grid, y, x, val + 1);
	  return (1);
	}
      val++;
    }
  return (0);
}

static unsigned char		unique_solutions(unsigned short grid[9][9])
{
  register unsigned char	ret;
  register unsigned char	y;
  register unsigned char	x;

  ret = 0;
  y = 0;
  while (y < 9)
  {
    x = 0;
    while (x < 9)
    {
      if (__builtin_popcount(grid[y][x]) == 8)
      {
        update_digit(grid, y, x, GET_DIGIT(grid[y][x]));
        ret = 1;
      }
      else if (__builtin_popcount(grid[y][x]) != 1)
        ret += check_alone(grid, y, x);
      x++;
    }
    y++;
  }
  if (ret == 0)
    return (0);
  return (unique_solutions(grid));
}

int		solve(unsigned short grid[9][9])
{
  unique_solutions(grid);
  while (change_map(grid))
    unique_solutions(grid);
  bruteforce(grid);
  return (0);
}
