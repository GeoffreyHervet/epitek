/*
** put_pix.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 30 13:09:42 2010 geoffrey hervet
** Last update Mon Dec  6 10:54:44 2010 geoffrey hervet
*/

#include	"fdf.h"
#include	"put_pix.h"

void		put_pxl_to_img(t_mlx *mlx, t_coords coords, unsigned int color)
{
  int		pos;

  if (coords.x < 0 || coords.y < 0 ||
      coords.x > mlx->width || coords.y > mlx->height)
    return ;
  pos = -1;
  while (++pos < mlx->bpp / 8)
    *(mlx->data + (int) coords.y * mlx->sizeline
      + (int) coords.x * (mlx->bpp / 8) + pos) =
      *((char *)(&color) + pos);
}

void		put_pxl_to_img2(t_mlx *mlx, int x, int y, unsigned int color)
{
  int		pos;

  if (x < 0 || y < 0 || x > mlx->width || y > mlx->height)
    return ;
  pos = -1;
  while (++pos < mlx->bpp / 8)
    *(mlx->data + y * mlx->sizeline + x * (mlx->bpp / 8) + pos) =
      *((char *)(&color) + pos);
}
