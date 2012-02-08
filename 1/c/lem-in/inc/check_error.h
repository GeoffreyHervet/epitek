/*
** check_error.h for inc in /afs/epitech.net/users/epitech_2015/hervet_g/public/lemin/inc
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Apr 11 20:10:40 2011 geoffrey hervet
** Last update Sat Apr 23 18:19:51 2011 quentin rufin
*/

#ifndef   __CHECK_ERROR_H__
# define  __CHECK_ERROR_H__

typedef struct
{
  int		type;
  int		(*f)();
}		t_func;

int	check_fourm(const char *str);
int	check_room(const char *str);
int	check_error(const t_line *line);

#endif     /* !__CHECK_ERROR_H__ */
