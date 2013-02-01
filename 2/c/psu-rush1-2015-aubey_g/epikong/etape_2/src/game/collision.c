/*
** collisions.c for  in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 11:21:20 2012 geoffroy aubey
** Last update Sun Mar  4 11:21:20 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "game/game.h"
#include "entity/entity.h"
#include "map.h"
#include "collision.h"

e_map_tile	check_wall_collide(t_game *g, float x, float y)
{
  int	tab_x;
  int	tab_y;

  tab_x = (float)(x / (float)SIZE_TILE_X);
  tab_y = (float)(y / (float)SIZE_TILE_Y);
  if (tab_y > g->map->height || tab_y < 0)
    return (WALL);
  if (tab_x > g->map->width || tab_x < 0)
    return (WALL);
  return (g->map->tiles[tab_y][tab_x]);
}

/*
  0 = U_RIGHT
  1 = U_LEFT
  2 = D_LEFT
  3 = D_RIGHT
*/
e_map_tile	*find_map_collisions(t_game *g, t_entity *e, float x, float y)
{
  static e_map_tile	pix[4];

  pix[0] = check_wall_collide(g, e->pos.x + x, e->pos.y + y);
  pix[1] = check_wall_collide(g, e->pos.x + x + SIZE_TILE_X - 5, e->pos.y + y);
  pix[2] = check_wall_collide(g, e->pos.x + x + SIZE_TILE_X - 5,
			      e->pos.y + y + SIZE_TILE_Y - 5);
  pix[3] = check_wall_collide(g, e->pos.x + x, e->pos.y + y + SIZE_TILE_Y - 5);
  return (pix);
}
