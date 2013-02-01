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
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <pthread.h>

#include "init_tgraphics.h"

char			sdl_quit = 0;
extern t_graphic	*graph;

static t_graphic	*ret_and_free(t_graphic *g)
{
  free(g);
  return (NULL);
}

static t_graphic	*init_philo_pos(t_graphic *g, unsigned int nb)
{
  unsigned int		idx;

  idx = 0;
  while (idx < nb)
  {
    g->philos[idx].x = (idx % PHILOS_PER_LINE) * SQUARE_CONTENT;
    g->philos[idx].y = (idx / PHILOS_PER_LINE) * SQUARE_CONTENT;
    g->philos[idx].img_pos.x = g->philos[idx].x + OFFSET_IMG;
    g->philos[idx].img_pos.y = g->philos[idx].y;
    idx++;
  }
  SDL_Flip(g->screen);
  return (g);
}

static void		*check_quit(void *a)
{
  SDL_Event		event;

  (void)a;
  while (1)
  {
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT)
    {
      sdl_quit = 1;
      graph = NULL;
      SDL_Quit();
      exit(0);
    }
    else if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        sdl_quit = 1;
        graph = NULL;
        SDL_Quit();
        exit(0);
      }
    }
  }
  return (NULL);
}

static t_graphic	*init_screen(t_graphic *g, unsigned int nb)
{
  int			width;
  int			height;
  pthread_t		sdl_thread;

  width = PHILOS_PER_LINE * SQUARE_CONTENT;
  height = (1 + nb / PHILOS_PER_LINE) * SQUARE_CONTENT;
  if (height > MAX_HEIGHT)
    return (ret_and_free(g));
  g->screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);
  if (g->screen == NULL)
    return (ret_and_free(g));
  SDL_WM_SetIcon(g->ressources[2], NULL);
  SDL_WM_SetCaption("Philosophes", NULL);
  SDL_FillRect(g->cleaner, NULL, SDL_MapRGB(g->screen->format, WHITE_3P));
  if (0 != SDL_FillRect(g->screen, NULL,
        SDL_MapRGB(g->screen->format, WHITE_3P)))
    return (ret_and_free(g));
  pthread_create(&sdl_thread, NULL, check_quit, NULL);
  return (init_philo_pos(g, nb));
}

t_graphic		*init_t_graphic(unsigned int nb)
{
  t_graphic	*ret;

  if (NULL == (ret = malloc(sizeof(*ret))))
    return (NULL);
  ret->ressources[IDX_SLEEP] = IMG_Load("imgs/sleep.png");
  ret->ressources[IDX_EAT] = IMG_Load("imgs/eat.png");
  ret->ressources[IDX_THINK] = IMG_Load("imgs/think.png");
  ret->cleaner = SDL_CreateRGBSurface(SDL_HWSURFACE, SQUARE_CONTENT,
      SQUARE_CONTENT, 32, 0, 0, 0, 0);
  if (ret->ressources[IDX_SLEEP] == NULL ||
      ret->ressources[IDX_EAT] == NULL   ||
      ret->ressources[IDX_THINK] == NULL ||
      ret->cleaner == NULL ||
      SDL_Init(SDL_INIT_VIDEO) != 0)
    return (ret_and_free(ret));
  if (NULL == (ret->philos = malloc(sizeof(*ret->philos) * nb)))
    return (ret_and_free(ret));
  return init_screen(ret, nb);
}
