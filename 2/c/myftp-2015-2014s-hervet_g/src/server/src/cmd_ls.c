/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include		<sys/dir.h>
#include		<dirent.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		<unistd.h>

#include		"cmd_ls.h"

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

static char		*add_in_str(char *dest, const char *src, char is_dir)
{
  size_t		idx;

  if (dest == NULL)
  {
    idx = strlen(src);
    dest = malloc(sizeof(*dest) * (idx + 2));
    dest = strcpy(dest, src);
    dest[idx] = '\n';
    dest[idx + 1] = 0;
    return (dest);
  }
  idx = strlen(dest);
  dest = realloc(dest, sizeof(*dest) * (strlen(src) + idx + is_dir + 4));
  while (*src)
    dest[idx++] = *src++;
  if (is_dir)
    dest[idx++] = '/';
  dest[idx] = '\n';
  dest[idx + 1] = 0;
  return (dest);
}

CMD_FUNC_PROTO(ls, clt, cmd)
{
  DIR			*directory;
  struct dirent		*file;
  char			*send;

  (void) cmd;
  if (NULL == (directory = opendir(clt->wd)))
    return send_msg(clt, "Can't opendir", EXIT_FAILURE);
  send = NULL;
  while (NULL != (file = readdir(directory)))
  {
    if (file->d_name[0] != '.' || file->d_name[1] != 0)
      send = add_in_str(send, file->d_name, file->d_type == DT_DIR);
  }
  send_msg(clt, send, 0);
  free(send);
  closedir(directory);
  return (EXIT_SUCCESS);
}
