/*
** set_env.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 13:40:24 2010 geoffrey hervet
** Last update Tue Jan  4 17:33:31 2011 geoffrey hervet
*/

#include	<sys/types.h>

#include	<stdlib.h>

#include	"my_sh.h"
#include	"errors.h"
#include	"env/get_env.h"
#include	"env/set_env.h"

static t_env	*edit_env(t_env *item,
			  char *val)
{
  item->val = val;
  return (item);
}

static t_env	*do_inlist(t_env *begin,
			   char *name,
			   char *val,
			   int have_free)
{
  t_env		*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    critical_error(1, 1, 1, ERR_MALLOC);
  tmp->next = begin;
  tmp->have_free = have_free;
  begin = tmp;
  tmp->name = name;
  tmp->val = val;
  return (begin);
}

t_env		*set_env(void *name,
			 void *val,
			 int have_free)
{
  static t_env	*env = NULL;
  t_env		*tmp;

  if (!env && val)
    critical_error(1, 1, 1, "env -i not supported ... Sorry :x\n");
  if (!val)
    {
      if (name)
	env = (t_env *) name;
      return (env);
    }
  tmp = get_env(env, val);
  if (tmp != NULL)
    return (edit_env(tmp, (char *) val));
  env = do_inlist(env, (char *) name, (char *) val, have_free);
  return (env);
}
