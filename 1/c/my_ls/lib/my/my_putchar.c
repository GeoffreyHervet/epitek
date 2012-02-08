/*
** my_putchar.c for lib in /home/hervet_g//work/projets/c/bsq/lib
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:49:19 2010 geoffrey hervet
** Last update Fri Dec 10 17:55:59 2010 geoffrey hervet
*/

#include	<unistd.h>

#include	"libmy.h"

void	my_putchar(char c, const int fd)
{
  write(fd, &c, 1);
}
