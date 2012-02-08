/*
** ptr_tricks.c for ex05 in /home/hervet_g/piscine/piscine_cpp_d02m-2015-hervet_g/ex05
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 14:39:12 2012 geoffrey hervet
** Last update Thu Jan 05 14:39:12 2012 geoffrey hervet
*/

#include <stdio.h>

#include	"ptr_tricks.h"

#define LUI(x) ((long unsigned int)(x))

int     get_array_nb_elem(int *ptr1, int *ptr2)
{
  int   ret = 0;

  ret = (int)((LUI(ptr2) - LUI(ptr1)) / sizeof(int));
  return (ret < 0) ? -ret : ret;
}

t_whatever *get_struct_ptr(int *member_ptr)
{
  return (t_whatever*)(LUI(member_ptr) - LUI(&((t_whatever *)(NULL))->member));
}
