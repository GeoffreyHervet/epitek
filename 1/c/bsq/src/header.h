/*
** header.h for bsq in /home/hervet_g//work/projets/c/bsq/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Nov 10 12:22:42 2010 geoffrey hervet
** Last update Sat Nov 13 14:39:17 2010 geoffrey hervet
*/

#ifndef		__HEADER_H__
#  define	__HEADER_H__

#  ifndef	BUFFER_SIZE
#    define	BUFFER_SIZE	1024
#  endif	/* !BUFFER_SIZE */

#  define	ERR_OPEN	"the file can't be open"
#  define	ERR_ALLOC	"allocation memory error"
#  define	ERR_LINES	"the number of lines is incorrect"

#  define	CHAR_NEW_LINE	'\n'
#  define	CHAR_OK		'.'
#  define	CHAR_REPLACE	'x'

typedef	struct	s_file
{
  char		*message;
  char		**tab;
  int		nb_lines;
  int		square_size;
  int		square_x;
  int		square_y;
}			t_file;

#endif		/* !__HEADER_H__ */
