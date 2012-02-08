/*
** order_ll_syntax_correction.c for  in /home/rufin_q//projet/42sh/42sh/src/syntax_corrector
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sat May 21 19:00:03 2011 quentin rufin
** Last update Sat May 21 19:48:15 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"

static void	my_swap_ptr_char(char **first, char **second)
{
  char		*tmp;

  tmp = *first;
  *first = *second;
  *second = tmp;
}

void		order_ll_syntax_correction(t_list_correc *ptr)
{
  int		bol;
  t_list_correc	*tmp;

  bol = TRUE;
  while (bol == TRUE)
    {
      bol = FALSE;
      tmp = ptr;
      while (tmp->next != NULL)
	{
	  if (strcmp(tmp->name, tmp->next->name) > 0)
	    {
	      bol = TRUE;
	      my_swap_ptr_char(&tmp->name, &tmp->next->name);
	    }
	  tmp = tmp->next;
	}
    }
}
