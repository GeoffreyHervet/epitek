/*
** get_id.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Apr 11 18:55:16 2011 geoffrey hervet
** Last update Sat Apr 23 18:29:00 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"get_id.h"
#include	"my_strcmp.h"

int		get_max_id(t_list *begin)
{
  static t_list	*save_begin = NULL;
  static int	max = -1;
  t_list	*tmp;

  if (save_begin != begin)
    save_begin = begin;
  if (save_begin == NULL)
  {
    max = -1;
    return (0);
  }
  if (max != -1)
    return (max);
  tmp = begin;
  while (tmp != NULL)
  {
    max = MAX(max, ((t_room *)tmp->data)->id);
    tmp = tmp->next;
  }
  return (max);
}

t_room		*get_id(const t_list *begin,
		        const char *name)
{
  while (begin != NULL)
  {
    if (!my_strcmp(((t_room *)begin->data)->name, name))
      return ((t_room *)begin->data);
    begin = begin->next;
  }
  return (NULL);
}
