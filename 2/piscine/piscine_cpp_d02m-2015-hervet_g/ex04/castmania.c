/*
** castmania.c for ex04 in /home/hervet_g/piscine/piscine_cpp_d02m-2015-hervet_g/ex04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 20:28:09 2012 geoffrey hervet
** Last update Thu Jan 05 20:28:09 2012 geoffrey hervet
*/

#include	<stdio.h>

#include	"castmania.h"

void		exec_operation(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == ADD_OPERATION)
  {
    exec_add((t_add *)(((t_instruction *)data)->operation));
    if (((t_instruction *)data)->output_type == VERBOSE)
      printf("%i\n", ((t_add *)(((t_instruction *)data)->operation))->add_op.res);
  }
  else if (instruction_type == DIV_OPERATION)
  {
    exec_div(((t_div *)(((t_instruction *)data)->operation)));
    if (((t_instruction *)data)->output_type == VERBOSE)
    {
      if (((t_div *)(((t_instruction *)data)->operation))->div_type == INTEGER)
      {
        printf("%i\n",
            ((t_integer_op*)((((t_div *)(((t_instruction *)data)->operation)))->div_op))->res
            );
      }
      else if (((t_div *)(((t_instruction *)data)->operation))->div_type == DECIMALE)
      {
        printf("%f\n",
          ((t_decimale_op*)((((t_div *)(((t_instruction *)data)->operation)))->div_op))->res
          );
      }
    }
  }
}

void		exec_instruction(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == PRINT_INT)
    printf("%i\n", *((int *)data));
  else if (instruction_type == PRINT_FLOAT)
    printf("%f\n", *((float *)data));
  else
    exec_operation(instruction_type, data);
}
