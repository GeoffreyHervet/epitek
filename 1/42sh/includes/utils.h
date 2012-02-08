/*
** utils.h for  in /home/yau_t//local/Projets/semestre_2/42sh/includes
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun Apr 17 16:03:28 2011 tom-brent yau
** Last update Wed May 11 16:29:31 2011 tom-brent yau
*/

#ifndef		UTILS_H_
# define	UTILS_H_

t_env	*cpy_env(char **);
char	**creat_env(t_env *);
t_env	*find_env_var(t_env *, char *);
int	find_path(t_env **, char *, char **);
void	free_env(t_env *);
t_tree	*free_node_ret_leaf(t_tree *, t_tree *);
void	free_tree(t_tree *);
char	**get_tab_arg(t_tree *);
int     len_eq_c(char *, char *);
void	print(char *);
int	strclen(char *, char *);
int	my_getnbr(char *);
void	epur_str(char *, char *, char *);

#endif	/* !UTILS_H_ */
