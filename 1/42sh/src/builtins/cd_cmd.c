/*
** cd_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/builtins
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Apr 15 15:52:34 2011 tom-brent yau
** Last update Thu May 12 12:25:32 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"
#include	"builtins.h"
#include	"utils.h"
#include	"xchdir.h"

static void	chg_prev_path(t_env *env, char *prev_path)
{
  env = find_env_var(env, "PWD");
  if (env)
    {
      memset(prev_path, 0, SIZE + 1);
      strncpy(prev_path, env->var + 4, SIZE);
    }
}

static int	cd_home(t_env *env)
{
  int	ret;

  ret = FALSE;
  env = find_env_var(env, "HOME");
  if (env && *(env->var + 5))
    ret = xchdir(env->var + 5);
  else
    fprintf(stderr, "Home directory not found\n");
  return (ret);
}

int	cd_cmd(t_tree *cmd, t_env **env)
{
  static char	prev_path[SIZE + 1] = {0};
  int		ret;

  ret = FALSE;
  if (cmd && cmd->right)
    {
      fprintf(stderr, "cd: Too many arguments\n");
      return (ret);
    }
  if (*env && cmd == NULL)
    ret = cd_home(*env);
  else if (cmd && strcmp(cmd->info.str, "-") == 0)
    ret = xchdir(prev_path);
  else if (cmd)
    ret = xchdir(cmd->info.str);
  if (ret != FALSE)
    chg_prev_path(*env, prev_path);
  chg_pwd(env);
  return (ret);
}
