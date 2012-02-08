/*
** exec_left_redir_for_pipe.c for  in /home/rufin_q//projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Fri May  6 14:49:24 2011 quentin rufin
** Last update Sat May 14 21:06:49 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#include	"sh.h"

#include	"exec_pipe.h"
#include	"exec_redir.h"
#include	"check_cmd.h"
#include	"utils.h"

#include	"xdup2.h"
#include	"xclose.h"
#include	"xfork.h"
#include	"xopen.h"
#include	"xpipe.h"

static int	exec_double_left_pipe(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  t_buff	*list;
  char		path[SIZE + 1];
  int		fd[2];
  pid_t		pid;

  list = NULL;
  if (cmd->left->info.type == CMD &&
      check_cmd(cmd->left, infos, path) == FALSE)
    return (FALSE);
  put_in_buff(cmd->right->info.str, &list);
  if (xpipe(fd) == -1)
    return (FALSE);
  redir_on_exec(list, fd);
  s_pipe->in = fd[0];
  xclose(fd[1]);
  if ((pid = fork()) == -1)
    return (FALSE);
  if (pid == 0)
    exec_no_fork(cmd->left, infos, path, s_pipe);
  put_in_list(&(s_pipe->wait_ll), pid);
  xclose(s_pipe->in);
  return (TRUE);
}

static int	exec_red_left_pipe(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  char		path[SIZE + 1];
  pid_t		pid;

  if (check_cmd(cmd->left, infos, path) == FALSE)
    return (FALSE);
  if ((s_pipe->in = xopen(cmd->right->info.str, O_RDONLY)) == -1)
    return (FALSE);
  if ((pid = xfork()) == -1)
    return (FALSE);
  if (pid == 0)
    {
      exec_no_fork(cmd->left, infos, path, s_pipe);
    }
  put_in_list(&(s_pipe->wait_ll), pid);
  xclose(s_pipe->in);
  return (TRUE);
}

int	exec_all_left_red_pipe(t_tree *cmd, t_inf *infos,
			       t_pipe *s_pipe)
{
  if (cmd->left == NULL || cmd->right == NULL)
    return (FALSE);
  if (cmd->info.type == OPE_RED_LEFT)
    {
      return (exec_red_left_pipe(cmd, infos, s_pipe));
    }
  else if (cmd->info.type == OPE_DOUBLE_LEFT)
    {
      return (exec_double_left_pipe(cmd, infos, s_pipe));
    }
  return (FALSE);
}
