/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include		<sys/types.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>

#include		"lemipc.h"
#include		"sem.h"
#include		"game/run.h"
#include		"game/alive.h"
#include		"game/move.h"
#include		"game/team_alone.h"

static int		join_game(t_process_infos *inf)
{
  unsigned int		start_point;

  LOCK_MAP(inf);
  inf->position = rand() % MAP_SIZE;
  start_point = inf->position;
  while (inf->shared->map[inf->position])
  {
    inf->position = (inf->position + 1) % MAP_SIZE;
    if (inf->position == start_point)
    {
      UNLOCK_MAP(inf);
      return (EXIT_FAILURE);
    }
  }
  inf->shared->map[inf->position] = inf->team_id;
  UNLOCK_MAP(inf);
  return (EXIT_SUCCESS);
}

static int		xmove(t_process_infos *inf, unsigned int last_pos)
{
  LOCK_MAP(inf);
  if (EXIT_FAILURE == move(inf))
  {
    inf->shared->map[last_pos] = 0;
    UNLOCK_MAP(inf);
    return (EXIT_FAILURE);
  }
  UNLOCK_MAP(inf);
  return (EXIT_SUCCESS);
}

int			game_run(t_process_infos *inf)
{
  unsigned int		last_pos;

  if (EXIT_FAILURE == join_game(inf))
  {
    fprintf(stderr, "Can't join the game :'(\n");
    return (EXIT_FAILURE);
  }
  usleep(TIME_WAIT);
  while (is_alive(inf) && !team_alone(inf))
  {
    last_pos = inf->position;
    if (EXIT_FAILURE == xmove(inf, last_pos))
      return (EXIT_FAILURE);
    if (last_pos != inf->position)
    {
      inf->shared->map[last_pos] = 0;
      inf->shared->map[inf->position] = inf->team_id;
    }
    UNLOCK_MAP(inf);
    usleep(TIME_WAIT);
  }
  inf->shared->map[inf->position] = 0;
  return (EXIT_SUCCESS);
}
