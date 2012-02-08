/*
** init_window.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 13:03:20 2011 geoffrey hervet
** Last update Sat Jan 15 13:10:10 2011 geoffrey hervet
*/

#include	<sys/ioctl.h>

#include	<stdlib.h>

#include	"libmy.h"
#include	"my_select.h"

#include	"init/init_window.h"

int			init_window(t_infos *inf,
				    const int fd)
{
  struct winsize	win;

  if ((inf->window = malloc(sizeof(*(inf->window)))) == NULL)
    {
      my_putstr(ERR_MALLOC, 2);
      return (-1);
    }
  ioctl(fd, TIOCGWINSZ, &win);
  inf->window->col = win.ws_col;
  inf->window->row = win.ws_row;
  return (0);
}

