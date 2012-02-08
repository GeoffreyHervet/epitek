/*
** get_id.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Apr 11 19:38:05 2011 geoffrey hervet
** Last update Sat Apr 23 18:29:06 2011 quentin rufin
*/

#ifndef   __GET_ID_H__
# define  __GET_ID_H__

# define		MAX(x, y)	((x) > (y) ? (x) : (y))

t_room		*get_id(const t_list *begin,
		        const char *name);

int		get_max_id(t_list *begin);

#endif     /* !__GET_ID_H__ */
