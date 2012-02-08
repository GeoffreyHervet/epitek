/*
** builtins.h for  in /home/yau_t//local/Projets/semestre_2/42sh/includes
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun Apr 17 18:17:42 2011 tom-brent yau
** Last update Mon May  9 11:48:39 2011 tom-brent yau
*/

#ifndef		__BUILTINS_H__
# define	__BUILTINS_H__

typedef enum
  {
    ENV = 1,
    HISTORY,
    ALIASES,
    INFOS
  }	t_arg;

typedef struct	s_builtin
{
  char	*cmd;
  int	(*f)();
  t_arg	arg;
}		t_builtin;

int	exec_builtin(t_tree *, t_inf *);

int	cd_cmd(t_tree *, t_env **);
void	chg_pwd(t_env **);
int	env_cmd(t_tree *, t_env **);
int	echo_cmd(t_tree *, t_env **);
int	if_builtin(t_tree *);
int	setenv_cmd(t_tree *, t_env **);
int	unsetenv_cmd(t_tree *, t_env **);
int	alias_set(t_tree *, t_aliases **);
int	unalias(t_tree *, t_aliases **);
int	free_aliases(t_aliases **);
int	exit_cmd(t_tree *, t_inf *);

#endif
