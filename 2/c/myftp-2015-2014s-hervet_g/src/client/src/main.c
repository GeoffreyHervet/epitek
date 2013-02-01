/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>

#include		"init.h"
#include		"run.h"

static int		usage_ret(const char *name)
{
  fprintf(stderr, "Usage: %s ip port\n", name);
  return (EXIT_FAILURE);
}

static int		get_args(int ac, char **av, t_client *clt)
{
  if (ac != 3)
    return (EXIT_FAILURE);
  clt->ip = av[1];
  clt->port = atoi(av[2]);
  return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
  t_client		client;

  if (EXIT_FAILURE == get_args(ac, av, &client))
    return (usage_ret(av[0]));
  if (EXIT_FAILURE == init(&client))
    return (EXIT_FAILURE);
  run(&client);
  close(client.fd);
  return (EXIT_SUCCESS);
}
