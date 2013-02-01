/*
** event.c for  in /home/wotan/projects/Epikong/etape_1
** 
** Made by geoffroy aubey
** Login   <aubey_g@epitech.net>
** 
** Started on  Sat Mar  3 19:09:43 2012 geoffroy aubey
** Last update Sat Mar  3 19:09:43 2012 geoffroy aubey
*/

#include <SDL/SDL.h>
#include "event.h"

void	toggle_key(t_event *e, int key, int toogle)
{
  if (toogle)
    e->action |= key;
  else
    e->action &= ~key;
}

void	get_event(t_event *e)
{
  SDL_Event event;

  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	toggle_key(e, ESCAPE, event.type == SDL_KEYDOWN);
      if (event.key.keysym.sym == SDLK_UP)
	toggle_key(e, MOVE_UP, event.type == SDL_KEYDOWN);
      if (event.key.keysym.sym == SDLK_DOWN)
	toggle_key(e, MOVE_DOWN, event.type == SDL_KEYDOWN);
      if (event.key.keysym.sym == SDLK_LEFT)
	toggle_key(e, MOVE_LEFT, event.type == SDL_KEYDOWN);
      if (event.key.keysym.sym == SDLK_RIGHT)
	toggle_key(e, MOVE_RIGHT, event.type == SDL_KEYDOWN);
      if (event.key.keysym.sym == SDLK_RETURN)
	toggle_key(e, SELECT, event.type == SDL_KEYDOWN);
    }
  else if (event.type == SDL_QUIT)
    toggle_key(e, EXIT, event.type == SDL_KEYDOWN);
}
