/*
** xkill.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 14 18:20:56 2011 tom-brent yau
** Last update Sat May 14 18:31:46 2011 tom-brent yau
*/

#include	<sys/types.h>
#include	<signal.h>
#include	<errno.h>
#include	<string.h>
#include	<stdio.h>

int	xkill(pid_t pid, int sig)
{
  int	ret;
  int	errno;

  errno = 0;
  if ((ret = kill(pid, sig)) == -1)
    {
      fprintf(stderr, "%s\n", strerror(errno));
    }
  return (ret);
}
