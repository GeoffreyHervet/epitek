/*
** my_strlen.c for lib in /home/hervet_g//work/projets/c/bsq/lib
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:50:25 2010 geoffrey hervet
** Last update Fri Dec 10 17:54:44 2010 geoffrey hervet
*/

#include	"libmy.h"

int	my_strlen(char *s)
{
  int	size;

  if (!s)
    return (0);
  size = -1;
  while (s[++size]);
  return (size);
}
