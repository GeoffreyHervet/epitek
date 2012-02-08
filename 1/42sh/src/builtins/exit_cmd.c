/*
** exit_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/builtins
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon May  9 11:47:33 2011 tom-brent yau
** Last update Mon May  9 15:50:31 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"

int	exit_cmd(t_tree *cmd, t_inf *infos)
{
  infos->if_exit = 1;
  if (cmd)
    infos->ret = atoi(cmd->info.str);
  return (infos->ret);
}
