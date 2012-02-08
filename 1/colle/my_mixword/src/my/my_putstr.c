/*
** my_putstr.c for my in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/src/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 19:24:17 2011 geoffrey hervet
** Last update Wed May 04 19:24:17 2011 geoffrey hervet
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
    if (fd == 2)
      exit(EXIT_FAILURE);
    else
      write(2, str, my_strlen(str));
  }
}
