/*
** termcmd.h for  in /home/yau_t//local/Projets/semestre_2/42sh/src/term-caps
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May 20 11:59:53 2011 tom-brent yau
** Last update Sun May 22 21:48:33 2011 tom-brent yau
*/

#ifndef		TERMCP_H_
# define	TERMCP_H_

# define	SIZE_PROMPT	3

# define	CTRL_A	1
# define	CTRL_C	3
# define	CTRL_D	4
# define	CTRL_E	5
# define	CTRL_K	11
# define	CTRL_L	12
# define	CTRL_T	20
# define	CTRL_U	21
# define	CTRL_W	23
# define	CTRL_Y	25

typedef struct	s_termcp
{
  int		size;
  int		idx;
  int		width;
  char		*term;
  char		tmp_buff[SIZE + 1];
  t_history	*hist;
  char		buffer[SIZE + 1];
  char		*cmd;
}		t_termcp;

typedef struct	s_ctrl
{
  char		key;
  void		(*ptr)(t_inf *, t_termcp *, char *);
}		t_ctrl;

typedef struct	s_tab
{
  char		*keys;
  void		(*ptr)(t_inf *, t_termcp *, char *);
}		t_tab;

void	classic_mode(void);
void	raw_mode(void);
char	*my_get_env(char **, char *);
int	read_keys(t_termcp *, char *, t_inf *);
int	pars_keys(t_termcp *, char *, char *, t_inf *);
void	del_key(t_inf *, t_termcp *, char *);
void	back_key(t_inf *, t_termcp *, char *);
void	move_cursor_left(t_inf *, t_termcp *, char *);
void	move_cursor_right(t_inf *, t_termcp *, char *);
int	go(int);
void	move_cursor_home(t_inf *, t_termcp *, char *);
void	move_cursor_end(t_inf *, t_termcp *, char *);
int	update_result(t_termcp *, char *, char);
void	gere_window(int);
void	init_termcp(t_termcp *, char **);
void	remove_key_from_str(char *, int *, int);
void	go_to_idx(t_termcp *, char *, int, t_inf *);
void	refresh_prompt(t_inf *, t_termcp *, char *);
void	replace_with_spaces(t_inf *, t_termcp *, char *);
int	is_printable(char *);
void	gere_cut(t_inf *, t_termcp *, char *, char *);
void	up_history(t_inf *, t_termcp *, char *);
void	down_history(t_inf *, t_termcp *, char *);
void    gere_ctrl_t(t_inf *, t_termcp *, char *);
void    gere_ctrl_l(t_inf *, t_termcp *, char *);
void    gere_ctrl_k(t_inf *, t_termcp *, char *);
void    gere_ctrl_y(t_inf *, t_termcp *, char *);
void    insert_char(t_termcp *, char *, char *, t_inf *);
void    gere_ctrl_w(t_inf *, t_termcp *, char *);
void    gere_ctrl_u(t_inf *, t_termcp *, char *);
void    gere_ctrl_c(t_inf *, t_termcp *, char *);
void    gere_ctrl_d(t_inf *, t_termcp *, char *);
void	complete_file(t_termcp *, char **, char *, int);
int	get_max_len(char **);
void	tab_key(t_inf *, t_termcp *, char *);
void	look_in_dir(t_inf *, t_termcp *, char *);
void	look_in_exec(t_inf *, t_termcp *, t_list_correc *, char *);
void	aff_list(t_inf *, t_termcp *, char **, char *);
int	get_win_col(void);

#endif	/* !TERMCP_H_ */
