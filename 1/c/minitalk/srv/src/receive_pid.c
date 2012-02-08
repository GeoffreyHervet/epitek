/*
** receive_pid.c for src in /home/hervet_g/work/unix/minitalk/serveur/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  ven. mars 11 18:59:11 2011 geoffrey hervet
** Last update ven. mars 11 18:59:11 2011 geoffrey hervet
*/

#include	<signal.h>
#include	<unistd.h>

#include	<stdio.h>

#include	"serv.h"

#include	"receive_pid.h"

extern t_infos	*infos;

static void     xkill(int pid, int sig)
{
  if (kill(pid, sig) == -1)
    write(1, "Kill faillure !\n", 17);
}

static void	receive_signal(int signum)
{
  if (signum == SIGUSR2)
    infos->receive |= 1 << infos->dec;
  if (++(infos->dec) == 32)
    infos->client = infos->receive;
}

static void	make_pause(void)
{
  if (!infos->client)
  {
    pause();
    make_pause();
  }
}

void		receive_pid(void)
{
  signal(SIGUSR1, receive_signal);
  signal(SIGUSR2, receive_signal);
  make_pause();
  xkill(infos->client, SIGUSR1);
}
