/*
** entity.h for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:10:22 2012 geoffroy aubey
** Last update Sat Mar  3 19:10:22 2012 geoffroy aubey
*/

#ifndef _ENTITY_H_
# define _ENTITY_H_

# include "game/game.h"
# include "epikong.h"
# include "graphics/graphics.h"

# define PLAYER_SPEED 0.2
# define TIME_INV 500

typedef enum
  {
    MONSTER = 0,
    PLAYER,
    E_EXIT,
    E_KEY,
    E_GUN,
    E_LIFE
  } e_entity_type;

typedef enum
  {
    ONGROUND = 0,
    ONAIR,
    ONSCALE
  } e_entity_state;

typedef enum
  {
    A_LEFT,
    A_RIGHT,
    A_RUN_LEFT,
    A_RUN_RIGHT,
    A_SCALE,
    A_JUMP,
    A_FALL
  } e_anim_state;
typedef enum
{
  TO_UP,
  TO_DOWN,
  TO_LEFT,
  TO_RIGHT
} e_side;

typedef struct s_entity
{
  int		exist;
  e_entity_state state;
  t_pos		pos;
  t_pos		vector;
  e_entity_type type;
  t_collidable	collidable;
  SDL_Surface	*drawable;
  e_side	side;
} t_entity;

typedef struct s_monster
{
  t_entity entity;
  int	   life;
  t_animation *anim;
  e_anim_state state;
  e_anim_state last_state;
} t_monster;

typedef struct s_player
{
  t_entity entity;
  e_anim_state state;
  e_anim_state last_state;
  t_animation *anim;
  int		gun;
  int		life;
  int		is_right;
  int		nb_continue;
  int		invuln;
  int		nb_key;
} t_player;

typedef struct s_item
{
  t_entity entity;
  int	   value;
} t_item;

void init_monster(t_monster *m);
void init_entity(t_entity *e, int x, int y, SDL_Surface *s);
t_monster *create_monster(t_graphics *g, int x, int y);
t_player *create_player(t_graphics *g, int x, int y);
t_entity *spaw_entity(t_game *g, e_entity_type type, int x, int y);
void	entity_update(t_game *g, t_entity *e, int delta);
void	draw_entity(t_graphics *g, t_entity *e);
void	delete_entities(t_game *game);
t_item *create_item(t_graphics *g, int x, int y, e_entity_type type);
void	monster_update(t_game *g, t_monster *e, int delta, e_map_tile *pix);
void	player_update(t_game *g, t_player *e, int delta, e_map_tile *pix);
int	player_collision(t_game *g, t_player *e, int delta);
void	check_move(float *move_x, float *move_y, e_map_tile *pix, t_entity *e);
void	check_first_move(float *move_x, float *move_y,
                       e_map_tile *pix, t_entity *e);
void	check_scale(t_game *g, t_entity *e);
int	draw_gui(t_game *g);
int	player_check_death(t_game *g, t_player *p);

#endif /* !_ENTITY_H_ */
