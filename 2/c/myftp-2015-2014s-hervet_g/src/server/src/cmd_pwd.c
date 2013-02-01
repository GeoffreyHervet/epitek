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
#include		<string.h>
#include		<unistd.h>
#include		<stdio.h>

#include		"cmd_pwd.h"

CMD_FUNC_PROTO(pwd, clt, cmd)
{
  size_t		idx;
  char			*tmp;
  char			to_free;

  (void)cmd;
  to_free = 0;
  tmp = malloc(sizeof(*tmp) * (strlen(clt->wd) + clt->srv->cwd_len + 3));
  if (tmp == NULL)
    tmp = clt->wd;
  else
  {
    strcpy(tmp, clt->wd + clt->srv->cwd_len);
    idx = strlen(tmp);
    tmp[idx++] = '/';
    tmp[idx] = 0;
    to_free = 1;
  }
  idx = strlen(tmp);
  write(clt->fd, &idx, sizeof(idx));
  write(clt->fd, tmp, idx);
  if (to_free)
    free(tmp);
  return (EXIT_FAILURE);
}
