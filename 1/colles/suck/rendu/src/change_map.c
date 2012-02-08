/*
** change_line.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun May 08 11:22:35 2011 geoffrey hervet
** Last update Sun May  8 19:36:22 2011 vincent caggiari
*/

#include			"apply_mask.h"
#include			"change_map.h"
#include			"digit_in_col.h"
#include			"digit_in_row.h"
#include			"digit_in_square.h"

static unsigned char		other_row(unsigned short grid[9][9],
					  const unsigned char y,
					  const unsigned char x,
					  const unsigned char digit)
{
  register unsigned char	incre_x;

  incre_x = x / 3 * 3;
  while (incre_x < x / 3 * 3 + 3)
    {
      if (incre_x != x && 0x1 & (grid[y][incre_x] >> (digit - 1)))
	return (1);
      ++incre_x;
    }
  return (0);
}

static unsigned char		other_col(unsigned short grid[9][9],
					  const unsigned char y,
					  const unsigned char x,
					  const unsigned char digit)
{
  register unsigned char	incre_y;

  incre_y = y / 3 * 3;
  while (incre_y < y / 3 * 3 + 3)
    {
      if (incre_y != y && 0x1 & (grid[incre_y][x] >> (digit - 1)))
        return (1);
      ++incre_y;
    }
  return (0);
}

static unsigned char		in_banned_case(unsigned short grid[9][9],
					       const unsigned char y,
					       const unsigned char x,
					       const unsigned char digit)
{
  register unsigned char	incre_x;
  register unsigned char	incre_y;

  incre_y = y / 3 * 3;
  while (incre_y < y / 3 * 3 + 3)
    {
      incre_x = x / 3 * 3;
      while (incre_x < x / 3 * 3 + 3)
	{
	  if (y != incre_y && x != incre_x &&
	      0x1 & (grid[incre_y][incre_x] >> (digit - 1)))
	    return (1);
	  ++incre_x;
	}
      ++incre_y;
    }
  return (0);
}

static unsigned char		try_mask(unsigned short grid[9][9],
					 const unsigned char y,
					 const unsigned char x,
					 const unsigned char digit)
{
  unsigned char			in_row;
  unsigned char			in_col;

  if (!in_banned_case(grid, y, x, digit))
    {
      in_row = other_row(grid, y, x, digit);
      in_col = other_col(grid, y, x, digit);
      if ((in_row == 1 && in_col == 0 &&
	   apply_mask_row(grid, y, x, ~(1 << (digit - 1)))) ||
	  (in_row == 0 && in_col == 1 &&
	   apply_mask_col(grid, y, x, ~(1 << (digit - 1)))))
	return (1);
    }
  return (0);
}

unsigned char			change_map(unsigned short grid[9][9])
{
  register int			x;
  register int			y;
  register int			idx;
  unsigned char			tracker;

  tracker = 0;
  y = -1;
  while (++y < 9)
    {
      x = -1;
      while (++x < 9)
	{
	  if (__builtin_popcount(grid[y][x]) != 1)
	    {
	      idx = -1;
	      while (++idx < 9)
                if (0x1 & (grid[y][x] >> idx) &&
                    try_mask(grid, y, x, idx + 1))
                  tracker = 1;
	    }
	}
    }
  return (tracker);
}
