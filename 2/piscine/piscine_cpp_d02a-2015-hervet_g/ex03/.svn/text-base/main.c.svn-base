/*
** main.c for ex03 in /home/hervet_g/piscine/piscine_cpp_d02a-2015-hervet_g/ex03
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 23:25:03 2012 geoffrey hervet
** Last update Thu Jan 05 23:25:03 2012 geoffrey hervet
*/

#include	<stdio.h>

#include	"stack.h"

int main(void)
{
  t_stack stack = NULL;
  int i = 5;
  int j = 4;
  int *data;

  stack_push(&stack, &i);
  stack_push(&stack, &j);

  data = (int *)stack_top(stack);

  printf("%d\n", *data);

  return (0);
}
