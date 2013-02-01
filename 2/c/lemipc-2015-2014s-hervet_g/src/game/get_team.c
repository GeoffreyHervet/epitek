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

#include		"game/get_team.h"

unsigned char		get_team_left(t_process_infos *inf)
{
  int			x;
  int			y;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  if (x > 0)
    return inf->shared->map[x - 1 + y * MAP_WIDTH];
  return (inf->team_id);
}

unsigned char		get_team_right(t_process_infos *inf)
{
  int			x;
  int			y;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  if (x < (MAP_WIDTH - 1))
    return inf->shared->map[(x + 1) + y * MAP_WIDTH];
  return (inf->team_id);
}

unsigned char		get_team_bottom(t_process_infos *inf)
{
  int			x;
  int			y;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  if (y < (MAP_HEIGHT - 1))
    return inf->shared->map[x + (y + 1) * MAP_WIDTH];
  return (inf->team_id);
}

unsigned char		get_team_top(t_process_infos *inf)
{
  int			x;
  int			y;

  x = IDX_TO_X(inf->position);
  y = IDX_TO_Y(inf->position);
  if (y > 0)
    return inf->shared->map[x + (y - 1) * MAP_WIDTH];
  return (inf->team_id);
}

