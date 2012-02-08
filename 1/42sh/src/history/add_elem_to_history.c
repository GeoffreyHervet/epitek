/*
** add_elem_to_history.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/history
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue May 10 15:52:57 2011 tom-brent yau
** Last update Sun May 22 20:44:17 2011 silvain tuilliere
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"history.h"

static void	remove_first_history_elem(t_history **history)
{
  t_history	*temp;

  temp = *history;
  *history = temp->next;
  (*history)->previous = NULL;
  if (temp)
    {
      free(temp->cmd);
      free(temp);
    }
}

void	add_elem_to_history(t_history **history, t_history *element)
{
  t_history	*temp;
  int		nb;

  nb = 1;
  if (*history == NULL)
    {
      *history = element;
      element->previous = NULL;
      element->id = 1;
    }
  else
    {
      temp = *history;
      while (temp->next)
	{
	  nb++;
	  temp = temp->next;
	}
      temp->next = element;
      element->previous = temp;
      element->id = temp->id + 1;
    }
  if (nb > LIMIT_HISTORY)
    remove_first_history_elem(history);
}
