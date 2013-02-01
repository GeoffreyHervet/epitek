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
  if (load_player(g) == -1 ||
      load_world(g) == -1 ||
      load_enemy(g) == -1)
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
  SDL_SetColorKey(surface->surface,
  		  SDL_SRCCOLORKEY,
  		  SDL_MapRGB(surface->surface->format, 255, 0, 255));
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
