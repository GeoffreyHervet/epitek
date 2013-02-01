/*
** entity.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 23:09:22 2012 geoffroy aubey
** Last update Sat Mar  3 23:09:22 2012 geoffroy aubey
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "game/game.h"
#include "entity.h"
#include "../collision.h"

void init_entity(t_entity *e, int x, int y, SDL_Surface *s)
{
  e->exist = 1;
  e->pos.x = x;
  e->pos.y = y;
  e->drawable = s;
  e->vector.x = 0;
  e->vector.y = 0;
  e->state = ONGROUND;
}

t_entity *spaw_entity(t_game *g, e_entity_type type, int x, int y)
{
  t_entity *e;

  if (type == MONSTER)
    e = (t_entity *)create_monster(g->graphics, x, y);
  else if (type == PLAYER)
    e = (t_entity *)create_player(g->graphics, x, y);
  else if (type == E_EXIT)
    e = (t_entity *)create_item(g->graphics, x, y, E_EXIT);
  else if (type == E_KEY)
    e = (t_entity *)create_item(g->graphics, x, y, E_KEY);
  else if (type == E_LIFE)
    e = (t_entity *)create_item(g->graphics, x, y, E_LIFE);
  else if (type == E_GUN)
    e = (t_entity *)create_item(g->graphics, x, y, E_GUN);
  list_push_back(&g->entities, e);
  return (e);
}

void	draw_entity(t_graphics *g, t_entity *e)
{
  if (e->exist)
    graphics_draw(g, e->drawable, e->pos.x - g->cam.x, e->pos.y - g->cam.y);
}

void	delete_entities(t_game *game)
{
  t_list list;

  list = game->entities;
  while (list != END)
    {
      free(list->value);
      list->value = NULL;
      NEXT(list);
    }
  list_clear(&list);
  game->entities = NULL;
}

void entity_update(t_game *g, t_entity *e, int delta)
{
  float	move_x;
  float move_y;
  e_map_tile *pix;

  move_x = delta * e->vector.x;
  move_y = delta * e->vector.y;
  pix = find_map_collisions(g, e, move_x, move_y + 3);
  if (pix[2] == FREE && pix[3] == FREE && e->state != ONSCALE)
    e->vector.y += 0.002 * delta;
  pix = find_map_collisions(g, e, move_x, move_y);
  check_first_move(&move_x, &move_y, pix, e);
  check_scale(g, e);
  check_move(&move_x, &move_y, pix, e);
  e->pos.x += move_x;
  e->pos.y += move_y;
  if (e->type == PLAYER)
    player_update(g, (t_player *)e, delta, pix);
  e->vector.x = 0;
  if (e->type == MONSTER)
    {
      pix = find_map_collisions(g, e, move_x, move_y + 20);
      monster_update(g, (t_monster *)e, delta, pix);
    }
  if (e->type == PLAYER)
    player_collision(g, (t_player *)e, delta);
}
