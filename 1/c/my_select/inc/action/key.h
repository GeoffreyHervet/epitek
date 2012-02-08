/*
** key.h for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Jan 15 17:49:06 2011 geoffrey hervet
** Last update Sun Jan 16 00:11:58 2011 geoffrey hervet
*/

#ifndef		__ACTION_KEY_H__
# define	__ACTION_KEY_H__

void		upper_key(t_infos *inf,
			  const int fd);
void		left_key(t_infos *inf,
			 const int fd);
void		right_key(t_infos *inf,
			  const int fd);
void		down_key(t_infos *inf,
			 const int fd);
void		delete_item(t_infos *inf,
			    const int fd);
void		delete_itemb(t_infos *inf,
			     const int fd);
void		validate(t_infos *inf,
			 const int fd);
void		escape_prog(t_infos *inf,
			    const int fd);

void		select_item(t_infos *inf,
			    const int fd);
#endif		/* !__ACTION_KEY_H__ */
