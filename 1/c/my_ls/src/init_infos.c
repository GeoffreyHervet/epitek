/*
** init_infos.c for my_ls in /home/hervet_g//work/projets/my_ls
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Dec 17 09:12:01 2010 geoffrey hervet
** Last update Fri Dec 17 11:57:51 2010 geoffrey hervet
*/

#include	<stdio.h>

#include	<stdlib.h>

#include	"my_ls.h"
#include	"init_infos.h"
#include	"table_flag.h"
#include	"libmy.h"

static int		get_flag(t_infos *infos, char *arg)
{
  int			idx;
  unsigned int		val_flag;
  int			idx_flag;

  idx = 0;
  while (arg[++idx])
    {
      val_flag = 0;
      idx_flag = 0;
      while ((good_flags[idx_flag] != arg[idx]) && good_flags[idx_flag])
	++idx_flag;
      if (!good_flags[idx_flag++])
	{
	  my_putstr(infos->exec_name, 2);
	  my_putstr(": invalid option -- '", 2);
	  my_putchar(arg[idx], 2);
	  my_putstr("'\n", 2);
	  exit(1);
	}
      val_flag = 1 << idx_flag;
      if (!(infos->flags & val_flag))
	infos->flags |= val_flag;
    }
  return (0);
}

static int		run_arg(t_infos *infos, char *arg)
{
  static t_list_path	*tmp = NULL;

  if (arg[0] == '-')
    return (get_flag(infos, arg));
  if (!tmp)
    {
      if ((tmp = malloc(sizeof(*tmp))) == NULL)
	return (-1);
      infos->begin_path_scan = tmp;
    }
  else
    {
      if ((tmp->next = malloc(sizeof(*(tmp->next)))) == NULL)
	return (-1);
      tmp = tmp->next;
    }
  tmp->next = NULL;
  tmp->name = arg;
  tmp->have_free = 0;
  return (0);
}

int			init_infos(t_infos *infos, int ac, char **av)
{
  int			idx;

  idx = 0;
  infos->flags = 0;
  infos->begin_path_scan = NULL;
  while (++idx < ac)
    {
      if (run_arg(infos, av[idx]) == -1)
	return (-1);
    }
  if (!infos->begin_path_scan)
    {
      infos->begin_path_scan = malloc(sizeof(*(infos->begin_path_scan)));
      if (!infos->begin_path_scan)
	return (-1);
      infos->begin_path_scan->next = NULL;
      infos->begin_path_scan->name = ".";
      infos->begin_path_scan->have_free = 0;
    }
  return (0);
}
