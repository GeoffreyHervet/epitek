/*
** find_env_var.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/utils
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun Apr 17 15:59:39 2011 tom-brent yau
** Last update Sun Apr 17 15:59:43 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"

t_env	*find_env_var(t_env *env, char *var)
{
  char	tmp[SIZE + 1];

  memset(tmp, 0, SIZE + 1);
  strncpy(tmp, var, SIZE);
  strncat(tmp, "=", SIZE - strlen(tmp));
  while (env != NULL && strncmp(env->var, tmp, strlen(tmp)) != 0)
    env = env->next;
  return (env);
}
