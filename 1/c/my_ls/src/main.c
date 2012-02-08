/*
** main.c for my_ls in /home/hervet_g//work/projets/my_ls
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Dec 17 08:52:42 2010 geoffrey hervet
** Last update Sat Dec 18 12:37:51 2010 geoffrey hervet
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	<libmy.h>

#include	"my_ls.h"
#include	"init_infos.h"
#include	"dir_list.h"

int		main(int ac, char **av)
{
  t_infos	infos;
  t_list_path	*path;

  infos.exec_name = av[0];
  if (init_infos(&infos, ac, av) == -1)
    {
      my_putstr(infos.exec_name, 2);
      my_putstr(": malloc error\n", 2);
      return (1);
    }
  while (infos.begin_path_scan)
    {
      if (dir_list(&infos) == -1)
	{
	  my_putstr(infos.exec_name, 2);
	  my_putstr(": critical error\n", 2);
	  return (1);
	}
      path = infos.begin_path_scan;
      infos.begin_path_scan = infos.begin_path_scan->next;
      if (path->have_free)
	free(path->name);
      free(path);
    }
  return (0);
}
