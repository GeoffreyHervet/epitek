/*
** main.c for  in /home/yau_t//local/Projets/semestre_2/42sh
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Mar 28 17:13:13 2011 tom-brent yau
** Last update Sun May 22 21:43:18 2011 tom-brent yau
*/

#include	<signal.h>
#include	<string.h>

#include	"sh.h"

#include	"termcp.h"
#include	"builtins.h"
#include	"history.h"
#include	"utils.h"
#include	"show_prompt.h"
#include	"syntax_correction.h"
#include	"my_handler.h"

#include	"xsignal.h"

extern char	**environ;

t_termcp	t;
t_inf		infos;

static void	free_all(t_inf *infos)
{
  free_env(*(infos->env));
  free_aliases(&(infos->aliases));
  free_hist(infos->history);
  free_ll_syntax_correction(infos->list_correc);
}

static void	init_info(t_inf *infos, t_env **my_env)
{
  memset(infos, 0, sizeof(*infos));
  *my_env = cpy_env(environ);
  infos->env = my_env;
  infos->history = creat_history();
  infos->list_correc = get_ll_syntax_correction(infos->env);
}

int	main(void)
{
  t_env		*my_env;

  t.buffer[0] = '\0';
  init_termcp(&t, environ);
  init_info(&infos, &my_env);
  xsignal(SIGINT, &my_handler);
  xsignal(SIGTSTP, &my_handler);
  xsignal(SIGWINCH, &gere_window);
  show_prompt(&infos, &t);
  free_all(&infos);
  return (infos.ret);
}
