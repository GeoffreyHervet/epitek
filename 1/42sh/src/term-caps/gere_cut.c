/*
** gere_cut.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 20 11:10:06 2011 tom-brent yau
** Last update Sun May 22 20:34:35 2011 tom-brent yau
*/

#include <unistd.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"
#include "xwrite.h"

static void	advance_cursor(t_termcp *termcp, int idx, int count)
{
  while (count-- > 0)
    {
      ++idx;
      if ((idx + SIZE_PROMPT) % termcp->width == 0)
      	xtputs(xtgetstr("do"), 1, &go);
      else
	xtputs(xtgetstr("nd"), 1, &go);
    }
}

void	gere_cut(t_inf *infos, t_termcp *termcp, char *buffer, char *key)
{
  int	count;

  count = -1;
  if (termcp->size >= SIZE)
    return ;
  while (key[++count] && termcp->size < SIZE)
    {
      ++termcp->size;
      update_result(termcp, buffer, key[count]);
      ++termcp->idx;
    }
  if (termcp->size == termcp->idx)
    xwrite(1, key, count);
  else
    {
      advance_cursor(termcp, termcp->idx - count, count);
      count = termcp->idx;
      replace_with_spaces(infos, termcp, buffer);
      refresh_prompt(infos, termcp, buffer);
      go_to_idx(termcp, buffer, count, infos);
    }
}
