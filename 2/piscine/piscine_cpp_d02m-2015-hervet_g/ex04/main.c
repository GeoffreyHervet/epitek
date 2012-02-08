/*
** main.c for ex04 in /home/hervet_g/piscine/piscine_cpp_d02m-2015-hervet_g/ex04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 20:57:26 2012 geoffrey hervet
** Last update Thu Jan 05 20:57:26 2012 geoffrey hervet
*/

#include	<stdio.h>

#include	"castmania.h"

int main(void)
{
  int i = 5;
  float f = 42.5;
  t_instruction inst;
  t_add add;
  t_div div;
  t_integer_op int_op;

  printf("Affiche i : ");
  exec_instruction(PRINT_INT, &i);

  printf("Affiche f : ");
  exec_instruction(PRINT_FLOAT, &f);

  printf("\n");

  int_op.a = 10;
  int_op.b = 3;

  add.add_type = ABSOLUTE;
  add.add_op = int_op;

  inst.output_type = VERBOSE;
  inst.operation = &add;

  printf("10 + 3 = ");
  exec_instruction(ADD_OPERATION, &inst);

  printf("En effet 10 + 3 = %d\n\n", add.add_op.res);

  div.div_type = INTEGER;
  div.div_op = &int_op;

  inst.operation = &div;

  printf("10 / 3 = ");
  exec_instruction(DIV_OPERATION, &inst);

  printf("En effet 10 / 3 = %d\n\n", int_op.res);

  return (0);
}
