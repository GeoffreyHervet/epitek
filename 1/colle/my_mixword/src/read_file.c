/*
** read_file.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 20:29:36 2011 geoffrey hervet
** Last update Wed May  4 22:29:25 2011 tracy nelcha
*/

#include	<fcntl.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>

#include	"types.h"

#include	"gnl.h"
#include	"my_putstr.h"
#include	"my_strlen.h"
#include	"putinlist.h"
#include	"read_file.h"
#include	"sortlist.h"
#include	"bbsort.h"

int		read_file(t_infos *inf)
{
  char		*str;
  t_list	*begin;

  begin = NULL;
  if ((inf->fd = open(inf->name, O_RDONLY)) == -1)
  {
    my_putstr(ERR_OPEN, 2);
    return (-1);
  }
  while ((str = gnl(inf->fd)) != NULL)
  {
    if (my_strlen(str) <= inf->size)
    {
      if (putinlist(&begin, str))
        return (-1);
    }
    else
      free(str);
  }
  if (close(inf->fd))
    my_putstr(ERR_CLOSE, 2);
  inf->begin = begin;
  sortlist(begin, bbsort);
  return (0);
}
