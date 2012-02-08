/*
** realloc.c for realloc in /home/poigna_s//my_malloc_svn
** 
** Made by sarah poignant
** Login   <poigna_s@epitech.net>
** 
** Started on  Fri Jan 27 13:47:01 2012 sarah poignant
** Last update Mon Jan 30 17:49:42 2012 sarah poignant
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"realloc.h"
#include	"malloc.h"

static size_t  pt_size(void *ptr)
{
  if (!ptr)
    return (0);
  return ((((t_block *)ptr - 1)->size));
}

/*
** On modifie la taille du bloc pointe par ptr
** pour qu'il fasse size octets On conserve
** le contenu de la zone memoire entre la new
** et l'ancienne taille. Le contenu de la new
** zone memoire allouee n'est pas init. Si ptr
** NULL aucune tentative de liberation.
*/

void      *realloc(void *ptr, size_t size)
{
  void          *ret;
  size_t        data;

  if (!size)
  {
    free(ptr);
    return (NULL);
  }
  data = pt_size(ptr);
  if (size <= data)
    return (ptr);
  ret = malloc(size);
  if (ret)
  {
    memcpy(ret, ptr, CHECK(data, size));
    free(ptr);
  }
  return (ret);
}
