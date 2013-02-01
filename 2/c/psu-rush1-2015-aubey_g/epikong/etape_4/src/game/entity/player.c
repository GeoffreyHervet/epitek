/*
** player.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 00:22:31 2012 geoffroy aubey
** Last update Sun Mar  4 00:22:31 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "entity.h"
#include "../animation.h"

void init_player(t_player *p)
{
  p->life = 100;
  p->nb_continue = 5;
  p->entity.type = PLAYER;
  p->state = A_LEFT;
  p->last_state = A_LEFT;
  p->anim = NULL;
  p->is_right = 0;
  p->invuln = TIME_INV + 1;
  p->nb_key = 0;
  p->gun = 0;
}

t_player *create_player(t_graphics *g, int x, int y)
{
  t_player *m;
  SDL_Surface *s;

  s = get_surface(g, PLAYER_LO_L);
  m = malloc(sizeof(*m));
  init_entity(&m->entity, x, y, s);
  init_player(m);
  return (m);
}

e_anim_state	player_get_state(t_game *g, t_player *e)
{
  (void) g;
  if (e->entity.vector.x < 0)
    e->is_right = 1;
  else if (e->entity.vector.x > 0)
    e->is_right = 0;
  if (e->entity.state == ONAIR)
    {
      if (e->entity.vector.y < 0)
	return (A_JUMP);
      else
	return (A_FALL);
    }
  else if (e->entity.state == ONSCALE)
    return (A_SCALE);
  else if (e->entity.vector.x != 0)
    return (e->is_right ? A_RUN_RIGHT : A_RUN_LEFT);
  else
    return (e->state = e->is_right ? A_RIGHT : A_LEFT);
}

static int	player_set_anim(t_game *g, t_player *e)
{
  if (e->state == A_JUMP)
    anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_JUMP_1));
  else if (e->state == A_RUN_LEFT)
    {
      anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_LEFT_1));
      anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_LEFT_2));
      anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_LEFT_3));
    }
  else if (e->state == A_RUN_RIGHT)
    {
      anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_RIGHT_1));
      anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_RIGHT_2));
      anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_RIGHT_3));
    }
  else if (e->state == A_RIGHT)
    anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_LO_R));
  else if (e->state == A_SCALE)
    {
      e->anim->time_frame = 400;
      anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_CLIMB_1));
      anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_CLIMB_2));
    }
  else
    return (1);
  return (0);
}

void	player_update(t_game *g, t_player *e, int delta, e_map_tile *pix)
{
  (void) pix;
  e->state = player_get_state(g, e);
  if (!e->anim)
    e->anim = create_animation(100);
  if (e->last_state != e->state)
    {
      anim_clear(e->anim);
      e->anim->time_frame = 100;
      if (player_set_anim(g, e))
	{
	  if (e->state == A_FALL)
	  {
	    e->anim->time_frame = 200;
	    anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_FALL_1));
	    anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_FALL_2));
	    anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_FALL_3));
	  }
	  else
	    anim_add_surface(e->anim, get_surface(g->graphics, PLAYER_LO_L));
	}
    }
  anim_update(e->anim, delta);
  e->entity.drawable = anim_get_current_surface(e->anim);
  e->last_state = e->state;
}
