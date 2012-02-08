/*
** parser.h for  in /home/yau_t//local/Projets/semestre_2/42sh/includes
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr  6 16:41:36 2011 tom-brent yau
** Last update Sun May 22 22:18:28 2011 silvain tuilliere
*/

#ifndef		HISTORY_H_
# define	HISTORY_H_

# define	LIMIT_HISTORY (1000)

t_history       *creat_history(void);
int		update_history(char *, t_history **);
void		add_elem_to_history(t_history **, t_history *);
int		display_history(t_history *);
void		free_hist(t_history *);
int		look_in_history(char *, int, t_history *);
int		history_modifiers(char *, int, int);
void		replace_cmd(char *, char *, const int, const int);

#endif	/* !HISTORY_H_ */
