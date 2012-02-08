/*
** my_params_in_list.c for my_params_in_list.c in /home/hervet_g//work/piscine/Jour_11
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Oct 20 13:55:33 2010 geoffrey hervet
** Last update Wed Oct 20 18:11:09 2010 geoffrey hervet
*/
#include	"definition.h"
t_list		*my_params_in_list(int ac, char **av)
{
  t_list	*begin;
  t_list	*tmp;
  int		i;

  i = 0;
  begin = NULL;
  while (i < ac)
    {
      tmp = begin;
      begin = malloc(sizeof(*begin));
      if (begin == NULL)
	{
	  my_putstr(MALLOC_ERROR_CRITICAL);
	  return (NULL);
	}
      begin->next = tmp;
      begin->data = av[i];
      i = i + 1;
    }
  return (begin);
}
