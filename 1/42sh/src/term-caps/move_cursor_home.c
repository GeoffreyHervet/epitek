/*
** move_cursor_home.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:22:00 2011 tom-brent yau
** Last update Sat May 21 00:48:01 2011 tom-brent yau
*/

#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	move_cursor_home(t_inf *infos, t_termcp *termcp, char *buffer)
{
  int	col;
  int	line;

  (void)buffer;
  (void)infos;
  line = -1;
  col = -1;
  while (++line < ((SIZE_PROMPT + termcp->idx) / termcp->width))
    {
      xtputs(xtgetstr("up"), 1, &go);
    }
  go('\r');
  while (++col < SIZE_PROMPT)
    {
      xtputs(xtgetstr("nd"), 1, &go);
    }
  termcp->idx = 0;
}
