/*
** my_strlen.c for lib in /home/hervet_g//work/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 21:50:25 2010 geoffrey hervet
** Last update Sun Jan  2 11:32:17 2011 geoffrey hervet
*/

#include	"libmy.h"

unsigned int	my_strlen(const char *s)
{
  unsigned int	size;

  if (!s)
    return (0);
  size = 0;
  while (s[size])
    ++size;
  return (size);
}
