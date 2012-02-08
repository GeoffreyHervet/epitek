/*
** main.c for src in /home/hervet_g/work/unix/minitalk/serveur/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  ven. mars 11 17:40:28 2011 geoffrey hervet
** Last update ven. mars 11 17:40:28 2011 geoffrey hervet
*/

#include	"serv.h"

#include	"aff_pid.h"
#include	"receive_msg.h"
#include	"receive_pid.h"

t_infos		*infos;

static void	jobs()
{
  write(1, "\n", 1);
  infos->have_quit = 0;
  infos->receive = 0;
  infos->client = 0;
  infos->dec = 0;
  receive_pid();
  receive_msg();
  jobs();
}

int		main(int ac, char **av)
{
  t_infos	infos_glb;

  infos = &infos_glb;
  aff_pid();
  jobs();
  return (0);
}
