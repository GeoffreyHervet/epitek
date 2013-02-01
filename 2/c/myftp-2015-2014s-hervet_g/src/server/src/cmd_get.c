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

#include		"cmd_get.h"

static char		*get_file_name(t_client *clt, char *cmd)
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
  while (*tmp == ' ' || *tmp == '\t' || *tmp == '\n')
    *tmp-- = 0;
  tmp = malloc(sizeof(*tmp) * (strlen(clt->wd) + strlen(cmd) + 4));
  if (tmp == NULL)
    return (NULL);
  strcpy(tmp, clt->wd);
  tmp[strlen(clt->wd)] = '/';
  strcpy(tmp + strlen(clt->wd) + 1, cmd);
  if (-1 == stat(tmp, &st))
    return (NULL);
  return (tmp);
}

static int		send_msg(t_client *clt, char *msg, int ret)
{
  int			size;

  size = strlen(msg);
  if (msg[size - 1] == '\n')
    msg[--size] = 0;
  write(clt->fd, &size, sizeof(size));
  write(clt->fd, msg, size);
  return (ret);
}

static void		send_size(t_client *clt, int size)
{
  write(clt->fd, &size, sizeof(size));
}

CMD_FUNC_PROTO(get, clt, cmd)
{
  int			fd;
  int			tmp;
  char			buf[2048];
  char			*file;

  file = NULL;

  printf("cmd = [%s]\n", cmd);
  if (NULL == (cmd = get_file_name(clt, cmd + 3)))
  {
    send_size(clt, -1);
    printf("cmd = %s\n", cmd);
    return (send_msg(clt, "File not found", EXIT_FAILURE));
  }
  if (-1 == (fd = open(cmd, O_RDONLY)))
  {
    send_size(clt, -1);
    return (send_msg(clt, "Can't open file", EXIT_FAILURE));
  }
  send_size(clt, lseek(fd, 0, SEEK_END));
  lseek(fd, 0, SEEK_SET);
  while ((tmp = read(fd, buf, 2048)) > 0)
    write(clt->fd, buf, tmp);
  free(file);
  return (send_msg(clt, "Done!", EXIT_SUCCESS));
}
