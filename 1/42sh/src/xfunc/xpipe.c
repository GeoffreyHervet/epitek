/*
** xpipe.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 13 19:56:45 2011 tom-brent yau
** Last update Fri May 13 19:58:03 2011 tom-brent yau
*/

#include	<unistd.h>
#include	<stdio.h>

int	xpipe(int fd[2])
{
  int	ret;

  if ((ret = pipe(fd)) == -1)
    fprintf(stderr, "Error on pipe\n");
  return (ret);
}
