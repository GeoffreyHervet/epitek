/*
** scene.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:06:41 2012 geoffroy aubey
** Last update Sat Mar  3 19:06:41 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "game.h"
#include "epikong.h"
#include "entity/entity.h"
#include "menu.h"

static void	draw_all_tiles(t_game *game)
{
  int	i;
  int	j;
  e_map_tile tile;
  int x;
  int y;

  i = 0;
  while (i < game->map->width)
    {
      j = 0;
      while (j < game->map->height)
	{
	  tile = game->map->tiles[j][i];
	  x = (i * SIZE_TILE_X) - game->graphics->cam.x;
	  y = (j * SIZE_TILE_Y) - game->graphics->cam.y;
	  if (tile == WALL)
	    graphics_draw(game->graphics, game->surface_wall, x, y);
	  else if (tile == SCALE)
	    graphics_draw(game->graphics, game->surface_scale, x, y);
	  else
	    graphics_draw(game->graphics, game->surface_free, x, y);
	  ++j;
	}
      ++i;
    }
}

static void draw_entities(t_game *game)
{
  t_list list;

  list = game->entities;
  while (list != END)
    {
      draw_entity(game->graphics, list->value);
      NEXT(list);
    }
}

int	draw_game_scene(t_game *game)
{
  if (game->state == INGAME)
    {
      if (game->map)
	draw_all_tiles(game);
      if (game->entities != END)
      	draw_entities(game);
      draw_gui(game);
    }
  else
    {
      draw_menu(game);
    }
  return (0);
}
