/*
** types.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/public/KHOL/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed May 04 19:50:32 2011 geoffrey hervet
** Last update Wed May 04 19:50:32 2011 geoffrey hervet
*/

#ifndef		TYPES_H_
# define	TYPES_H_

# define	DEFAULT_SIZE	(8)

# define	IS_DIGIT(x)	(((char)(x) >= '0') && ((char)(x) <= '9'))
# define	CAST_CHAR_S(x)	((char *)(x))

# define	USAGE		"./my_mixword -f FILE [-s SIZE]\n"
# define	ERR_OPEN	"Error : can't open the file\n"
# define	ERR_CLOSE	"Error : can't close fd associed to the file.\n"
# define	ERR_MALLOC	"Error : can't perform malloc ...\n"

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

typedef struct
{
  int		fd;
  char		*name;
  int		size;
  t_list	*begin;
}		t_infos;

#endif    /* !TYPES_H_ */
