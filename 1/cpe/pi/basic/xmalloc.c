/*
** xmalloc.c for  in /u/all/hervet_g/public/Pi/basic
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Wed Apr 27 22:12:53 2011 tracy nelcha
** Last update Wed Apr 27 22:13:28 2011 tracy nelcha
*/

#include        <stdlib.h>

void            xmalloc(size_t size)
{
  int           ptr;

  ptr = malloc(size);
  if (ptr == NULL)
  {
    my_putstr(R"[ERROR] -> invalid malloc"W);
    exit(EXIT_FAILURE);
  }
}
