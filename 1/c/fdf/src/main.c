/*
** main.c for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 30 13:06:45 2010 geoffrey hervet
** Last update Wed Dec  8 16:13:27 2010 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdio.h>

#include	<mlx.h>

#include	"fdf.h"
#include	"put_pix.h"
#include	"set.h"
#include	"draw_line.h"
#include	"load_file.h"
#include	"free_file.h"
#include	"load_points.h"
#include	"draw_points.h"
#include	"linker.h"

int		gere_expose(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
  return (0);
}

int		main(int ac, char **av)
{
  t_mlx		mlx;

  if (ac < 2)
    return (0);
  mlx.mlx_ptr = mlx_init();
  if (load_file(&mlx, av[1]) == -1)
    {
      write(2, "[ERROR] - The file can't be loaded...\n", 38);
      return (1);
    }
  load_points(&mlx);
  linker(&mlx);
  mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width, mlx.height, av[1]);
  mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, mlx.width, mlx.height);
  mlx.data = mlx_get_data_addr(mlx.img_ptr, &(mlx.bpp),
			       &(mlx.sizeline), &(mlx.endian));
  draw_points(&mlx);
  mlx_expose_hook(mlx.win_ptr, gere_expose, &mlx);
  mlx_loop(mlx.mlx_ptr);
  return (0);
}
