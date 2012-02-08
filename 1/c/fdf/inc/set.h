/*
** set.h for fdf in /home/hervet_g//work/projets/libx
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue Nov 30 13:13:15 2010 geoffrey hervet
** Last update Mon Dec  6 10:35:35 2010 geoffrey hervet
*/

#ifndef		__SET_H__
#  define	__SET_H__

t_coords	set_coords(int x, int y, int z, unsigned int color);
int		set_data_in_list(t_coords coo, t_list *item);

#endif		/* !__SET_H__ */
