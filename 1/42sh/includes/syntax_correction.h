/*
** syntax_correction.h for j in /home/rufin_q/projet/42sh/42sh/src/exec
** 
0** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sun Apr 24 22:07:12 2011 quentin rufin
** Last update Wed Jun  8 16:04:08 2011 quentin rufin
*/

#ifndef SYNTAX_CORRECTION_H_
# define SYNTAX_CORRECTION_H_

void		check_syntax_correction(t_tree *cmd, t_list_correc *list);
t_list_correc	*get_ll_syntax_correction(t_env **env);
void		free_ll_syntax_correction(t_list_correc *ptr);
void		order_ll_syntax_correction(t_list_correc *ptr);

#endif	/* !SYNTAX_CORRECTION_H_ */
