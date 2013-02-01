/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/
/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
 */
#include		"game/try_mv_corner.h"

int			try_move_corner_a(t_process_infos *inf)
{
  unsigned int		x;
  unsigned int		y;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  if (y > 0 && x > 0 && !inf->shared->map[x - 1 + (y - 1) * MAP_WIDTH])
  {
    inf->position = x - 1 + (y - 1) * MAP_WIDTH;
    return (EXIT_SUCCESS);
  }
  return (EXIT_FAILURE);
}

int			try_move_corner_b(t_process_infos *inf)
{
  unsigned int		x;
  unsigned int		y;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  if (y > 0 && x < (MAP_WIDTH - 1) &&
      !inf->shared->map[x + 1 + (y - 1) * MAP_WIDTH])
  {
    inf->position = x + 1 + (y - 1) * MAP_WIDTH;
    return (EXIT_SUCCESS);
  }
  return (EXIT_FAILURE);
}

int		try_move_corner_c(t_process_infos *inf)
{
  unsigned int		x;
  unsigned int		y;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  if (x > 0 && y < (MAP_HEIGHT - 1) &&
      !inf->shared->map[x - 1 + (y + 1) * MAP_WIDTH])
  {
    inf->position = x - 1 + (y + 1) * MAP_WIDTH;
    return (EXIT_SUCCESS);
  }
  return (EXIT_FAILURE);
}

int		try_move_corner_d(t_process_infos *inf)
{
  unsigned int		x;
  unsigned int		y;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  if (x < (MAP_WIDTH - 1) && y < (MAP_HEIGHT - 1) &&
      !inf->shared->map[x + 1 + (y + 1) * MAP_WIDTH])
  {
    inf->position = x + 1 + (y + 1) * MAP_WIDTH;
    return (EXIT_SUCCESS);
  }
  return (EXIT_FAILURE);
}
