/*
** exec_builtins.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec 22 15:01:58 2010 geoffrey hervet
** Last update Fri Dec 31 10:59:14 2010 geoffrey hervet
*/

#include		<sys/types.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"libmy.h"
#include		"errors.h"
#include		"builtins/is_builtins.h"
#include		"builtins/builtins_all.h"
#include		"builtins/builtins_list.h"
#include		"builtins/exec_builtins.h"

int			exec_builtins(t_base *base)
{
  unsigned int		idx;

  idx = 0;
  while (builtins_all[idx].name)
    {
      if (!my_strcmp(builtins_all[idx].name, base->cmd_splited->data))
	return (builtins_all[idx].func(base));
      ++idx;
    }
  critical_error(1, 1, 0, "Builtins not found ...\n");
  return (0);
}

