/*
** is_alone.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/suck/rendu/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat May 07 13:57:44 2011 geoffrey hervet
** Last update Sun May  8 22:41:56 2011 vincent caggiari
*/

inline static short		check_row(const unsigned short grid[9][9],
    const unsigned short y,
    const unsigned short x,
    const unsigned short mask)
{
  return (
      (x != 0 && grid[y][0] & mask) ||
      (x != 1 && grid[y][1] & mask) ||
      (x != 2 && grid[y][2] & mask) ||
      (x != 3 && grid[y][3] & mask) ||
      (x != 4 && grid[y][4] & mask) ||
      (x != 5 && grid[y][5] & mask) ||
      (x != 6 && grid[y][6] & mask) ||
      (x != 7 && grid[y][7] & mask) ||
      (x != 8 && grid[y][8] & mask));
}

inline static short		check_col(const unsigned short grid[9][9],
    const unsigned short y,
    const unsigned short x,
    const unsigned short mask)
{
  return ((y != 0 && grid[0][x] & mask) ||
      (y != 1 && grid[1][x] & mask) ||
      (y != 2 && grid[2][x] & mask) ||
      (y != 3 && grid[3][x] & mask) ||
      (y != 4 && grid[4][x] & mask) ||
      (y != 5 && grid[5][x] & mask) ||
      (y != 6 && grid[6][x] & mask) ||
      (y != 7 && grid[7][x] & mask) ||
      (y != 8 && grid[8][x] & mask));
}

inline static short             check_square(const unsigned short grid[9][9],
    const unsigned char y,
    const unsigned char x,
    unsigned short mask)
{
  unsigned char         sqx = x / 3 * 3;
  unsigned char         sqy = y / 3 * 3;
  unsigned char         yy;
  unsigned char         xx;

  yy = sqy;
  while (yy <= (sqy + 2))
  {
    xx = sqx;
    while (xx <= (sqx + 2))
    {
      if (x == xx && y == yy);
      else if (grid[yy][xx] & mask)
        return (1);
      xx++;
    }
    yy++;
  }
  return (0);
}

int				is_alone(const unsigned short grid[9][9],
					 const unsigned short y,
                		         const unsigned short x,
		                         unsigned short val)
{
  register unsigned short	ret1;
  register unsigned short	ret2;
  register unsigned short	ret3;

  ret2 = !check_col(grid, y, x, val);
  ret1 = !check_row(grid, y, x, val);
  ret3 = !check_square(grid, y, x, val);

  return (ret1 || ret2 || ret3);
}
