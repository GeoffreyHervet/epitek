/*
** show_prompt.h for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr 27 18:00:52 2011 tom-brent yau
** Last update Wed Apr 27 18:03:57 2011 tom-brent yau
*/

#ifndef		SHOW_MESSAGE_H_
# define	SHOW_MESSAGE_H_

typedef struct	s_sig_rec
{
  int	signum;
  char	*msg;
}		t_sig_rec;

void	show_message(int);

#endif	/* SHOW_MESSAGE_H_ */
