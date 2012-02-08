/*
** my.c for gnl in /home/hervet_g//work/projets/c/gnl
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 16 23:28:05 2010 geoffrey hervet
** Last update Tue Nov 16 23:29:08 2010 geoffrey hervet
*/

#include	<unistd.h>

unsigned int	my_strlen(char *s)
{
  int		size;

  size = -1;
  if (!s)
    return (0);
  while (s[++size]);
  return (size);
}

void	my_putstr(char *s)
{
  write(1, s, my_strlen(s));
}
