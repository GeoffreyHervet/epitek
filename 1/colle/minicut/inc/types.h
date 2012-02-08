/*
** types.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 19:17:15 2011 geoffrey hervet
** Last update Tue May 17 19:17:15 2011 geoffrey hervet
*/

#ifndef   TYPES_H_
# define  TYPES_H_

# define  IS_DIGIT(x)	((x) >= '0' && (x) <= '9')

# define  WRONG_FORMAT	"Wrong format..."

typedef struct		s_opt_c
{
  int			delim[2];
  struct s_opt_c	*next;
}			t_opt_c;

typedef struct		s_opt_f
{
  int			delim[2];
  struct s_opt_f	*next;
}			t_opt_f;


typedef struct
{
  t_opt_c		*opt_c;
  t_opt_f		*opt_f;
}			t_infos;

#endif     /* !TYPES_H_ */
