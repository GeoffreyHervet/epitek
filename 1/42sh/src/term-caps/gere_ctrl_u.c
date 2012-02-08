/*
** gere_ctrl_t.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Sat May 21 19:00:23 2011 silvain tuilliere
** Last update Sun May 22 22:16:47 2011 silvain tuilliere
*/

#include <string.h>
#include <stdlib.h>

#include "sh.h"

#include "termcp.h"

#include "xtputs.h"
#include "xtgetstr.h"

void	gere_ctrl_u(t_inf *infos, t_termcp *termcp, char *result)
{
  strncpy(termcp->buffer, result, SIZE);
  replace_with_spaces(infos, termcp, result);
  termcp->size = 0;
  refresh_prompt(infos, termcp, result);
}
