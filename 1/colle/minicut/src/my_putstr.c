/*
** my_putstr.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 19:40:05 2011 geoffrey hervet
** Last update Tue May 17 19:40:05 2011 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"my_putstr.h"
#include	"my_strlen.h"

void		my_putstr(const char *str, const int fd)
{
  if (write(fd, str, my_strlen(str)) == -1)
  {
    if (fd == 2)
      exit(EXIT_FAILURE);
    my_putstr(str, 2);
  }
}
