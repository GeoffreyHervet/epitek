/*
** search_ways_init.c for src in /home/igix/work/lem-in/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  jeu. avril 14 11:58:54 2011 geoffrey hervet
** Last update Sat Apr 23 18:30:29 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"search_ways_init.h"

int		*init_wait_list(const int *srch,
				const int size)
{
  int		*wl;
  int		pos;
  int		pos2;

  if ((wl = malloc(sizeof(*wl) * size)) == NULL)
    return (NULL);
  pos = 0;
  pos2 = 0;
  while (pos < size)
  {
    if (srch[pos] == -2)
      wl[pos2++] = pos;
    pos++;
  }
  while (pos2 < size)
    wl[pos2++] = -1;
  return (wl);
}

int		*init_search(const t_infos *infos)
{
  int		*srch;
  int		pos;

  if ((srch = malloc(sizeof(*srch) * (infos->matrice->size - 2))) == NULL)
    return (NULL);
  pos = 0;
  while (pos < infos->matrice->size - 2)
  {
    srch[pos] = (infos->matrice->tab[1][pos + 2] == 1) ? -2 : -1;
    pos++;
  }
  return (srch);
}
