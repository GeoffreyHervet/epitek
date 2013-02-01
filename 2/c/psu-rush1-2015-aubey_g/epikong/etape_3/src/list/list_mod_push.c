/*
** list_mod_push.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:21 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:21 2012 geoffroy aubey
*/

#include <stdlib.h>
#include "list.h"

t_bool		list_push_front(t_list *front_ptr, void *elem)
{
  t_node	*new_node;

  if ((new_node = malloc(sizeof(*new_node))) == NULL)
    return (FALSE);
  new_node->value = elem;
  new_node->next = *front_ptr;
  *front_ptr = new_node;
  return (TRUE);
}

t_bool		list_push_back(t_list *front_ptr, void *elem)
{
  t_node	*new_node;
  t_list	list;

  if ((new_node = malloc(sizeof(*new_node))) == NULL)
    return (FALSE);
  new_node->value = elem;
  new_node->next = NULL;
  list = *front_ptr;
  if (*front_ptr != NULL)
    {
      while (list->next != NULL)
	list = list->next;
      list->next = new_node;
    }
  else
    *front_ptr = new_node;
  return (TRUE);
}

t_bool		list_push_position(t_list *front_ptr, void *elem,
				   unsigned int position)
{
  t_node	*new_node;
  t_list	list;
  t_list	save;
  unsigned int		i;

  i = 0;
  if (position == 0)
    return (list_push_front(front_ptr, elem));
  if ((new_node = malloc(sizeof(*new_node))) == NULL)
    return (FALSE);
  new_node->value = elem;
  new_node->next = NULL;
  list = *front_ptr;
  while (i < position)
    {
      if (list == NULL)
	return (FALSE);
      i++;
      if (i != position)
	list = list->next;
    }
  save = list->next;
  list->next = new_node;
  new_node->next = save;
  return (TRUE);
}
