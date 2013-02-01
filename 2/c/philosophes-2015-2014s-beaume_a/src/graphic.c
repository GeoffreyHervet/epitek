/*
** philosophe.h for  in /home/hervet_g/philosophe
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Mar 17 16:42:41 2012 geoffrey hervet
** Last update Sat Mar 17 16:42:42 2012 geoffrey hervet
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <pthread.h>

#include "graphic.h"
#include "init_tgraphics.h"

static pthread_mutex_t 	screen_access = PTHREAD_MUTEX_INITIALIZER;

t_graphic		*init_graphic(unsigned int nb)
{
  return (init_t_graphic(nb));
}

void		graphic_sleep(size_t idx, t_graphic *graph)
{
  pthread_mutex_lock(&screen_access);
  if (graph != NULL)
  {
    SDL_BlitSurface(graph->cleaner, NULL,
        graph->screen, &graph->philos[idx].img_pos);
    SDL_BlitSurface(graph->ressources[IDX_SLEEP], NULL,
        graph->screen, &graph->philos[idx].img_pos);
    SDL_Flip(graph->screen);
  }
  else
    printf("Philosophe #%li sleeps\n", idx);
  pthread_mutex_unlock(&screen_access);
}

void		graphic_think(size_t idx, t_graphic *graph)
{
  pthread_mutex_lock(&screen_access);
  if (graph != NULL)
  {
    SDL_BlitSurface(graph->cleaner, NULL,
        graph->screen, &graph->philos[idx].img_pos);
    SDL_BlitSurface(graph->ressources[IDX_THINK], NULL,
        graph->screen, &graph->philos[idx].img_pos);
    SDL_Flip(graph->screen);
  }
  else
    printf("Philosophe #%li thinks\n", idx);
  pthread_mutex_unlock(&screen_access);
}

void		graphic_eat(size_t idx, t_graphic *graph)
{
  pthread_mutex_lock(&screen_access);
  if (graph != NULL)
  {
    SDL_BlitSurface(graph->cleaner, NULL,
        graph->screen, &graph->philos[idx].img_pos);
    SDL_BlitSurface(graph->ressources[IDX_EAT], NULL,
        graph->screen, &(graph->philos[idx].img_pos));
    SDL_Flip(graph->screen);
  }
  else
    printf("Philosophe #%li eats\n", idx);
  pthread_mutex_unlock(&screen_access);
}
