/*
** o.c for HEADER A LA NORME!!! in /home/hervet_g/
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sun Mar 25 13:36:49 2012 geoffrey hervet
** Last update Sun Mar 25 13:36:49 2012 geoffrey hervet
*/

#include		<string.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<readline.h>

#include		"run.h"
#include		"set_put.h"
#include		"set_get.h"

static int		err_ret(const char *err, int ret)
{
  fprintf(stderr, "%s\n", err);
  return (ret);
}

static int		read_answer(int read_size,
					char buf[2048],
					t_client *clt)
{
  int			tmp;

  while (read_size > 0)
  {
    tmp = read(clt->fd, buf, 2047);
    if (tmp == -1)
      return (err_ret("Can't get information from the server", EXIT_FAILURE));
    write(1, buf, tmp);
    read_size -= 2047;
  }
  return (EXIT_SUCCESS);
}

static int		dialog(t_client *clt)
{
  int			read_size;
  char			buf[2048];

  if (read(clt->fd, &read_size, sizeof(read_size)) <= 0)
    return (err_ret("Can't get information from the server", EXIT_FAILURE));
  if (read_size == -2)
    return (-1337);
  if (read_size == -1)
    return (err_ret("Command not found", EXIT_SUCCESS));
  return (read_answer(read_size, buf, clt));
}

static int		work(char *str, t_client *clt)
{
  int			tmp;

  if (!strncmp("put", str, 3)  && (str[3] == ' ' || str[3] == '\t'))
  {
    if (-2 == (tmp = set_put(str, clt)))
      return (EXIT_SUCCESS);
    else if (tmp == EXIT_FAILURE)
      return (EXIT_FAILURE);
  }
  else if (!strncmp("get", str, 3)  && (str[3] == ' ' || str[3] == '\t'))
  {
    if (-2 == (tmp = set_get(str, clt)))
      return (EXIT_SUCCESS);
    else if (tmp == EXIT_FAILURE)
      return (EXIT_FAILURE);
  }
  else if (write(clt->fd, str, strlen(str)) <= 0)
    return (err_ret("Can't send information to the server", EXIT_FAILURE));
  return (dialog(clt));
}

int			run(t_client *clt)
{
  char			*str;
  int			tmp;

  while (1)
  {
    str = readline("ftp>");
    if (strlen(str))
    {
      tmp = work(str, clt);
      free(str);
      if (tmp == EXIT_FAILURE)
        return (EXIT_FAILURE);
      if (tmp == -1337)
        return (EXIT_SUCCESS);
      printf("\n");
    }
  }
  return (EXIT_FAILURE);
}
