/*
** my_sys.c for my_sys in /home/poigna_s//my_malloc_svn
** 
** Made by sarah poignant
** Login   <poigna_s@epitech.net>
** 
** Started on  Fri Jan 27 12:08:00 2012 sarah poignant
** Last update Fri Jan 27 13:32:14 2012 sarah poignant
*/

#include	"my_malloc.h"

#if 0
void     *my_sbrk(intptr_t s) /* incremente l'espace de donnes */
{
  void   *i;
  if ((int)(i = sbrk(s) == -1))
    return (NULL);
  else
    return (i);
}

long	my_sysconf(int name) // obtenir des infos de config
{
  long	res;

  res = sysconf(name);
  if (res == -1)
    res = 0;
  return (res);
}

#endif
