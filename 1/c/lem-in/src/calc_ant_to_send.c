/*
** calc_ant_to_send.c for  in /home/yau_t//local/Projets/semestre_2/lem-in/src
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr 13 13:25:59 2011 tom-brent yau
** Last update Fri Apr 15 18:31:15 2011 tom-brent yau
*/

#include	"types.h"

static void	apply_last_ants(t_ways *ways, int tmp_to_send)
{
  t_ways	*tmp;

  while (tmp_to_send > 0 && (tmp = ways))
    {
      while (tmp && tmp_to_send > 0)
	{
	  tmp_to_send--;
	  (tmp->start->if_ant)++;
	  tmp = tmp->next;
	}
    }
}

static int	count_ant_to_send(t_ways *ways)
{
  int	nb_ant;

  nb_ant = 0;
  while (ways)
    {
      nb_ant += ways->start->if_ant;
      ways = ways->next;
    }
  return (nb_ant);
}

void	calc_ant_to_send(int nb_ant, int nb_ways, t_ways *ways)
{
  int	tmp_to_send;
  t_ways	*tmp;

  tmp_to_send = nb_ant / nb_ways;
  tmp = ways;
  while (tmp)
    {
      tmp->start->if_ant = tmp_to_send;
      tmp = tmp->next;
    }
  if (count_ant_to_send(ways) < nb_ant)
    ways->start->if_ant += nb_ant - count_ant_to_send(ways);
  tmp_to_send = 0;
  tmp = ways;
  while (tmp->next)
    {
      tmp_to_send += tmp->next->nb_room - tmp->nb_room;
      tmp->next->start->if_ant -= tmp->next->nb_room - tmp->nb_room;
      if (tmp->next->start->if_ant < 0)
	tmp->next->start->if_ant = 0;
      tmp = tmp->next;
    }
  apply_last_ants(ways, tmp_to_send);
}
