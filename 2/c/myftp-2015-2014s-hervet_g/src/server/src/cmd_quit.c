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
#include		<unistd.h>

#include		"cmd_quit.h"

CMD_FUNC_PROTO(quit, clt, cmd)
{
  int			size;

  (void)cmd;
  clt->quit &= ~1;
  size = -2;
  write(clt->fd, &size, sizeof(size));
  return (0);
}
