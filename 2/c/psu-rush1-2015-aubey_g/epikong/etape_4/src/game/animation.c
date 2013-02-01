/*
** animation.c for ] in /home/wotan/projects/Epikong/etape_2
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sun Mar  4 16:51:35 2012 geoffroy aubey
** Last update Sun Mar  4 16:51:35 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "animation.h"

t_animation	*create_animation(int time_frame)
{
  t_animation *a;

  a = malloc(sizeof(*a));
  a->time_frame = time_frame;
  a->last_time = 0;
  a->surfaces = NULL;
  a->it = NULL;
  a->pause = 0;
  return (a);
}

int	anim_add_surface(t_animation *a, SDL_Surface *s)
{
  list_push_back(&a->surfaces, s);
  return (0);
}

SDL_Surface	*anim_get_current_surface(t_animation *a)
{
  return ((SDL_Surface *)a->it->value);
}

int		anim_update(t_animation *a, int delta)
{
  if (a->pause)
    {
      a->last_time = 0;
      return (0);
    }
  if (a->it == END)
    a->it = a->surfaces;
  a->last_time += delta;
  if (a->last_time > a->time_frame)
    {
      NEXT(a->it);
      if (a->it == END)
	a->it = a->surfaces;
      a->last_time = 0;
    }
  return (0);
}

void		anim_clear(t_animation *a)
{
  list_clear(&a->surfaces);
  a->surfaces = NULL;
  a->it = NULL;
}
