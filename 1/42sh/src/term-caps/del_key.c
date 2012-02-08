/*
** del_key.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:26:13 2011 tom-brent yau
** Last update Sun May 22 16:33:21 2011 tom-brent yau
*/

#include <unistd.h>

#include "sh.h"

#include "termcp.h"

void	del_key(t_inf *infos, t_termcp *termcp, char *buffer)
{
  int	tmp;

  (void)infos;
  if (termcp->size > 0 && termcp->idx >= 0 && termcp->size != termcp->idx)
    {
      tmp = termcp->idx;
      replace_with_spaces(infos, termcp, buffer);
      remove_key_from_str(buffer, &(termcp->size), tmp);
      refresh_prompt(infos, termcp, buffer);
      go_to_idx(termcp, buffer, tmp, infos);
    }
}
