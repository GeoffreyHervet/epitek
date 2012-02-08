/*
** search_ways.c for src in /home/igix/work/lem-in/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  jeu. avril 14 08:40:58 2011 geoffrey hervet
** Last update Sat Apr 23 18:30:16 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"my_putstr.h"
#include	"search_ways.h"
#include	"search_ways_init.h"
#include	"set_way_list.h"

static int	get_update_wl(int *wait_list,
			      const int size)
{
  int		tmp;
  int		pos;

  tmp = wait_list[0];
  pos = 0;
  while (pos < (size - 1))
  {
    wait_list[pos] = wait_list[pos + 1];
    pos++;
  }
  wait_list[size - 1] = -1;
  return (tmp);
}

static void	insert_wl(int *wait_list,
			  const int val)
{
  int		pos;

  pos = 0;
  while (wait_list[pos] != -1)
    pos++;
  wait_list[pos] = val;
}

static int	find_best_way(int *search,
			      int **m,
                              int size)
{
  int		*wait_list;
  int		pos;
  int		pos2;

  if ((wait_list = init_wait_list(search, size)) == NULL || size == 0)
    return (-1);
  while ((pos = get_update_wl(wait_list, size)) != -1)
  {
    if (m[0][pos + 2] == 1)
    {
      free(wait_list);
      return (pos);
    }
    pos2 = -1;
    while (++pos2 < size)
    {
      if ((search[pos2] == -1) && (m[pos2 + 2][pos + 2] == 1))
      {
        search[pos2] = pos;
        insert_wl(wait_list, pos2);
      }
    }
  }
  free(wait_list);
  return (-1);
}

static int	direct_way(t_infos *i,
			   int *nb_ways,
                           int *nb_room_tot)
{
  if (i->matrice->tab[0][1] == 1)
  {
    *nb_ways = 1;
    if (set_way_list(i, NULL, -2, nb_room_tot))
      return (-1);
  }
  return (0);
}

int		search_ways(t_infos *i)
{
  int		*search_table;
  int		nb_ways;
  int		room;
  int		nb_room_tot;

  update_infos();
  room = 0;
  if (i->matrice == NULL || i->matrice->tab == NULL ||
      direct_way(i, &nb_ways, &nb_room_tot))
    return (-1);
  while (room != -1 && nb_room_tot < i->nb_fourm)
  {
    if ((search_table = init_search(i)) == NULL)
      return (0);
    room = find_best_way(search_table, i->matrice->tab, i->matrice->size - 2);
    if (room != -1)
      {
        if (set_way_list(i, search_table, room, &nb_room_tot))
          return (-1);
        nb_ways++;
      }
    free(search_table);
  }
  i->nb_ways = nb_ways;
  return (0);
}
