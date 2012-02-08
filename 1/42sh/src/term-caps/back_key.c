/*
** back_key.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:25:36 2011 tom-brent yau
** Last update Sun May 22 16:33:32 2011 tom-brent yau
*/

#include <unistd.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	back_key(t_inf *infos, t_termcp *termcp, char *buffer)
{
  int	tmp;

  if (termcp->size > 0 && termcp->idx > 0)
    {
      if ((termcp->idx + SIZE_PROMPT) % termcp->width == 0)
      	{
      	  xtputs(xtgetstr("up"), 1, &go);
      	  tmp = termcp->width;
      	  while (tmp-- > 0)
      	    xtputs(xtgetstr("nd"), 1, &go);
      	}
      tmp = --termcp->idx;
      replace_with_spaces(infos, termcp, buffer);
      remove_key_from_str(buffer, &(termcp->size), tmp);
      refresh_prompt(infos, termcp, buffer);
      go_to_idx(termcp, buffer, tmp, infos);
    }
}
