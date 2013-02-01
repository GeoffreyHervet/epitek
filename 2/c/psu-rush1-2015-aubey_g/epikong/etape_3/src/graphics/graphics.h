/*
** graphics.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:10:20 2012 geoffroy aubey
** Last update Sat Mar  3 19:10:20 2012 geoffroy aubey
*/

#ifndef _GRAPHIC_ENGINE_H_
# define _GRAPHIC_ENGINE_H_

# include <SDL/SDL_ttf.h>
# include "epikong.h"
# include "camera.h"
# include "list/list.h"
# include "game/animation.h"

enum
  {
    S_WALL = 0,
    S_FREE,
    S_SCALE,
    S_MONSTER,
    S_EXIT,
    S_EXIT_O,
    S_KEY,
    S_LIFE,
    S_GUN,
    PLAYER_CLIMB_1,
    PLAYER_CLIMB_2,
    PLAYER_DEAD,
    PLAYER_FALL_1,
    PLAYER_FALL_2,
    PLAYER_FALL_3,
    PLAYER_JUMP_1,
    PLAYER_LEFT_1,
    PLAYER_LEFT_2,
    PLAYER_LEFT_3,
    PLAYER_LO_L,
    PLAYER_LO_R,
    PLAYER_RIGHT_1,
    PLAYER_RIGHT_2,
    PLAYER_RIGHT_3,
    ENEMY_LEFT_1,
    ENEMY_LEFT_2,
    ENEMY_LEFT_3,
    ENEMY_LEFT_4,
    ENEMY_RIGHT_1,
    ENEMY_RIGHT_2,
    ENEMY_RIGHT_3,
    ENEMY_RIGHT_4,
    NB_SURFACE
  } e_surface_type;

typedef enum
  {
    RED,
    WHITE
  } e_color;

typedef struct
{
  t_pos	pos;
  t_pos size;
  SDL_Surface *surface;
} t_collidable;

typedef struct
{
  SDL_Surface *screen;
  int	win_x;
  int	win_y;
  t_list surface_list;
  t_camera cam;

  TTF_Font *font;
  TTF_Font *font_gui;
} t_graphics;

typedef struct
{
  int	id;
  SDL_Surface *surface;
} t_surface;

void		delete_graphics(t_graphics *g);
void		graphics_shutdown(t_graphics *g);
int		graphics_init(t_graphics *g, int win_x, int win_y);
t_graphics	*create_graphics();
void		graphics_draw(t_graphics *g, SDL_Surface *s, int x, int y);
void		graphics_flush(t_graphics *g);
void		graphics_draw_text(t_graphics *g, char *str,
                           e_color color_name, t_pos *pos);

int		load_all_surfaces(t_graphics *g);
int		load_player(t_graphics *g);
int		load_world(t_graphics *g);
int		load_enemy(t_graphics *g);

int		add_surface(t_graphics *g, char *filename, int id);
SDL_Surface	*get_surface(t_graphics *g, int id);
void		delete_surfaces(t_graphics *g);

void		graphics_clear(t_graphics *g);
void		graphics_draw_gui(t_graphics *g, char *str,
    			  e_color color_name, t_pos *pos);
void		fill_color(SDL_Color *color, int r, int g, int b);

#endif /* !_GRAPHIC_ENGINE_H_ */
