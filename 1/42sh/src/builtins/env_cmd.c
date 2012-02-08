/*
** env_cmd.c for env_cmd in /home/yau_t//local/Projets/mysh
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sun Dec 19 19:58:42 2010 tom-brent yau
** Last update Mon May  9 12:38:04 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"utils.h"

int	env_cmd(__attribute__((unused)) t_tree *cmd, t_env **env)
{
  t_env	*tmp;

  tmp = *env;
  while (tmp)
    {
      print(tmp->var);
      print("\n");
      tmp = tmp->next;
    }
  return (TRUE);
}
