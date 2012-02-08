/*
** receive_msg.c for src in /home/hervet_g/work/unix/minitalk/serveur/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Mar 12 18:44:23 2011 geoffrey hervet
** Last update Sat Mar 12 18:44:23 2011 geoffrey hervet
*/

#include	<sys/types.h>
#include	<signal.h>
#include	<unistd.h>

#include	"serv.h"

#include	"receive_msg.h"

#ifndef		__builtin_popcount
# define	__builtin_popcount(x) my_popcount(x)
#endif		/* !__builtin_popcount */

extern t_infos	*infos;

static void	xkill(int pid, int sig)
{
  if (kill(pid, sig) == -1)
    write(1, "Kill faillure !\n", 17);
}

static int	my_popcount(int nb)
{
  if (!nb)
    return (0);
  return ((nb & 1) + my_popcount(nb >> 1));
}

static void	receive_sig(int signum)
{
  if (signum == SIGUSR2)
    infos->receive |= 1 << infos->dec;
  infos->dec++;
  xkill(infos->client, signum);
  if (infos->dec == 8)
  {
    if (infos->receive)
      write(1, &(infos->receive), 1);
    else
      infos->have_quit = 1;
    infos->receive = 0;
    infos->dec = 0;
  }
}

static void	job_signal(void)
{
  if (!infos->have_quit)
  {
    usleep(42000);
    job_signal();
  }
}

void		receive_msg(void)
{
  infos->dec = 0;
  infos->receive = 0;
  infos->have_quit = 0;
  signal(SIGUSR1, receive_sig);
  signal(SIGUSR2, receive_sig);
  job_signal();
}

