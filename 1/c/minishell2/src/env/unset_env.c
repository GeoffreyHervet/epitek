/*
** unset_env.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Jan  2 17:22:28 2011 geoffrey hervet
** Last update Tue Jan  4 14:00:54 2011 geoffrey hervet
*/

#include		<sys/types.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"libmy.h"
#include		"env/unset_env.h"

static t_env		free_item(t_env *item)
{
  t_env			*next;

  next = item->next;
  if (item->have_free & FREE_NAME)
    free(item->name);
  if (item->have_free & FREE_VAL)
    free(item->val);
  free(item);
  return (next);
}

t_env			*unset_env(t_env *env,
				  const char *name)
{
  t_env			*tmp;

  if (!my_strcmp(name, env->name))
    {
      env = free_item(env);
      return (env);
    }
  tmp = env;
  while (tmp != NULL)
    {
      if (!my_strcmp(tmp->next->name, name))
	{
	  tmp->next = free_item(tmp->next);
	  return (env);
	}
    }
  return (env);
}
