/*
** move_cursor_right.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:24:55 2011 tom-brent yau
** Last update Sun May 22 18:32:00 2011 tom-brent yau
*/

#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	move_cursor_right(t_inf *infos, t_termcp *termcp, char *buffer)
{
  (void)buffer;
  (void)infos;
  if (termcp->idx < termcp->size)
    {
      ++termcp->idx;
      if ((termcp->idx + SIZE_PROMPT) % termcp->width == 0)
      	xtputs(xtgetstr("do"), 1, &go);
      else
	xtputs(xtgetstr("nd"), 1, &go);
    }
}
