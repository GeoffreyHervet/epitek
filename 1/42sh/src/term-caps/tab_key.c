/*
** tab_key.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 21 03:30:29 2011 tom-brent yau
** Last update Sun May 22 18:49:13 2011 tom-brent yau
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "sh.h"

#include "termcp.h"
#include "utils.h"

static int	is_sep(char c)
{
  if (c == ';' || c == '|' || c == '&' || c == '<' || c == '>' || c == '/')
    return (1);
  return (0);
}

static int	if_cmd(char *b, int i)
{
  int	bol;

  if (*b == 0)
    return (0);
  bol = 0;
  while (i >= 0 && b[i] == ' ')
    {
      --i;
      bol = 1;
    }
  if (i < 0 || is_sep(b[i]))
    return (0);
  while (i >= 0 && b[i] != ' ' && is_sep(b[i]) == 0)
    --i;
  if ((i > 0 && b[i] == '/') || ((i < 0 || is_sep(b[i])) && bol))
    return (0);
  if (i < 0 || (is_sep(b[i]) && b[i] != '/' && b[i] != '>' && b[i] != '<'))
    return (1);
  while (i >= 0 && b[i] == ' ')
    --i;
  if (i < 0)
    return (1);
  if ((b[i] != ';' && b[i] != '|' && b[i] != '&') || bol || b[i] == '/')
    return (0);
  return (1);
}

void	tab_key(t_inf *infos, t_termcp *termcp, char *buffer)
{
  int	ret;

  ret = if_cmd(buffer, termcp->idx - 1);
  if (ret == 0)
    look_in_dir(infos, termcp, buffer);
  else if (ret == 1)
    look_in_exec(infos, termcp, infos->list_correc, buffer);
}
