/*
** main.c for src in /home/hervet_g/work/unix/minitalk/client/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Mar 12 10:44:02 2011 geoffrey hervet
** Last update Sat Mar 12 10:44:02 2011 geoffrey hervet
*/

#include	<signal.h>
#include	<sys/types.h>

#include	"client.h"

#include	"get_pid.h"
#include	"send_pid.h"
#include	"send_msg.h"

t_infos		*infos;

int		main(int ac, char **av)
{
  t_infos	informations;

  infos = &informations;
  infos->pid = 0;
  if (ac != 3)
    return (1);
  if (get_pid(av[1]) == -1)
    return (1);
  send_pid();
  if (!infos->bit)
  {
    write(1, "Server timeout !\n", 18);
    kill(SIGINT, infos->pid);
    return (1);
  }
  send_msg(av[2]);
  return (0);
}
