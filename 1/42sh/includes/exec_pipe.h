/*
** exec_pipe.h for  in /home/yau_t//local/Projets/semestre_2/42sh/includes
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Apr 16 23:24:52 2011 tom-brent yau
** Last update Sat May 14 19:06:42 2011 tom-brent yau
*/

#ifndef		EXEC_PIPE_H_
# define	EXEC_PIPE_H_

typedef struct		s_wait_list
{
  pid_t			pid;
  char			*name;
  struct s_wait_list	*next;
}			t_wait_list;

typedef struct		s_close_list
{
  int			fd;
  struct s_close_list	*next;
  struct s_close_list	*prev;
}			t_close_list;

typedef struct		s_pipe
{
  int			in;
  int			out;
  t_wait_list		*wait_ll;
  t_close_list		*close_ll;
}			t_pipe;

int	exec_no_fork(t_tree *, t_inf *, char *, t_pipe *);
int	exec_pipe(t_tree *, t_inf *);
void	put_in_list(t_wait_list **, pid_t);
void	close_in_list(t_close_list **, int);
void	close_all_opened_fd(t_close_list *);
void	rm_in_list(t_close_list **, int);
int	wait_all(t_wait_list *);

#endif	/* !EXEC_PIPE_H_ */
