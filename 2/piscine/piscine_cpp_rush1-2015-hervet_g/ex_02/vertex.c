/*
** vertex.c for ex_02 in /home/hervet_g/rush/piscine_cpp_rush1-2015-hervet_g/ex_02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 07 16:21:02 2012 geoffrey hervet
** Last update Sat Jan 07 16:21:02 2012 geoffrey hervet
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>

#include	"vertex.h"
#include	"raise.h"

typedef struct
{
    Class base;
    int x, y, z;
} VertexClass;


static void Vertex_ctor(Object* self, va_list *ap)
{
  ((VertexClass *)self)->x = va_arg(*ap, int);
  ((VertexClass *)self)->y = va_arg(*ap, int);
  ((VertexClass *)self)->z = va_arg(*ap, int);
}

static void Vertex_dtor(Object* self)
{
  (void) self;
}

static char const *__str(Object *self)
{
  /* length('<', ' (', ' ', ', ', ', ', '>\0') = 11) */
  size_t	  length = 10;
  char		  *str = NULL;

  size_t	 getIntWith(int a)
  {
    if (a < 0) return 1 + getIntWith(- a);
    if (0 == (a / 10)) return 1;
    return 1 + getIntWith(a / 10);
  }

  /* get the size of str */
  length += strlen(((VertexClass *)self)->base.__name__);
  length += getIntWith(((VertexClass *)self)->x);
  length += getIntWith(((VertexClass *)self)->y);
  length += getIntWith(((VertexClass *)self)->z);
  if (NULL == (str = malloc(sizeof(*str) * length)))
    raise("Out of memory");
  snprintf(str, length, "<%s (%i, %i, %i)>",
      ((VertexClass *)self)->base.__name__,
      ((VertexClass *)self)->x,
      ((VertexClass *)self)->y,
      ((VertexClass *)self)->z);
  return str;
}


static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &__str},
    0, 0, 0
};

Class* Vertex = (Class*) &_description;
