/*
** move_cursor_end.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:21:22 2011 tom-brent yau
** Last update Sun May 22 20:33:30 2011 tom-brent yau
*/

#include <unistd.h>
#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"
#include "xwrite.h"

void	move_cursor_end(t_inf *infos, t_termcp *termcp, char *buffer)
{
  move_cursor_home(infos, termcp, buffer);
  termcp->idx = termcp->size;
  xwrite(1, buffer, termcp->size);
  if ((termcp->idx + SIZE_PROMPT) % termcp->width == 0)
    xtputs(xtgetstr("do"), 1, &go);
}
