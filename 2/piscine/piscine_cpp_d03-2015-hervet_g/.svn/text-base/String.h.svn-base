/*
** String.h for ex00 in /home/hervet_g/piscine/l/kk/ex00
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Jan 06 09:15:55 2012 geoffrey hervet
** Last update Fri Jan 06 09:15:55 2012 geoffrey hervet
*/

#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>
#include	<stdio.h>

#ifndef   __STRING_H__
# define  __STRING_H__

typedef struct	s_string
{
  char			*str;
  void			(*assign_s)(struct s_string *this, struct s_string const *str);
  void			(*assign_c)(struct s_string *this, char const *s);
  void			(*append_s)(struct s_string *this, struct s_string const *str);
  void			(*append_c)(struct s_string *this, char const *s);
  char			(*at)(struct s_string *this, size_t pos);
  void			(*clear)(struct s_string *this);
  int			(*size)(struct s_string *this);
  int			(*compare_s)(struct s_string *this, struct s_string *str);
  int			(*compare_c)(struct s_string *this, char const *str);
  size_t		(*copy)(struct s_string *this, char *s, size_t n, size_t pos);
  char const *		(*c_str)(struct s_string *this);
  int			(*empty)(struct s_string *this);
  int			(*find_s)(struct s_string *this, const struct s_string *str, size_t pos);
  int			(*find_c)(struct s_string *this, const char *str, size_t pos);
  void			(*insert_c)(struct s_string *this, size_t pos, char const *str);
  void			(*insert_s)(struct s_string *this, size_t pos, struct s_string const *str);
  int			(*to_int)(struct s_string *this);
  char **		(*split_c)(struct s_string *this, char separator);
  struct s_string *	(*split_s)(struct s_string *this, char separator);
  void			(*aff)(struct s_string *this);
  void			(*join_c)(struct s_string *this, char delim, char const **tab);
  void			(*join_s)(struct s_string *this, char delim, struct s_string *tab);
  struct s_string *	(*substr)(struct s_string *this, int offset, int length);
}			String;

void		StringInit(String *this, char const *s);
void		StringDestroy(String *this);


#endif     /* !__STRING_H__ */
