/*
** simple_list.c for ex00 in /home/hervet_g/piscine/l/ex00
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 15:15:53 2012 geoffrey hervet
** Last update Thu Jan 05 15:15:53 2012 geoffrey hervet
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"simple_list.h"

unsigned int    list_get_size(t_list list)
{
  if (list == NULL)
    return 0;
  return 1 + list_get_size(list->next);
}

t_bool          list_is_empty(t_list list)
{
  if (list == NULL)
    return TRUE;
  return FALSE;
}

void            list_dump(t_list list)
{
  if (list != NULL)
  {
    printf("%f\n", list->value);
    list_dump(list->next);
  }
}

t_bool  list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	item;

  if (NULL == (item = malloc(sizeof(*item))))
    return FALSE;
  item->next = *front_ptr;
  item->value = elem;
  *front_ptr = item;
  return TRUE;
}

t_bool  list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_list	item;

  if (*front_ptr == NULL)
    return list_add_elem_at_front(front_ptr, elem);
  item = *front_ptr;
  while (item->next != NULL)
    item = item->next;
  if (NULL == (item->next = malloc(sizeof(*item))))
    return FALSE;
  item->next->next = NULL;
  item->next->value = elem;
  return TRUE;
}

t_bool  list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
  if (*front_ptr == NULL)
    return FALSE;
  if (!position)
    return list_add_elem_at_front(front_ptr, elem);
  return list_add_elem_at_position(&(*(front_ptr)), elem, position - 1);
}

t_bool  list_del_elem_at_front(t_list *front_ptr)
{
  t_list	item;

  if (*front_ptr == NULL)
    return FALSE;
  item = (*front_ptr)->next;
  free(*front_ptr);
  *front_ptr = item;
  if (*front_ptr == NULL)
    return FALSE;
  return TRUE;
}

t_bool  list_del_elem_at_back(t_list *front_ptr)
{
  t_list	item;

  if (*front_ptr == NULL)
    return FALSE;
  item = *front_ptr;
  if (item->next == NULL)
    return list_del_elem_at_front(front_ptr);
  do
  {
    item = item->next;
  } while (item->next->next != NULL);
  free(item->next);
  item->next = NULL;
  return TRUE;
}

t_bool  list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list	item;
  t_list	prev = NULL;

  item = *front_ptr;
  if (!position)
    return list_del_elem_at_front(front_ptr);
  if (*front_ptr == NULL)
    return FALSE;
  while (position--)
  {
    if (item->next == NULL)
      return FALSE;
    prev = item;
    item = item->next;
  }
  if (prev == NULL)
    return FALSE;
  prev->next = item->next;
  free(item);
  return TRUE;
}

/* Value Access */

double   list_get_elem_at_front(t_list list)
{
  if (list == NULL)
    return 0;
  return list->value;
}

double   list_get_elem_at_back(t_list list)
{
  if (list == NULL)
    return 0;
  if (list->next == NULL)
    return list->value;
  return list_get_elem_at_back(list);
}

double   list_get_elem_at_position(t_list list, unsigned int position)
{
  if (list == NULL)
    return 0;
  if (!position)
    return list->value;
  return list_get_elem_at_position(list, position - 1);
}

/* Node Access */

t_node  *list_get_first_node_with_value(t_list list, double value)
{
  if (list == NULL)
    return NULL;
  if (list->value == value)
    return list;
  return list_get_first_node_with_value(list, value);
}
