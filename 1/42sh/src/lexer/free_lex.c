/*
** free_lex.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/lexer
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Apr 14 23:21:13 2011 tom-brent yau
** Last update Wed Apr 27 15:20:02 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"

void	free_lex(t_lex *list)
{
  t_lex	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp->info.str);
      free(tmp);
    }
}
