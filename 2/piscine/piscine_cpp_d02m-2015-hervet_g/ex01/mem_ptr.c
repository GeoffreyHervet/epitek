/*
** mem_ptr.c for ex01 in /home/hervet_g/piscine/piscine_cpp_d02m-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 09:29:58 2012 geoffrey hervet
** Last update Thu Jan 05 09:29:58 2012 geoffrey hervet
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"mem_ptr.h"

void add_str(char *str1, char *str2, char **res)
{
  int idx = 0;
  int i;
  *res = malloc(sizeof(**res) * (strlen(str1) + strlen(str2) + 1));
  if (*res != NULL)
  {
    for (i = 0; str1[i] != 0; i++)
      (*res)[idx++] = str1[i];
    for (i = 0; str2[i] != 0; i++)
      (*res)[idx++] = str2[i];
    (*res)[idx] = 0;
  }
}

void add_str_struct(t_str_op *str_op)
{
  int idx = 0;
  int i;

  str_op->res = malloc(sizeof(*(str_op->res) * (strlen(str_op->str1) + strlen(str_op->str2) + 1)));
  if (str_op->res != NULL)
  {
    for (i = 0; str_op->str1[i] != 0; i++)
      (str_op->res)[idx++] = str_op->str1[i];
    for (i = 0; str_op->str2[i] != 0; i++)
      (str_op->res)[idx++] = str_op->str2[i];
    (str_op->res)[idx] = 0;
  }
}

