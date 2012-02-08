/*
** free_env.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Dec 19 11:38:52 2010 geoffrey hervet
** Last update Tue Jan  4 17:27:16 2011 geoffrey hervet
*/

#include	<sys/types.h>

#include	<stdlib.h>

#include	"my_sh.h"
#include	"env/free_env.h"

void		free_env(t_base *base)
{
  t_env		*tmp;

  tmp = base->env;
  while (tmp)
    {
      base->env = tmp->next;
      if (tmp->have_free & FREE_NAME)
      	free(tmp->name);
      if (tmp->have_free & FREE_VAL)
      	free(tmp->val);
      free(tmp);
      tmp = base->env;
    }
}
