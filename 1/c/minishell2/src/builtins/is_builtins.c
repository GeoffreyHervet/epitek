/*
** is_builtins.c for my_sh in /home/hervet_g//work/projets/minishel
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Mon Dec 20 13:17:05 2010 geoffrey hervet
** Last update Fri Dec 31 10:59:23 2010 geoffrey hervet
*/

#include	<sys/types.h>

#include	<stdlib.h>

#include	"my_sh.h"
#include	"libmy.h"
#include	"builtins/is_builtins.h"
#include	"builtins/builtins_all.h"
#include	"builtins/builtins_list.h"

int		is_builtins(char *str)
{
  unsigned int	idx;

  idx = 0;
  while (builtins_all[idx].name)
    {
      if (!my_strcmp(builtins_all[idx].name, str))
	return (1);
      ++idx;
    }
  return (0);
}
