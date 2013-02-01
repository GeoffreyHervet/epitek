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
#include	<sys/shm.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"game/exit.h"
#include	"game/is_last.h"

int		game_exit(t_process_infos *inf)
{
  if (is_last(inf))
  {
    semctl(inf->sem_id, 1, IPC_RMID);
    shmctl(inf->shm_id, IPC_RMID, NULL);
  }
  return (EXIT_SUCCESS);
}
