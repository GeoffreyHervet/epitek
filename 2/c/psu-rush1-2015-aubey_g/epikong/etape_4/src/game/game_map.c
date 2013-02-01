/*
** game_map.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 01:52:35 2012 geoffroy aubey
** Last update Sun Mar  4 01:52:35 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "game.h"
#include "entity/entity.h"
#include "graphics/camera.h"

static void	init_camera(t_game *g)
{
  g->graphics->cam.x = (g->map->width * SIZE_TILE_X) / 2 - (WIN_X / 2);
  g->graphics->cam.y = (g->map->height * SIZE_TILE_Y) / 2 - (WIN_Y / 2);

  g->graphics->cam.max_x = (g->map->width * SIZE_TILE_X) - (WIN_X / 2);
  g->graphics->cam.max_y = (g->map->height * SIZE_TILE_Y) - (WIN_Y / 2);
  g->graphics->cam.min_x = -(WIN_X / 2);
  g->graphics->cam.min_y = -(WIN_Y / 2);
}

int	game_load_map(t_game *g, char *file_name)
{
  if (load_map(g, file_name, g->map) == -1)
    return (-1);
  SDL_WM_SetCaption(file_name, NULL);
  g->player = (t_player *)spaw_entity(g, PLAYER,
				      g->map->start.x * SIZE_TILE_X,
				      g->map->start.y * SIZE_TILE_X);
  init_camera(g);
  return (0);
}

void	game_unload_map(t_game *g)
{
  if (g != END)
    delete_entities(g);
  if (g->map)
    delete_map(g->map);
  g->map = NULL;
  g = END;
}
