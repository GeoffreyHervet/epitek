/*
** get_cmd.c for my_ls in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 15:52:13 2010 geoffrey hervet
** Last update Tue Jan  4 14:06:28 2011 geoffrey hervet
*/

#include	<sys/types.h>

#include	<stdlib.h>

#include	<stdio.h>

#include	"my_sh.h"
#include	"libmy.h"
#include	"env/get_env.h"
#include	"env/set_env.h"
#include	"cmd/get_cmd.h"
#include	"cmd/exec_cmd.h"
#include	"gnl.h"

void			get_cmd(t_base *base,
				t_env *prompt)
{
  my_putstr(prompt->val, 1);
  while ((base->cmd = gnl(0)))
    {
      if (!my_strcmp(base->cmd, "exit"))
	{
	  free(base->cmd);
	  return ;
	}
      if (base->cmd[0])
	exec_cmd(base);
      free(base->cmd);
      prompt = get_env(base->env, "PROMPT");
      if (prompt == NULL)
	{
	  prompt = set_env("PROMPT", DEF_PROMPT, FREE_NOTH);
	  base->env = set_env(NULL, NULL, FREE_NOTH);
	}
      my_putstr(prompt->val, 1);
    }
  my_putchar('\n', 1);
}
