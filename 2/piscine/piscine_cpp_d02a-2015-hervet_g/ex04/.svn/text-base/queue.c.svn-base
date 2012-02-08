/*
** queue.c for ex04 in /home/hervet_g/piscine/piscine_cpp_d02a-2015-hervet_g/ex04
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 23:32:23 2012 geoffrey hervet
** Last update Thu Jan 05 23:32:23 2012 geoffrey hervet
*/

#include	<stdlib.h>

#include	"queue.h"

unsigned int    queue_get_size(t_queue queue)
{
  unsigned int	size = 0;

  while (queue != NULL)
  {
    size++;
    queue = queue->next;
  }
  return size;
}

t_bool          queue_is_empty(t_queue queue)
{
  if (queue == NULL)
    return TRUE;
  return FALSE;
}

t_bool  queue_push(t_queue *queue_ptr, void *elem)
{
  t_queue	item;

  if (*queue_ptr == NULL)
  {
    if (NULL == (item = malloc(sizeof(*item))))
      return FALSE;
    *queue_ptr = item;
    item->next = NULL;
    item->value = elem;
    return TRUE;
  }
  item = *queue_ptr;
  while (item->next != NULL)
    item = item->next;
  if (NULL == (item->next = malloc(sizeof(*item))))
    return FALSE;
  item->next->next = NULL;
  item->next->value = elem;
  return TRUE;
}

t_bool  queue_pop(t_queue *queue_ptr)
{
  t_queue	item;

  if (*queue_ptr == NULL)
    return FALSE;
  item = (*queue_ptr)->next;
  free(*queue_ptr);
  *queue_ptr = item;
  if (*queue_ptr == NULL)
    return FALSE;
  return TRUE;
}

void    *queue_front(t_queue queue)
{
  if (queue == NULL)
    return NULL;
  return queue->value;
}

