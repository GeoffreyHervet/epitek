/*
** exec_and_or.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Apr 16 20:25:11 2011 tom-brent yau
** Last update Fri May 13 20:24:02 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"sh.h"

#include	"exec_pipe.h"

int	exec_and_or(t_tree *cmd, t_inf *infos)
{
  int	ret;

  ret = FALSE;
  if (cmd->info.type == OPE_AND || cmd->info.type == OPE_OR)
    {
      if (cmd->left)
	ret = exec_and_or(cmd->left, infos);
      if (cmd->right && ((cmd->info.type == OPE_OR && ret != TRUE) ||
			 (cmd->info.type == OPE_AND && ret == TRUE)))
	ret = exec_and_or(cmd->right, infos);
    }
  else
    ret = exec_pipe(cmd, infos);
  return (ret);
}
