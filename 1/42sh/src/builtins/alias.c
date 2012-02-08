/*
** alias.c for builtins in /home/hervet_g/work/42sh/src/builtins
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 14:02:55 2011 geoffrey hervet
** Last update Thu May 12 17:17:28 2011 quentin rufin
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"sh.h"

#include	"builtins.h"
#include	"xmalloc.h"
#include	"xstrdup.h"

static int	aff_list(t_aliases *aliases)
{
  while (aliases != NULL)
  {
    printf("%s=%s\n", aliases->name, aliases->value);
    aliases = aliases->next;
  }
  return (TRUE);
}

static char	*get_value(t_tree *cmd)
{
  char		*ret;
  int		len;
  t_tree	*tmp;

  len = 0;
  tmp = cmd;
  while (tmp != NULL)
    {
      len += strlen(tmp->info.str) + 1;
      tmp = tmp->right;
    }
  if ((ret = malloc(sizeof(*ret) * (len))) == NULL)
    return (NULL);
  ret[0] = 0;
  while (cmd != NULL)
  {
    if (ret[0])
      strcat(ret, " ");
    strcat(ret, cmd->info.str);
    cmd = cmd->right;
  }
  return (ret);
}

static int	add_alias(t_tree *cmd,
			  t_aliases **aliases)
{
  t_aliases	*tmp;

  tmp = *aliases;
  while (tmp != NULL)
  {
    if (!strcmp(cmd->info.str, tmp->name))
    {
      free(tmp->value);
      tmp->value = xstrdup(cmd->right->info.str);
      return ((tmp->value == NULL) ? FALSE : TRUE);
    }
    tmp = tmp->next;
  }
  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (FALSE);
  tmp->next = *aliases;
  *aliases = tmp;
  tmp->value = get_value(cmd->right);
  tmp->name = xstrdup(cmd->info.str);
  return ((tmp->value == NULL || tmp->name == NULL) ? FALSE : TRUE);
}

int		alias_set(t_tree *cmd,
			  t_aliases **aliases)
{
  if (cmd == NULL)
    return (aff_list(*aliases));
  if (cmd->right == NULL)
  {
    fprintf(stderr, "Error : alias <name> <value ...>\n");
    return (FALSE);
  }
  if (FALSE == add_alias(cmd, aliases))
  {
    fprintf(stderr, "Can't perform malloc\n");
    return (FALSE);
  }
  return (TRUE);
}
