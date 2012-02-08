/*
** gere_ctrl_t.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Sat May 21 19:00:23 2011 silvain tuilliere
** Last update Sun May 22 23:03:47 2011 silvain tuilliere
*/

#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	gere_ctrl_t(t_inf *infos, t_termcp *termcp, char *result)
{
  char	buffer;
  int	idx_tmp;

  if (termcp->idx != termcp->size && termcp->idx > 0)
    {
      idx_tmp = termcp->idx;
      buffer = result[termcp->idx];
      result[termcp->idx] = result[termcp->idx - 1];
      result[termcp->idx - 1] = buffer;
      refresh_prompt(infos, termcp, result);
      go_to_idx(termcp, result, idx_tmp + 1, infos);
    }
  else if (termcp->idx == termcp->size && termcp->idx > 1)
    {
      idx_tmp = termcp->idx;
      buffer = result[termcp->idx - 1];
      result[termcp->idx - 1] = result[termcp->idx - 2];
      result[termcp->idx - 2] = buffer;
      refresh_prompt(infos, termcp, result);
      go_to_idx(termcp, result, idx_tmp, infos);
    }
}
