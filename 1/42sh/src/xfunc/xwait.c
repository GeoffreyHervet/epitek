/*
** xwait.c for  in /home/rufin_q//projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Thu May  5 15:39:10 2011 quentin rufin
** Last update Sat May 14 18:20:00 2011 tom-brent yau
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	<unistd.h>

pid_t	xwait(int *status)
{
  pid_t	ret;

  if ((ret = wait(status)) == -1)
    fprintf(stderr, "Error on wait\n");
  return (ret);
}
