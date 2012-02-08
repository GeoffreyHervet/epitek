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

#  ifndef	BUFF_SIZE
#    define	BUFF_SIZE		4096
#  endif	/* !BUFF_SIZE */

#  ifndef	READ_SIZE
#    define	READ_SIZE		4096
#  endif	/* !READ_SIZE */

char	*gnl(const int fd);

#endif		/* !__GET_NEXT_LINE__ */
