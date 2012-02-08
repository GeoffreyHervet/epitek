/*
** xmalloc.c for  in /home/rufin_q//projet/lem-in/lem-in/src
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Thu Apr 21 17:35:32 2011 quentin rufin
** Last update Thu Apr 21 17:39:01 2011 quentin rufin
*/

#include <stdlib.h>

void	*xmalloc(int size)
{
  void	*ret;

  ret = malloc(size);
  if (ret == NULL)
    exit(EXIT_FAILURE);
  return (ret);
}
