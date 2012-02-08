/*
** xwrite.c for  in /u/all/hervet_g/public/opt_get/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 20:40:11 2011 tracy nelcha
** Last update Mon May  9 21:05:43 2011 tracy nelcha
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my_putstr.h"

int		xwrite(int fd, const void *buf, int count)
{
  int		ptr;

  ptr = write(fd, buf, count);
  if (ptr == -1)
  {
    my_putstr("ERROR WRITE\n");
    exit(EXIT_FAILURE);
  }
  return (ptr);
}
