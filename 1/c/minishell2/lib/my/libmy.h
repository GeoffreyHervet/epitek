/*
** lib.h for my in /home/hervet_g//work/lib/my
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 12 22:05:22 2010 geoffrey hervet
** Last update Tue Jan  4 17:26:20 2011 geoffrey hervet
*/

#ifndef			__LIB_MY_H__
#  define		__LIB_MY_H___

void			my_putchar(const char c,
				   const int fd);

void			my_putstr(const char *s,
				  int const fd);

char			*my_strcat(const char *left,
				   const char *right);

char			*my_strdup(const char *str);

unsigned int		my_strlen(const char *s);

int			my_strcmp(const char *s1,
				  const char *s2);

void			my_swap(void *left,
				void *right);

void			*my_memset(void *tab,
				   const int val,
				   const unsigned int size);

char			*strncpy(char *dest,
				 const char *src,
				 unsigned int length);

char			**my_explode(const char delim,
				     char *str);

void			my_free_wordtab(char **tab);

void			my_errno_oaff(const int errnum,
				     const int fd);

#endif			/* !__LIB_MY_H___ */
