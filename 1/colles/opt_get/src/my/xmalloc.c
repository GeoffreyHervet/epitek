/*
** xmalloc.c for  in /u/all/hervet_g/public/opt_get/src/my
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 19:38:32 2011 tracy nelcha
** Last update Mon May  9 21:22:54 2011 tracy nelcha
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my_strlen.h"

void		*xmalloc(int size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
  {
    write(2, "ERROR ALLOC\n", 12);
    exit(EXIT_FAILURE);
  }
  return (ptr);
}
