/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

#include	"init.h"
#include	"run.h"

static int	usage(const char *name)
{
  fprintf(stderr, "Usage: %s port\n", name);
  return (EXIT_FAILURE);
}

static int	set_port(int ac,
			 const char **av,
			 t_server *serv)
{
  if (ac < 2)
    return (EXIT_FAILURE);
  serv->port = atoi(av[1]);
  return (EXIT_SUCCESS);
}

int		main(int ac, const char **av)
{
  t_server	serv;

  if (EXIT_FAILURE == set_port(ac, av, &serv))
    return (usage(av[0]));
  if (EXIT_SUCCESS == init(&serv))
    run(&serv);
  close(serv.socket);
  free(serv.cwd);
  return (EXIT_FAILURE);
}
