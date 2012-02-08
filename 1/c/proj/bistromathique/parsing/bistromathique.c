/*
** bistromathique.c for bistro in /home/hervet_g//work/projets/c/bistro
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Oct 26 08:54:55 2010 geoffrey hervet
** Last update Sat Oct 30 16:44:38 2010 geoffrey hervet
*/

#include	"../bistromathique.h"
#include	<stdlib.h>

char		*eval_expr(char *base, char *ops, char *expr, unsigned int size)
{
  t_expr	*s;

  s = create_expr_s(base, ops, expr, size);
  get_operator_priority('\0', s);
  if (expr == NULL)
    return (MALLOC_ERROR_MSG);
  if (grow_btree(s) == -1)
    return (MALLOC_ERROR_MSG);
  return (NULL);
}

t_expr		*create_expr_s(char *base, char *ops, char *expr, unsigned int size)
{
  t_expr	*exp;

  exp = malloc(sizeof(*exp));
  if (exp == NULL)
    return (NULL);
  exp->btree = malloc(sizeof(*(exp->btree)));
  if (exp->btree == NULL)
    return (NULL);
  exp->expr = expr;
  exp->base = base;
  exp->ops = ops;
  exp->size_expr = size;
  exp->size_base = my_strlen(base);
  return (exp);
}
