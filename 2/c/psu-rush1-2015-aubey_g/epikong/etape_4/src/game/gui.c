/*
** gui.c for  in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 21:48:43 2012 geoffroy aubey
** Last update Sun Mar  4 21:48:43 2012 geoffroy aubey
*/

#include "SDL/SDL.h"
#include "graphics/graphics.h"
#include "game/game.h"
#include "menu.h"
#include "entity/entity.h"

void	graphics_draw_gui(t_graphics *g, char *str,
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
  s = TTF_RenderText_Blended(g->font_gui, str, color);
  SDL_BlitSurface(s, NULL, g->screen, &position);
  SDL_FreeSurface(s);
}

int	draw_gui(t_game *g)
{
  char buffer[512];
  t_pos pos;

  pos.x = 0;
  pos.y = 0;
  snprintf(buffer, 512, "Player life : %i - %i continue - %i key",
	   g->player->life, g->player->nb_continue, g->player->nb_key);
  graphics_draw_gui(g->graphics, buffer, WHITE, &pos);
  return (0);
}
