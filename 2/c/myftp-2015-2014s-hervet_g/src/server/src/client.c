/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"server.h"
#include	"client.h"
#include	"commands.h"

static struct {
  const char	*cmd;
  int		(*func)(t_client *, char *);
}		cmd_func[] =
{
  {"quit", cmd_quit},
  {"ls", cmd_ls},
  {"pwd", cmd_pwd},
  {"cd", cmd_cd},
  {"put", cmd_put},
  {"get", cmd_get},
  {NULL, NULL}
};

static int	exec_cmd(char *cmd, t_client *clt)
{
  size_t	idx;
  int		size;

  idx = 0;
  while (cmd_func[idx].cmd != NULL)
  {
    if (!strncmp(cmd_func[idx].cmd, cmd, strlen(cmd_func[idx].cmd)))
      return cmd_func[idx].func(clt, cmd);
    ++idx;
  }
  size = -1;
  write(clt->fd, &size, sizeof(size));
  fprintf(stderr, "\n[Command not found!] : \"%s\"", cmd);
  return (-1);
}

void		client_exec(t_client clt)
{
  char		buf[BUFF_LEN];
  int		readed;

  clt.quit = 1;
  while (clt.quit & 1)
  {
    memset(buf, 0, BUFF_LEN);
    if ((readed = read(clt.fd, buf, BUFF_LEN - 1)) <= 0)
    {
      if (readed == -1)
        perror("Read fail");
      return ;
    }
    exec_cmd(buf, &clt);
  }
  write(clt.fd, "\0", 1);
}
