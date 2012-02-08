/*
** aff_list.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 21 23:05:36 2011 tom-brent yau
** Last update Sun May 22 14:01:58 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>
#include	<glob.h>
#include	<stdio.h>

#include	"sh.h"

#include	"termcp.h"
#include	"utils.h"

#include	"xtputs.h"
#include	"xtgetstr.h"

static void	put_files(t_termcp *t, char **name)
{
  int	count;
  int	max;
  int	count2;
  int	tmp;

  max = get_max_len(name);
  max = max + 5 - (max % 5);
  if (max <= 0)
    return ;
  count = 0;
  count2 = t->width / max;
  while (name && name[count])
    {
      tmp = 0;
      while (name[count] && tmp < count2)
	{
	  printf("%-*s", max, name[count++]);
	  ++tmp;
	}
      printf("\n");
    }
}

static int	matched(char **name, char *buffer)
{
  int	count;
  int	count2;
  int	len;

  count = 0;
  len = (int)strlen(buffer);
  count2 = 0;
  while (name && name[count])
    {
      if (strncmp(buffer, name[count], len) == 0)
	++count2;
      ++count;
    }
  if (count == 1)
    return (1);
  return (0);
}

static int	is_sep(char c)
{
  if (c == ';' || c == '|' || c == '&' || c == '<' || c == '>' || c == ' ')
    return (1);
  return (0);
}

void	aff_list(t_inf *infos, t_termcp *t, char **name, char *buffer)
{
  int	tmp;
  int	count;
  char	tmp_buff[SIZE + 1];

  memset(tmp_buff, 0, SIZE + 1);
  count = t->idx - 1;
  while (count >= 0 && is_sep(buffer[count]) == 0)
    --count;
  ++count;
  strncpy(tmp_buff, buffer + count, strclen(buffer + count, " <>|;&"));
  tmp = t->idx;
  if (matched(name, tmp_buff) == 0)
    {
      xtputs(xtgetstr("do"), 1, &go);
      put_files(t, name);
      print("$> ");
    }
  else
    replace_with_spaces(infos, t, buffer);
  refresh_prompt(infos, t, buffer);
  go_to_idx(t, buffer, tmp, infos);
}
