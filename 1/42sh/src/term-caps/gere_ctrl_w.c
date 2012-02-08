/*
** gere_ctrl_t.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Sat May 21 19:00:23 2011 silvain tuilliere
** Last update Sun May 22 21:07:13 2011 silvain tuilliere
*/

#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	gere_ctrl_w(t_inf *infos, t_termcp *termcp, char *result)
{
  int	idx_tmp;
  int	count;

  idx_tmp = termcp->idx;
  count = 0;
  while (count < termcp->idx)
    {
      termcp->buffer[count] = result[count];
      result[count] = result[idx_tmp];
      count++;
      idx_tmp++;
    }
  termcp->buffer[count] = '\0';
  replace_with_spaces(infos, termcp, result);
  termcp->size -= count;
  refresh_prompt(infos, termcp, result);
  go_to_idx(termcp, result, 0, infos);
}
