/*
** get_next_line.h for gnl in /home/hervet_g//work/projets/c/gnl
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Nov 15 09:09:12 2010 geoffrey hervet
** Last update Thu Dec 23 08:29:59 2010 geoffrey hervet
*/

#ifndef		__GNL_H__
#  define	__GNL_H__

#  ifndef	GNL_BUFFER_SIZE
#    define	GNL_BUFFER_SIZE		1024
#  endif	/* !GNL_BUFFER_SIZE */

#  ifndef	GNL_LW
#    define	GNL_LW			2048
#  endif	/* !GNL_LW */

char		*gnl(const int fd);

#endif		/* !__GNL_H__ */
