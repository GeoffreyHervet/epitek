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

void init_player(t_player *p)
{
  p->life = 100;
}

t_player *create_player(t_graphics *g, int x, int y)
{
  t_player *m;
  SDL_Surface *s;

  s = get_surface(g, S_PLAYER);
  m = malloc(sizeof(*m));
  init_entity(&m->entity, x, y, s);
  init_player(m);
  return (m);
}
