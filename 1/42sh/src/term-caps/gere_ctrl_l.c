/*
** gere_ctrl_t.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Sat May 21 19:00:23 2011 silvain tuilliere
** Last update Sat May 21 23:58:56 2011 silvain tuilliere
*/

#include <stdlib.h>

#include "sh.h"

#include "termcp.h"
#include "utils.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	gere_ctrl_l(t_inf *infos, t_termcp *termcp, char *result)
{
  int	idx_tmp;

  idx_tmp = termcp->idx;
  xtputs(xtgetstr("cl"), 1, &go);
  print("$> ");
  refresh_prompt(infos, termcp, result);
  go_to_idx(termcp, result, idx_tmp, infos);
}
