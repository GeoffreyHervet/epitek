/*
** path_gestion.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Wed Dec 29 10:24:09 2010 geoffrey hervet
** Last update Fri Dec 31 10:57:51 2010 geoffrey hervet
*/

#include		<sys/types.h>
#include		<unistd.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"libmy.h"
#include		"env/path_gestion.h"
#include		"errors.h"

static char		*get_link(char *cmd,
				 char *link)
{
  static int		error = -1;

  if (link == NULL)
    {
      my_putstr(cmd, 2);
      critical_error(error, X_OK, 0, ERR_EXEC);
      critical_error(error, -1, 0, ERR_CMDNOTFND);
      return (NULL);
    }
  if (access(link, F_OK) == -1)
    {
      free(link);
      return (NULL);
    }
  if (access(link, X_OK) == -1)
    {
      error = X_OK;
      free(link);
      return (NULL);
    }
  return (link);
}

char			*exec_path(char *path,
				   char *exec_name)
{
  char			**path_splited;
  char			*link;
  char			*tmp;
  unsigned int		idx;

  if (exec_name[0] == '/')
    return (exec_name);
  if ((path_splited = my_explode(':', path)) == NULL)
    {
      critical_error(1, 1, 0, ERR_PATH);
      return (NULL);
    }
  idx = 0;
  tmp = my_strcat("/", exec_name);
  while (path_splited[idx] != NULL)
    {
      if ((link = get_link(NULL, my_strcat(path_splited[idx++], tmp))) != NULL)
	{
	  free(tmp);
	  my_free_wordtab(path_splited);
	  return (link);
	}
    }
  my_free_wordtab(path_splited);
  return (get_link(exec_name, NULL));
}
