/*
** dir_list.c for my_ls in /home/hervet_g//work/projets/my_ls
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Dec 17 10:40:31 2010 geoffrey hervet
** Last update Fri Dec 17 17:20:19 2010 geoffrey hervet
*/

#ifndef		__DIR_GESTION_H__
#  define	__DIR_GESTION_H__

int		open_direrror(t_infos *infos, int errnum);
int		do_inlist(t_infos *infos, char *name);
char		*get_path(char *path, char *file);
int		save_path(t_infos *infos, char *name, int have_free);

#endif		/* !__DIR_GESTION_H__ */
