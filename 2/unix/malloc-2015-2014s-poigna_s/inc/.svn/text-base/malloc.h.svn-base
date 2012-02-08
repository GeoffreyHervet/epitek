/*
** malloc.h for inc in /home/hervet_g/malloc/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Jan 31 16:01:02 2012 geoffrey hervet
** Last update Tue Jan 31 16:01:02 2012 geoffrey hervet
*/

#ifndef   __MALLOC_H__
# define  __MALLOC_H__

# include	<unistd.h>

# define PAGE_SIZE (getpagesize())
# define ALLOC_SIZE(x) \
  (((x) % PAGE_SIZE) ? ((x) + PAGE_SIZE - (x) %  PAGE_SIZE) * PAGE_SIZE : (x))
# define DEC_PTR(p, n) (((char *)(p)) + (n))

void                  *malloc(size_t size);

typedef struct s_block
{
  struct s_block	*next;
  struct s_block	*prev;
  size_t		 size;
  char			 is_free;
} t_block;

extern t_block	*g_memory;

#endif     /* !__MALLOC_H__ */
