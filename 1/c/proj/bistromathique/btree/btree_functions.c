/*
** btree_functions.c for bistro in /home/hervet_g//work/projets/c/bistro/btree
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Oct 26 11:27:21 2010 geoffrey hervet
** Last update Sat Oct 30 16:48:06 2010 geoffrey hervet
*/

#include	"../bistromathique.h"
#include	<stdlib.h>

int		grow_btree(t_expr *s)
{
  s->btree->data = s->expr;
  btree_repartition(s, 0, 0, s->btree);
  return (0);
}

int		btree_repartition(t_expr *s, int pos, int tmp, t_btree *parent)
{
  t_btree	*child;

  parent = parent;
  if (is_only_digits(s, pos, my_strlen(s->expr) - 1))
    {
      free(parent->data);
      parent->data = malloc(sizeof(*(parent->data)) * my_strlen(parent->data));
      return (0);
    }
  child = malloc(sizeof(*child));
  if (child == NULL)
    return (-1);
  tmp = tmp;
  return (0);
}

int		btree_add_node(t_btree *parent, int position, char *data)
{
  t_btree	*child;

  if ((child = malloc(sizeof(*child))) == NULL)
    return (-1);
  child->data = data;
  parent = parent;
  if (position == 0)
    {
      child->right = NULL;
      child->left = child;
    }
  else
    {
      child->left = NULL;
      child->right = child;
    }
  return (1);
}
