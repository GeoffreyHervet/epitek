/*
** my_memset.c for my in /home/hervet_g//work/projets/minishel/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Dec 23 10:46:14 2010 geoffrey hervet
** Last update Sun Jan  2 11:31:12 2011 geoffrey hervet
*/

#include		"libmy.h"

void			*my_memset(void *tab,
				   const int val,
				   const unsigned int size)
{
  unsigned int		idx;
  char			*tmp;

  idx = 0;
  tmp = (char *) tab;
  while (idx < size)
    {
      tmp[idx++] = val;
    }
  tab = tmp;
  return (tab);
}
