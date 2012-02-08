/*
** down_history.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 21 02:41:03 2011 tom-brent yau
** Last update Sat May 21 14:52:30 2011 tom-brent yau
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

void	down_history(t_inf *infos, t_termcp *termcp, char *buffer)
{
  if (infos->history == NULL || termcp->hist == NULL)
    return ;
  replace_with_spaces(infos, termcp, buffer);
  termcp->hist = termcp->hist->next;
  memset(buffer, 0, SIZE + 1);
  if (termcp->hist && termcp->hist->cmd)
    strncpy(buffer, termcp->hist->cmd, SIZE);
  else
    strncpy(buffer, termcp->tmp_buff, SIZE);
  termcp->size = strlen(buffer);
  refresh_prompt(infos, termcp, buffer);
}
