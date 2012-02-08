/*
** init_termcp.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 20 12:55:37 2011 tom-brent yau
** Last update Sun May 22 17:32:33 2011 tom-brent yau
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>

#include "sh.h"

#include "termcp.h"
#include "utils.h"

#include "xtgetstr.h"

static int	init_capabilities(void)
{
  if (get_win_col() != -1 && xtgetstr("up") && xtgetstr("nd") &&
      xtgetstr("do") && xtgetstr("le") && xtgetstr("kl") &&
      xtgetstr("kr") && xtgetstr("kD") && xtgetstr("kh") &&
      xtgetstr("@7"))
    return (0);
  return (1);
}

void	init_termcp(t_termcp *termcp, char **environ)
{
  if (!isatty(0))
    {
      termcp->term = NULL;
      return ;
    }
  termcp->term = my_get_env(environ, "TERM");
  if (termcp->term == NULL || tgetent(NULL, termcp->term) == -1)
    {
      termcp->term = NULL;
      return ;
    }
  if (init_capabilities() == 1)
    {
      termcp->term = NULL;
      return ;
    }
  termcp->width = get_win_col();
}
