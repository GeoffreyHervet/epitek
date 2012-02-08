/*
** exec_redir.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Apr 16 20:38:14 2011 tom-brent yau
** Last update Sat May 14 15:24:33 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>

#include	"sh.h"

#include	"exec_cmd.h"
#include	"utils.h"
#include	"exec_pipe.h"
#include	"exec_redir.h"
#include	"check_cmd.h"

#include	"xopen.h"
#include	"xopen_mod.h"

const t_redir_func	all_funcs[] = {
  {OPE_RED_RIGHT, &exec_red_right},
  {OPE_DOUBLE_RIGHT, &exec_double_red_right},
  {OPE_RED_LEFT, &exec_red_left},
  {OPE_DOUBLE_LEFT, &exec_double_red_left},
  {0, NULL}
};

int		exec_red_right(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  char		path[SIZE + 1];

  if (check_cmd(cmd->left, infos, path) == FALSE)
    return (FALSE);
  if ((s_pipe->out = xopen_mod(cmd->right->info.str, F_SINGLE, OP_MOD)) == -1)
    return (FALSE);
  return (redir_cmd(cmd->left, infos, s_pipe, path));
}

int		exec_double_red_right(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  char		path[SIZE + 1];

  if (check_cmd(cmd->left, infos, path) == FALSE)
    return (FALSE);
  if ((s_pipe->out = xopen_mod(cmd->right->info.str, F_DOUBLE, OP_MOD)) == -1)
    return (FALSE);
  return (redir_cmd(cmd->left, infos, s_pipe, path));
}

static t_tree	*special_case(t_tree *cmd, t_pipe *s_pipe, t_inf *infos,
			      char *path)
{
  if (cmd->left->info.type == CMD)
    return (cmd);
  cmd = cmd->left;
  if (check_cmd(cmd->left, infos, path) == FALSE)
      return (NULL);
  if (cmd->info.type == OPE_RED_RIGHT &&
      (s_pipe->out = xopen_mod(cmd->right->info.str, F_SINGLE, OP_MOD)) == -1)
    {
      return (NULL);
    }
  else if (cmd->info.type == OPE_DOUBLE_RIGHT &&
	   (s_pipe->out = xopen_mod(cmd->right->info.str,
				    F_DOUBLE, OP_MOD)) == -1)
    {
      return (NULL);
    }
  return (cmd);
}

int		exec_red_left(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  char		path[SIZE + 1];

  if (cmd->left->info.type != OPE_DOUBLE_RIGHT &&
      cmd->left->info.type != OPE_RED_RIGHT &&
      check_cmd(cmd->left, infos, path) == FALSE)
    return (FALSE);
  if ((s_pipe->in = xopen(cmd->right->info.str, O_RDONLY)) == -1)
    return (FALSE);
  if ((cmd = special_case(cmd, s_pipe, infos, path)) == NULL)
    return (FALSE);
  return (redir_cmd(cmd->left, infos, s_pipe, path));
}

int	exec_redir(t_tree *cmd, t_inf *infos, t_pipe *s_pipe)
{
  int		ret;
  int		count;

  count = 0;
  ret = FALSE;
  if (cmd->info.type == OPE_RED_RIGHT || cmd->info.type == OPE_DOUBLE_RIGHT ||
      cmd->info.type == OPE_RED_LEFT || cmd->info.type == OPE_DOUBLE_LEFT)
    {
      if (cmd->right == NULL || cmd->left == NULL)
	return (FALSE);
      while (cmd->info.type != all_funcs[count].type)
	count++;
      if (all_funcs[count].ptr != NULL)
	ret = all_funcs[count].ptr(cmd, infos, s_pipe);
    }
  else
    ret = exec_cmd(cmd, infos);
  return (ret);
}
