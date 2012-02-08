/*
** my_strlen.c for lib in /home/hervet_g//work/projets/c/bsq/lib
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:50:25 2010 geoffrey hervet
** Last update Fri Nov 12 21:57:31 2010 geoffrey hervet
*/

#include	"lib.h"

int	my_strlen(char *s)
{
  int	size;

  size = -1;
  while (s[++size]);
  return (size);
}
