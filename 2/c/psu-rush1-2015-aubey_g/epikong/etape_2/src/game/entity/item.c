/*
** item.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 02:45:32 2012 geoffroy aubey
** Last update Sun Mar  4 02:45:32 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "entity.h"

void init_item(t_item *m)
{
  m->value = 100;
}

t_item *create_item(t_graphics *g, int x, int y, e_entity_type type)
{
  t_item *m;
  SDL_Surface *s;

  if (type == E_EXIT)
    s = get_surface(g, S_EXIT);
  if (type == E_GUN)
    s = get_surface(g, S_GUN);
  else if (type == E_KEY)
    s = get_surface(g, S_KEY);
  else if (type == E_LIFE)
    s = get_surface(g, S_LIFE);
  else
    s = get_surface(g, S_EXIT);
  m = malloc(sizeof(*m));
  init_entity(&m->entity, x, y, s);
  init_item(m);
  m->entity.type = type;
  return (m);
}
