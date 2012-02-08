/*
** marvin.h for marvin in /home/hervet_g//work/rush/marvin
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 26 20:24:43 2010 geoffrey hervet
** Last update Sat Nov 27 16:49:02 2010 geoffrey hervet
*/

#ifndef			__MARVIN_H__
#  define		__MARVIN_H__

#  ifndef		IS_SEPA
#    define		IS_SEPA(c)	((c) <= ' ')
#  endif		/* !IS_SEPA */

#  ifndef		MAX
#    define		MAX(x, y)	((x) > (y) ? (x) : (y))
#  endif		/* !MAX */

typedef struct		s_marvin
{
  void			*is_funct;
  char			*str;
  int			len_str;
}			t_marvin;

typedef struct		s_function
{
  int			start_type;
  int			end_type;
  int			is_return_ptr;
  int			start_name;
  int			end_name;
  int			start_return;
  int			end_return;
  void			*params;
}			t_function;

typedef struct		s_variable
{
  int			start_name;
  int			end_name;
  int			start_type;
  int			end_type;
  int			is_ptr;
  struct s_variable	*next;
}			t_variable;

typedef struct		s_translate
{
  char			*in_c;
  int			priority;
  char			*in_fr;
}			t_translate;

typedef struct		s_lang
{
  char			*trans;
  int			priority;
  struct s_lang		*next;
}			t_lang;

#endif			/* !__MARVIN_H__ */
