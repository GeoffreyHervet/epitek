/*
** init_list.h for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Jan 14 17:37:05 2011 geoffrey hervet
** Last update Sat Jan 15 15:34:36 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"libmy.h"

#include	"my_select.h"
#include	"init/init_list.h"

static int	put_inlist(t_infos *inf,
			   const char *data)
{
  t_list_db	*item;

  if ((item = malloc(sizeof(*item))) == NULL)
    return (-1);
  item->data = data;
  item->flags = 0;
  if (inf->begin == NULL)
    inf->begin = item;
  else
    item->prev = inf->begin->prev;
  inf->begin->prev = item;
  item->prev->next = item;
  item->next = inf->begin;
  if (inf->min_w < (signed int)my_strlen(data))
    inf->min_w = my_strlen(data);
  item->coords.col = 0;
  item->coords.row = 0;
  return (0);
}

int		init_list(t_infos *inf,
			  const int ac,
			  const char **av)
{
  int		idx;

  if (ac == 1)
    {
      my_putstr("Usage : ", 2);
      my_putstr(av[0], 2);
      my_putstr(" item [, ... ]\n", 2);
      return (-1);
    }
  inf->min_w = 0;
  idx = 0;
  inf->begin = NULL;
  while (++idx != ac)
    if (!put_inlist(inf, av[idx]) == -1)
      {
	my_putstr(ERR_MALLOC, 2);
	return (-1);
      }
  inf->begin->flags = FL_HOVER;
  return (0);
}
