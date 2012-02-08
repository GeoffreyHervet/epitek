/*
** types.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  lun. avril 11 10:12:38 2011 geoffrey hervet
** Last update Wed Apr 13 11:58:23 2011 tom-brent yau
*/

#ifndef __TYPES_H__
# define __TYPES_H__

# define T_FOURM	(1)
# define T_ROOM		(2)
# define T_END		(T_ROOM | 4)
# define T_START	(T_ROOM | 8)
# define T_TUBE		(16)

# define M_ST		"##start"
# define M_END		"##end"

# define ERR_MALLOC	"Error malloc ...\n"
# define ERR_COOR	"Please check coords ...\n"

# define ERR_START	"Error, no start ...\n"
# define ERR_END	"Error, no end ...\n"
# define ERR_COMM	"Error comments not recognized ...\n"
# define ERR_LINE	"Error, line not recognized ...\n"
# define ERR_FOUR	"Error, the number of ants is wrong.\n"
# define ERR_ROOM	"Error, the name of room mustn't have special chars ...\n"
# define ERR_TUBE	\
"Error, syntax of tube is \"room1-room2\" whith valdid rooms' name...\n"

# define IS_INT(x)	((char)(x) >= '0' && (char)(x) <= '9')

typedef struct		s_line
{
  int			type;
  char			*strline;
}			t_line;

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

typedef struct
{
  int		  	id;
  int			coo[2];
  char			*name;
}			t_room;

typedef struct		s_way
{
  int			if_ant;
  int			ant_id;
  t_room		*room;
  struct s_way		*next;
  struct s_way		*prev;
}			t_way;

typedef struct		s_ways
{
  int			nb_room;
  int			to_send;
  t_way			*start;
  struct s_ways		*next;
}			t_ways;

typedef struct
{
  int			**tab;
  int			size;
  t_room		**corresp;
}			t_matrice;

typedef struct
{
  int			nb_fourm;
  int			nb_ways;
  t_list		*rooms;   /*list + void* */
  t_room		*start;
  t_room		*end;
  t_ways		*ways;    /* liste ! */
  t_matrice		*matrice;
}			t_infos;

#endif /* !__TYPES_H__ */
