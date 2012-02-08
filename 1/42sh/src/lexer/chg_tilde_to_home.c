/*
** chg_tilde_to_home.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/lexer
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 12 12:09:18 2011 tom-brent yau
** Last update Thu May 12 12:32:26 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"sh.h"

#include	"utils.h"

void	chg_tilde_to_home(char *str, t_env *env)
{
  char	tmp[SIZE + 1];

  env = find_env_var(env, "HOME");
  memset(tmp, 0, SIZE + 1);
  if (env == NULL || env->var == NULL)
    {
      fprintf(stderr, "Couldn't find home directory\n");
      return ;
    }
  strncpy(tmp, str, SIZE);
  memset(str, 0, SIZE + 1);
  strncpy(str, env->var + 5, SIZE);
  strncat(str, tmp + 1, SIZE - strlen(str));
}
