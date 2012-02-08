/*
** my_list_size.c for my_list_size.c in /home/hervet_g//work/piscine/Jour_11
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 20 17:54:38 2010 geoffrey hervet
** Last update Wed Oct 20 18:12:48 2010 geoffrey hervet
*/

#include	"definition.h"

int		my_list_size(t_list *begin)
{
  t_list	*tmp;
  int		size;

  size = 0;
  tmp = begin;
  while (tmp != NULL)
    {
      size = size + 1;
      tmp = tmp->next;
    }
  return (size);
}
