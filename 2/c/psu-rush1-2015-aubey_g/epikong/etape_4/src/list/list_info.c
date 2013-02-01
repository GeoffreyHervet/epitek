/*
** list_info.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:31 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:31 2012 geoffroy aubey
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void	list_dump(t_list list, t_displayer displayer)
{
  while (list != NULL)
    {
      displayer(list->value);
      list = list->next;
    }
}

t_bool	list_is_empty(t_list list)
{
  return (list == NULL ? TRUE : FALSE);
}

unsigned int	list_get_size(t_list list)
{
  unsigned int	i;

  i = 0;
  while (list != NULL)
    {
      list = list->next;
      i++;
    }
  return (i);
}
