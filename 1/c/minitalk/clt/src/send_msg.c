/*
** send_msg.c for src in /home/hervet_g/work/unix/minitalk/client/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Mar 13 01:41:41 2011 geoffrey hervet
** Last update Sun Mar 13 01:41:41 2011 geoffrey hervet
*/

#include	<signal.h>
#include	<unistd.h>

#include	"client.h"
#include	"send_msg.h"

extern t_infos	*infos;

static void	receive_msg(int signum)
{
  (void)signum;
  infos->bit++;
}

static void     xkill(int pid, int sig)
{
  if (kill(pid, sig) == -1)
    write(1, "Kill faillure !\n", 17);
}

static void	send_char(const char c)
{
  if (c & (1 << infos->bit))
    xkill(infos->pid, SIGUSR2);
  else
    xkill(infos->pid, SIGUSR1);
  usleep(2000);
  if (infos->bit < 8)
    send_char(c);
  else
    infos->bit = 0;
}

void		send_msg(char *str)
{
  if (*str)
  {
    signal(SIGUSR1, receive_msg);
    signal(SIGUSR2, receive_msg);
    infos->bit = 0;
    send_char(*str);
    send_msg(str + 1);
  }
  else
    send_char(0);
}
