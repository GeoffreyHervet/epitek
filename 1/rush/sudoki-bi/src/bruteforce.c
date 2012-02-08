/*
** bruteforce.c for sudoki-bi in /u/all/hervet_g/public/suck/rendu
** 
** Made by vincent caggiari
** Login   <caggia_v@epitech.net>
** 
** Started on  Sun May  8 22:51:51 2011 vincent caggiari
** Last update Sun May  8 23:44:14 2011 vincent caggiari
*/

unsigned char		get_best(unsigned short grid[9][9],
				 unsigned char *best_y,
				 unsigned char *best_x)
{
  unsigned char         best;
  int			incre_x;
  int			incre_y;

  best = 10;
  incre_y = -1;
  while (++incre_y < 9)
    {
      incre_x = -1;
      while (++incre_x < 9)
        {
          if (__builtin_popcount(grid[incre_y][incre_x]) > 1 &&
	      __builtin_popcount(grid[incre_y][incre_x]) - 7 < best)
            {
	      *best_x = incre_x;
	      *best_y = incre_y;
              if (__builtin_popcount(grid[incre_y][incre_x]) - 7 != 2)
		best = __builtin_popcount(grid[incre_y][incre_x]) - 7;
              else
		return (1);
            }
        }
    }
  return (best != 10);
}

char			bruteforce(unsigned short grid[9][9])
{
  unsigned char		best_y;
  unsigned char		best_x;
  unsigned short	mask;

  while (get_best(grid, &best_y, &best_x))
    {
      mask = grid[best_y][best_x];
      grid[best_y][best_x] = (1 << (__builtin_ffs(grid[best_y][best_x]) - 1));
    }
  return (0);
}
