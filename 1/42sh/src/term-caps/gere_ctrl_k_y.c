/*
** gere_ctrl_t.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Sat May 21 19:00:23 2011 silvain tuilliere
** Last update Sun May 22 21:12:12 2011 silvain tuilliere
*/

#include <stdlib.h>
#include <string.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	gere_ctrl_k(t_inf *infos, t_termcp *termcp, char *result)
{
  int	idx_tmp;
  int	count;

  idx_tmp = termcp->idx;
  count = 0;
  while (idx_tmp < termcp->size)
    {
      termcp->buffer[count] = result[idx_tmp];
      count++;
      idx_tmp++;
    }
  termcp->buffer[count] = '\0';
  memset(result + termcp->idx, 0, SIZE - termcp->idx);
  idx_tmp = termcp->idx;
  replace_with_spaces(infos, termcp, result);
  termcp->size = idx_tmp;
  refresh_prompt(infos, termcp, result);
}

void	gere_ctrl_y(t_inf *infos, t_termcp *termcp, char *result)
{
  int	count;

  count = 0;
  while (termcp->buffer[count] && termcp->size < SIZE)
    {
      insert_char(termcp, result, &(termcp->buffer[count]), infos);
      count++;
    }
}
