/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<unistd.h>
#include		<fcntl.h>
#include	  	"set_get.h"

#include		"set_get.h"

static char		*get_file_name(char *cmd)
{
  char			*tmp;

  while (*cmd != ' ' && *cmd != '\t' && *cmd != '\0')
    cmd++;
  while (*cmd == ' ' || *cmd == '\t')
    cmd++;
  if (!*cmd)
    return (NULL);
  tmp = cmd + strlen(cmd) - 1;
  while (*tmp == ' ' || *tmp == '\t')
    *tmp-- = 0;
  return (cmd);
}

static int		receive_file(int socket,
					int fd,
					size_t fsize,
					const char *file)
{
  int			tmp;
  size_t		rest;
  char			buf[1024];

  rest = fsize;
  printf("[%-3i%%] %s", 0, file);
  fflush(stdout);
  while (rest > 0)
  {
    if (0 == (tmp = read(socket, buf, 1024)))
      return (EXIT_FAILURE);
    if (-1 == (write(fd, buf, tmp)))
    {
      fprintf(stderr, "\nCan't write into the file !\n");
      return (EXIT_SUCCESS);
    }
    rest -= tmp;
    printf("\r[%-3li%%] %s", 100 * (fsize - rest) / fsize, file);
    fflush(stdout);
  }
  printf("\r[%-3i%%] %s", 100, file);
  return (EXIT_SUCCESS);
}

static int		display_ret(const char *s, int ret)
{
  fprintf(stderr, "%s\n", s);
  return (ret);
}

int			set_get(char *cmd, t_client *clt)
{
  int			fsize;
  int			fd;

  if (NULL == (cmd = get_file_name(cmd)))
    return (display_ret("Bad syntax! get _FILE_\n", -2));
  if (-1 == (fd = open(cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644)))
    return (display_ret("Can\'t create file\n", -2));
  if (-1 == dprintf(clt->fd, "get %s\n", cmd) ||
      -1 == read(clt->fd, &fsize, sizeof(fsize)))
  {
    close(fd);
    fprintf(stderr, "CONNECION ERROR\n");
    return (EXIT_FAILURE);
  }
  if (fsize > 0 && EXIT_FAILURE == receive_file(clt->fd, fd, fsize, cmd))
  {
    close(fd);
    fprintf(stderr, "CONNECION ERROR\n");
    return (EXIT_FAILURE);
  }
  close(fd);
  return (EXIT_SUCCESS);
}
