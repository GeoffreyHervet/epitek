/*
** read_instruction.c for  in /home/tuilli_s//projet/42sh/src/term-caps
** 
** Made by silvain tuilliere
** Login   <tuilli_s@epitech.net>
** 
** Started on  Mon May  2 17:36:41 2011 silvain tuilliere
** Last update Sun May 22 19:18:55 2011 silvain tuilliere
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "sh.h"

#include "termcp.h"

void	insert_char(t_termcp *termcp, char *buffer, char *key,
			    t_inf *infos)
{
  int	tmp;

  ++termcp->size;
  update_result(termcp, buffer, *key);
  tmp = termcp->idx + 1;
  refresh_prompt(infos, termcp, buffer);
  go_to_idx(termcp, buffer, tmp, infos);
}

static int	grep_key(char *key)
{
  int	ret;

  if ((ret = read(0, key, 9)) <= 0)
    return (0);
  key[ret] = '\0';
  return (ret);
}

int	read_keys(t_termcp *termcp, char *buffer, t_inf *infos)
{
  char		key[10];
  int		bol;

  bol = 1;
  while (bol > 0)
    {
      memset(key, 0, 10);
      if ((bol = grep_key(key)) == 0 || key[0] == CTRL_D)
	bol = 0;
      else if (*key == '\n')
	bol = -1;
      else if (bol != 1 && is_printable(key))
	gere_cut(infos, termcp, buffer, key);
      else if (pars_keys(termcp, buffer, key, infos) &&
	       termcp->size < SIZE)
	insert_char(termcp, buffer, key, infos);
    }
  buffer[termcp->size] = '\0';
  return (bol);
}
