/*
** set.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 30 13:12:26 2010 geoffrey hervet
** Last update Mon Dec  6 18:31:37 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"fdf.h"
#include	"set.h"

t_coords	set_coords(int x, int y, int z, unsigned int color)
{
  t_coords	coords;

  coords.x = x;
  coords.y = y;
  coords.z = z;
  coords.color = color;
  return (coords);
}

int		set_data_in_list(t_coords coo, t_list *item)
{
  if (!item)
    if ((item = malloc(sizeof(*item))) == NULL)
      return (-1);
  if ((item->data = malloc(sizeof(*(item->data)))) == NULL)
    return (-1);
  item->data->x = TRANS_ISO_X(coo.x, coo.y, coo.z);
  item->data->y = TRANS_ISO_Y(coo.x, coo.y, coo.z);
  item->next = NULL;
  item->bottom = NULL;
  return (0);
}
