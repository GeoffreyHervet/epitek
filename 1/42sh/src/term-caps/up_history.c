/*
** up_history.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 21 00:49:10 2011 tom-brent yau
** Last update Sat May 21 14:57:42 2011 tom-brent yau
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

static t_history	*get_last_hist(t_history *list)
{
  while (list && list->next)
    list = list->next;
  if (list != NULL)
    return (list);
  return (NULL);
}

void	up_history(t_inf *infos, t_termcp *termcp, char *buffer)
{
  if (infos->history == NULL)
    return ;
  if (termcp->hist == NULL)
    {
      memset(termcp->tmp_buff, 0, SIZE + 1);
      strncpy(termcp->tmp_buff, buffer, termcp->size);
    }
  if (termcp->hist == NULL)
    termcp->hist = get_last_hist(infos->history);
  else if (termcp->hist->previous != NULL)
    termcp->hist = termcp->hist->previous;
  if (termcp->hist && termcp->hist->cmd)
    {
      replace_with_spaces(infos, termcp, buffer);
      memset(buffer, 0, SIZE + 1);
      strncpy(buffer, termcp->hist->cmd, SIZE);
      termcp->size = strlen(buffer);
      refresh_prompt(infos, termcp, buffer);
    }
}
