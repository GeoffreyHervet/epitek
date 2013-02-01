/*
** malloc.c for malloc.c in /home/poigna_s//my_malloc_svn
** 
** Made by sarah poignant
** Login   <poigna_s@epitech.net>
** 
** Started on  Fri Jan 27 11:09:22 2012 sarah poignant
** Last update Fri Jan 27 14:12:03 2012 sarah poignant
*/

#include	<stdlib.h>

#include	"block_init.h"

t_block		*block_init(void *addr,
                            size_t size,
                            char is_free)
{
  t_block	*item;

  item = (t_block*) addr;
  item->prev = NULL;
  item->next = NULL;
  item->is_free = is_free;
  item->size = size;
  return item;
}

/*
** item->ptr = item + 1;
*/
