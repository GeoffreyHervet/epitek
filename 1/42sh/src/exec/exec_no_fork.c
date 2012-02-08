/*
** exec_redir_cmd.c for  in /home/rufin_q/projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Fri May 13 15:03:22 2011 quentin rufin
** Last update Sat May 14 13:34:25 2011 tom-brent yau
*/

#include	<stdlib.h>

#include	"sh.h"

#include	"exec_cmd.h"
#include	"builtins.h"
#include	"utils.h"
#include	"exec_pipe.h"
#include	"exec_redir.h"
#include	"check_cmd.h"

#include	"xdup2.h"
#include	"xexecve.h"

int	exec_no_fork(t_tree *cmd, t_inf *infos, char *path, t_pipe *s_pipe)
{
  if (xdup2(s_pipe->out, 1) == -1)
    exit(EXIT_FAILURE);
  if (xdup2(s_pipe->in, 0) == -1)
    exit(EXIT_FAILURE);
  close_all_opened_fd(s_pipe->close_ll);
  if (path[0] == 0)
    {
      if (exec_builtin(cmd, infos) == TRUE)
	exit(EXIT_SUCCESS);
    }
  else
    xexecve(path, get_tab_arg(cmd), creat_env(*(infos->env)));
  exit(EXIT_FAILURE);
}
