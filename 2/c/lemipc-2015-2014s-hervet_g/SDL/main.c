/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include	<sys/types.h>
#include	<sys/ipc.h>
#include	<sys/sem.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	<pthread.h>

#include	"lemipc.h"
#include	"display.h"

char		sdl_quit = 0;

static int	leave_error(const char *s)
{
  fprintf(stderr, "%s", s);
  return (EXIT_FAILURE);
}

static void	do_work(SDL_Surface *screen, t_infos *inf)
{
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

  display_map(screen, inf->map);
  while (!sdl_quit)
  {
    SDL_Flip(screen);
    usleep(1000000 / 42);
    display_map(screen, inf->map);
  }
}

int main(void)
{
  SDL_Surface		*screen;
  key_t			key;
  t_infos		*inf;
  pthread_t		sdl_thread;

  inf = NULL;
  if (EXIT_FAILURE == get_key(&key))
    return (leave_error(NO_FTOK));
  if (EXIT_FAILURE == get_shared_information(&inf, key))
    return (leave_error(NO_SHM));
  if (-1 == SDL_Init(SDL_INIT_VIDEO))
    return (leave_error("Error, can't init SDL :'(\n"));
  if (NULL == (screen = SDL_SetVideoMode(MAP_WIDTH * PLAYER_SIZE_PXL,
         MAP_HEIGHT * PLAYER_SIZE_PXL, 32, SDL_HWSURFACE)))
    return (leave_error("Error, can't create window\n"));
  printf("%i\n", pthread_create(&sdl_thread, NULL, check_quit, NULL));
  do_work(screen, inf);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
