/*
** env.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sun Jan  2 16:47:52 2011 geoffrey hervet
** Last update Wed Jan  5 15:15:41 2011 geoffrey hervet
*/

#include		<sys/types.h>

#include		<stdlib.h>

#include		"my_sh.h"
#include		"errors.h"
#include		"libmy.h"
#include		"builtins/builtins_all.h"
#include		"builtins/cd_strcat_pwd.h"
#include		"env/set_env.h"
#include		"env/get_env.h"

int			_env(t_base *base)
{
  t_env			*item;

  item = base->env;
  while (item != NULL)
    {
      my_putstr(item->name, 1);
      my_putchar('=', 1);
      if (item->val != NULL)
	my_putstr(item->val, 1);
      my_putchar('\n', 1);
      item = item->next;
    }
  return (0);
}

