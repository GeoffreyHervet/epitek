/*
** lib.h for my in /home/hervet_g//work/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 22:05:22 2010 geoffrey hervet
** Last update Sat Jan 15 14:20:52 2011 geoffrey hervet
*/

#ifndef			__LIB_MY_H__
#  define		__LIB_MY_H___

void			my_putchar(const char c,
				   int const fd);
void			my_putstr(const char *s,
				  int const fd);
char			*my_strcat(const char *left,
				   const char *right);
char			*my_strdup(const char *str);

unsigned int		my_strlen(const char *s);

int			my_strcmp(const char *s1,
				  const char *s2);

int			my_strncmp(const char *s1,
				   const char *s2,
				   unsigned int size);

void			my_swap(void *left,
				void *right);

void			*my_memset(void *,
				   const int val,
				   unsigned int size);

char			*strncpy(char *dest,
				 const char *src,
				 unsigned int length);

char			**my_explode(const char delim,
				     const char *str);

void			my_free_wordtab(char **);

void			my_errno_aff(const int errnum,
				     const int fd);

#endif			/* !__LIB_MY_H___ */
