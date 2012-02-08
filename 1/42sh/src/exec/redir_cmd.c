/*
** redir_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat May 14 15:14:07 2011 tom-brent yau
** Last update Sat May 14 15:25:59 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"sh.h"

#include	"exec_pipe.h"
#include	"exec_redir.h"
#include	"wait_and_ret.h"

#include	"xfork.h"

int	redir_cmd(t_tree *cmd, t_inf *infos, t_pipe *s_pipe, char *path)
{
  pid_t		pid;

  close_in_list(&(s_pipe->close_ll), s_pipe->in);
  close_in_list(&(s_pipe->close_ll), s_pipe->out);
  if ((pid = xfork()) == -1)
    return (FALSE);
  if (pid == 0)
    {
      exec_no_fork(cmd, infos, path, s_pipe);
    }
  close_all_opened_fd(s_pipe->close_ll);
  return (wait_and_ret());
}
