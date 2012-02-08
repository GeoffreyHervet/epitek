/*
** count_arrived_ants.c for  in /home/yau_t//local/Projets/semestre_2/lem-in/src
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Apr 15 12:40:15 2011 tom-brent yau
** Last update Fri Apr 15 12:43:55 2011 tom-brent yau
*/

#include	"types.h"

int	count_arrived_ants(t_ways *ways)
{
  t_way	*tmp;
  int	count;

  count = 0;
  while (ways)
    {
      tmp = ways->start;
      while (tmp->next)
	tmp = tmp->next;
      count += tmp->if_ant;
      ways = ways->next;
    }
  return (count);
}
