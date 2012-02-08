/*
** my_ls.h for my_ls in /home/hervet_g//work/projets/my_ls
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Dec 17 08:40:22 2010 geoffrey hervet
** Last update Sat Dec 18 12:15:30 2010 geoffrey hervet
*/

#ifndef			__MY_LS_H__
#  define		__MY_LS_H__

typedef struct		s_list_file
{
  char			*name;
  int			st_mode;
  int			st_uid;
  int			st_gid;
  int			st_size;
  int			st_mtime;
  int			st_nlink;
  struct s_list_file	*next;
}			t_list_file;

typedef struct		s_list_path
{
  char			*name;
  void			*begin_file_to_print;
  int			have_free;
  struct s_list_path	*next;
}			t_list_path;

typedef struct		s_infos
{
  unsigned int		flags;
  int			have_stat;
  t_list_path		*begin_path_scan;
  char			*exec_name;
}			t_infos;

#endif			/* !__MY_LS_H__ */
