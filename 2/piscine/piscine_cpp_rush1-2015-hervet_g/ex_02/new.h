/*
** new.h for ex_02 in /home/hervet_g/rush/piscine_cpp_rush1-2015-hervet_g/ex_02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 07 16:17:28 2012 geoffrey hervet
** Last update Sat Jan 07 16:17:28 2012 geoffrey hervet
*/

#ifndef NEW_H
# define NEW_H

# include <stdarg.h>

#include "object.h"

Object* new(Class * class, ...);
Object* va_new(Class* class, va_list* ap);
void delete(Object * ptr);

#endif
