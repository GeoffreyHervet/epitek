/*
** list_get.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:34 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:34 2012 geoffroy aubey
*/

#include <stdlib.h>
#include "list.h"

void   *list_get_front(t_list list)
{
  if (list == NULL)
    return (NULL);
  return (list->value);
}

void   *list_get_back(t_list list)
{
  if (list == NULL)
    return (NULL);
  while (list->next != NULL)
    list = list->next;
  return (list->value);
}

void	*list_get_position(t_list list, unsigned int position)
{
  unsigned int i;

  i = 0;
  if (list == NULL)
    return (NULL);
  while (i < position)
    {
      list = list->next;
      if (list == NULL)
	return (NULL);
      i++;
    }
  return (list->value);
}

t_node  *list_get_first_value(t_list list, void *value, t_comparator comp)
{
  while (list != NULL)
    {
      if (comp(value, list->value) == 1)
	return (list);
      list = list->next;
    }
  return (NULL);
}
