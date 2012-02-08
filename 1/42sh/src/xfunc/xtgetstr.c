/*
** xtgetstr.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 20 22:37:20 2011 tom-brent yau
** Last update Fri May 20 22:45:46 2011 tom-brent yau
*/

#include	<curses.h>
#include	<term.h>
#include	<stdlib.h>
#include	<stdio.h>

char	*xtgetstr(char *id)
{
  char	*termcp;

  if ((termcp = tgetstr(id, NULL)) == NULL)
    {
      fprintf(stderr, "Failed to get termcap\n");
    }
  return (termcp);
}
