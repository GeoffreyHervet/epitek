/*
** unalias.c for builtins in /home/hervet_g/work/42sh/src/builtins
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu May 05 15:15:47 2011 geoffrey hervet
** Last update Thu May 05 15:15:47 2011 geoffrey hervet
*/

#include	<stdlib.h>
#include	<string.h>

#include	"sh.h"

#include	"builtins.h"

static void	free_item(t_aliases *byebye)
{
  free(byebye->name);
  free(byebye->value);
  free(byebye);
}

int		free_aliases(t_aliases **alias)
{
  t_aliases	*tmp;
  while (*alias != NULL)
  {
    tmp = *alias;
    *alias = (*alias)->next;
    free(tmp->name);
    free(tmp->value);
    free(tmp);
  }
  return (TRUE);
}

int		unalias(t_tree *cmd,
			t_aliases **alias)
{
  t_aliases	*tmp;
  t_aliases	*save;

  if (alias == NULL || *alias == NULL || cmd == NULL)
    return (TRUE);
  tmp = *alias;
  if (!strcmp(cmd->info.str, tmp->name))
  {
    *alias = (*alias)->next;
    free_item(tmp);
    return (unalias(cmd->right, alias));
  }
  while (tmp->next != NULL)
  {
    if (!strcmp(cmd->info.str, tmp->next->name))
    {
      save = tmp->next;
      tmp->next = tmp->next->next;
      free_item(save);
      return (unalias(cmd->right, alias));
    }
    tmp = tmp->next;
  }
  return (TRUE);
}
