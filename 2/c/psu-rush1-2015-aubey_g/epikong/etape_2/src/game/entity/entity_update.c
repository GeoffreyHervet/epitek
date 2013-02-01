/*
** entity_update.c for  in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 21:32:00 2012 geoffroy aubey
** Last update Sun Mar  4 21:32:00 2012 geoffroy aubey
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "game/game.h"
#include "entity.h"
#include "../collision.h"

void	check_move(float *move_x, float *move_y, e_map_tile *pix, t_entity *e)
{
  if (pix[0] == WALL || pix[1] == WALL || pix[2] == WALL || pix[3] == WALL)
    {
      e->vector.y = 0;
      e->vector.x = 0;
    }
  if (pix[0] == WALL)
    {
      *move_x += 1;
      *move_y += 1;
    }
  if (pix[1] == WALL)
    {
      *move_x += -1;
      *move_y += 1;
    }
  if (pix[2] == WALL)
    {
      *move_x += -1;
      *move_y += -1;
    }
  if (pix[3] == WALL)
    {
      *move_x += 1;
      *move_y += -1;
    }
}

void	check_first_move(float *move_x, float *move_y,
   			 e_map_tile *pix, t_entity *e)
{
  if ((pix[2] == WALL || pix[3] == WALL) && e->state == ONAIR)
    if (e->vector.y > 1 && e->type == PLAYER)
      ((t_player *)e)->life -= 20;
  if (pix[2] == FREE && pix[3] == FREE)
    e->state = ONAIR;
  if (pix[2] == WALL || pix[3] == WALL)
    e->vector.y = 0;
  if (e->vector.y == 0)
    e->state = ONGROUND;
  if ((pix[0] == WALL || pix[1] == WALL) && *move_y < 0)
    *move_y = 0;
  if ((pix[2] == WALL || pix[3] == WALL) && *move_y > 0)
    *move_y = 0;
  if ((pix[0] == WALL || pix[3] == WALL) && *move_x < 0)
    *move_x = 0;
  if ((pix[1] == WALL || pix[2] == WALL) && *move_x > 0)
    *move_x = 0;
}

void check_scale(t_game *g, t_entity *e)
{
  if (check_wall_collide(g, e->pos.x, e->pos.y + SIZE_TILE_Y + 5) == SCALE
      || check_wall_collide(g, e->pos.x + SIZE_TILE_X,
			    e->pos.y + SIZE_TILE_Y + 5) == SCALE)
    {
      e->vector.y = 0;
      e->state = ONSCALE;
    }
}
