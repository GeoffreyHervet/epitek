/*
** my_putstr.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Apr 11 17:15:37 2011 geoffrey hervet
** Last update Mon Apr 11 17:15:37 2011 geoffrey hervet
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"my_putstr.h"
#include	"my_strlen.h"

void		my_putstr(const char *str,
			  const int fd)
{
  if (write(fd, str, my_strlen(str)) == -1)
  {
    if ((fd == 1 && write(2, str, my_strlen(str)) == -1) ||
        (fd == 2))
      exit(EXIT_FAILURE);
    else if (fd != 1)
      my_putstr("my_putstr can't write", 2);
   }
}
