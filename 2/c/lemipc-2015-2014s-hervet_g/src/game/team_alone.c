/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include	"sem.h"
#include	"game/team_alone.h"

int		team_alone(t_process_infos *inf)
{
  static char	round_alone = 0;
  unsigned int	idx;

  idx = 0;
  LOCK_MAP(inf);
  while (idx < MAP_SIZE)
  {
    if (inf->shared->map[idx] != inf->team_id &&
        inf->shared->map[idx] != 0)
    {
      UNLOCK_MAP(inf);
      round_alone = 0;
      return (0);
    }
    idx++;
  }
  round_alone++;
  if (round_alone < ROUND_ALONE_MAX)
    return (0);
  return (1);
}
