/*
** setenv_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/builtins
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Apr 15 17:30:10 2011 tom-brent yau
** Last update Wed May 18 21:21:17 2011 quentin rufin
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"sh.h"
#include	"builtins.h"
#include	"utils.h"
#include	"xmalloc.h"

static int	add_env(t_env *env, t_tree *cmd)
{
  t_env	*new;
  int	len1;
  int	len2;
  int	size;

  len1 = strlen(cmd->info.str);
  len2 = 0;
  if (cmd->right)
    len2 = strlen(cmd->right->info.str);
  new = xmalloc(sizeof(*new));
  size = (len1 + len2 + 3) * sizeof(*(new->var));
  new->var = xmalloc(size);
  memset(new->var, 0, size);
  strcat(strcpy(new->var, cmd->info.str), "=");
  if (cmd->right)
    strcat(new->var, cmd->right->info.str);
  new->next = NULL;
  while (env->next)
    env = env->next;
  env->next = new;
  return (TRUE);
}

static int	rep_env(t_env *env, t_tree *cmd)
{
  char	tmp[SIZE + 1];
  int	pos;

  pos = strclen(env->var, "=");
  memset(tmp, 0, SIZE + 1);
  if (env->var[pos])
    pos++;
  strncpy(tmp, env->var, pos);
  free(env->var);
  if (cmd->right)
    pos += strlen(cmd->right->info.str);
  env->var = xmalloc((pos + 1) * sizeof(*(env->var)));
  strcpy(env->var, tmp);
  if (cmd->right)
    strcat(env->var, cmd->right->info.str);
  return (TRUE);
}

static int	new_env(t_tree *cmd, t_env **env)
{
  int	len1;
  int	len2;

  len1 = strlen(cmd->info.str);
  len2 = 0;
  if (cmd->right)
    len2 = strlen(cmd->right->info.str);
  *env = xmalloc(sizeof(**env));
  (*env)->var = xmalloc((len1 + len2 + 2) * sizeof(*((*env)->var)));
  strcat(strcpy((*env)->var, cmd->info.str), "=");
  if (cmd->right)
    strcat((*env)->var, cmd->right->info.str);
  (*env)->next = NULL;
  return (TRUE);
}

int	setenv_cmd(t_tree *cmd, t_env **env)
{
  int	ret;
  t_env	*tmp;

  ret = FALSE;
  if (!(*env) && (cmd || (cmd && cmd->right)))
    ret = new_env(cmd, env);
  else if (*env && cmd == NULL)
    ret = env_cmd(NULL, env);
  else if (*env && (cmd || (cmd && cmd->right)))
    {
      tmp = find_env_var(*env, cmd->info.str);
      if (tmp)
	ret = rep_env(tmp, cmd);
      else
	ret = add_env(*env, cmd);
    }
  else
    fprintf(stderr, "setenv: Too many arguments\n");
  return (ret);
}
