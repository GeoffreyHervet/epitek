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
#include		<string.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<fcntl.h>

#include		"server.h"
#include		"cmd_put.h"

static int		send_msg(t_client *clt, char *msg, int ret, char problem)
{
  int			size;

  if (problem)
    write(clt->fd, &problem, sizeof(problem));
  size = strlen(msg);
  if (msg[size - 1] == '\n')
    msg[--size] = 0;
  write(clt->fd, &size, sizeof(size));
  write(clt->fd, msg, size);
  return (ret);
}

static int		create_file(t_client *clt, char *file)
{
  int			fd;
  char			*fname;

  fname = malloc(sizeof(*fname) * (strlen(clt->wd) + strlen(file) + 3));
  if (fname == NULL)
    return (-1);
  strcpy(fname, clt->wd);
  fd = strlen(fname);
  fname[fd++] = '/';
  while (*file)
    fname[fd++] = *file++;
  fname[fd] = '\0';
  return (open(fname, O_CREAT | O_TRUNC | O_WRONLY, 0644));
}

static char		*get_file_name(char *cmd)
{
  char      *tmp;

  while (*cmd != ' ' && *cmd != '\t' && *cmd != '\0')
    cmd++;
  while (*cmd == ' ' || *cmd == '\t')
    cmd++;
  if (!*cmd)
    return (NULL);
  tmp = cmd + strlen(cmd) - 1;
  while (*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
    *tmp-- = 0;
  return (cmd);
}

static void		send_ok(int fd)
{
  char			c;

  c = 0;
  write(fd, &c, sizeof(c));
}

CMD_FUNC_PROTO(put, clt, cmd)
{
  size_t		file_size;
  char			buf[BUF_SIZE];
  int			tmp;
  int			fd;
  char			problem;

  if (NULL == (cmd = get_file_name(cmd)))
    return (send_msg(clt, "No file name !", EXIT_FAILURE, 1));
  if (-1 == (fd = create_file(clt, cmd)))
    return (send_msg(clt, "-> Couldn\'t not create file", EXIT_FAILURE, 1));
  send_ok(clt->fd);
  if (-1 == read(clt->fd, &file_size, sizeof(file_size)))
    return (EXIT_FAILURE);
  problem = 0;
  while (file_size > 0)
  {
    if (-1 == (tmp = read(clt->fd, buf, BUF_SIZE)))
      return (send_msg(clt, "A problem occuring...", EXIT_FAILURE, 1));
    file_size -= tmp;
    if (-1 == write(fd, buf, tmp))
      problem = 1;
  }
  close(fd);
  return (send_msg(clt, problem ? "A problem occuring..." : "File transfer te"
    "rminated !", problem  ? EXIT_FAILURE : EXIT_SUCCESS, 0));
}

/*
** La norme ...
*/
