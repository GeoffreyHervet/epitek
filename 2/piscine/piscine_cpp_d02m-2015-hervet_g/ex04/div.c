/*
** div.c for ex04 in /home/hervet_g/piscine/piscine_cpp_d02m-2015-hervet_g/ex04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 19:49:36 2012 geoffrey hervet
** Last update Thu Jan 05 19:49:36 2012 geoffrey hervet
*/

#include	"castmania.h"

int		integer_div(int a, int b)
{
  if (b == 0)
    return 0;
  return a / b;
}

float		decimale_div(int a, int b)
{
  if (b == 0)
    return 0;
  return ((float)a) / ((float)b);
}

void		exec_div(t_div *operation)
{
  if (operation->div_type == INTEGER)
    ((t_integer_op *)(operation->div_op))->res =
      integer_div(((t_integer_op *)operation->div_op)->a,
                  ((t_integer_op *)operation->div_op)->b);
  else if (operation->div_type == DECIMALE)
    ((t_decimale_op *)(operation->div_op))->res =
      decimale_div(((t_decimale_op *)(operation->div_op))->a,
                   ((t_decimale_op *)(operation->div_op))->b);
}
