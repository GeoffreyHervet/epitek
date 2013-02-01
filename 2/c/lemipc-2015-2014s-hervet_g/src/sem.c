/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/
/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
 */
#include	<sys/shm.h>
#include	<sys/sem.h>
#include	<sys/ipc.h>
#include	<sys/types.h>

#include	"sem.h"

static int	sem_operation(short val, int sem_id)
{
  struct sembuf	sops;

  sops.sem_num = 0;
  sops.sem_op = val;
  sops.sem_flg = 0;
  return (semop(sem_id, &sops, 1));
}

int		sem_add(t_process_infos *inf)
{
  return (sem_operation(1, inf->sem_id));
}

int		sem_del(t_process_infos *inf)
{
  return (sem_operation(-1, inf->sem_id));
}
