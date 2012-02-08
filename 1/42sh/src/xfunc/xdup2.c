/*
** xdup2.c for  in /home/rufin_q//projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Tue May  3 20:26:20 2011 quentin rufin
** Last update Fri May 13 19:55:26 2011 tom-brent yau
*/

#include	<unistd.h>
#include	<stdio.h>

int	xdup2(int old, int new)
{
  int	ret;

  if ((ret = dup2(old, new)) == -1)
    fprintf(stderr, "Error on dup2\n");
  return (ret);
}
