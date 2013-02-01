/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include	<netdb.h>
#include	<arpa/inet.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

#include	"init.h"

static int	init_socket(t_client *clt)
{
  struct protoent	*pe;

  if (NULL == (pe = getprotobyname("TCP")))
  {
    fprintf(stderr, "Unknown TCP protocole.\n");
    return (EXIT_FAILURE);
  }
  if (-1 == (clt->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)))
  {
    perror("Socket fail");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

int		init(t_client *clt)
{
  struct sockaddr_in	sin;

  if (EXIT_FAILURE == init_socket(clt))
    return (EXIT_FAILURE);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(clt->port);
  sin.sin_addr.s_addr = inet_addr(clt->ip);
  if (-1 == connect(clt->fd, (struct sockaddr*)&sin, sizeof(sin)))
  {
    perror("connect fail");
    close(clt->fd);
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
