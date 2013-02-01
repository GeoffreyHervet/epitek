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

int manage_event_item(t_game *g, t_player *p, t_entity *e)
{
  (void) g;
  if (e->type == E_KEY)
  {
    p->nb_key++;
    e->exist = 0;
  }
  else if (e->type == E_GUN)
  {
    p->gun = 1;
    e->exist = 0;
  }
  else if (e->type == E_LIFE)
  {
    if (p->life < 100)
      p->life += 10;
    e->exist = 0;
  }
  return (1);
}
