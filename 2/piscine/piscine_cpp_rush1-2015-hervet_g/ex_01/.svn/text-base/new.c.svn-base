/*
** new.c for ex_01 in /home/hervet_g/rush/piscine_cpp_rush1-2015-hervet_g/ex_01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 07 03:12:27 2012 geoffrey hervet
** Last update Sat Jan 07 03:12:27 2012 geoffrey hervet
*/

#include	<stdlib.h>

#include	"new.h"
#include	"point.h"
#include	"raise.h"

Object *	new(Class *p)
{
  Object *	ret;

  if (NULL == (ret = malloc(p->__size__)))
    raise("Out of memory");
  p->__init__(ret);
  return ret;
}

void		delete(Object* ptr)
{
  if (((Class *)ptr)->__del__ != NULL)
    ((Class *)ptr)->__del__(ptr);
  free(ptr);
}
