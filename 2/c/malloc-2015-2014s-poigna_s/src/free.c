/*
** free.c for free.c in /home/poigna_s//tek0/malloc/src
** 
** Made by sarah poignant
** Login   <poigna_s@epitech.net>
** 
** Started on  Fri Jan 27 15:56:45 2012 sarah poignant
** Last update Sat Jan 28 13:29:06 2012 sarah poignant
*/

#include	<stdio.h>

#include	"free.h"
#include	"malloc.h"
#include	"show_alloc_mem.h"

/*
** join right : va tout le temps reset le b->next
** jusqu'a avoir un next = NULL ou occupe
*/

static void	join_right(t_block *b)
{
  size_t	dec;

  while ((b != NULL) && (b->next != NULL))
  {
    if (b->next != (t_block *)(((char *)(b) + sizeof(*b) + b->size)) ||
        !b->next->is_free)
      return;
    b->size = sizeof(*b) + b->next->size;
    b->next = b->next->next;
    if (b->next != NULL)
      b->next->prev = b;
  }
  if (b != NULL && b->next == NULL && b->size > (size_t)(PAGE_SIZE))
  {
    dec = b->size - b->size % PAGE_SIZE;
    if ((void*)(-1) != brk((void *)((char *)(b + 1) + b->size - dec)))
      b->size %= PAGE_SIZE;
  }
}

static t_block	*join_left(t_block *b)
{
  while (b != NULL && b->prev != NULL)
  {
    if (b != (t_block *)((char *)(b->prev) + b->prev->size + sizeof(*b))
        || !b->prev->is_free)
      return b;
    b->size += b->prev->size + sizeof(*b);
    b->prev = b->prev->prev;
    if (b->prev != NULL)
      b->prev->next = b;
  }
  return b;
}

/*
** Checker si le prev ou le next est free
** le join right join les next tant que
** c'est libre, et retourne le
*/

void		free(void *ptr)
{
  t_block	*b;

  if (ptr != NULL)
  {
    b = (t_block*)(ptr) - 1;
    b->is_free = 1;
    if (0)  join_right(b);
    if (0) join_left(b);
  }
}
