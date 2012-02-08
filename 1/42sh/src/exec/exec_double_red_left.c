/*
** exec_double_red_left.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed May 11 12:00:09 2011 tom-brent yau
** Last update Sun May 22 20:31:00 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

#include	"sh.h"

#include	"check_cmd.h"
#include	"exec_pipe.h"
#include	"exec_redir.h"
#include	"utils.h"

#include	"xpipe.h"
#include	"xclose.h"
#include	"xwrite.h"

void	redir_on_exec(t_buff *list, int fd[2])
{
  t_buff	*tmp;

  tmp = list;
  while (tmp)
    {
      xwrite(fd[1], tmp->buff, strlen(tmp->buff));
      xwrite(fd[1], "\n", 1);
      tmp = tmp->next;
    }
  while (list)
    {
      tmp = list;
      list = list->next;
      free(tmp->buff);
      free(tmp);
    }
}

int	exec_double_red_left(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  t_buff	*list;
  char		path[SIZE + 1];
  int		fd[2];

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
  if (cmd->left->info.type == CMD)
    return (redir_cmd(cmd->left, infos, s_pipe, path));
  return (exec_all_right_red_pipe(cmd->left, infos, s_pipe));
}
