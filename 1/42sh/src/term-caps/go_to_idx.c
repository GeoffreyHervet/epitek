/*
** go_to_idx.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:22:55 2011 tom-brent yau
** Last update Sat May 21 19:40:14 2011 silvain tuilliere
*/

#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	go_to_idx(t_termcp *termcp, char *buffer, int idx, t_inf *infos)
{
  int	col;
  int	line;

  move_cursor_home(infos, termcp, buffer);
  go('\r');
  line = (SIZE_PROMPT + idx) / termcp->width;
  col = (SIZE_PROMPT + idx) % termcp->width;
  while (line > 0)
    {
      xtputs(xtgetstr("do"), 1, &go);
      line--;
    }
  while (col > 0)
    {
      xtputs(xtgetstr("nd"), 1, &go);
      col--;
    }
  termcp->idx = idx;
}
