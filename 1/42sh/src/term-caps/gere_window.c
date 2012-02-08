/*
** gere_window.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Mon May 16 15:56:20 2011 silvain tuilliere
** Last update Sun May 22 21:54:08 2011 tom-brent yau
*/

#include	<stdlib.h>

#include	"sh.h"

#include	"termcp.h"

#include	"xtputs.h"
#include	"xtgetstr.h"

extern t_termcp	t;
extern t_inf	infos;

void	gere_window(int nb)
{
  (void)nb;
  t.width = get_win_col();
  if (t.width == -1)
    {
      t.term = NULL;
      return ;
    }
  replace_with_spaces(&infos, &t, t.cmd);
  refresh_prompt(&infos, &t, t.cmd);
}
