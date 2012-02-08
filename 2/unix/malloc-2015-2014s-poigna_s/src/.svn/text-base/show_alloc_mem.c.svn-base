/*
** show_alloc_mem.c for src in /home/hervet_g/malloc/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Jan 31 23:24:44 2012 geoffrey hervet
** Last update Tue Jan 31 23:24:44 2012 geoffrey hervet
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"show_alloc_mem.h"
#include	"malloc.h"

void            show_alloc_mem()
{
  t_block	*p;

  p = g_memory;
  printf("break: %p\n", sbrk(0));
  while (p != NULL)
  {
    printf("%p - %p : %lu octets\n",
        (void *)(p + 1),
        (void *)((char *)(p + 1) + p->size),
        p->size);
    p = p->next;
  }
}

