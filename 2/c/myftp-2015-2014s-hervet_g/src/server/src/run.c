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
#include		<unistd.h>
#include		<string.h>
#include		<stdio.h>

#include		"client.h"
#include		"run.h"

static void		launcher(t_client *client)
{
  pid_t			pid;

  pid = fork();
  if (pid == 0)
  {
    printf("Client connected\n");
    client->wd = strdup(client->srv->cwd);
    client_exec(*client);
    printf("Client disconnected\n");
  }
  else if (pid == -1)
    perror("fork fail");
}

int			run(t_server *serv)
{
  t_client		client;

  client.srv = serv;
  client.sin_size = sizeof(client.sin);
  while (1)
  {
    client.fd = accept(serv->socket,
			(struct sockaddr *)&(client.sin),
			&(client.sin_size));
    if (client.fd == -1)
    {
      perror("accept fail");
      return (EXIT_FAILURE);
    }
    launcher(&client);
  }
  return (EXIT_FAILURE);
}
