/*
** game.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:42 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:42 2012 geoffroy aubey
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "event.h"
#include "game.h"
#include "entity/entity.h"

t_game	*game_create()
{
  t_game *g;

  g = malloc(sizeof(*g));
  g->map = NULL;
  g->graphics = NULL;
  g->file_name = NULL;
  g->entities = NULL;
  g->player = NULL;
  return (g);
}

int	game_parse_arguments( t_game *game, int ac, char **av)
{
  if (ac < 2)
    {
      fprintf(stderr, "./epikong_etape_1 file\n");
      return (-1);
    }
  game->file_name = av[1];
  return (0);
}

int	game_init(t_game *game)
{
  game->state = DISPLAYING;
  game->map = create_map();
  game->graphics = create_graphics();
  if (graphics_init(game->graphics,
		    WIN_X,
		    WIN_Y) == -1)
    return (-1);
  game->surface_wall = get_surface(game->graphics, S_WALL);
  game->surface_scale = get_surface(game->graphics, S_SCALE);
  game->surface_free = get_surface(game->graphics, S_FREE);
  if (game_load_map(game, game->file_name) == -1)
    return (-1);
  return (0);
}

int	game_run(t_game *game)
{
  int	run;
  t_event e;
  int	time_after;
  int	delta;

  e.action = NONE;
  run = 1;
  delta = 1000 / 60;
  time_after = SDL_GetTicks();
  while (run)
    {
      get_event(&e);
      if (e.action & EXIT || e.action & ESCAPE)
	run = 0;
      game_logic(game, &e, delta);
      graphics_clear(game->graphics);
      draw_game_scene(game);
      graphics_flush(game->graphics);
      delta = SDL_GetTicks() - time_after;
      time_after = SDL_GetTicks();
    }
  return (0);
}

int	game_end(t_game *game)
{
  game_unload_map(game);
  delete_graphics(game->graphics);
  return (0);
}
