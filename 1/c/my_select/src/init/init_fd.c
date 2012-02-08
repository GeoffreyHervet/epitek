/*
** init_fd.c for my_select in /home/hervet_g//work/projets/my_select
**
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
**
** Started on  Sat Jan 15 11:24:42 2011 geoffrey hervet
** Last update Sat Jan 15 14:33:16 2011 geoffrey hervet
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#include	"libmy.h"
#include	"my_select.h"

#include	"init/init_fd.h"
#include	"put_cap.h"

int		init_fd(int *fd)
{
  if ((*fd = open("/dev/tty", O_WRONLY)) == -1)
    {
      my_putstr(ERR_OPEN, 2);
      return (-1);
    }
  put_cap(*fd);
  return (0);
}
