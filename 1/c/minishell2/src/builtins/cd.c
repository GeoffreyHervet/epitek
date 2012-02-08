/*
** cd.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec 22 11:07:43 2010 geoffrey hervet
** Last update Sun Jan  2 12:36:52 2011 geoffrey hervet
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

static char		*clear_pwd(char *pwd)
{
  unsigned int		idx1;
  unsigned int		idx2;

  idx1 = 0;
  while (pwd[idx1])
    {
      if (pwd[idx1] == '/' && pwd[idx1 + 1] == '/')
	{
	  idx2 = idx1 + 1;
	  while (pwd[idx2])
	    {
	      pwd[idx2] = pwd[idx2 + 1];
	      ++idx2;
	    }
	}
      else
	++idx1;
    }
  while (idx1 - 2 > 0 && (pwd[idx1 - 1] == '.' && pwd[idx1 - 2] == '/'))
    {
      pwd[idx1 - 2] = '\0';
      idx1 -= 2;
    }
  return (pwd);
}

static int		update_pwd(t_env *pwd,
				   char *new_pwd,
				   char **ex_cd)
{
  if (xchdir(new_pwd) == -1)
    {
      free(new_pwd);
      return (-1);
    }
  free(*ex_cd);
  *ex_cd = clear_pwd(my_strdup(pwd->val));
  if (pwd->have_free & FREE_VAL)
    free(pwd->val);
  pwd->val = clear_pwd(new_pwd);
  pwd->have_free |= FREE_VAL;
  return (0);
}

static int		exec_cd(t_base *base,
				t_env *pwd,
				t_cmd_split *cmd,
				char **ex_cd)
{
  char			*new_pwd;
  t_env			*env;

  if (!cmd->next || (cmd->next && cmd->next->data[0] == '~'))
    {
      if ((env = get_env(base->env, "HOME")) == NULL)
	{
	  critical_error(1, 1, 0, ERR_NEEDHOME);
	  return (-1);
	}
      if (cmd->next)
	new_pwd = tilde_gestion(env->val, cmd->next->data);
      else
	new_pwd = my_strdup(env->val);
    }
  else if ((!my_strcmp("-", cmd->next->data)))
      new_pwd = my_strdup(*ex_cd);
  else if (cmd->next->data[0] != '/')
    new_pwd = clear_pwd(strcat_pwd(clear_pwd(pwd->val), cmd->next->data));
  else
      new_pwd = strcat_pwd(NULL, my_strdup(cmd->next->data));
  if (new_pwd == NULL)
    return (-1);
  return (update_pwd(pwd, new_pwd, ex_cd));
}

int			cd(t_base *base)
{
  static char		*ex_cd = NULL;
  t_env			*env;

  if (base == NULL)
    {
      if (ex_cd == NULL)
	free(ex_cd);
      return (0);
    }
  env = get_env(base->env, "PWD");
  if (env == NULL)
    {
      critical_error(1, 1, 0, ERR_NEEDPWD);
      return (-1);
    }
  if (ex_cd == NULL)
    ex_cd = my_strdup(env->val);
  return (exec_cd(base, env, base->cmd_splited, &ex_cd));
}
