/*
** my_select.h for my_select in /home/hervet_g//work/projets/my_select
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Jan 14 17:17:10 2011 geoffrey hervet
** Last update Sat Jan 15 17:12:03 2011 geoffrey hervet
*/

#ifndef			__MY_SELECT_H__
# define		__MY_SELECT_H__

# define		GET_MAX(x, y)		(((x) > (y)) ? (x) : (y))

# define		ERR_MALLOC		"Memmory allocation failled ...\n"
# define		ERR_OPEN		"Sys-call open() failled ...\n"
# define		ERR_CLOSE		"Sys-call close() failled ...\n"

# define		FL_SELECT		1
# define		FL_HOVER		2

typedef struct		s_coords
{
  int			col;
  int			row;
}			t_coords;

typedef struct		s_list_db
{
  t_coords		coords;
  unsigned int		flags;
  const char		*data;
  struct s_list_db	*next;
  struct s_list_db	*prev;
}			t_list_db;

typedef struct		s_infos
{
  int			min_w;
  unsigned int		flags;
  t_coords		*window;
  t_coords		*cursor;
  t_list_db		*cursor_item;
  t_list_db		*begin;
}			t_infos;

#endif			/* !__MY_SELECT_H__ */
