/*
** game.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:10:21 2012 geoffroy aubey
** Last update Sat Mar  3 19:10:21 2012 geoffroy aubey
*/

#ifndef _GAME_H_
# define _GAME_H_

# include "graphics/graphics.h"
# include "map.h"
# include "event.h"

/* less is speeder */
# define MOVE_SPEED 5.0

typedef enum
{
  INGAME,
  MENU
} e_state;

typedef struct
{
  e_state	state;
  char		*file_name;
  t_map		*map;
  t_graphics	*graphics;
  struct s_menu	*menu;
  t_list	entities;

  SDL_Surface *surface_wall;
  SDL_Surface *surface_scale;
  SDL_Surface *surface_free;

  struct s_player *player;
  int		run;

  int		finish;
  int		load_next;
} t_game;

t_game	*game_create();
int	game_init(t_game *game);
int	game_run(t_game *game);
int	game_end(t_game *game);
int	game_parse_arguments(t_game *game, int ac, char **av);
int	draw_game_scene(t_game *game);

int	game_logic(t_game *game, t_event *e, int delta);

int	load_map(t_game *g, char *file_name, t_map *map);
int	game_load_map(t_game *g, char *file_name);
void	game_unload_map(t_game *g);

int	update_camera(t_game *g, int delta);

#endif /* !_GAME_H_ */
