/*
** malloc.c for src in /home/hervet_g/malloc/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Jan 31 22:22:31 2012 geoffrey hervet
** Last update Tue Jan 31 22:22:31 2012 geoffrey hervet
*/

#include		<strings.h>
#include		<stdio.h>
#include		<strings.h>
#include		<stdlib.h>
#include		<pthread.h>

#include		"malloc.h"
#include		"block_init.h"

/*
** creation du verrou & indication de g_memory
** est partage
*/

t_block	*g_memory = NULL;
static pthread_mutex_t	g_lock;

/*
** size % 4 => pour avoir des blocs de taille %4
** le malloc alouera la taille demandee + la taille
** de la struct d'information t_block :
**
**          Memoire allouee
**
**  ________________/\________________
** /                                  \
** +---------+------------------------+
** | t_block |        void *          |
** +---------+------------------------+
**  le bloc d'   le bloc retourne
**  infos           par malloc
*/

void		*split_block(void *ret, size_t ask, size_t alc)
{
  t_block	*b;
  t_block	*tmp;

  bzero(ret, alc);
  b = block_init(ret, alc, 0);
  if (NULL == (tmp = g_memory))
    g_memory = b;
  else
  {
    while (tmp->next != NULL)
      tmp = tmp->next;
    b->prev = tmp;
    tmp->next = b;
  }
  if (alc > (ask + sizeof(int) + sizeof(*b)))
  {
    tmp = block_init(DEC_PTR(b, sizeof(*b) + ask),
        alc - b->size - sizeof(*b), 1);
    b->size = ask;
    tmp->prev = b;
    b->next = tmp;
  }
  return b + 1;
}

static void	*check_no_realoc(size_t size, t_block *ret)
{
  t_block	*tmp;

  if (NULL == (tmp = g_memory))
    return NULL;
  while (tmp != NULL)
  {
    if ((tmp->is_free && tmp->size >= size) &&
        ((ret == NULL) || (ret->size > tmp->size)))
      ret = tmp;
    tmp = tmp->next;
  }
  if (ret == NULL)
    return NULL;
  ret->is_free = 0;
  if (ret->size > (size + sizeof(int) + sizeof(*ret)))
  {
    tmp = block_init(DEC_PTR(ret, sizeof(*ret) + size),
        ret->size - size - sizeof(*ret), 1);
    tmp->next = ret->next;
    tmp->prev = ret;
    ret->next = tmp;
    ret->size = size;
  }
  return ret + 1;
}

static void	*malloc_ret(void *p)
{
  pthread_mutex_unlock(&g_lock);
  return p;
}

void		*malloc(size_t size)
{
  void		*ret;
  size_t	alloc_size;
  static int	s_check = 0;

  if (!s_check)
  {
    pthread_mutex_init(&g_lock, NULL);
    ++s_check;
  }
  pthread_mutex_lock (&g_lock);
  if (size % sizeof(int))
    size = size + sizeof(int) - size % sizeof(int);
  if (NULL != (ret = check_no_realoc(size, NULL)))
    return malloc_ret(ret);
  alloc_size = ALLOC_SIZE(size + sizeof(t_block));
  if ((((void *) -1) == (ret = sbrk(alloc_size))) ||
      (void*)(-1) == brk(((char *) ret) + alloc_size))
    return malloc_ret(NULL);
  ret = split_block(ret, size, alloc_size - sizeof(t_block));
  return malloc_ret(ret);
}
