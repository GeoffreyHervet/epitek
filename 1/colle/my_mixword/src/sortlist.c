/*
** sortlist.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 21:50:41 2011 geoffrey hervet
** Last update Wed May 04 21:50:41 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"

#include	"sortlist.h"

void		sortlist(t_list *begin,
			 t_predicate pred)
{
  int		have_change;
  t_list	*tmp;
  void		*data;

  have_change = 1;
  while (have_change < 10)
  {
    have_change = 0;
    tmp = begin;
    while (tmp != NULL)
    {
      if (pred(tmp, tmp->next))
      {
        data = tmp->data;
        tmp->data = tmp->next->data;
        tmp->next->data = data;
        have_change = 1;
      }
      tmp = tmp->next;
    }
  } 
}
