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
#include	<string.h>

#include	"new.h"
#include	"point.h"
#include	"vertex.h"
#include	"raise.h"

Object* new(Class * class, ...)
{
  va_list ap;
  Object *ret;

  va_start(ap, class);
  ret = va_new(class, &ap);
  va_end(ap);
  return ret;
}

Object* va_new(Class* class, va_list* ap)
{
  Class	*ret = NULL;

  if (NULL == (ret = malloc(class->__size__)))
    raise("Out of memory\n");

  ret = memcpy(ret, class, class->__size__);
  ret->__init__(ret, ap);
  return ret;
}

void delete(Object * ptr)
{
  ((Class *)ptr)->__del__(ptr);
}

