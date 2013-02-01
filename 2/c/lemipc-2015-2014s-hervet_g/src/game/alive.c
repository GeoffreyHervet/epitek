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

#include		"game/alive.h"
#include		"game/get_team.h"

char			is_alive(t_process_infos *inf)
{
  unsigned char		teams[4];
  int			idx1;
  int			idx2;

  teams[0] = get_team_left(inf);
  teams[1] = get_team_right(inf);
  teams[2] = get_team_bottom(inf);
  teams[3] = get_team_top(inf);
  idx1 = 0;
  while (idx1 < 4)
  {
    if (teams[idx1] != 0 && teams[idx1] != inf->team_id)
    {
      idx2 = idx1 + 1;
      while (idx2 < 4)
      {
        if (teams[idx2] == teams[idx1])
          return (0);
        idx2++;
      }
    }
    idx1++;
  }
  return (1);
}
