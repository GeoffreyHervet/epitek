/*
** main.c for src in /afs/epitech.net/users/epitech_2015/hervet_g/public/ok/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Tue May 17 19:18:45 2011 geoffrey hervet
** Last update Tue May 17 19:18:45 2011 geoffrey hervet
*/

#include	<stdlib.h>

#include	"types.h"

#include	"my_strlen.h"
#include	"apply_optionsdf.h"
#include	"sort_opt_c.h"
#include	"sort_opt_f.h"
#include	"gnl.h"
#include	"apply_options.h"
#include	"my_strcmp.h"
#include	"my_putstr.h"
#include	"parse_opt_c.h"
#include	"parse_opt_f.h"

static char	*get_option(int ac, char **av, const char *opt)
{
  int		idx;

  idx = 1;
  while (idx < ac)
  {
    if (!my_strcmp(opt, av[idx++]))
      return ((idx < ac) ? av[idx] : NULL);
  }
  return (NULL);
}

static int	option_c_only(char *tmp)
{
  t_infos	infos;
  t_opt_c	*tmp2;

  infos.opt_c = (tmp != NULL) ? parse_opt_c(tmp) : NULL;
  if (sort_opt_c(infos.opt_c))
    return (EXIT_FAILURE);
  while ((tmp = gnl(0)) != NULL)
  {
    apply_options(&infos, tmp);
    my_putstr(tmp, 1);
    my_putstr("\n", 1);
    free(tmp);
  }
  while (infos.opt_c != NULL)
  {
    tmp2 = infos.opt_c;
    free(tmp2);
    infos.opt_c = infos.opt_c->next;
  }
  return (EXIT_SUCCESS);
}

int		option_df(char *d, char *tmp)
{
  t_infos	infos;
  t_opt_f	*tmp2;

  infos.opt_f = (tmp != NULL) ? parse_opt_f(tmp) : NULL;
  if (sort_opt_f(infos.opt_f))
    return (EXIT_FAILURE);
  while ((tmp = gnl(0)) != NULL)
  {
    apply_optionsdf(&infos, tmp, *d);
    my_putstr(tmp, 1);
    my_putstr("\n", 1);
    free(tmp);
  }
  while (infos.opt_f != NULL)
  {
    tmp2 = infos.opt_f;
    free(tmp2);
    infos.opt_f = infos.opt_f->next;
  }
  return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
  char		*opt_c;
  char		*opt_d;
  char		*opt_f;

  opt_c = get_option(ac, av, "-c");
  opt_d = get_option(ac, av, "-d");
  opt_f = get_option(ac, av, "-f");
  if (my_strlen(opt_d) > 1)
    return (EXIT_FAILURE);
  if (opt_c != NULL &&
      opt_f == NULL &&
      opt_d == NULL)
    return (option_c_only(opt_c));
  if (opt_f != NULL &&
      opt_d != NULL &&
      opt_c == NULL)
    return (option_df(opt_d, opt_f));
  return (EXIT_FAILURE);
}
