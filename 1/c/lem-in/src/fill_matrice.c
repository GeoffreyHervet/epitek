/*
** fill_matrice.c for src in /home/hervet_g/lemin/lem-in/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Apr 12 19:08:21 2011 geoffrey hervet
** Last update Sat Apr 23 18:28:26 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"types.h"
#include	"create_matrice.h"
#include	"fill_matrice.h"
#include	"get_id.h"
#include	"my_putstr.h"
#include	"update_matrice.h"

static int	check_error(const t_infos *infos)
{
  if (infos->start == NULL || infos-> end == NULL)
  {
    my_putstr((infos->start == NULL) ? ERR_START : ERR_END, 2);
    return (-1);
  }
  return (0);
}

static int	init_matrice(t_infos *infos)
{
  if (check_error(infos))
    return (-1);
  if ((create_matrice(infos)) == -1)
  {
    my_putstr(ERR_MALLOC, 2);
    return (-1);
  }
  return (0);
}

int	  	fill_matrice(t_line *line,
			     t_infos *infos)
{
  if (infos->matrice == NULL)
    if (init_matrice(infos))
      return (-1);
  if (update_matrice(infos, line))
    return (-1);
  free(line->strline);
  return (0);
}
