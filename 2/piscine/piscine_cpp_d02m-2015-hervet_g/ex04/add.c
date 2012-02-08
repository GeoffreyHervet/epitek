/*
** add.c for ex04 in /home/hervet_g/piscine/piscine_cpp_d02m-2015-hervet_g/ex04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 20:24:03 2012 geoffrey hervet
** Last update Thu Jan 05 20:24:03 2012 geoffrey hervet
*/

#include	"castmania.h"

int		normal_add(int a, int b)
{
  return a + b;
}

int		absolute_add(int a, int b)
{
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;
  return a + b;
}

void		exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL)
    operation->add_op.res = normal_add(operation->add_op.a,
        			      operation->add_op.b);
  else if (operation->add_type == ABSOLUTE)
    operation->add_op.res = absolute_add(operation->add_op.a,
        			      	 operation->add_op.b);

}
