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

typedef enum
  {
    MONSTER,
    PLAYER,
    E_EXIT
  } e_entity_type;

typedef struct s_entity
{
  t_pos		pos;
  t_pos		vector;
  e_entity_type type;
  t_collidable	collidable;
  SDL_Surface	*drawable;
} t_entity;

typedef struct s_monster
{
  t_entity entity;
  int	   life;
} t_monster;

typedef struct s_player
{
  t_entity entity;
  int	   life;
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
void	draw_entity(t_graphics *g, t_entity *e);
void	delete_entities(t_game *game);
t_item *create_item(t_graphics *g, int x, int y, e_entity_type type);

#endif /* !_ENTITY_H_ */
