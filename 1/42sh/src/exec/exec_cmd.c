/*
** exec_command.c for  in /home/rufin_q/projet/42sh/42sh/src/exec
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sat Apr 16 14:56:56 2011 quentin rufin
** Last update Fri May 13 23:49:47 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"sh.h"

#include	"builtins.h"
#include	"check_cmd.h"
#include	"utils.h"
#include	"wait_and_ret.h"

#include	"xfork.h"
#include	"xexecve.h"

static int	exec_bin(char *path, t_tree *cmd, t_env **env)
{
  pid_t		pid;

  if ((pid = xfork()) == -1)
    return (FALSE);
  if (pid == 0)
    {
      xexecve(path, get_tab_arg(cmd), creat_env(*env));
    }
  return (wait_and_ret());
}

int	exec_cmd(t_tree *cmd, t_inf *infos)
{
  char		path[SIZE + 1];
  int		ret;

  ret = FALSE;
  if (check_cmd(cmd, infos, path) == FALSE)
    return (ret);
  if (path[0] == 0)
    ret = exec_builtin(cmd, infos);
  else
    {
      ret = exec_bin(path, cmd, infos->env);
    }
  infos->ret = ret;
  return (ret);
}
