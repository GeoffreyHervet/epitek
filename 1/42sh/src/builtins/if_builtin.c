/*
** if_builtin.c for if_builtin in /home/yau_t//local/Projets/semestre_2/minishell2/prompt
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Feb 10 11:49:49 2011 tom-brent yau
** Last update Thu May 12 15:31:00 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"sh.h"
#include	"builtins.h"
#include	"history.h"
#include	"syntax_correction.h"

const t_builtin	built[] = {
  {"cd",         cd_cmd,          ENV},
  {"setenv",     setenv_cmd,      ENV},
  {"unsetenv",   unsetenv_cmd,    ENV},
  {"env",        env_cmd,         ENV},
  {"echo",       echo_cmd,        ENV},
  {"alias",      alias_set,       ALIASES},
  {"unalias",    unalias,         ALIASES},
  {"history",    display_history, HISTORY},
  {"exit",       exit_cmd,        INFOS},
  {NULL,         NULL,            0}
};

static int	launch_builtin(int pos, t_tree *cmd, t_inf *infos)
{
  if (built[pos].arg == ENV)
    return ((built[pos].f)(cmd->right, infos->env));
  if (built[pos].arg == HISTORY)
    return ((built[pos].f)(infos->history));
  if (built[pos].arg == ALIASES)
    return ((built[pos].f)(cmd->right, &(infos->aliases)));
  return ((built[pos].f)(cmd->right, infos));
}

int	exec_builtin(t_tree *cmd, t_inf *infos)
{
  int	pos;
  int	ret;

  pos = 0;
  ret = FALSE;
  while (built[pos].cmd && strcmp(cmd->info.str, built[pos].cmd))
    pos++;
  if (built[pos].cmd)
    ret = launch_builtin(pos, cmd, infos);
  return (ret);
}

int	if_builtin(t_tree *cmd)
{
  int	pos;

  pos = 0;
  while (built[pos].cmd && strcmp(cmd->info.str, built[pos].cmd))
    pos++;
  if (built[pos].cmd)
    return (TRUE);
  return (FALSE);
}
