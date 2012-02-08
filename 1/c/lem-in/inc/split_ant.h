/*
** split_ant.h for  in /home/yau_t//local/Projets/semestre_2/lem-in/inc
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Apr 15 12:36:36 2011 tom-brent yau
** Last update Thu Apr 21 17:47:25 2011 quentin rufin
*/

#ifndef __SPLIT_ANT_H__
# define __SPLIT_ANT_H__

typedef struct			s_list_to_print
{
  int				ant_id;
  char				*name;
  struct s_list_to_print	*next;
}				t_list_to_print;

void	split_ant(t_infos *);

#endif /* !__SPLIT_ANT_H__ */
