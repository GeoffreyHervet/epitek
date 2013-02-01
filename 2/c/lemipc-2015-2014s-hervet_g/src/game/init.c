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
#include	<sys/shm.h>
#include	<sys/sem.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>

#include	"game/init.h"
#include	"sem.h"

static int	set_id(t_process_infos *inf)
{
  char		cwd[1024];

  if (NULL == getcwd(cwd, 1023))
    return (EXIT_FAILURE);
  if (-1 == (inf->key = ftok(cwd, 42)))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

/*
** usleep -> au cas ou y a deja un pelerin qui cree la shared
*/

static int	get_shared_information(t_process_infos *i)
{
  i->shared = NULL;
  i->shm_id = shmget(i->key, sizeof(*(i->shared)), SHM_R | SHM_W);
  if (-1 == i->shm_id)
  {
    usleep(rand() % (TIME_WAIT / 100));
    if (-1 == i->shm_id)
    {
      i->shm_id = shmget(i->key, sizeof(*(i->shared)), IPC_CREAT | SHM_RW);
      if (-1 == i->shm_id)
        return (EXIT_FAILURE);
      printf("Init\n");
      if ((void *)(-1) == (i->shared = shmat(i->shm_id, i->shared, SHM_RW)))
        return (EXIT_FAILURE);
      return (EXIT_SUCCESS);
    }
  }
  if (i->shared == NULL &&
      (void *)(-1) == (i->shared = shmat(i->shm_id, i->shared, SHM_R | SHM_W)))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

static int	init_sem(t_process_infos *inf)
{
  if (-1 == (inf->sem_id = semget(inf->key, 1, SHM_RW)))
  {
    if (-1 == (inf->sem_id = semget(inf->key, 1, IPC_CREAT | SHM_RW)))
      return (EXIT_FAILURE);
    semctl(inf->sem_id, 0, SETVAL, 1);
  }
  return (EXIT_SUCCESS);
}

int		game_init(t_process_infos *inf)
{
  if (EXIT_FAILURE == set_id(inf))
  {
    fprintf(stderr, NO_FTOK);
    return (EXIT_FAILURE);
  }
  if (EXIT_FAILURE == init_sem(inf))
  {
    fprintf(stderr, NO_SHM);
    return (EXIT_FAILURE);
  }
  if (EXIT_FAILURE == get_shared_information(inf))
  {
    fprintf(stderr, NO_SHM);
    return (EXIT_FAILURE);
  }
  sem_add(inf);
  inf->trick_id = inf->shared->trick_id;
  return (EXIT_SUCCESS);
}
