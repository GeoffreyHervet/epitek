
#include <stdlib.h>
#include <stdarg.h>

#include "raise.h"
#include "array.h"
#include "new.h"

typedef struct
{
    Container base;
    Class* _type;
    size_t _size;
    Object** _tab;
} ArrayClass;

typedef struct {
    Iterator base;
    ArrayClass* _array;
    size_t _idx;
} ArrayIteratorClass;

static void ArrayIterator_ctor(ArrayIteratorClass* self, va_list* args)
{
  self->_array = va_arg(*args, ArrayClass*);
  self->_idx = va_arg(*args, size_t);
}

static void ArrayIterator_incr(ArrayIteratorClass* self)
{
  self->_idx++;
}

static Object* ArrayIterator_getval(ArrayIteratorClass* self)
{
  return self->_array->_tab[self->_idx];
}

static bool ArrayIterator_eq(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  return eq(self->_array->_tab[self->_idx],  other->_array->_tab[other->_idx]);
}

static bool ArrayIterator_gt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  return gt(self->_array->_tab[self->_idx],  other->_array->_tab[other->_idx]);
}

static bool ArrayIterator_lt(ArrayIteratorClass* self, ArrayIteratorClass* other)
{
  return lt(self->_array->_tab[self->_idx],  other->_array->_tab[other->_idx]);
}

static void ArrayIterator_setval(ArrayIteratorClass* self, ...)
{
  va_list ap;

  va_start(ap, self);
  ((Class *)(self->_array->_tab[self->_idx]))->__init__(self->_array->_tab[self->_idx], &ap);
}

static ArrayIteratorClass ArrayIteratorDescr = {
    {
        {
            sizeof(ArrayIteratorClass), "ArrayIterator",
            (ctor_t) &ArrayIterator_ctor,
            NULL, /* dtor */
            NULL, /* str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            (binary_comparator_t) &ArrayIterator_eq,
            (binary_comparator_t) &ArrayIterator_gt,
            (binary_comparator_t) &ArrayIterator_lt,
        },
        (incr_t) &ArrayIterator_incr,
        (getval_t) &ArrayIterator_getval,
        (setval_t) &ArrayIterator_setval,
    },
    NULL,
    0
};

static Class* ArrayIterator = (Class*) &ArrayIteratorDescr;

void Array_ctor(ArrayClass* self, va_list* args)
{
  size_t	size;
  va_list	aq;

  self->_size = va_arg(*args, size_t);
  self->_type = va_arg(*args, Class*);
  size = self->_size;
  if (NULL == (self->_tab = malloc((size + 1) * self->_type->__size__)))
    raise("out of memory");
  self->_tab[size] = NULL;
  size = 0;
  while (size < self->_size)
  {
    va_copy(aq, *args);
    self->_tab[size++] = va_new(self->_type, &aq);
    va_end(aq);
  }
}

void Array_dtor(ArrayClass* self)
{
  size_t	i = 0;

  while (i < self->_size)
    delete(self->_tab[i++]);
}

size_t Array_len(ArrayClass* self)
{
  return self->_size;
}

Iterator* Array_begin(ArrayClass* self)
{
  return (Iterator *)new(ArrayIterator, self, 0);
}

Iterator* Array_end(ArrayClass* self)
{
  return (Iterator *)new(ArrayIterator, self, self->_size - 1);
}

Object* Array_getitem(ArrayClass* self, ...)
{
  va_list	ap;
  Object	*item;

  va_start(ap, self);
  item = self->_tab[va_arg(ap, size_t)];
  va_end(ap);
  return item;
}

void Array_setitem(ArrayClass* self, ...)
{
  va_list	ap;
  size_t	idx;

  va_start(ap, self);
  idx = va_arg(ap, size_t);
  if (idx < self->_size)
    {
      delete(self->_tab[idx]);
      self->_tab[idx] = va_new(self->_type, &ap);
    }
  va_end(ap);
}

static ArrayClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ArrayClass), "Array",
            (ctor_t) &Array_ctor, (dtor_t) &Array_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &Array_len,
        (iter_t) &Array_begin,
        (iter_t) &Array_end,
        (getitem_t) &Array_getitem,
        (setitem_t) &Array_setitem,
    },
    NULL, 0, NULL
};

Class* Array = (Class*) &_descr;
