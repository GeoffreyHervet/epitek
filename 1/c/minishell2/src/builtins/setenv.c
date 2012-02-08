/*
** setenv.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Jan  2 16:47:43 2011 geoffrey hervet
** Last update Wed Jan  5 19:44:02 2011 geoffrey hervet
*/

#include		<sys/types.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"libmy.h"
#include		"errors.h"
#include		"builtins/builtins_all.h"
#include		"builtins/cd_strcat_pwd.h"
#include		"env/set_env.h"
#include		"env/get_env.h"

static int		return_setenv_at_the_norme(t_cmd_split *cmd)
{
  my_putstr(cmd->data, 2);
  critical_error(1, 1, 0, ERR_NB_ARG);
  return (-1);
}

int			_setenv(t_base *base)
{
  t_cmd_split		*cmd;
  t_env			*env;
  char			*str;

  cmd = base->cmd_splited;
  if (cmd->next == NULL)
    return (return_setenv_at_the_norme(cmd));
  str = my_strdup((cmd->next->next == NULL) ? "" : cmd->next->next->data);
  env = get_env(base->env, cmd->next->data);
  if (env == NULL)
    {
      if ((env = malloc(sizeof(*env))) == NULL)
	critical_error(1, 1, 1, ERR_MALLOC);
      env->next = base->env->next;
      env->have_free = FREE_BOTH;
      env->val = str;
      env->name = my_strdup(cmd->next->data);
      base->env->next = env;
      return (0);
    }
  if (env->have_free & FREE_VAL)
    free(env->val);
  env->val = str;
  env->have_free |= FREE_VAL;
  return (0);
}
