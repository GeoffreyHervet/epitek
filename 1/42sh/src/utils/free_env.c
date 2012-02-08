/*
** free_env.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/utils
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Apr 15 12:17:50 2011 tom-brent yau
** Last update Wed Apr 27 15:16:28 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"

void	free_env(t_env *list)
{
  t_env	*tmp;

  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp->var);
      free(tmp);
    }
}
