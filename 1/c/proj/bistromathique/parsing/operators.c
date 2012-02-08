/*
** operators.c for bistro in /home/hervet_g//work/projets/c/bistro/parsing
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Oct 29 20:56:26 2010 geoffrey hervet
** Last update Sat Oct 30 00:53:30 2010 geoffrey hervet
*/

#include	"../bistromathique.h"
#include	<stdlib.h>

int		get_operator_priority(char c, t_expr *s)
{
  static int	priority[7];
  int		ops_position;

  if (s == '\0')
    {
      priority[0] = 3;
      priority[1] = 3;
      priority[2] = 1;
      priority[3] = 1;
      priority[4] = 2;
      priority[5] = 2;
      priority[6] = 2;
      priority[7] = 0;
      return (0);
    }
  ops_position = 0;
  while (ops_position < 7)
    {
      if(s->ops[ops_position] == c)
	return (priority[ops_position]);
      ops_position++;
    }
  return (0);
}

int		is_operator(t_expr *s, int pos)
{
  int		ops_pos;

  ops_pos = 0;
  while (ops_pos < 7)
    {
      if (s->expr[pos] == s->ops[ops_pos])
	{
	  if (s->ops[ops_pos] == 0)
	    return (-1);
	  if (s->ops[ops_pos++] == 1)
	    return (-2);
	}
    }
  return (0);
}

int		get_highest_priority(t_expr *s, int start, int end)
{
  int		max_prio;

  max_prio = 0;
  while (s->expr[start] && start <= end)
    {
      max_prio = GET_MAX(max_prio, get_operator_priority(s->expr[start++], s));
      if (max_prio == 3)
	return(max_prio);
    }
  return (max_prio);
}

int		is_only_digits(t_expr *s, int start, int end)
{
  while (s->expr[start] && start <= end)
    {
      if (get_operator_priority(s->expr[start++], s))
	return (0);
    }
  return (1);
}

int		count_operators(t_expr *s, int start, int end)
{
  int		count;
  int		tmp;

  count = 0;
  while (s->expr[start] && start <= end)
    {
      tmp = is_operator(s, start++);
      if (tmp > 0)
	count += tmp;
    }
  return (tmp);
}
