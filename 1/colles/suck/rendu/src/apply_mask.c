/*
** apply_mask.c for sudoki-bi in /u/all/hervet_g/public/suck/rendu
** 
** Made by vincent caggiari
** Login   <caggia_v@epitech.net>
** 
** Started on  Sun May  8 11:48:42 2011 vincent caggiari
** Last update Sun May  8 19:30:36 2011 vincent caggiari
*/

unsigned char			apply_mask_row(unsigned short grid[9][9],
					       const unsigned char y,
					       const unsigned char x,
					       const unsigned short mask)
{
  register unsigned char	incre_x;
  unsigned char			tracker;

  tracker = 0;
  incre_x = 0;
  while (incre_x < 9)
    {
      if ((incre_x < x / 3 * 3 || incre_x > x / 3 * 3 + 3) &&
          (grid[y][incre_x] & ~mask))
	{
	  tracker = 1;
	  grid[y][incre_x] &= mask;
	}
      ++incre_x;
    }
  return (tracker);
}

unsigned char			apply_mask_col(unsigned short grid[9][9],
					       const unsigned char y,
					       const unsigned char x,
					       const unsigned short mask)
{
  register unsigned char        incre_y;
  unsigned char			tracker;

  tracker = 0;
  incre_y = 0;
  while (incre_y < 9)
    {
       if ((incre_y < y / 3 * 3 || incre_y > y / 3 * 3 + 3) &&
          (grid[incre_y][x] & ~mask))
	{
	  tracker = 1;
	  grid[incre_y][x] &= mask;
	}
      ++incre_y;
    }
  return (tracker);
}
