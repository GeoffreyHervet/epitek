/*
** int.c for  in /home/musial_j//piscine/piscine_cpp_rush1-2015-hervet_g/ex_04
**
** Made by jerome musialak
** Login   <musial_j@epitech.eu>
**
** Started on  Sat Jan  7 21:42:21 2012 jerome musialak
** Last update Sun Jan  8 07:29:53 2012 jerome musialak
*/

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>

#include	"bool.h"
#include	"int.h"
#include	"raise.h"
#include	"new.h"

typedef struct
{
  Class base;
  int	i;
}	IntClass;

static char const *__str(Object *self);
static Object *	__add(const Object* self, const Object* other);
static Object *	__sub(const Object* self, const Object* other);
static Object * __mul(const Object* self, const Object* other);
static Object * __div(const Object* self, const Object* other);
static bool __eq(const Object* self, const Object* other);
static bool __gt(const Object* self, const Object* other);
static bool __lt(const Object* self, const Object* other);

static void Int_ctor(Object* self, va_list *ap)
{
  ((IntClass *)self)->i = va_arg(*ap, int);
}

static void Int_dtor(Object* self)
{
  free(self);
}

static Object *	__add(const Object* self, const Object* other)
{
  return new (Int, ((IntClass *)self)->i + ((IntClass *)other)->i);
}

static Object *	__sub(const Object* self, const Object* other)
{
  return new (Int, ((IntClass *)self)->i - ((IntClass *)other)->i);
}

static Object * __mul(const Object* self, const Object* other)
{
  return new (Int, ((IntClass *)self)->i * ((IntClass *)other)->i);
}

static Object * __div(const Object* self, const Object* other)
{
  return new (Int, ((IntClass *)self)->i / ((IntClass *)other)->i);
}

static bool __eq(const Object* self, const Object* other)
{
  if (((IntClass *)self)->i == ((IntClass *)other)->i)
    return true;
  return false;
}

static bool __gt(const Object* self, const Object* other)
{
  if (((IntClass *)self)->i > ((IntClass *)other)->i)
    return true;
  return false;
}

static bool __lt(const Object* self, const Object* other)
{
  if (((IntClass *)self)->i < ((IntClass *)other)->i)
    return true;
  return false;
}

static char const *__str(Object *self)
{
  char *str;

  asprintf(&str,
	   "<%s (%d)>",
	   ((IntClass *)self)->base.__name__,
	   ((IntClass *)self)->i);
  if (str == NULL)
    raise("out of memory");
  return str;
}

static IntClass _description = {
    {
        sizeof(IntClass),
        "Int",
        Int_ctor,
        Int_dtor,
        __str,
        __add,
        __sub,
        __mul,
        __div,
        __eq,
        __gt,
        __lt
    },
    0
};

Class* Int = (Class*) &_description;
