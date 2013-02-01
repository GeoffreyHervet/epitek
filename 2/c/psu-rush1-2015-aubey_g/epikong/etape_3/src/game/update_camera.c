/*
** game_logic.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 21:57:07 2012 geoffroy aubey
** Last update Sat Mar  3 21:57:07 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "graphics/graphics.h"
#include "game.h"
#include "event.h"
#include "menu.h"
#include "entity/entity.h"

int	update_camera(t_game *g, int delta)
{
  float		x;
  float		y;
  float		diffx;
  float		diffy;
  t_player	*player;

  player = (t_player *)g->player;
  x = player->entity.pos.x - WIN_X / 2 + SIZE_TILE_X / 2;
  y = player->entity.pos.y - WIN_Y / 2 + SIZE_TILE_Y / 2;
  diffx = x - g->graphics->cam.x;
  diffy = y - g->graphics->cam.y;
  camera_move(&g->graphics->cam, (diffx) / (200.0 / (float)delta),
	      (diffy) / (200.0 / (float)delta));
  return (0);
}
