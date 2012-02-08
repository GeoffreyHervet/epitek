/*
** unsetenv_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/builtins
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Apr 15 20:47:10 2011 tom-brent yau
** Last update Sun Apr 17 18:52:03 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"sh.h"
#include	"utils.h"

int	unset_env(t_tree *cmd, t_env **env)
{
  t_env	*tmp;
  t_env	*tmp2;

  while (cmd)
    {
      tmp = find_env_var(*env, cmd->info.str);
      if (tmp)
	{
	  if (tmp == *env)
	    *env = tmp->next;
	  else
	    {
	      tmp2 = *env;
	      while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	      tmp2->next = tmp->next;
	    }
	  free(tmp->var);
	  free(tmp);
	}
      cmd = cmd->right;
    }
  return (TRUE);
}

int	unsetenv_cmd(t_tree *cmd, t_env **env)
{
  t_tree	*tmp;
  int	ret;

  tmp = cmd;
  ret = FALSE;
  if (*env == NULL)
    return (ret);
  while (tmp && strcmp(tmp->info.str, "*"))
    tmp = tmp->right;
  if (cmd == NULL)
    fprintf(stderr, "unsetenv: Not enough arguments\n");
  else if (tmp)
    {
      free_env(*env);
      ret = TRUE;
      *env = NULL;
    }
  else
    ret = unset_env(cmd, env);
  return (ret);
}
