/*
** xwrite.c for xwrite in /home/yau_t//local/Projets/mysh/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Jan  3 18:20:39 2011 tom-brent yau
** Last update Sun May 22 20:26:20 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<unistd.h>

int	xwrite(int fd, const void *buf, int count)
{
  int	ret;

  if ((ret = write(fd, buf, count)) == -1)
    {
      fprintf(stderr, "Error using function write\n");
    }
  return (ret);
}
