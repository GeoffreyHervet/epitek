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

# include "epikong.h"
# include "camera.h"
# include "list/list.h"

enum
  {
    S_WALL = 0,
    S_FREE,
    S_SCALE,
    S_MONSTER,
    S_PLAYER,
    S_EXIT,
    NB_SURFACE
  };

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

int		load_all_surfaces(t_graphics *g);
int		add_surface(t_graphics *g, char *filename, int id);
SDL_Surface	*get_surface(t_graphics *g, int id);
void		delete_surfaces(t_graphics *g);

void		graphics_clear(t_graphics *g);

#endif /* !_GRAPHIC_ENGINE_H_ */
