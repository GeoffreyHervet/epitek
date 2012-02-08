/*
** save_env.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 10:22:54 2010 geoffrey hervet
** Last update Fri Dec 31 10:57:55 2010 geoffrey hervet
*/

#include		<sys/types.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"libmy.h"
#include		"env/save_env.h"

static char		*str_cpy_a_to_b(char *str,
					unsigned int start,
					const unsigned int end)
{
  char			*tmp;
  unsigned int		str_pos;

  if ((tmp = malloc(sizeof(*tmp) * (end - start + 2))) == NULL)
    return (NULL);
  str_pos = 0;
  while (start < end)
    tmp[str_pos++] = str[start++];
  tmp[str_pos] = 0;
  return (tmp);
}

static int		do_inlist(t_base *base,
				  char *str,
				  const unsigned int eq_pos)
{
  t_env			*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);

  tmp->next = base->env;
  tmp->have_free = FREE_BOTH;
  base->env = tmp;
  tmp->name = str_cpy_a_to_b(str, 0, eq_pos);
  if (!tmp->name)
    return (-1);
  tmp->val = str_cpy_a_to_b(str, eq_pos + 1, my_strlen(str));
  if (!tmp->val)
    return (-1);
  return (0);
}

int			save_env(t_base *base,
				 char **env)
{
  unsigned int		idx;
  unsigned int		str_pos;
  unsigned int		while_exec;

  base->env = NULL;
  idx = 0;
  while (env[idx])
    {
      str_pos = 0;
      while_exec = 1;
      while (while_exec)
	{
          if (env[idx][str_pos] == '=' && str_pos &&
	      env[idx][str_pos - 1] != '\\')
	    while_exec = 0;
	  if (!env[idx][str_pos])
	    while_exec = 0;
	  ++str_pos;
	}
      if (do_inlist(base, env[idx], str_pos - 1) == -1)
	return (-1);
      ++idx;
    }
  return (0);
}
