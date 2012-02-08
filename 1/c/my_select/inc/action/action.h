/*
** action.h for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 17:13:59 2011 geoffrey hervet
** Last update Sat Jan 15 20:07:43 2011 geoffrey hervet
*/

#ifndef			__ACTION_H__
# define		__ACTION_H__

typedef struct		s_func_array
{
  void			(*func)();
  char			*keys;
}			t_func_array;

void			action(t_infos *inf,
			       const int fd,
			       char buf[5]);

#endif		/* !__ACTION_H__ */
