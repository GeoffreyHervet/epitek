/*
** cpy_env.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Apr 14 22:24:42 2011 tom-brent yau
** Last update Thu May 12 18:10:05 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"
#include	"xmalloc.h"
#include	"xstrdup.h"

static char	*get_value(const char *name,
			   const char *val)
{
  int		idx;
  char		*ret;

  if ((ret = malloc(sizeof(*ret) * (strlen(name) + strlen(val) + 2))) == NULL)
    return (NULL);
  idx = 0;
  while (*name)
    ret[idx++] = *name++;
  ret[idx++] = '=';
  while (*val)
    ret[idx++] = *val++;
  ret[idx] = 0;
  return (ret);
}

static t_env	*rescue_env(void)
{
  t_env		*env;

  env = xmalloc(sizeof(*env));
  env->var = get_value("PATH", ENV_PATH);
  env->next = NULL;
  return (env);
}

t_env		*cpy_env(char **env)
{
  int		pos;
  t_env		*my_env;
  t_env		*tmp;
  t_env		*tmp2;

  my_env = NULL;
  pos = -1;
  if (env[0] == NULL)
    return (rescue_env());
  while (env[++pos] != NULL)
    {
      tmp = xmalloc(sizeof(*tmp));
      tmp->var = xstrdup(env[pos]);
      tmp->next = NULL;
      if (my_env == NULL)
	my_env = tmp;
      else
	{
	  tmp2 = my_env;
	  while (tmp2->next)
	    tmp2 = tmp2->next;
	  tmp2->next = tmp;
	}
    }
  return (my_env);
}
