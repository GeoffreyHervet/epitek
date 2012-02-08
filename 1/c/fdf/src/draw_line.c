/*
** draw_line.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 30 13:21:47 2010 geoffrey hervet
** Last update Wed Dec  8 16:12:05 2010 geoffrey hervet
*/

#include	<stdio.h>
#include	<mlx.h>

#include	"fdf.h"
#include	"put_pix.h"
#include	"draw_line.h"

static void	draw_line_low(t_mlx *mlx, t_coords start, t_coords end)
{
  int		x;
  unsigned int	color;

  color = mlx_get_color_value(mlx->mlx_ptr, end.color);
  if (start.x < end.x)
    {
      x = start.x - 1;
      while (++x <= end.x)
	put_pxl_to_img2(mlx,
			x,
			start.y + ((end.y - start.y) * (x - start.x)) / (end.x - start.x),
			color);
    }
  else
    {
      x = end.x - 1;
      while (++x <= start.x)
	put_pxl_to_img2(mlx,
			x,
			start.y + ((end.y - start.y) * (x - start.x)) / (end.x - start.x),
			color);
    }
}

static void	draw_line_high(t_mlx *mlx, t_coords start, t_coords end)
{
  int		y;
  int		color;

  color = mlx_get_color_value(mlx->mlx_ptr, end.color);
  if (start.y < end.y)
    {
      y = start.y - 1;
      while (++y <= end.y)
	put_pxl_to_img2(mlx,
			start.x + ((end.x - start.x) * (y - start.y)) / (end.y - start.y),
			y,
			color);
    }
  else
    {
      y= end.y - 1;
      while (++y <= start.y)
	put_pxl_to_img2(mlx,
			start.x + ((end.x - start.x) * (y - start.y)) / (end.y - start.y),
			y,
			color);
    }
}

void		draw_line(t_mlx *mlx, t_coords start, t_coords end)
{
  double	coef_dir;

  start.x++;
  start.y++;
  end.x++;
  end.y++;
  start.x = TRANS_ISO_X(start.x, start.y, start.z);
  start.y = TRANS_ISO_Y(start.x, start.y, start.z);
  end.x = TRANS_ISO_X(end.x, end.y, end.z);
  end.y = TRANS_ISO_Y(end.x, end.y, end.z);
  coef_dir = (double) (end.y - start.y) / (end.x - start.x);
  if ((coef_dir <= 1) && (coef_dir >= -1))
    draw_line_low(mlx, start, end);
  else
    draw_line_high(mlx, start, end);
}
