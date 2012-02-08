/*
** launcher.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec 27 14:02:34 2010 geoffrey hervet
** Last update Wed Jan  5 13:47:49 2011 geoffrey hervet
*/

#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/wait.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"libmy.h"
#include		"cmd/launcher.h"
#include		"env/get_env.h"
#include		"env/set_env.h"
#include		"env/path_gestion.h"
#include		"errors.h"

static unsigned int	nb_list_item(void *begin,
				     int type)
{
  t_cmd_split		*tmp_cmd;
  t_env			*tmp_env;
  unsigned int		nb;

  nb = 0;
  tmp_cmd = begin;
  tmp_env = begin;
  while ((type && tmp_cmd != NULL) || (!type && tmp_env != NULL))
    {
      ++nb;
      if (type)
	tmp_cmd = tmp_cmd->next;
      else
	tmp_env = tmp_env->next;
    }
  return (nb);
}

static char		**av_to_wordtab(t_cmd_split *begin,
					const unsigned int nb)
{
  char			**tab;
  unsigned int		idx;
  t_cmd_split		*tmp;

  if ((tab = malloc(sizeof(*tab) * (1 + nb))) == NULL)
    critical_error(1, 1, 1, ERR_MALLOC);
  idx = 0;
  tmp = begin;
  while (idx < nb)
    {
      tab[idx++] = my_strdup(tmp->data);
      tmp = tmp->next;
    }
  tab[idx] = NULL;
  return (tab);
}

static char		**env_to_wordtab(t_env *begin,
					const unsigned int nb)
{
  char			**tab;
  unsigned int		idx;
  t_env			*tmp;
  char			*tmp2;

  if ((tab = malloc(sizeof(*tab) * (1 + nb))) == NULL)
    critical_error(1, 1, 1, ERR_MALLOC);
  idx = 0;
  tmp = begin;
  while (idx < nb)
    {
      tmp2 = my_strcat(tmp->name, "=");
      tab[idx++] = my_strcat(tmp2, tmp->val);
      free(tmp2);
      tmp = tmp->next;
    }
  tab[idx] = NULL;
  return (tab);
}

static int		exec_prog(t_base *base,
				  char *link)
{
  char			**argv;
  char			**env;
  int			statut;

  argv = av_to_wordtab(base->cmd_splited, nb_list_item(base->cmd_splited, 1));
  env = env_to_wordtab(base->env, nb_list_item(base->env, 0));
  critical_error((base->child = fork()), -1, 1, ERR_FORK);
  if (base->child == 0)
    critical_error(execve(link, argv, env), -1, 1, ERR_EXECVE);
  else
    waitpid(base->child, &statut, WUNTRACED);
  base->child = 0;
  my_free_wordtab(argv);
  my_free_wordtab(env);
  return (0);
}

int			launcher(t_base *base)
{
  t_env			*path;
  char			*to_exec;

  path = get_env(base->env, "PATH");
  if (path == NULL)
    {
      path = set_env("PATH", DEF_PATH, FREE_NOTH);
      base->env = set_env(NULL, NULL, FREE_NOTH);
    }
  if (base->cmd_splited->data[0] == '.' || base->cmd_splited->data[0] == '/')
    to_exec = my_strdup(base->cmd_splited->data);
  else if ((to_exec = exec_path(path->val, base->cmd_splited->data)) == NULL)
    to_exec = my_strdup(base->cmd_splited->data);
  if (access(to_exec, F_OK) == -1)
    {
      if (CMD[0] == '.' || CMD[0] == '/')
	{
	  ERR critical_error(1, 1, 0, ERR_CMDNOTFND);
	}
      free(to_exec);
      return (-1);
    }
  exec_prog(base, to_exec);
  free(to_exec);
  return (0);
}
