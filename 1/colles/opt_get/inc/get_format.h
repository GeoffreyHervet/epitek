/*
** get_format.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/public/opt_get/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon May 09 20:06:18 2011 geoffrey hervet
** Last update Mon May 09 20:06:18 2011 geoffrey hervet
*/

#ifndef			GET_FORMAT_H_
# define		GET_FORMAT_H_

typedef struct		s_format
{
  char			*str;
  int			nb_arg;
  struct s_format	*next;
  int			nb_oblig;
}			t_format;

t_format		*get_format(const char *str);

#endif     		/* !GET_FORMAT_H_ */
