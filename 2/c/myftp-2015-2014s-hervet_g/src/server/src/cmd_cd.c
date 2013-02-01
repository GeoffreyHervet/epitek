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
#include		<sys/param.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<string.h>
#include		<stdlib.h>
#include		<ctype.h>

#include		"cmd_cd.h"

static char		is_dir(const char *file, const char *root)
{
  struct stat		tmp;

  if (-1 == stat(file, &tmp) || ((S_IFDIR & tmp.st_mode) != S_IFDIR))
    return (0);
  if (strlen(root) > strlen(file))
    return (-1);
  if (strncmp(root, file, strlen(root) - 1))
    return (-1);
  return (1);
}

static char	      	*send_msg(t_client *clt, char *msg, char *ret)
{
  int			size;

  size = strlen(msg);
  write(clt->fd, &size, sizeof(size));
  write(clt->fd, msg, size);
  return (ret);
}

static char		*epur_dir(char *cmd, t_client *clt)
{
  size_t		idx;

  if (cmd[strlen(cmd) - 1] == '\n')
    cmd[strlen(cmd) - 1] = 0;
  while (*cmd != ' ' && *cmd != '\t' && *cmd != 0)
    cmd++;
  while (*cmd == ' ' || *cmd == '\t')
    cmd++;
  if (!*cmd)
    return (send_msg(clt, "Not enough arguments", NULL));
  idx = 0;
  while (cmd[idx] != ' ' && cmd[idx] != '\t' && cmd[idx] != 0)
    idx++;
  cmd[idx] = 0;
  return (cmd);
}

static char		*real_path(char *path, char *cwd, t_client *clt)
{
  char			*ret;
  size_t		idx;

  if (NULL == (ret = malloc(sizeof(*ret) * (strlen(path) + strlen(cwd) + 3))))
    return (send_msg(clt, "Not found", NULL));
  idx = 0;
  while (*cwd)
    ret[idx++] = *cwd++;
  ret[idx++] = '/';
  while (*path)
    ret[idx++] = *path++;
  ret[idx++] = '/';
  ret[idx] = 0;
  return (ret);
}

CMD_FUNC_PROTO(cd, clt, cmd)
{
  char			*nwd;
  int			tmp;

  if (NULL == (nwd = epur_dir(cmd, clt)))
    return (EXIT_FAILURE);
  if (NULL == (nwd = real_path(nwd, clt->wd, clt)))
    return (EXIT_FAILURE);
  printf("nwd = [%s]\n", nwd);
  tmp = is_dir(nwd, clt->srv->cwd);
  if (tmp != 1)
  {
    send_msg(clt, (tmp == 0) ? "Not found" : "Permission denied", NULL);
    return (EXIT_SUCCESS);
  }
  free(clt->wd);
  if (NULL == (clt->wd = realpath(nwd, NULL)))
    clt->wd = nwd;
  else
    free(nwd);
  send_msg(clt, "Done! ", 0);
  return (EXIT_SUCCESS);
}
