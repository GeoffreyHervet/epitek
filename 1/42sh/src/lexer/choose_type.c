/*
** choose_type.c for  in /home/rufin_q/projet/42sh/42sh/src/lexer
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Wed Apr 20 15:23:07 2011 quentin rufin
** Last update Sat May 14 21:02:52 2011 tom-brent yau
*/

#include <stdlib.h>

#include "sh.h"

int	choose_type(t_lex *new)
{
  int	prev_type;

  if (new->prev == NULL)
    return (CMD);
  prev_type = new->prev->info.type;
  if (prev_type == CMD || prev_type == CMD_ARG)
    return (CMD_ARG);
  if (prev_type == OPE_RED_RIGHT || prev_type == OPE_DOUBLE_RIGHT ||
      prev_type == OPE_RED_LEFT || prev_type == OPE_DOUBLE_LEFT)
    return (WORD);
  if (prev_type == WORD)
    {
      while (new->prev && (new->prev->info.type == WORD ||
			   new->prev->info.type == OPE_RED_RIGHT ||
			   new->prev->info.type == OPE_DOUBLE_RIGHT ||
			   new->prev->info.type == OPE_RED_LEFT ||
			   new->prev->info.type == OPE_DOUBLE_LEFT))
	new = new->prev;
      if (new->prev && (new->prev->info.type == CMD_ARG ||
			new->prev->info.type == CMD))
      return (CMD_ARG);
    }
  return (CMD);
}
