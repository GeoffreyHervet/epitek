/*
** realloc.h for inc in /home/hervet_g/malloc/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Jan 31 23:07:15 2012 geoffrey hervet
** Last update Tue Jan 31 23:07:15 2012 geoffrey hervet
*/

#ifndef   __REALLOC_H__
# define  __REALLOC_H__

# define CHECK(i, j)  ((i) < (j) ? (i) : (j))

void      *realloc(void *ptr, size_t size);

#endif     /* !__REALLOC_H__ */
