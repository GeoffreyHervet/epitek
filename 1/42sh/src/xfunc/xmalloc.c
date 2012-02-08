/*
** xmalloc.c for  in /home/rufin_q//projet/42sh/42sh/src
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Tue Apr  5 16:53:30 2011 quentin rufin
** Last update Sat Apr 16 22:50:47 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<stdlib.h>

void	*xmalloc(int size)
{
  void	*ret;

  ret = malloc(size);
  if (ret == NULL)
    {
      fprintf(stderr, "Can't perform malloc\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
