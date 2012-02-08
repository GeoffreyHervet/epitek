/*
** char.c for ex_04 in /home/hervet_g/rush/piscine_cpp_rush1-2015-hervet_g/ex_04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 07 21:31:40 2012 geoffrey hervet
** Last update Sat Jan  7 21:45:13 2012 vincent caggiari
*/
#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>

#include	"bool.h"
#include	"char.h"
#include	"raise.h"
#include	"new.h"

typedef struct
{
    Class base;
    char c;
} CharClass;

static char const *__str(Object *self);
static Object *	__add(const Object* self, const Object* other);
static Object *	__sub(const Object* self, const Object* other);
static Object * __mul(const Object* self, const Object* other);
static Object * __div(const Object* self, const Object* other);
static bool __eq(const Object* self, const Object* other);
static bool __gt(const Object* self, const Object* other);
static bool __lt(const Object* self, const Object* other);

static void Char_ctor(Object* self, va_list *ap)
{
  ((CharClass *)self)->c = (char) va_arg(*ap, int);
}

static void Char_dtor(Object* self)
{
  free(self);
}

static Object *	__add(const Object* self, const Object* other)
{
  return new(Char, ((CharClass *)self)->c + ((CharClass *)other)->c);
}

static Object *	__sub(const Object* self, const Object* other)
{
  return new(Char, ((CharClass *)self)->c - ((CharClass *)other)->c);
}

static Object * __mul(const Object* self, const Object* other)
{
  return new(Char, ((CharClass *)self)->c * ((CharClass *)other)->c);
}

static Object * __div(const Object* self, const Object* other)
{
  return new(Char, ((CharClass *)self)->c / ((CharClass *)other)->c);
}

static bool __eq(const Object* self, const Object* other)
{
  if (((CharClass *)self)->c == ((CharClass *)other)->c)
    return true;
  return false;
}

static bool __gt(const Object* self, const Object* other)
{
  if (((CharClass *)self)->c > ((CharClass *)other)->c)
    return true;
  return false;
}

static bool __lt(const Object* self, const Object* other)
{
  if (((CharClass *)self)->c < ((CharClass *)other)->c)
    return true;
  return false;
}

static char const *__str(Object *self)
{
  char		*ret;

  asprintf(&ret,
      "<%s (%c)>",
      ((CharClass *)self)->base.__name__,
      ((CharClass *)self)->c);
  if (ret == NULL)
    raise("Out of memory");
  return ret;
}

static CharClass _description = {
    {
        sizeof(CharClass),
        "Char",
        Char_ctor,
        Char_dtor,
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

Class* Char = (Class*) &_description;
