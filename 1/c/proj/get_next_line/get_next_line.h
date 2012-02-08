/*
** get_next_line.h for gnl in /home/hervet_g//work/projets/c/gnl
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Nov 15 09:09:12 2010 geoffrey hervet
** Last update Thu Nov 25 14:00:10 2010 geoffrey hervet
*/

#ifndef		__GET_NEXT_LINE__
#  define	__GET_NEXT_LINE__

#  ifndef	GNL_BUFFER_SIZE
#    define	GNL_BUFFER_SIZE		5
#  endif	/* !GNL_BUFFER_SIZE */

#  ifndef	GNL_LINE_WIDTH
#    define	GNL_LINE_WIDTH		20
#  endif	/* !GNL_LINE_WIDTH */

#  ifndef	GNL_DELIM
#    define	GNL_DELIM		'\n'
#  endif	/* !GNL_DELIM */

char	*get_next_line(const int fd);

#endif		/* !__GET_NEXT_LINE__ */
