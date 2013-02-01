/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include	"game/is_last.h"

int		is_last(t_process_infos *inf)
{
  unsigned int	idx;
  unsigned char	count;

  idx = 0;
  count = 0;
  while (idx <  MAP_SIZE)
  {
    if (inf->shared->map[idx])
    {
      if (inf->shared->map[idx] != inf->team_id)
        return (0);
      if (++count == 2)
        return (0);
    }
    ++idx;
  }
  return (1);
}

