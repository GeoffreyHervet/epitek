/*
** free_ll_syntax_correction.c for  in /home/rufin_q//projet/42sh/42sh/src/syntax_corrector
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Thu May 12 17:04:46 2011 quentin rufin
** Last update Thu May 12 19:10:05 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"

void		free_ll_syntax_correction(t_list_correc *ptr)
{
  t_list_correc	*tmp;

  while (ptr != NULL)
    {
      free(ptr->name);
      tmp = ptr->next;
      free(ptr);
      ptr = tmp;
    }
}
