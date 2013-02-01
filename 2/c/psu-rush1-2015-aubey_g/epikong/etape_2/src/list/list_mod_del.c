/*
** list_mod_del.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:26 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:26 2012 geoffroy aubey
*/

#include <stdlib.h>
#include "list.h"

t_bool  list_del_front(t_list *front_ptr)
{
  t_list save;
  t_list list;

  if (front_ptr == NULL || *front_ptr == NULL)
    return (FALSE);
  list = *front_ptr;
  save = list->next;
  free(list);
  *front_ptr = save;
  return (TRUE);
}

t_bool  list_del_back(t_list *front_ptr)
{
  t_list list;

  if (front_ptr == NULL || *front_ptr == NULL)
    return (FALSE);
  list = *front_ptr;
  if (list->next == NULL)
    {
      free(*front_ptr);
      *front_ptr = NULL;
      return (TRUE);
    }
  while (list->next->next != NULL)
    list = list->next;
  free(list->next);
  list->next = NULL;
  return (TRUE);
}

t_bool  list_del_position(t_list *front_ptr, unsigned int position)
{
  unsigned int i;
  t_list	list;
  t_list	save;

  if (position == 0)
    return (list_del_front(front_ptr));
  list = *front_ptr;
  save = *front_ptr;
  i = 1;
  list = list->next;
  while (i < position)
    {
      if (list == NULL)
	return (FALSE);
      list = list->next;
      save = save->next;
      i++;
    }
  save->next = list->next;
  free(list);
  return (TRUE);
}

t_bool  list_del_value(t_list *front_ptr, void *value)
{
  t_list	list;
  t_list	save;

  list = *front_ptr;
  save = *front_ptr;
  if (list->value == value)
    return (list_del_front(front_ptr));
  list = list->next;
  while (list->value != value)
    {
      if (list == NULL)
	return (FALSE);
      list = list->next;
      save = save->next;
    }
  save->next = list->next;
  free(list);
  return (TRUE);
}

void    list_clear(t_list *front_ptr)
{
  while (list_del_front(front_ptr) == TRUE)
    ;
}
