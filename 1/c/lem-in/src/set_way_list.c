/*
** set_way_list.c for src in /home/igix/work/lem-in/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  jeu. avril 14 23:32:16 2011 geoffrey hervet
** Last update Sat Apr 23 18:30:44 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"set_way_list.h"

static int	add_room_way(t_way **begin,
			     t_room *room)
{
  t_way		*item;

  if ((item = malloc(sizeof(*item))) == NULL)
    return (-1);
  item->if_ant = 0;
  item->ant_id = 0;
  item->room = room;
  item->prev = NULL;
  item->next = *begin;
  if (*begin != NULL)
    (*begin)->prev = item;
  *begin = item;
  return (0);
}

static void	del_to_mat(int **tab,
			   int size,
                           int pos)
{
  int		pos2;

  pos2 = 0;
  while (pos2 < size)
  {
    tab[pos2][pos] = -1;
    tab[pos][pos2] = -1;
    pos2++;
  }
}

static t_ways	*create_t_ways(t_infos *i,
			       int *search,
			       int r,
                               int *nb_room_tot)
{
  int		nb_rooms;
  t_way		*way;
  t_ways	*ret;

  if ((ret = malloc(sizeof(*ret))) == NULL)
    return (NULL);
  nb_rooms = 0;
  way = NULL;
  if (add_room_way(&way, i->end))
    return (NULL);
  while (r != -2)
  {
    del_to_mat(i->matrice->tab, i->matrice->size, r + 2);
    nb_rooms++;
    if (add_room_way(&way, i->matrice->corresp[r + 2]))
      return (NULL);
    r = search[r];
  }
  if (add_room_way(&way, i->start))
    return (NULL);
  ret->nb_room = nb_rooms;
  *nb_room_tot = *nb_room_tot + nb_rooms;
  ret->to_send = 0;
  ret->start = way;
  return (ret);
}

int		set_way_list(t_infos *i,
			     int *search,
	                     int r,
                             int *nb_room_tot)
{
  t_ways	*item;
  t_ways	*tmp;

  if ((item = create_t_ways(i, search, r, nb_room_tot)) == NULL)
    return (-1);
  item->next = NULL;
  if ((tmp = i->ways) == NULL)
  {
    i->ways = item;
    return (0);
  }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = item;
  return (0);
}
