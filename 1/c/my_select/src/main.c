/*
** main.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Jan 14 17:15:31 2011 geoffrey hervet
** Last update Wed Jan 26 16:00:59 2011 geoffrey hervet
*/

#include	<signal.h>
#include	<unistd.h>

#include	<stdlib.h>

#include	"libmy.h"
#include	"my_select.h"

#include	"action/action.h"
#include	"display/display_list.h"
#include	"init/init_fd.h"
#include	"init/init_keys.h"
#include	"init/init_list.h"
#include	"init/init_termios.h"
#include	"init/init_window.h"

static int	fd;
static t_infos	*infos_ptr;

static void	resized(int sig)
{
  t_list_db	*tmp;

  sig = 0;
  init_window(infos_ptr, fd);
  tmp = infos_ptr->begin;
  while (tmp != NULL)
    {
      tmp->coords.col = 0;
      tmp->coords.row = 0;
      tmp = tmp->next;
      if (tmp == infos_ptr->begin)
	tmp = NULL;
    }
  display_list(infos_ptr, fd);
  signal(SIGWINCH, resized);
}

int		main(const int ac,
		     const char **av,
		     const char **env)
{
  t_infos	inf;
  char		buf[5];
  int		nb_read;

  if ((init_fd(&fd)) ||
      (init_termios(env, fd) == -1) ||
      (init_window(&inf, fd) == -1) ||
      (init_list(&inf, ac, av) == -1))
    return (1);
  init_keys();
  infos_ptr = &inf;
  inf.cursor_item = inf.begin;
  display_list(&inf, fd);
  signal(SIGWINCH, resized);
  while ((nb_read = read(0, buf, 4)) >= 0)
    {
      buf[nb_read] = '\0';
      action(&inf, fd, buf);
    }
  return (0);
}

