/*
** init.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:35 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:35 2012 geoffroy aubey
*/

#include <stdlib.h>
#include "SDL/SDL.h"
#include "graphics/graphics.h"

t_graphics *create_graphics()
{
  t_graphics *g;

  g = malloc(sizeof(*g));
  g->win_x = 0;
  g->win_y = 0;
  g->screen = NULL;
  g->surface_list = NULL;
  return (g);
}

void	graphics_shutdown(t_graphics *g)
{
  delete_surfaces(g);
  SDL_Quit();
}

void	delete_graphics(t_graphics *g)
{
  if (g->screen)
    SDL_FreeSurface(g->screen);
  graphics_shutdown(g);
  free(g);
}

int	graphics_init(t_graphics *g, int win_x, int win_y)
{
  SDL_Init(SDL_INIT_VIDEO);
  g->win_y = win_x;
  g->win_x = win_y;
  if (!(g->screen = SDL_SetVideoMode(g->win_y, g->win_x, 32, SDL_HWSURFACE)))
    return (-1);
  if (load_all_surfaces(g) == -1)
    return (-1);
  camera_init(&g->cam);
  return (0);
}
