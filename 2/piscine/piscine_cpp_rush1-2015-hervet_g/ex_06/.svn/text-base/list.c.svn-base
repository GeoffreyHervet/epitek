/*
** list.c for  in /home/musial_j//piscine/piscine_cpp_rush1-2015-hervet_g/ex_06
**
** Made by jerome musialak
** Login   <musial_j@epitech.eu>
**
** Started on  Sun Jan  8 08:50:20 2012 jerome musialak
** Last update Sun Jan  8 09:19:12 2012 jerome musialak
*/


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
  Object** _list;
} ListClass;

typedef struct {
  Iterator base;
  ListClass* _list;
  Object* _idx;
} ListIteratorClass;


/***********************/

void List_ctor(ListClass* self, va_list* args)
{
  size_t	size;
  va_list	aq;

  self->_size = va_arg(*args, size_t);
  self->_type = va_arg(*args, Class*);
  size = self->_size;
  /* creer premier maillon */
  size = 0;
  while (size < self->_size)
  {
    va_copy(aq, *args);
    /* self->_add_node_at_back(va_new(self->_type, &aq)); */
    va_end(aq);
  }
}

void List_dtor(ListClass* self)
{
  /* size_t	i = 0; */

  /* while (i < self->_size) */
  /*   delete(self->_tab[i++]); */
  (void)self;
}

size_t List_len(ListClass* self)
{
  return self->_size;
}

/* Iterator* List_begin(ListClass* self) */
/* { */
/*   return (Iterator *)new(ListIterator, self, 0); */
/* } */

/* Iterator* List_end(ListClass* self) */
/* { */
/*   return (Iterator *)new(ListIterator, self, self->_size - 1); */
/* } */

Object* List_getitem(ListClass* self, ...)
{
  va_list	ap;
  Object	*item;

  va_start(ap, self);
  item = self->_tab[va_arg(ap, size_t)];
  va_end(ap);
  return item;
}

void List_setitem(ListClass* self, ...)
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

static ListClass _descr = {
    { /* Container */
        { /* Class */
            sizeof(ListClass), "List",
            (ctor_t) &List_ctor, (dtor_t) &List_dtor,
            NULL, /*str */
            NULL, NULL, NULL, NULL, /* add, sub, mul, div */
            NULL, NULL, NULL, /* eq, gt, lt */
        },
        (len_t) &List_len,
        (iter_t) &List_begin,
        (iter_t) &List_end,
        (getitem_t) &List_getitem,
        (setitem_t) &List_setitem,
    },
    NULL, 0, NULL
};

Class* List = (Class*) &_descr;
