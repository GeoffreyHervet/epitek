/*
** chg_pwd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/builtins
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Apr 15 17:21:40 2011 tom-brent yau
** Last update Wed May 11 15:36:42 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	"sh.h"
#include	"utils.h"
#include	"xmalloc.h"

static void	create_pwd(t_env **env, char *path)
{
  t_env	*tmp;
  t_env	*tmp2;

  tmp = xmalloc(sizeof(*tmp));
  tmp->var = xmalloc((4 + strlen(path) + 1) * sizeof(*(tmp->var)));
  strcat(strcpy(tmp->var, "PWD="), path);
  tmp->next = NULL;
  if (*env == NULL)
    *env = tmp;
  else
    {
      tmp2 = *env;
      while (tmp2->next)
	tmp2 = tmp2->next;
      tmp2->next = tmp;
    }
}

void	chg_pwd(t_env **env)
{
  t_env	*tmp;
  char	path[SIZE + 1];

  tmp = *env;
  memset(path, 0, SIZE + 1);
  if (getcwd(path, SIZE) == NULL)
    fprintf(stderr, "Can't find current working directory\n");
  else
    {
      tmp = find_env_var(tmp, "PWD");
      if (tmp)
	{
	  free(tmp->var);
	  tmp->var = xmalloc((4 + strlen(path) + 1) * sizeof(*(tmp->var)));
	  strcat(strcpy(tmp->var, "PWD="), path);
	}
      else
	create_pwd(env, path);
    }
}
