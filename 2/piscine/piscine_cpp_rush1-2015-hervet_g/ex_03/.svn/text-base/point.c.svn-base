/*
** point.c for ex_02 in /home/hervet_g/rush/piscine_cpp_rush1-2015-hervet_g/ex_02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 07 16:28:24 2012 geoffrey hervet
** Last update Sat Jan 07 16:28:24 2012 geoffrey hervet
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>

#include	"point.h"
#include	"raise.h"
#include	"new.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static char const *Point_to_str(Object *self);
static Object *	__add(const Object* self, const Object* other);
static Object *	__sub(const Object* self, const Object* other);


static void Point_ctor(Object* self, va_list *ap)
{
  ((PointClass *)self)->x = va_arg(*ap, int);
  ((PointClass *)self)->y = va_arg(*ap, int);
}

static void Point_dtor(Object* self)
{
  free(self);
}

static char const *Point_to_str(Object *self)
{
  /* length('<', ' (', ', ', '>\0') = 9) */
  size_t	  length = 8;
  char		  *str = NULL;

  size_t	 getIntWith(int a)
  {
    if (a < 0) return 1 + getIntWith(- a);
    if (0 == (a / 10)) return 1;
    return 1 + getIntWith(a / 10);
  }

  /* get the size of str */
  length += strlen(((PointClass *)self)->base.__name__);
  length += getIntWith(((PointClass *)self)->x);
  length += getIntWith(((PointClass *)self)->y);
  if (NULL == (str = malloc(sizeof(*str) * length)))
    raise("Out of memory");
  snprintf(str, length, "<%s (%i, %i)>",
      ((PointClass *)self)->base.__name__,
      ((PointClass *)self)->x,
      ((PointClass *)self)->y);
  return str;
}

static Object *	__add(const Object* self, const Object* other)
{
  return new(Point,
      ((PointClass *)self)->x + ((PointClass *)other)->x,
      ((PointClass *)self)->y + ((PointClass *)other)->y);
}

static Object *	__sub(const Object* self, const Object* other)
{
  return new(Point,
      ((PointClass *)self)->x - ((PointClass *)other)->x,
      ((PointClass *)self)->y - ((PointClass *)other)->y);
}

static PointClass _description = {
    {
        sizeof(PointClass),
        "Point",
        Point_ctor,
        Point_dtor,
        Point_to_str,
        __add,
        __sub
    },
    0,
    0
};

Class* Point = (Class*) &_description;
