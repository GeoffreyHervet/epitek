/*
** graphics.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:36 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:36 2012 geoffroy aubey
*/

#include "SDL/SDL.h"
#include "graphics.h"

void	graphics_draw(t_graphics *g, SDL_Surface *s, int x, int y)
{
  SDL_Rect rect;

  rect.x = x;
  rect.y = y;
  SDL_BlitSurface(s, NULL, g->screen , &rect);
}

void	graphics_flush(t_graphics *g)
{
  SDL_Flip(g->screen);
}

void	graphics_clear(t_graphics *g)
{
  SDL_FillRect(g->screen, NULL, SDL_MapRGB(g->screen->format, 0, 0, 0));
}
