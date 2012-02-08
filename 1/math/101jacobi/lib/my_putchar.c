/*
** my_putchar.c for lib in /home/hervet_g//work/projets/c/bsq/lib
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:49:19 2010 geoffrey hervet
** Last update Fri Nov 12 21:52:39 2010 geoffrey hervet
*/

#include	<unistd.h>

#include	"lib.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
