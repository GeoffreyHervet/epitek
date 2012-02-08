/*
** exec_cmd.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec 20 08:19:12 2010 geoffrey hervet
** Last update Fri Dec 31 10:58:21 2010 geoffrey hervet
*/

#include	<sys/types.h>
#include	<stdlib.h>

#include	<stdio.h>

#include	"my_sh.h"
#include	"libmy.h"
#include	"cmd/exec_cmd.h"
#include	"cmd/split_cmd.h"
#include	"cmd/launcher.h"
#include	"builtins/is_builtins.h"
#include	"builtins/exec_builtins.h"
#include	"errors.h"

static void	free_split(t_cmd_split *begin)
{
  t_cmd_split	*tmp;

  while (begin != NULL)
    {
      tmp = begin;
      begin = begin->next;
      free(tmp->data);
      free(tmp);
    }
  begin = NULL;
}

void		exec_cmd(t_base *base)
{
  if (split_cmd(base) == -1)
    critical_error(-1, -1, 0, ERR_SPLIT);
  else if (base->cmd_splited)
    {
      if (is_builtins(base->cmd_splited->data))
	exec_builtins(base);
      else
	{
	  launcher(base);
	}
      free_split(base->cmd_splited);
    }
}
