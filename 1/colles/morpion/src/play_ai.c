/*
** header for norme in /
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.eu>
**
** Started on  Mon Jan 01 00:00:00 2011 geoffrey hervet
** Last update Wed May 25 22:56:55 2011 tracy nelcha
*/

#include	"play_ai.h"
#include	"possible_win.h"

#define		OWN_CASE(x) (((x) & (1 << (sign + 1))) ? 1 : 0)

static int	count_diag(char grid[3][3], int y, int x, char sign)
{
  if (y == 1 && x == 1)
    return ((!OWN_CASE(grid[0][0]) && grid[0][0])
          + (!OWN_CASE(grid[1][1]) && grid[1][1])
          + (!OWN_CASE(grid[2][2]) && grid[2][2])
          + (!OWN_CASE(grid[0][2]) && grid[0][2])
          + (!OWN_CASE(grid[1][1]) && grid[1][1])
          + (!OWN_CASE(grid[2][0]) && grid[2][0]));
  if (y == x)
    return ((!OWN_CASE(grid[0][0]) && grid[0][0])
          + (!OWN_CASE(grid[1][1]) && grid[1][1])
          + (!OWN_CASE(grid[2][2]) && grid[2][2]));
  return ((!OWN_CASE(grid[0][2]) && grid[0][2])
          + (!OWN_CASE(grid[1][1]) && grid[1][1])
          + (!OWN_CASE(grid[2][0]) && grid[2][0]));
}

static int	nb_counter(char grid[3][3], int y, int x, char sign)
{
  int		ret;
  int		count;

  ret = 0;
  if (x == y || (!y && x == 2) || (!x && y == 2))
    ret += count_diag(grid, y, x, sign);
  count = 0;
  while (count < 3)
  {
    if (!OWN_CASE(grid[(y + count) % 3][x]) && grid[(y + count) % 3][x])
      ret++;
    if (!OWN_CASE(grid[y][(x + count) % 3]) && grid[y][(x + count) % 3])
      ret++;
    count++;
  }
  return (ret);
}

int		play_ai(char grid[3][3], char sign)
{
  t_ai		ai;

  if (possible_win(grid, sign))
    return (1);
  ai.y = 0;
  ai.coo[2] = 0;
  while (ai.y < 3)
  {
    ai.x = 0;
    while (ai.x < 3) {
      if (!grid[ai.y][ai.x])
      {
        ai.tmp = nb_counter(grid, ai.y, ai.x, sign);
        if (ai.tmp > ai.coo[2])
        {
          ai.coo[0] = ai.y;
          ai.coo[1] = ai.x;
        }
      }
      ai.x++;
    }
    ai.y++;
  }
  grid[ai.coo[0]][ai.coo[1]] = 1 << (1 + sign);
  return (0);
}
