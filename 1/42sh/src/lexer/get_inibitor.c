/*
** get_inibitor.c for  in /home/rufin_q/projet/42sh/42sh/src/lexer
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Wed Apr 20 15:30:49 2011 quentin rufin
** Last update Thu May 12 17:35:58 2011 tom-brent yau
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sh.h"
#include "get_the_last.h"

int	get_inibitor(t_lex **ptr, char *str)
{
  int		count;
  t_lex		*new;
  char		c;
  char		tmp[SIZE + 1];

  if (!(*str == '"' || *str == '\''))
    return (0);
  c = *str;
  count = 1;
  while (str[count] != c && str[count] != 0)
    count++;
  if (str[count] == 0)
    return (0);
  new = get_the_last(ptr);
  new->info.str = strndup(str, count);
  new->info.type = WORD;
  strncpy(tmp, str + count + 1, SIZE);
  strncpy(str, tmp, SIZE);
  return (1);
}
