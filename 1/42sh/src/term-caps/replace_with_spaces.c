/*
** replace_with_spaces.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 19 22:35:58 2011 tom-brent yau
** Last update Sat May 21 15:00:52 2011 tom-brent yau
*/

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	replace_with_spaces(t_inf *infos, t_termcp *termcp, char *buffer)
{
  int	tmp;

  tmp = termcp->size;
  move_cursor_home(infos, termcp, buffer);
  while (tmp-- > 0)
    go(' ');
  termcp->idx = termcp->size;
  if ((termcp->idx + SIZE_PROMPT) % termcp->width == 0)
    xtputs(xtgetstr("do"), 1, &go);
}
