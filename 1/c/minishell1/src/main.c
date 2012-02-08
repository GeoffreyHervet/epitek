/*
** main.c for minishell in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 08:59:33 2010 geoffrey hervet
** Last update Wed Jan  5 15:49:45 2011 geoffrey hervet
*/

#include	<sys/types.h>
#include	<signal.h>

#include	<stdlib.h>

#include	"my_sh.h"
#include	"libmy.h"
#include	"env/free_env.h"
#include	"env/save_env.h"
#include	"env/set_env.h"
#include	"env/get_env.h"
#include	"errors.h"
#include	"prompt/prompt_set.h"
#include	"builtins/builtins_all.h"

static t_base	*base_st;

static t_env	*get_prompt(t_base *base)
{
  t_env			*prompt;

  prompt = get_env(base->env, "PROMPT");
  if (!prompt)
    {
      prompt = set_env("PROMPT", DEF_PROMPT, FREE_NOTH);
      base->env = set_env(NULL, NULL, FREE_NOTH);
    }
  return (prompt);
}

void	get_sig(int sig)
{
  t_env	*prompt;

  if (base_st->child != 0)
    {
      if (kill(base_st->child, sig) == -1)
	my_putstr("kill failled ...\n", 2);
    }
  else
    {
      if (sig == SIGINT || sig == SIGTSTP)
	{
	  my_putstr("\b\b  \n", 0);
	  prompt = get_prompt(base_st);
	  my_putstr(prompt->val, 1);
	}
    }
}
int		main(int ac,
		     char **av,
		     char **env)
{
  t_base	base;

  if (ac > 1 && av[0])
    critical_error(-1, -1, 1, ERR_DEFAULT);
  base.child = 0;
  base_st = &base;
  signal(SIGINT, get_sig);
  signal(SIGTSTP, get_sig);
  critical_error(save_env(&base, env), -1, 1, ERR_MALLOC);
  set_env(base.env, NULL, FREE_NOTH);
  prompt_set(&base);
  free_env(&base);
  cd(NULL);
  return (0);
}
