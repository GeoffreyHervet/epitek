/*
** get_the_last.c for  in /home/rufin_q/projet/42sh/42sh/src/lexer
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Wed Apr 20 15:33:11 2011 quentin rufin
** Last update Thu May 12 17:33:01 2011 tom-brent yau
*/

#include <stdlib.h>
#include <string.h>
#include "sh.h"
#include "xmalloc.h"

t_lex	*get_the_last(t_lex **ptr)
{
  t_lex		*new;
  t_lex		*tmp;

  new = xmalloc(sizeof(*new));
  memset(new, 0, sizeof(*new));
  if (*ptr != NULL)
    {
      tmp = *ptr;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      new->prev = tmp;
      return (new);
    }
  *ptr = new;
  return (new);
}
