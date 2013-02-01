/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include		<sys/stat.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<unistd.h>
#include		<fcntl.h>

#include		"set_put.h"

static char		*get_file_name(char *cmd)
{
  char			*tmp;
  struct stat		st;

  while (*cmd != ' ' && *cmd != '\t' && *cmd != '\0')
    cmd++;
  while (*cmd == ' ' || *cmd == '\t')
    cmd++;
  if (!*cmd)
    return (NULL);
  tmp = cmd + strlen(cmd) - 1;
  while (*tmp == ' ' || *tmp == '\t')
    *tmp-- = 0;
  if (-1 == stat(cmd, &st))
  {
    fprintf(stderr, "File not found!\n");
    return (NULL);
  }
  return (cmd);
}

static int		write_file(int fd_serv,
					const char *file,
					int fd,
					size_t fsize)
{
  char			buf[3072];
  int			read_size;
  size_t		rest;

  rest = fsize;
  while ((read_size = read(fd, buf, 3072)) > 0)
  {
    if (-1 == write(fd_serv, buf, read_size))
      return (-2);
    rest -= read_size;
    if (rest)
      printf("\r[%-3li%%] %s", 100 * (fsize - rest) / fsize , file);
    fflush(stdout);
  }
  printf("\r[%-3i%%] %s\r", 100, file);
  fflush(stdout);
  close(fd);
  return (read_size);
}

static int		send_file(int fd_serv, const char *file)
{
  int			fd;
  size_t		fsize;

  if (-1 == (fd = open(file, O_RDONLY)))
    return (-1);
  fsize = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);
  if (-1 == write(fd_serv, &fsize, sizeof(fsize)))
  {
    close(fd);
    return (-1);
  }
  printf("\r[%-3i%%] %s", 0, file);
  fflush(stdout);
  return (write_file(fd_serv, file, fd, fsize));
}

int			set_put(char *cmd, t_client *clt)
{
  char			nok;

  if (NULL == (cmd = get_file_name(cmd)))
    return (-2);
  if (-1 == dprintf(clt->fd, "put %s\n", cmd))
  {
    fprintf(stderr, "CONNECION ERROR\n");
    return (EXIT_FAILURE);
  }
  if (-1 == read(clt->fd, &nok, sizeof(nok)))
  {
    fprintf(stderr, "CONNECION ERROR\n");
    return (EXIT_FAILURE);
  }
  if (nok == 1)
    return (EXIT_SUCCESS);
  if (-2 == send_file(clt->fd, cmd))
  {
    fprintf(stderr, "CONNECION ERROR\n");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}
