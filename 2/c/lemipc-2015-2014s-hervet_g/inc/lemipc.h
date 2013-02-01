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
#ifndef LEMIPC_H_
# define LEMIPC_H_

# include <sys/types.h>
# include <sys/shm.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define MAP_WIDTH		(80)
# define MAP_HEIGHT		(60)
# define PLAYER_SIZE_PXL	(10)
# define MAP_SIZE		(MAP_WIDTH * MAP_HEIGHT)
# define ROUND_ALONE_MAX	(10)

/*
** Interval de temps minimum entre 2 actions (micro sec)
*/

# define TIME_WAIT		(600000)

/*
** Cool stuff
*/

# define MAP(map, x, y)		(map[MAP_WIDTH * (y) + (x)])
# define IDX_TO_X(idx)		((idx) % MAP_WIDTH)
# define IDX_TO_Y(idx)		((int)(idx) / MAP_WIDTH)
# define MAX_CONSECUTIVE_FAILS	(20)
# define ENABLE_CHECK_MOVES	(0)

# ifndef SHM_RW
#  define SHM_RW		(SHM_R | SHM_W)
# endif

/*
** ERROR MESSAGES
*/

# define NO_FTOK		"Can't get unique key (ftok)\n"
# define NO_SHM			"Can't get shared memory (shm*)\n"
# define NO_SEM			"Can't get semaphore (sem*)\n"

/*
** Structure contenue dans la memoire partage
*/

# define DEFAULT_TEAM_NB	(2)

typedef struct
{
  unsigned char	map[MAP_SIZE];
  unsigned int	trick_id;
}		t_infos;

typedef struct
{
  unsigned char	team_id;
  key_t		key;
  int		sem_id;
  int		shm_id;
  unsigned int	position;
  unsigned int	trick_id;
  t_infos	*shared;
}		t_process_infos;

#endif /* LEMIPC_H_ */
