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
#ifndef SEM_H_
# define SEM_H_

# include "lemipc.h"

# define LOCK_MAP(X)	sem_del(X)
# define UNLOCK_MAP(X)	sem_add(X)

int		sem_add(t_process_infos *inf);
int		sem_del(t_process_infos *inf);

#endif /* SEM_H_ */
