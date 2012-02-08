/*
** stack.c for ex03 in /home/hervet_g/piscine/piscine_cpp_d02a-2015-hervet_g/ex03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 23:01:09 2012 geoffrey hervet
** Last update Thu Jan 05 23:01:09 2012 geoffrey hervet
*/

#include	<stdlib.h>

#include	"stack.h"

unsigned int	stack_get_size(t_stack stack)
{
  unsigned int	size = 0;

  while (stack != NULL)
  {
    size++;
    stack = stack->next;
  }
  return size;
}

t_bool          stack_is_empty(t_stack stack)
{
  if (stack == NULL)
    return FALSE;
  return TRUE;
}

t_bool		stack_push(t_stack *stack_ptr, void *elem)
{
  t_stack	item;

  if (NULL == (item = malloc(sizeof(*item))))
    return FALSE;
  item->next = *stack_ptr;
  *stack_ptr = item;
  item->value = elem;
  return TRUE;
}

t_bool  stack_pop(t_stack *stack_ptr)
{
  t_stack	item;

  if (*stack_ptr == NULL)
    return FALSE;
  item = *stack_ptr;
  *stack_ptr = item->next;
  free(item);
  if (stack_is_empty(*stack_ptr))
    return FALSE;
  return TRUE;
}

void		*stack_top(t_stack stack)
{
  if (stack == NULL)
    return NULL;
  return stack->value;
}

