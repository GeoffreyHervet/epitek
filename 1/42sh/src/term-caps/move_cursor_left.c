/*
** move_cursor_left.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:23:52 2011 tom-brent yau
** Last update Sat May 21 00:47:45 2011 tom-brent yau
*/

#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	move_cursor_left(t_inf *infos, t_termcp *termcp, char *buffer)
{
  int	count;

  (void)buffer;
  (void)infos;
  if (termcp->idx > 0)
    {
      if ((termcp->idx + SIZE_PROMPT) % termcp->width == 0)
	{
	  xtputs(xtgetstr("up"), 1, &go);
	  count = termcp->width;
	  while (count-- > 0)
	    xtputs(xtgetstr("nd"), 1, &go);
	}
      else
	xtputs(xtgetstr("le"), 1, &go);
      termcp->idx -= 1;
    }
}
