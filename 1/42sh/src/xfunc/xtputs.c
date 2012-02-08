/*
** xtputs.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/xfunc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 20 22:32:44 2011 tom-brent yau
** Last update Fri May 20 22:40:01 2011 tom-brent yau
*/

#include	<curses.h>
#include	<term.h>
#include	<stdlib.h>
#include	<stdio.h>

void	xtputs(const char *str, int affcnt, int (*putc)(int))
{
  if (tputs(str, affcnt, putc) == ERR)
    {
      fprintf(stderr, "tputs encountered an error\n");
    }
}
