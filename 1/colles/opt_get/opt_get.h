/*
** opt_get.h for  in /u/all/hervet_g/public/opt_get
** 
** Made by tracy nelcha
** Login   <nelcha_t@epitech.net>
** 
** Started on  Mon May  9 19:28:03 2011 tracy nelcha
** Last update Mon May  9 22:27:33 2011 tracy nelcha
*/

#ifndef		OPT_GET_H_
# define	OPT_GET_H_


typedef int	t_bool;
typedef int	t_pos;

typedef struct	s_opt
{
  char		*name;
  char		*value;
  struct s_opt	*next;
}		t_opt;

t_opt		*opt_get(int ac,
			 char **av,
                         const char* format);

t_bool		opt_isset(t_opt *options,
			  const char *option);

t_pos		opt_pos(t_opt *options,
			const char *option);

const char **opt_args(t_opt *options,
		      const char *option);

#endif		/*!OPT_GET_H_*/
