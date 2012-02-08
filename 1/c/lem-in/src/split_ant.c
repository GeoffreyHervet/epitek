/*
** split_ant.c for  in /home/yau_t//local/Projets/semestre_2/lem-in/src
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue Apr 12 19:22:53 2011 tom-brent yau
** Last update Sat Apr 23 18:27:31 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"calc_ant_to_send.h"
#include	"count_arrived_ants.h"
#include	"my_printf.h"
#include	"split_ant.h"
#include	"xmalloc.h"

static t_list_to_print	*display_ll_print(t_list_to_print *list)
{
  void		*adr;

  while (list)
    {
      my_printf("P%d-%s", list->ant_id, list->name);
      if (list->next)
	my_printf(" ");
      adr = list->next;
      free(list);
      list = adr;
    }
  my_printf("\n");
  return (NULL);
}

static t_list_to_print	*add_node(t_list_to_print *list,
    				  int ant_id,
                                  char *name)
{
  t_list_to_print	*new;
  t_list_to_print	*tmp;

  tmp = list;
  new = xmalloc(sizeof(*new));
  new->ant_id = ant_id;
  new->name = name;
  new->next = NULL;
  if (list == NULL)
    return (new);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (list);
}

static t_list_to_print	*print_move(t_way *start, t_way *tmp,
			    int *high_ant_id, t_list_to_print *ll_print)
{
  if (tmp->next == NULL)
    {
      tmp->if_ant++;
      if (tmp->prev && tmp->prev->prev)
	ll_print = add_node(ll_print , tmp->prev->ant_id, tmp->room->name);
      else if (start->if_ant > 0)
	{
	  (start->if_ant)--;
	  ll_print = add_node(ll_print, (*high_ant_id)++, tmp->room->name);
	}
    }
  else if (tmp->prev && tmp->prev->prev)
    {
      tmp->if_ant = 1;
      tmp->ant_id = tmp->prev->ant_id;
      ll_print = add_node(ll_print, tmp->ant_id, tmp->room->name);
    }
  else if (start->if_ant > 0)
    {
      (start->if_ant)--;
      tmp->if_ant = 1;
      tmp->ant_id = (*high_ant_id)++;
      ll_print = add_node(ll_print, tmp->ant_id, tmp->room->name);
    }
  return (ll_print);
}

static t_list_to_print	*move_ants(t_way *start,
				   int *high_ant_id,
                                   t_list_to_print *ll_print)
{
  t_way		*tmp;

  if (start == NULL || (start->next == NULL && start->prev == NULL))
    return (ll_print);
  tmp = start;
  while (tmp->next)
    tmp = tmp->next;
  while (tmp->prev->prev && tmp->prev->if_ant == 0)
    tmp = tmp->prev;
  while (tmp->prev)
    {
      if (tmp->prev->if_ant == 0 && tmp->next)
	tmp->if_ant = 0;
      if (tmp->prev->if_ant)
	ll_print = print_move(start, tmp, high_ant_id, ll_print);
      tmp = tmp->prev;
    }
  return (ll_print);
}

void		split_ant(t_infos *info)
{
  int			arrived_ants;
  int			ant_at_start;
  int			high_ant_id;
  t_ways		*tmp;
  t_list_to_print	*ll_print;

  ll_print = NULL;
  arrived_ants = 0;
  high_ant_id = 1;
  ant_at_start = info->nb_fourm;
  calc_ant_to_send(info->nb_fourm, info->nb_ways, info->ways);
  while (info->nb_fourm > arrived_ants)
    {
      ll_print = move_ants(info->ways->start, &high_ant_id, ll_print);
      tmp = info->ways->next;
      while (info->nb_ways > 1 && tmp)
	{
	  ll_print = move_ants(tmp->start, &high_ant_id, ll_print);
	  tmp = tmp->next;
	}
      ll_print = display_ll_print(ll_print);
      arrived_ants = count_arrived_ants(info->ways);
    }
}
