/*
** put_cap.c for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 12:38:58 2011 geoffrey hervet
** Last update Sat Jan 15 14:24:16 2011 geoffrey hervet
*/

#include	<unistd.h>

#include	"put_cap.h"

int		put_cap(int c)
{
  static int	fd = -1;

  if (fd == -1)
    {
      fd = c;
      return (0);
    }
  return (write(fd, &c, 1));
}
