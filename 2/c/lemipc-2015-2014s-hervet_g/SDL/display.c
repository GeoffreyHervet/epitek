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

#include	"display.h"

void		display_player(int team_id,
			       int idx,
			       SDL_Surface *s)
{
  SDL_Rect		pixel;
  Uint32		color;

  pixel.w = PLAYER_SIZE_PXL;
  pixel.h = PLAYER_SIZE_PXL;
  pixel.x = (idx % MAP_WIDTH) * PLAYER_SIZE_PXL;
  pixel.y = (idx / MAP_WIDTH) * PLAYER_SIZE_PXL;
  srand(team_id + 2);
  color = SDL_MapRGB(s->format,
      rand() % 0x100, rand() % 0x100, rand() % 0x100);
  SDL_FillRect(s, &pixel, color);
}

void			display_map(SDL_Surface *s, unsigned char map[MAP_SIZE])
{
  int 			idx;

  SDL_FillRect(s, NULL, SDL_MapRGB(s->format, 0, 0, 0));
  idx = 0;
  while (idx < MAP_SIZE)
  {
    if (map[idx])
      display_player(map[idx], idx, s);
    ++idx;
  }
}

void		*check_quit(void *a)
{
  SDL_Event		event;

  (void)a;
  while (1)
  {
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT ||
        (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
    {
      sdl_quit = 1;
      exit(0);
    }
  }
  return (NULL);
}

int		get_key(key_t *ret)
{
  char		cwd[1024];

  if (NULL == getcwd(cwd, 1023))
    return (EXIT_FAILURE);
  if (-1 == (*ret = ftok(cwd, 42)))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		get_shared_information(t_infos **i, key_t key)
{
  int		shm_id;

  shm_id = shmget(key, sizeof(**i), SHM_R | SHM_W);
  printf("shm_id = %i\n", shm_id);
  printf("key = %d\n", key);
  if ((void *)(-1) == (*i = shmat(shm_id, *i, SHM_R | SHM_W)))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
