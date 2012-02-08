/*
** draw_points.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec  6 16:05:09 2010 geoffrey hervet
** Last update Wed Dec  8 16:12:24 2010 geoffrey hervet
*/

#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"fdf.h"
#include	"draw_points.h"
#include	"draw_line.h"

void		draw_points(t_mlx *mlx)
{
  t_list	*tmp[2];

  tmp[0] = mlx->list;
  tmp[1] = tmp[0];
  while	(tmp[0])
    {
      while (tmp[1]->next)
	{
	  if (tmp[0]->next)
	    draw_line(mlx, *(tmp[0]->data), *(tmp[0]->next->data));
	  if (tmp[0]->bottom)
	    draw_line(mlx, *(tmp[0]->data), *(tmp[0]->bottom->data));
	  tmp[1] = tmp[1]->next;
	}
      tmp[0] = tmp[0]->bottom;
    }
}
