/*
** check_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri May  6 17:13:51 2011 tom-brent yau
** Last update Sun May 22 19:56:24 2011 tom-brent yau
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>

#include	"sh.h"

#include	"builtins.h"
#include	"syntax_correction.h"
#include	"utils.h"

int	check_cmd(t_tree *cmd, t_inf *infos, char *path)
{
  struct stat	s;

  if (cmd == NULL)
    return (FALSE);
  if ((int)strlen(cmd->info.str) > 256)
    {
      fprintf(stderr, "%s : File name too long\n", cmd->info.str);
      return (FALSE);
    }
  memset(path, 0, SIZE + 1);
  check_syntax_correction(cmd, infos->list_correc);
  if (if_builtin(cmd) == FALSE &&
      find_path(infos->env, path, &(cmd->info.str)) == FALSE)
    {
      fprintf(stderr, "%s: Command not found\n", cmd->info.str);
      return (FALSE);
    }
  if (path[0] && (access(path, X_OK | F_OK) == -1 ||
		  (!stat(path, &s) && !S_ISREG(s.st_mode))))
    {
      fprintf(stderr, "%s: Permission Denied\n", cmd->info.str);
      return (FALSE);
    }
  return (TRUE);
}
