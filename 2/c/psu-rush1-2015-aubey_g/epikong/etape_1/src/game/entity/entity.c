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

void init_entity(t_entity *e, int x, int y, SDL_Surface *s)
{
  e->pos.x = x;
  e->pos.y = y;
  e->drawable = s;
  e->collidable.pos.x = x;
  e->collidable.pos.y = y;
  e->collidable.size.x = SIZE_TILE_X;
  e->collidable.size.y = SIZE_TILE_Y;
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
  else
    return (NULL);
  list_push_back(&g->entities, e);
  return (e);
}

void	draw_entity(t_graphics *g, t_entity *e)
{
  graphics_draw(g, e->drawable, e->pos.x - g->cam.x, e->pos.y - g->cam.y);
}

void	delete_entities(t_game *game)
{
  t_list list;

  list = game->entities;
  while (list != END)
    {
      free(list->value);
      NEXT(list);
    }
  list_clear(&list);
}
