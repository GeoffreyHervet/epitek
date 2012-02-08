/*
** xsignal.c for  in /home/yau_t//local/Projets/semestre_2/minitalk/client_dir/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Mar 18 12:07:11 2011 tom-brent yau
** Last update Sat Apr 16 22:51:25 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<signal.h>
#include	"xsignal.h"

void	xsignal(int signum, sighandler_t handler)
{
  if (signal(signum, handler) == SIG_ERR)
    fprintf(stderr, "Signal is invalid\n");
}
