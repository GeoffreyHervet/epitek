/*
** update_matrice.c for src in /home/hervet_g/lemin/lem-in/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Apr 13 17:40:21 2011 geoffrey hervet
** Last update Sat Apr 23 18:31:00 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"get_id.h"
#include	"my_printf.h"
#include	"update_matrice.h"

static int	get_posofid(const t_matrice *m,
			    const int id)
{
  int		pos;

  pos = m->size;
  while (--pos >= 0)
    if (m->corresp[pos] != NULL && (m->corresp[pos]->id == id))
      return (pos);
  return (-1);
}

static int	get_nextfreepos(const t_matrice *m)
{
  int		pos;

  pos = m->size;
  while (--pos > 1)
    if (m->corresp[pos] == NULL)
      return (pos);
  return (-1);
}

static int	id_idx_manager(t_infos *infos,
			       t_room *room)
{
  int		ret;

  if  ((ret = get_posofid(infos->matrice, room->id)) != -1)
    return (ret);
  if (room == infos->start || room == infos->end)
    ret = (room == infos->start) ? 1 : 0;
  else
    ret = get_nextfreepos(infos->matrice);
  infos->matrice->corresp[ret] = room;
  return (ret);
}

int		update_matrice(t_infos *infos,
			       t_line *line)
{
  t_room	*ids[2];
  int		idx;
  int		tmp[1];

  idx = 0;
  while (line->strline[idx] && line->strline[idx] != '-')
    idx++;
  if (!line->strline[idx])
    return (-1);
  line->strline[idx] = 0;
  if ((ids[0] = get_id(infos->rooms, line->strline)) == NULL)
  {
    my_printf("Room %s not found\n", line->strline);
    return (-1);
  }
  if ((ids[1] = get_id(infos->rooms, &(line->strline[idx + 1]))) == NULL)
  {
    my_printf("Room %s not found\n", line->strline);
    return (-1);
  }
  tmp[0] = id_idx_manager(infos, ids[0]);
  tmp[1] = id_idx_manager(infos, ids[1]);
  infos->matrice->tab[tmp[0]][tmp[1]] = 1;
  infos->matrice->tab[tmp[1]][tmp[0]] = 1;
  return (0);
}

