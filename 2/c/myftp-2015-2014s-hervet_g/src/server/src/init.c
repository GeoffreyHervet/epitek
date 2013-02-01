/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<stdio.h>
#include		<netdb.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<string.h>

#include		"init.h"

static int		init_socket(t_server *serv)
{
  struct protoent	*pe;

  if (NULL == (pe = getprotobyname("TCP")))
  {
    fprintf(stderr, "Unknown TCP protocole.\n");
    return (EXIT_FAILURE);
  }
  if (-1 == (serv->socket = socket(AF_INET, SOCK_STREAM, pe->p_proto)))
  {
    perror("Socket fail");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

static int		bind_socket(t_server *srv)
{
  struct sockaddr_in	sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(srv->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (-1 == bind(srv->socket, (struct sockaddr *)&sin, sizeof(sin)))
  {
    perror("Bind fail");
    return (EXIT_FAILURE);
  }
  if (-1 == listen(srv->socket, 10))
  {
    perror("listen fail");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

int		init(t_server *srv)
{
  if (NULL == (srv->cwd = realpath(".", NULL)))
  {
    perror("getcwd fail");
    return (EXIT_FAILURE);
  }
  srv->cwd_len = strlen(srv->cwd);
  if (EXIT_FAILURE == init_socket(srv) || EXIT_FAILURE == bind_socket(srv))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
