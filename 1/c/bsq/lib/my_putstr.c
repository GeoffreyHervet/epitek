/*
** my_putstr.c for lib in /home/hervet_g//work/projets/c/bsq/lib
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:52:49 2010 geoffrey hervet
** Last update Fri Nov 12 21:53:27 2010 geoffrey hervet
*/

#include	<unistd.h>

#include	"lib.h"

void	my_putstr(char *s)
{
  write(1, s, my_strlen(s));
}
