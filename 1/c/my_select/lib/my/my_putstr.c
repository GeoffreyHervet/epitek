/*
** my_putstr.c for lib in /home/hervet_g//work/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:52:49 2010 geoffrey hervet
** Last update Fri Jan 14 20:15:42 2011 geoffrey hervet
*/

#include	<unistd.h>

#include	"libmy.h"

void	my_putstr(const char *s,
		  const int fd)
{
  write(fd, s, my_strlen(s));
}
