/*
** surface.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 20:05:42 2012 geoffroy aubey
** Last update Sat Mar  3 20:05:42 2012 geoffroy aubey
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "graphics.h"

int	load_all_surfaces(t_graphics *g)
{
  if (add_surface(g, "data/sprites/wall.bmp", S_WALL) == -1 ||
      add_surface(g, "data/sprites/free.bmp", S_FREE) == -1 ||
      add_surface(g, "data/sprites/scale.bmp", S_SCALE) == -1 ||
      add_surface(g, "data/sprites/monster.bmp", S_MONSTER) == -1 ||
      add_surface(g, "data/sprites/exit.bmp", S_EXIT) == -1 ||
      add_surface(g, "data/sprites/player.bmp", S_PLAYER) == -1)
    return (-1);
  return (0);
}

int	add_surface(t_graphics *g, char *filename, int id)
{
  t_surface *surface;

  surface = malloc(sizeof(*surface));
  surface->id = id;
  if ((surface->surface = SDL_LoadBMP(filename)) == NULL)
    {
      fprintf(stderr, "Unable to load %s\n", filename);
      return (-1);
    }
  list_push_back(&g->surface_list, surface);
  return (0);
}

SDL_Surface *get_surface(t_graphics *g, int id)
{
  t_list list;

  list = g->surface_list;
  while (list != END)
    {
      if (((t_surface *)list->value)->id == id)
	return (((t_surface *)list->value)->surface);
      NEXT(list);
    }
  return (NULL);
}

void	delete_surfaces(t_graphics *g)
{
  t_list list;

  list = g->surface_list;
  while (list != END)
    {
      SDL_FreeSurface(((t_surface *)list->value)->surface);
      free(list->value);
      NEXT(list);
    }
  list_clear(&g->surface_list);
}
