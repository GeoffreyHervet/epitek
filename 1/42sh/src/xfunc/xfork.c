/*
** xfork.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 13 19:58:10 2011 tom-brent yau
** Last update Fri May 13 19:59:35 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<unistd.h>

int	xfork()
{
  pid_t	ret;

  if ((ret = fork()) == -1)
    fprintf(stderr, "Error on fork\n");
  return (ret);
}
