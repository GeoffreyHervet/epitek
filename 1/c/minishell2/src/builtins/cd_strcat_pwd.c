/*
** cd_strcat_pwd.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Dec 23 10:57:10 2010 geoffrey hervet
** Last update Sun Jan  2 12:37:24 2011 geoffrey hervet
*/

#include		<sys/types.h>
#include		<unistd.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"libmy.h"
#include		"errors.h"
#include		"builtins/cd_strcat_pwd.h"

char		*tilde_gestion(const char *home,
			       const char *str)
{
  char		*ret;
  unsigned int	idx;
  unsigned int	idx2;

  idx = 0;
  idx2 = 1;
  ret = malloc(sizeof(*ret) * (my_strlen(home) + my_strlen(str) + 2));
  if (ret == NULL)
    critical_error(1, 1, 1, ERR_MALLOC);
  while (home[idx])
    {
      ret[idx] = home[idx];
      ++idx;
    }
  if (str[idx] != '/')
    ret[idx++] = '/';
  while (str[idx2])
    ret[idx++] = str[idx2++];
  ret[idx] = '\0';
  return (ret);
}

int			xchdir(const char *path)
{
  if (!chdir(path))
    return (0);
  critical_error(1, 1, 0, ERR_CHDIR);
  return (-1);
}

static char		*add_stratpwd(char *ret,
				      const char *str,
				      unsigned int ret_str)
{
  unsigned int		idx;

  idx = 0;
  while (str[idx])
    {
      if ((!idx || str[idx - 1] == '/') &&
	  str[idx] == '.' && str[idx + 1] == '.' &&
	  (str[idx + 2] == '\0' || str[idx + 2] == '/'))
	{
	  while (ret_str &&  ret[ret_str] == '/')
	    --ret_str;
	  while (ret_str && ret[ret_str] != '/')
	    --ret_str;
	  idx += 3;
	}
      else
	ret[ret_str++] = str[idx++];
    }
  ret[ret_str++] = '/';
  ret[ret_str] = '\0';
  return (ret);
}

char			*strcat_pwd(const char *pwd,
				    const char *str)
{
  char			*ret;
  unsigned int		idx;

  ret = malloc(sizeof(*ret) * (my_strlen(pwd) + my_strlen(str) + 3));
  if (ret == NULL)
    critical_error(1, 1, 1, ERR_MALLOC);
  idx = 0;
  while (pwd && pwd[idx])
    {
      ret[idx] = pwd[idx];
      ++idx;
    }
  ret[idx] = '/';
  return (add_stratpwd(ret, str, idx));
}
