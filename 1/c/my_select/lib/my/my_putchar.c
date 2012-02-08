/*
** my_putchar.c for lib in /home/hervet_g//work/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:49:19 2010 geoffrey hervet
** Last update Fri Jan 14 20:15:59 2011 geoffrey hervet
*/

#include	<unistd.h>

#include	"libmy.h"

void	my_putchar(const char c,
		   const int fd)
{
  write(fd, &c, 1);
}
