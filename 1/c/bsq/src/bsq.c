/*
** bsq.c for bsq in /home/hervet_g//work/projets/c/bsq/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Nov 11 21:46:50 2010 geoffrey hervet
** Last update Sat Nov 13 15:10:05 2010 geoffrey hervet
*/

#include <stdio.h>

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>

#include	"lib.h"
#include	"header.h"
#include	"gnl.h"
#include	"calculs.h"
#include	"display.h"

static int	my_getnbr(char *str)
{
  int		idx;
  int		res;
  int		signe;

  idx = 0;
  res = 0;
  signe = 1;
  if (str[idx] == '-')
    {
      signe = -1;
      idx++;
    }
  while (str[idx])
    {
      if (str[idx] >= '0' && str[idx] <= '9')
	res = res * 10 + str[idx] - '0';
      idx++;
    }
  return (res * signe);
}

static int	do_in_tab(int fd, t_file *f)
{
  int		nb_lines;
  int		tab_line;

  nb_lines = 0;
  tab_line = -1;
  nb_lines = my_getnbr(get_next_line(fd));
  if ((f->tab = malloc(sizeof(*f->tab) * (nb_lines + 1))) == NULL)
    {
      f->message = ERR_ALLOC;
      close(fd);
      return (-1);
    }
  f->tab[nb_lines + 1] = NULL;
  while (++tab_line < nb_lines)
    {
      if (!(f->tab[tab_line] = get_next_line(fd)))
	{
	  f->tab[tab_line] = NULL;
	  f->message = ERR_LINES;
	  return (-1);
	}
    }
  return (0);
}

int		do_bsq(char *path, t_file *f)
{
  int		fd;

  if ((fd= open(path, O_RDONLY)) == -1)
    {
      f->message = ERR_OPEN;
      close(fd);
      return (-1);
    }
  if (do_in_tab(fd, f) == -1)
    return (-1);
  do_calculs(f);
  display(f);
  close(fd);
  return (0);
}
