/*
** free_hist.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/history
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed May 11 11:42:03 2011 tom-brent yau
** Last update Wed May 11 11:43:24 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"

void	free_hist(t_history *list)
{
  t_history	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp->cmd);
      free(tmp);
    }
}
