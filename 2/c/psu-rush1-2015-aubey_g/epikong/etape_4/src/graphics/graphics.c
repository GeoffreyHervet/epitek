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

void	fill_color(SDL_Color *color, int r, int g, int b)
{
  color->r = r;
  color->g = g;
  color->b = b;
}

void	graphics_draw_text(t_graphics *g, char *str,
    			  e_color color_name, t_pos *pos)
{
  SDL_Surface *s;
  SDL_Color color;
  SDL_Rect position;

  position.x = pos->x;
  position.y = pos->y;
  if (color_name == RED)
    fill_color(&color, 255, 0, 0);
  else if (color_name == WHITE)
    fill_color(&color, 255, 255, 255);
  s = TTF_RenderText_Blended(g->font, str, color);
  SDL_BlitSurface(s, NULL, g->screen, &position);
  SDL_FreeSurface(s);
}
