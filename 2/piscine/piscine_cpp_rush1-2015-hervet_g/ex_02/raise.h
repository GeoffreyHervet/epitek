/*
** raise.h for ex_02 in /home/hervet_g/rush/piscine_cpp_rush1-2015-hervet_g/ex_02
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 07 16:17:38 2012 geoffrey hervet
** Last update Sat Jan 07 16:17:38 2012 geoffrey hervet
*/

#ifndef RAISE_H
# define RAISE_H

# include <stdio.h>
# include <stdlib.h>

# define raise(msg)                                             \
do {                                                            \
    fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);   \
    abort();                                                    \
} while (0)

#endif

