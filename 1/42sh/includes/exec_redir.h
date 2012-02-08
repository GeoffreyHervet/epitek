/*
** exec_redir.h for  in /home/yau_t//local/Projets/semestre_2/42sh/includes
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Apr 16 23:25:31 2011 tom-brent yau
** Last update Sat May 14 21:09:56 2011 tom-brent yau
*/

#ifndef		EXEC_REDIR_H_
# define	EXEC_REDIR_H_

# define	F_SINGLE	(O_CREAT | O_WRONLY | O_TRUNC)
# define	F_DOUBLE	(O_WRONLY | O_CREAT | O_APPEND)
# define	OP_MOD		(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

typedef struct	s_redir
{
  int		fd_in;
  int		fd_out;
}		t_redir;

typedef struct	s_redir_func
{
  int		type;
  int		(*ptr)(t_tree *, t_inf *, t_pipe *);
}		t_redir_func;

int	exec_red_right(t_tree *, t_inf *, t_pipe *);
int	exec_double_red_right(t_tree *, t_inf *, t_pipe *);
int	exec_red_left(t_tree *, t_inf *, t_pipe *);
int	exec_all_right_red_pipe(t_tree *, t_inf *, t_pipe *);
int	exec_redir(t_tree *, t_inf *, t_pipe *);
int	exec_double_red_left(t_tree *, t_inf *, t_pipe *);
void	put_in_buff(char *, t_buff **);
int	exec_all_left_red_pipe(t_tree *, t_inf *, t_pipe *);
int	exec_double_right_pipe(t_tree *, t_inf *, t_pipe *);
int	redir_cmd(t_tree *, t_inf *, t_pipe *, char *);
void	redir_on_exec(t_buff *, int [2]);

#endif	/* !EXEC_REDIR_H_ */
