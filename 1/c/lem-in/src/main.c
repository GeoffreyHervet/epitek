/*
** main.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  lun. avril 11 10:25:34 2011 geoffrey hervet
** Last update Sat Apr 23 18:30:04 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"types.h"
#include	"fill_matrice.h"
#include	"my_putstr.h"
#include	"next_line.h"
#include	"save_item.h"
#include	"search_ways.h"
#include	"split_ant.h"

static void	free_ways(t_ways *w)
{
  t_ways	*tmp;
  t_way		*tmp2;

  while (w != NULL)
  {
    while (w->start != NULL)
    {
      tmp2 = w->start;
      w->start = w->start->next;
      free(tmp2);
    }
    tmp = w;
    w = w->next;
    free(tmp);
  }
}

static void	free_all(t_infos *i)
{
  t_list	*tmp;
  int		count;

  count = 0;
  while (count < i->matrice->size)
    free(i->matrice->tab[count++]);
  free(i->matrice->tab);
  free(i->matrice->corresp);
  free(i->matrice);
  tmp = i->rooms;
  while (i->rooms != NULL)
  {
    tmp = i->rooms;
    i->rooms = i->rooms->next;
    free(((t_room *)(tmp->data))->name);
    free(tmp->data);
    free(tmp);
  }
  free_ways(i->ways);
}

static void	init_infos(t_infos *infos)
{
  infos->rooms = NULL;
  infos->start = NULL;
  infos->end = NULL;
  infos->ways = NULL;
  infos->nb_fourm = 0;
  infos->matrice = NULL;
}

int		main(void)
{
  int		ret;
  t_line	line;
  t_infos	infos;

  init_infos(&infos);
  while ((ret = next_line(&line)) != 1)
    if (ret == -1)
      return (EXIT_FAILURE);
    else if (line.type != T_TUBE)
    {
      if (save_item(&line, &infos) == -1)
        return (EXIT_FAILURE);
    }
    else if (fill_matrice(&line, &infos))
      return (EXIT_FAILURE);
  if (infos.rooms == NULL || search_ways(&infos) == -1)
    return (EXIT_FAILURE);
  if (infos.nb_ways)
    split_ant(&infos);
  else
    my_putstr("No ways found ...\n", 2);
  free_all(&infos);
  return (EXIT_SUCCESS);
}
