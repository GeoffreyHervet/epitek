/*
** sortlist.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 21:46:53 2011 geoffrey hervet
** Last update Wed May 04 21:46:53 2011 geoffrey hervet
*/

#ifndef		SORTLIST_H_
# define	SORTLIST_H_

typedef int (*t_predicate)(t_list *, t_list *);

void		sortlist(t_list *begin,
			 t_predicate pred);

#endif		/* !SORTLIST_H_ */
