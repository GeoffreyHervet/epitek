/*
** player_collision.c for  in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 20:40:04 2012 geoffroy aubey
** Last update Sun Mar  4 20:40:04 2012 geoffroy aubey
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "game/game.h"
#include "entity/entity.h"
#include "collision.h"

int	player_check_death(t_game *g, t_player *p)
{
  if (p->life <= 0)
    {
      p->life = 100;
      p->entity.pos.x = g->map->start.x * 32;
      p->entity.pos.y = g->map->start.y * 32;
      p->entity.vector.x = 0;
      p->entity.vector.y = 0;
      p->nb_continue--;
      if (p->nb_continue == 0)
	g->finish = 1;
    }
  return (0);
}

static int	player_hit(t_game *g, t_player *p)
{
  p->life -= 10;
  p->invuln = 0;
  player_check_death(g, p);
  return (0);
}

static int player_on_event(t_game *g, t_player *p, t_entity *e)
{
  if (!e->exist)
    return (0);
  if (e->type == E_EXIT)
    {
      if (p->nb_key > 0)
	{
	  g->finish = 1;
	  g->load_next = 1;
	}
    }
  else if (e->type == MONSTER && p->invuln > TIME_INV)
    player_hit(g, p);
  else
    manage_event_item(g, p, e);
  return (0);
}

static int player_check_collision(t_game *g, t_player *p, t_entity *e)
{
  if (p->entity.pos.x + 32 < e->pos.x)
    return (0);
  if (p->entity.pos.x > e->pos.x + 32)
    return (0);
  if (p->entity.pos.y + 32 < e->pos.y)
    return (0);
  if (p->entity.pos.y > e->pos.y + 32)
    return (0);
  player_on_event(g, p, e);
  return (1);
}

int	player_collision(t_game *g, t_player *e, int delta)
{
  t_list list;

  (void)delta;
  list = g->entities;
  while (list != END)
    {
      if (list->value != (t_player *)e)
	player_check_collision(g, e, list->value);
      NEXT(list);
    }
  return (0);
}
