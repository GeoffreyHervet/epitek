/*
** find_path.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun Apr 17 14:03:51 2011 tom-brent yau
** Last update Thu May 12 18:10:48 2011 quentin rufin
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	"sh.h"
#include	"utils.h"
#include	"xstrdup.h"

static int	find_in_env(t_env *env, char *path, char *name)
{
  int		count;

  env = find_env_var(env, "PATH");
  if (env == NULL)
    return (FALSE);
  count = strclen(env->var, "=") + 1;
  while (access(path, F_OK) == -1 && count < (int)strlen(env->var))
    {
      memset(path, 0, SIZE + 1);
      strncpy(path, env->var + count, strclen(env->var + count, ":"));
      strncat(path, "/", SIZE - strlen(path));
      strncat(path, name, SIZE - strlen(path));
      count += strclen(env->var + count, ":") + 1;
    }
  if (count >= (int)strlen(env->var) && access(path, F_OK) == -1)
    return (FALSE);
  return (TRUE);
}

static int	get_current_path(char *path, char **name)
{
  char	tmp[SIZE + 1];

  memset(tmp, 0, SIZE + 1);
  strncpy(tmp, *name, SIZE);
  free(*name);
  if (getcwd(path, SIZE) == NULL)
    {
      fprintf(stderr, "Can't find current working directory\n");
      return (FALSE);
    }
  strncat(path, "/", SIZE - strlen(path));
  *name = xstrdup(tmp + 2);
  strncat(path, *name, SIZE - strlen(path));
  if (access(path, F_OK) == -1)
    return (FALSE);
  return (TRUE);
}

static int	get_actual_path(char *path, char **name)
{
  char	tmp[SIZE + 1];
  int	pos;

  memset(tmp, 0, SIZE + 1);
  strncpy(tmp, *name, SIZE);
  free(*name);
  strcpy(path, tmp);
  pos = strlen(path);
  while (pos > 0 && path[pos - 1] != '/')
    pos--;
  *name = xstrdup(path + pos);
  if (access(path, F_OK) == -1)
    return (FALSE);
  return (TRUE);
}

int	find_path(t_env **env, char *path, char **name)
{
  int	ret;

  ret = FALSE;
  if (strclen(*name, "/") != (int)strlen(*name))
    {
      if (strncmp(*name, "./", 2) == 0)
	ret = get_current_path(path, name);
      else
	ret = get_actual_path(path, name);
    }
  else
    ret = find_in_env(*env, path, *name);
  return (ret);
}
