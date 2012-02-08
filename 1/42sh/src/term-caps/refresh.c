/*
** refresh.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 23:33:04 2011 tom-brent yau
** Last update Sun May 22 20:35:18 2011 tom-brent yau
*/

#include <unistd.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"
#include "xwrite.h"

void	refresh_prompt(t_inf *infos, t_termcp *termcp, char *buffer)
{
  move_cursor_home(infos, termcp, buffer);
  xwrite(1, buffer, termcp->size);
  termcp->idx = termcp->size;
  if ((termcp->idx + SIZE_PROMPT) % termcp->width == 0)
    xtputs(xtgetstr("do"), 1, &go);
}
