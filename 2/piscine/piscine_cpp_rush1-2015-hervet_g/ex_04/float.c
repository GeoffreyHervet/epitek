#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>

#include	"bool.h"
#include	"float.h"
#include	"raise.h"
#include	"new.h"

typedef struct
{
    Class base;
    float f;
} FloatClass;

static char const *__str(Object *self);
static Object *	__add(const Object* self, const Object* other);
static Object *	__sub(const Object* self, const Object* other);
static Object *__mul(const Object* self, const Object* other);
static Object *__div(const Object* self, const Object* other);
static bool   __eq(const Object* self, const Object* other);
static bool   __gt(const Object* self, const Object* other);
static bool   __lt(const Object* self, const Object* other);


static void Float_ctor(Object* self, va_list *ap)
{
  ((FloatClass *)self)->f = (float) va_arg(*ap, double);
}

static void Float_dtor(Object* self)
{
  (void) self;
}

static char const *__str(Object *self)
{
  char *str = NULL;

  if (asprintf(&str, "<%s (%f)>", ((FloatClass *)self)->base.__name__, ((FloatClass *)self)->f) == -1 || str == NULL)
    raise("out of memory");
  return str;
}

static Object * __add(const Object* self, const Object* other)
{
  return new(Float,
	     ((FloatClass *)self)->f + ((FloatClass *)other)->f);
}

static Object * __sub(const Object* self, const Object* other)
{
  return new(Float,
             ((FloatClass *)self)->f - ((FloatClass *)other)->f);
}

static Object * __mul(const Object* self, const Object* other)
{
  return new(Float,
             ((FloatClass *)self)->f * ((FloatClass *)other)->f);
}
_GNU_SOURCE
static Object * __div(const Object* self, const Object* other)
{
  if (((FloatClass *)other)->f == 0)
    raise("Floating exception");
  return new(Float,
             ((FloatClass *)self)->f / ((FloatClass *)other)->f);
}

static bool   __eq(const Object* self, const Object* other)
{
  if (((FloatClass *)self)->f == ((FloatClass *)other)->f)
    return true;
  return false;
}

static bool   __gt(const Object* self, const Object* other)
{
  if (((FloatClass *)self)->f > ((FloatClass *)other)->f)
    return true;
  return false;
}

static bool   __lt(const Object* self, const Object* other)
{
  if (((FloatClass *)self)->f < ((FloatClass *)other)->f)
    return true;
  return false;
}

static FloatClass _description = {
    {
        sizeof(FloatClass),
        "Float",
        Float_ctor,
        Float_dtor,
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

Class* Float = (Class*) &_description;
