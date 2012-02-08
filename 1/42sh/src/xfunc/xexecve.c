/*
** xexecve.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 13 20:28:02 2011 tom-brent yau
** Last update Fri May 13 20:42:41 2011 tom-brent yau
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<string.h>
#include	<stdio.h>

void	xexecve(const char *filename, char *const argv[],
		char *const envp[])
{
  int	errno;

  errno = 0;
  if (execve(filename, argv, envp) == -1)
    fprintf(stderr, "%s : %s\n", filename, strerror(errno));
  exit(EXIT_FAILURE);
}
