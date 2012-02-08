/*
** xwaitpid.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 14 18:14:54 2011 tom-brent yau
** Last update Sat May 14 18:31:27 2011 tom-brent yau
*/

#include	<sys/wait.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdio.h>

pid_t	xwaitpid(pid_t pid, int *status, int options)
{
  pid_t	ret;

  if ((ret = waitpid(pid, status, options)) == -1)
    fprintf(stderr, "Error on waitpid\n");
  return (ret);
}
