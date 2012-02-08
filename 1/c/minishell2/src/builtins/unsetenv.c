/*
** unsetenv.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Jan  2 16:46:55 2011 geoffrey hervet
** Last update Wed Jan  5 15:15:23 2011 geoffrey hervet
*/

#include		<sys/types.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"errors.h"
#include		"libmy.h"
#include		"builtins/builtins_all.h"
#include		"builtins/cd_strcat_pwd.h"
#include		"env/set_env.h"
#include		"env/get_env.h"
#include		"env/free_env.h"

static void		free_item(t_env *env)
{
  if (env->have_free & FREE_NAME)
    free(env->name);
  if (env->have_free & FREE_VAL)
    free(env->val);
  free(env);
}

static int		free_val(t_base *base,
				 const char *name)
{
  t_env			*env;
  t_env			*prev;

  if (base->env == NULL)
    return (0);
  env = base->env;
  if (!my_strcmp(name, env->name))
    {
      base->env = env->next;
      free_item(env);
      set_env(base->env, NULL, FREE_NOTH);
      return (0);
    }
  while (env != NULL)
    {
      if (!my_strcmp(name, env->name))
	{
	  prev->next = env->next;
	  free_item(env);
	  return (0);
	}
      prev = env;
      env = env->next;
    }
  return (-1);
}

static t_env		*save_env(t_env *item)
{
  static t_env		*beg = NULL;

  if (item == NULL)
    {
      item = beg;
      beg = NULL;
      return (item);
    }
  item->next = beg;
  beg = item;
  return (beg);
}

static int		unsetenv_all(t_base *base,
				     t_env *env)
{
  t_env			*base_last;
  t_env			*tmp;

  base_last = NULL;
  env = base->env;
  while (env != NULL)
    {
      tmp = env->next;
      if (my_strcmp("HOME", env->name) && my_strcmp("PATH", env->name) &&
	  my_strcmp("PWD", env->name))
	free_val(base, env->name);
      env = tmp;
    }
  base->env = save_env(NULL);
  set_env(base->env, NULL, FREE_NOTH);
  return (0);
 }

int			_unsetenv(t_base *base)
{
  t_cmd_split		*cmd;
  t_env			*env;

  cmd = base->cmd_splited->next;
  if (cmd == NULL)
    {
      my_putstr(base->cmd_splited->data, 2);
      critical_error(1, 1, 0, ERR_NB_ARG);
      return (-1);
    }
  env = base->env;
  if (!my_strcmp("*", cmd->data))
    return (unsetenv_all(base, env));
  return (free_val(base, base->cmd_splited->next->data));
}
