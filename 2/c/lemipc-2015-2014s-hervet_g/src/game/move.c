/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include		<stdio.h>
#include		<stdlib.h>

#include		"game/move.h"
#include		"game/get_team.h"
#include		"game/try_mv_corner.h"
#include		"game/try_mv_adjacent.h"

static tmp  tab[] =
{
  try_move_top,
  try_move_right,
  try_move_bottom,
  try_move_left
#if ENABLE_CHECK_MOVES
    ,
  try_move_corner_a,
  try_move_corner_b,
  try_move_corner_c,
  try_move_corner_d
#endif
};

static char		inarr(unsigned int need, unsigned int where[TAB_SIZE])
{
  unsigned int		idx;

  idx = 0;
  while (idx < TAB_SIZE)
    if (where[idx++] == need)
      return (1);
  return 0;
}

static int		try_move(t_process_infos *inf)
{
  unsigned int		idx;
  unsigned int		order[TAB_SIZE];
  unsigned int		tmp_val;

  idx = 0;
  while (idx < TAB_SIZE)
    order[idx++] = 0;
  idx = 0;
  while (idx < TAB_SIZE)
  {
    tmp_val = rand() % TAB_SIZE;
    while (inarr(tmp_val, order))
      tmp_val = (tmp_val + 1) % TAB_SIZE;
    order[idx] = tmp_val;
    idx++;
  }
  idx = 0;
  while (idx < TAB_SIZE)
  {
    if (EXIT_SUCCESS == tab[order[idx]](inf))
      return (EXIT_SUCCESS);
    idx++;
  }
  return (EXIT_FAILURE);
}

int			move(t_process_infos *inf)
{
  static char		consecutive_fails = 0;
  int			x;
  int			y;
  char			x_direction;
  char			y_direction;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  x_direction = (x - MAP_WIDTH / 2) > 0 ?   -1 : 1;
  y_direction = (y - MAP_HEIGHT / 2) > 0 ?  -1 : 1;
  if (MAP(inf->shared->map, x + x_direction, y + y_direction))
  {
    if (EXIT_FAILURE == try_move(inf))
    {
      ++consecutive_fails;
      if (consecutive_fails == MAX_CONSECUTIVE_FAILS)
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
  }
  inf->position = (x + x_direction) + (y + y_direction) * MAP_WIDTH;
  consecutive_fails = 0;
  return (EXIT_SUCCESS);
}
