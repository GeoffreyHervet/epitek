/*
** split_cmd.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec 20 12:34:29 2010 geoffrey hervet
** Last update Sun Jan  2 16:21:03 2011 geoffrey hervet
*/

#include		<sys/types.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"cmd/split_cmd.h"

static char		*cpy_str_ab(char *str,
				    unsigned int start,
				    const unsigned int end)
{
  char			*tmp;
  unsigned int		pos;

  if ((tmp = malloc(sizeof(*tmp) * (end - start + 1))) == NULL)
    return (NULL);
  pos = 0;
  while (start < end)
    tmp[pos++] = str[start++];
  tmp[pos] = '\0';
  return (tmp);
}

static int		add_inlist(char *str,
				   const unsigned int start,
				   const unsigned int end,
				   t_cmd_split **endlist)
{
  t_cmd_split		*item;

  if ((item = malloc(sizeof(*item))) == NULL)
    return (-1);
  if ((item->data = cpy_str_ab(str, start, end)) == NULL)
    return (-1);
  item->next = NULL;
  if (*endlist)
    (*endlist)->next = item;
  *endlist = item;
  return (0);
}

static int		split_cmd_(t_base *base,
				   unsigned int pos1,
				   unsigned int pos2,
				   t_cmd_split *end)
{
  while (1)
    {
      if (base->cmd[pos1] > ' ' && base->cmd[pos2] <= ' ')
        pos2 = pos1;
      if (base->cmd[pos1] <= ' ' && base->cmd[pos2] > ' ')
        {
          if (add_inlist(base->cmd, pos2, pos1, &end) == -1)
            return (-1);
          else
            pos2 = pos1;
	  if (!base->cmd_splited)
	    base->cmd_splited = end;
        }
      if (!base->cmd[pos1++])
        {
          if (base->cmd[pos2] > ' ')
            return (add_inlist(base->cmd, pos2, pos1, &end));
          else
            return (0);
        }
    }
}

int			split_cmd(t_base *base)
{
  unsigned int		pos1;
  unsigned int		pos2;
  t_cmd_split		*end;

  base->cmd_splited = NULL;
  end = NULL;
  pos1 = 0;
  pos2 = 0;
  return (split_cmd_(base, pos1, pos2, end));
}
