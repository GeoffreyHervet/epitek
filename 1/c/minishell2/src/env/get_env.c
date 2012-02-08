/*
** get_env.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 13:10:21 2010 geoffrey hervet
** Last update Fri Dec 31 10:57:47 2010 geoffrey hervet
*/

#include		<sys/types.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"libmy.h"
#include		"env/get_env.h"

t_env			*get_env(t_env *env,
				 char *name)
{
  while (env)
    {
      if (!my_strcmp(env->name, name))
	return (env);
      env = env->next;
    }
  return (NULL);
}
