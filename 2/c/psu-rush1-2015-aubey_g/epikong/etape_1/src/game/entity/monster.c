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
}

t_monster *create_monster(t_graphics *g, int x, int y)
{
  t_monster *m;
  SDL_Surface *s;

  s = get_surface(g, S_MONSTER);
  m = malloc(sizeof(*m));
  init_entity(&m->entity, x, y, s);
  init_monster(m);
  return (m);
}

