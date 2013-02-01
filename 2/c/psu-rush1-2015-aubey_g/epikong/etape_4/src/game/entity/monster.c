/*
** monster.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 23:32:53 2012 geoffroy aubey
** Last update Sat Mar  3 23:32:53 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "entity.h"

void init_monster(t_monster *m)
{
  m->life = 100;
  m->entity.vector.x = 0.5;
  m->entity.type = MONSTER;
  m->entity.side = TO_RIGHT;
  m->state = A_RIGHT;
  m->last_state = A_RIGHT;
  m->anim = NULL;
}

t_monster *create_monster(t_graphics *g, int x, int y)
{
  t_monster *m;
  SDL_Surface *s;

  s = get_surface(g, ENEMY_LEFT_4);
  m = malloc(sizeof(*m));
  init_entity(&m->entity, x, y, s);
  init_monster(m);
  return (m);
}

void monster_update(t_game *g, t_monster *m, int delta, e_map_tile *pix)
{
  if (!m->anim)
    {
      m->anim = create_animation(100);
      anim_add_surface(m->anim, get_surface(g->graphics, ENEMY_LEFT_3));
      anim_add_surface(m->anim, get_surface(g->graphics, ENEMY_LEFT_4));
    }
  m->entity.vector.x = 0.1 * (m->entity.side == TO_LEFT ? -1 : 1);
  if (pix[2] == FREE || pix[1] == WALL)
    {
      anim_clear(m->anim);
      anim_add_surface(m->anim, get_surface(g->graphics, ENEMY_RIGHT_3));
      anim_add_surface(m->anim, get_surface(g->graphics, ENEMY_RIGHT_4));
      m->entity.side = TO_LEFT;
    }
  if (pix[3] == FREE || pix[0] == WALL)
    {
      anim_clear(m->anim);
      anim_add_surface(m->anim, get_surface(g->graphics, ENEMY_LEFT_3));
      anim_add_surface(m->anim, get_surface(g->graphics, ENEMY_LEFT_4));
      m->entity.side = TO_RIGHT;
    }
  anim_update(m->anim, delta);
  m->entity.drawable = anim_get_current_surface(m->anim);
  m->last_state = m->state;
  (void)g;
}
