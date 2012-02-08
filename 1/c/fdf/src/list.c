/*
** list.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Dec  3 13:50:38 2010 geoffrey hervet
** Last update Mon Dec  6 10:53:24 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	<stdio.h>
#include	"fdf.h"
#include	"list.h"

int		create_item_after(t_list *item, t_coords *data)
{
  if ((item->next = malloc(sizeof(*(item->next)))) == NULL)
    return (-1);
  item->next->data = data;
  item->next->next = NULL;
  item->next->bottom = NULL;
  return (0);
}

void		list_add_end(t_list *item, t_mlx *mlx)
{
  t_list	*tmp;

  item->next = NULL;
  if (! mlx->list)
    mlx->list = item;
  else
    {
      tmp = mlx->list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = item;
    }
}
