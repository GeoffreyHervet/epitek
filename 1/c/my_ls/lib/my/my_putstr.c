/*
** my_putstr.c for lib in /home/hervet_g//work/projets/c/bsq/lib
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:52:49 2010 geoffrey hervet
** Last update Fri Dec 10 17:56:32 2010 geoffrey hervet
*/

#include	<unistd.h>

#include	"libmy.h"

void	my_putstr(char *s, const int fd)
{
  write(fd, s, my_strlen(s));
}
