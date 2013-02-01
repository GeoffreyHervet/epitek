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
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "philosophe.h"
#include "graphic.h"

static t_chopstick	chopsticks[PHILOSOPHES_NBR];
static pthread_mutex_t 	chopstick_access = PTHREAD_MUTEX_INITIALIZER;
t_graphic		*graph = NULL;
extern char		sdl_quit;

static void		philosophe_eat(size_t idx[2])
{
  while (1)
    if (pthread_mutex_lock(&chopstick_access) == 0)
    {
      if (chopsticks[idx[0]] == CHOPSTICK_IS_UNUSED &&
          chopsticks[idx[1]] == CHOPSTICK_IS_UNUSED)
      {
        chopsticks[idx[0]] = CHOPSTICK_IS_USED;
        chopsticks[idx[1]] = CHOPSTICK_IS_USED;
        pthread_mutex_unlock(&chopstick_access);
        graphic_eat(idx[0], graph);
        sleep(EAT_TIME);
        pthread_mutex_lock(&chopstick_access);
        chopsticks[idx[0]] = CHOPSTICK_IS_UNUSED;
        chopsticks[idx[1]] = CHOPSTICK_IS_UNUSED;
        pthread_mutex_unlock(&chopstick_access);
        return ;
      }
      pthread_mutex_unlock(&chopstick_access);
    }
}

static void		philosophe_sleep(size_t idx[2])
{
  graphic_sleep(idx[0], graph);
  sleep(SLEEP_TIME);
}

static void		philosophe_think(size_t idx[2])
{
  ssize_t		current_chopstick;

  while (1)
  {
    current_chopstick = -1;
    if (pthread_mutex_lock(&chopstick_access) == 0)
    {
      if (chopsticks[idx[0]] == CHOPSTICK_IS_UNUSED)
        current_chopstick = idx[0];
      else if (chopsticks[idx[1]] == CHOPSTICK_IS_UNUSED)
        current_chopstick = idx[1];
      if (current_chopstick != -1)
      {
        chopsticks[current_chopstick] = CHOPSTICK_IS_USED;
        pthread_mutex_unlock(&chopstick_access);
        graphic_think(idx[0], graph);
        sleep(THINK_TIME);
        pthread_mutex_lock(&chopstick_access);
        chopsticks[current_chopstick] = CHOPSTICK_IS_UNUSED;
        pthread_mutex_unlock(&chopstick_access);
        return ;
      }
      pthread_mutex_unlock(&chopstick_access);
    }
  }
}

static void		*philosophe_create(size_t idx[2])
{
  int			chopsticks_available;

  if (graph == NULL)
    printf("Philosophe [%li]: was created\n", idx[0]);
  philosophe_eat(idx);
  philosophe_sleep(idx);
  while (1)
  {
    if (sdl_quit)
      pthread_exit(0);
    else
    {
      pthread_mutex_lock(&chopstick_access);
      chopsticks_available = (chopsticks[idx[0]] == CHOPSTICK_IS_UNUSED)
        + (chopsticks[idx[1]] == CHOPSTICK_IS_UNUSED);
      pthread_mutex_unlock(&chopstick_access);
      if (chopsticks_available > 0)
        philosophe_think(idx);
      philosophe_eat(idx);
      philosophe_sleep(idx);
    }
  }
  return (NULL);
}

int			philosophe(void)
{
  unsigned int		error;
  unsigned int		i;
  size_t 		chopsticks_index[PHILOSOPHES_NBR][2];
  pthread_t		philosophes_threads[PHILOSOPHES_NBR];

  graph = init_graphic(PHILOSOPHES_NBR);
  memset(chopsticks, CHOPSTICK_IS_UNUSED, sizeof(chopsticks));
  error = 0;
  i = -1;
  while (error == 0 && ++i < PHILOSOPHES_NBR)
  {
    chopsticks_index[i][0] = i;
    chopsticks_index[i][1] = (i + 1) % PHILOSOPHES_NBR;
    if (pthread_create(philosophes_threads + i, NULL,
          (void *(*)(void *))philosophe_create,
          &chopsticks_index[i]) != 0)
    {
      perror("pthread_create");
      error = i;
    }
  }
  i = 0;
  while (i < PHILOSOPHES_NBR)
    pthread_join(philosophes_threads[i++], NULL);
  return ((error == 0) ? 0 : -1);
}
