/*
** exec_right_redir_for_pipe.c for  in /home/rufin_q//projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Thu May  5 13:57:02 2011 quentin rufin
** Last update Sat May 14 12:34:37 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#include	"sh.h"

#include	"exec_pipe.h"
#include	"exec_redir.h"
#include	"check_cmd.h"
#include	"utils.h"

#include	"xclose.h"
#include	"xfork.h"
#include	"xopen_mod.h"

int	exec_red_right_pipe(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  char		path[SIZE + 1];
  pid_t		pid;

  if (cmd == NULL || check_cmd(cmd->left, infos, path) == FALSE)
    return (FALSE);
  if ((s_pipe->out = xopen_mod(cmd->right->info.str, F_SINGLE, OP_MOD)) == -1)
    return (FALSE);
  if ((pid = xfork()) == -1)
    return (FALSE);
  if (pid == 0)
    {
      exec_no_fork(cmd->left, infos, path, s_pipe);
    }
  put_in_list(&(s_pipe->wait_ll), pid);
  xclose(s_pipe->out);
  return (TRUE);
}

int	exec_double_right_pipe(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  char		path[SIZE + 1];
  pid_t		pid;

  if (cmd == NULL || check_cmd(cmd->left, infos, path) == FALSE)
    return (FALSE);
  if ((s_pipe->out = xopen_mod(cmd->right->info.str, F_DOUBLE, OP_MOD)) == -1)
    return (FALSE);
  if ((pid = xfork()) == -1)
    return (FALSE);
  if (pid == 0)
    {
      exec_no_fork(cmd->left, infos, path, s_pipe);
    }
  put_in_list(&(s_pipe->wait_ll), pid);
  xclose(s_pipe->out);
  return (TRUE);
}

int	exec_all_right_red_pipe(t_tree *cmd, t_inf *infos,
				t_pipe *s_pipe)
{
  if (cmd->info.type == OPE_RED_RIGHT)
    {
      return (exec_red_right_pipe(cmd, infos, s_pipe));
    }
  else if (cmd->info.type == OPE_DOUBLE_RIGHT)
    {
      return (exec_double_right_pipe(cmd, infos, s_pipe));
    }
  return (FALSE);
}
