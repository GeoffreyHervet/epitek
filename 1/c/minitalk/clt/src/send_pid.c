/*
** send_pid.c for src in /home/hervet_g/work/unix/minitalk/client/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Mar 12 14:24:15 2011 geoffrey hervet
** Last update Sat Mar 12 14:24:15 2011 geoffrey hervet
*/

#include	<sys/types.h>
#include	<signal.h>
#include	<unistd.h>

#include	"client.h"

#include	"send_pid.h"

extern t_infos	*infos;

static void     xkill(int pid, int sig)
{
  if (kill(pid, sig) == -1)
    write(1, "Kill faillure !\n", 17);
}

static void	sig_pid(int pid, int dec)
{
  if (dec < 32)
  {
    xkill(infos->pid, (pid & (1 << dec)) ? SIGUSR2 : SIGUSR1);
    usleep(200);
    sig_pid(pid, dec + 1);
  }
}

static void	answer(int sig)
{
  infos->bit = sig;
}

void		send_pid(void)
{
  infos->bit = 0;
  signal(SIGUSR1, answer);
  sig_pid(getpid(), 0);
  usleep(9000);
}
