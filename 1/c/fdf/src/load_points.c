/*
** load_points.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Dec  2 20:46:48 2010 geoffrey hervet
** Last update Wed Dec  8 14:15:21 2010 geoffrey hervet
*/

#include	"fdf.h"
#include	"load_points.h"

void		load_points(t_mlx *mlx)
{
  if (mlx->list_elemt > MIN_WIDTH)
    {
      mlx->espaces_btw_pxl = 1;
      mlx->width = mlx->ppl;
      mlx->height = mlx->list_elemt;
    }
  else
    {
      mlx->espaces_btw_pxl = 500 / (mlx->list_elemt - 1);
      if (!mlx->espaces_btw_pxl)
  	mlx->espaces_btw_pxl = 1;
      mlx->width = MIN_WIDTH;
      mlx->height = mlx->list_elemt * mlx->espaces_btw_pxl;
    }
}
