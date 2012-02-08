/*
** exec_pipe.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Apr 16 20:33:48 2011 tom-brent yau
** Last update Sun May 22 20:10:21 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

#include	"sh.h"

#include	"exec_pipe.h"
#include	"exec_redir.h"
#include	"check_cmd.h"
#include	"utils.h"

#include	"xpipe.h"
#include	"xfork.h"
#include	"xexecve.h"

static void	free_wait_ll(t_wait_list *list)
{
  t_wait_list		*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
}

static int	pipe_cmd(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  char		path[SIZE + 1];
  pid_t		pid;

  if (cmd->info.type == OPE_RED_LEFT || cmd->info.type == OPE_DOUBLE_LEFT)
    return (exec_all_left_red_pipe(cmd, infos, s_pipe));
  memset(path, 0, SIZE + 1);
  if (check_cmd(cmd, infos, path) == FALSE)
    return (FALSE);
  if ((pid = xfork()) == -1)
    return (FALSE);
  if (pid == 0)
    {
      exec_no_fork(cmd, infos, path, s_pipe);
    }
  put_in_list(&(s_pipe->wait_ll), pid);
  return (TRUE);
}

static t_pipe	*fill_pipe(t_pipe *s_pipe, int fd_in, int fd_out)
{
  s_pipe->in = fd_in;
  s_pipe->out = fd_out;
  return (s_pipe);
}

static int	create_pipe(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  int		ret;
  int		fd[2];
  int		tmp_fd;

  tmp_fd = s_pipe->in;
  ret = FALSE;
  if (xpipe(fd) == -1)
    return (FALSE);
  close_in_list(&(s_pipe->close_ll), fd[0]);
  close_in_list(&(s_pipe->close_ll), fd[1]);
  if (cmd->right && cmd->right->info.type == OPE_PIPE)
    ret = create_pipe(cmd->right, infos, fill_pipe(s_pipe, fd[0], fd[1]));
  if (cmd->right && cmd->right->info.type == CMD)
    ret = pipe_cmd(cmd->right, infos, fill_pipe(s_pipe, fd[0], 1));
  else if (cmd->right && cmd->right->info.type != OPE_PIPE)
    ret = exec_all_right_red_pipe(cmd->right, infos,
				  fill_pipe(s_pipe, fd[0], 1));
  rm_in_list(&(s_pipe->close_ll), fd[0]);
  if (ret == TRUE && cmd->info.type == OPE_PIPE)
    ret = pipe_cmd(cmd->left, infos, fill_pipe(s_pipe, tmp_fd, fd[1]));
  rm_in_list(&(s_pipe->close_ll), fd[1]);
  return (ret);
}

int	exec_pipe(t_tree *cmd, t_inf *infos)
{
  int		ret;
  t_pipe	s_pipe;

  ret = FALSE;
  s_pipe.in = 0;
  s_pipe.out = 1;
  s_pipe.wait_ll = NULL;
  s_pipe.close_ll = NULL;
  if (cmd->info.type == OPE_PIPE)
    {
      ret = create_pipe(cmd, infos, &s_pipe);
      ret = wait_all(s_pipe.wait_ll);
      free_wait_ll(s_pipe.wait_ll);
      infos->ret = ret;
    }
  else
    ret = exec_redir(cmd, infos, &s_pipe);
  return (ret);
}
