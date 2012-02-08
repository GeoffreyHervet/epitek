/*
** list_sort.c for my_ls in /home/hervet_g//work/projets/my_ls
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Dec 18 11:09:23 2010 geoffrey hervet
** Last update Sat Dec 18 15:05:54 2010 geoffrey hervet
*/

#include		<stdlib.h>

#include		"my_ls.h"
#include		"is_flag.h"
#include		"list_sort.h"

static t_list_file	*sort_by_time(t_list_file *item)
{
  static t_list_file	*new_list = NULL;
  t_list_file		*tmp;

  if (!item)
    return (new_list);
  tmp = new_list;
  if (!tmp || item->st_mtime < tmp->st_mtime)
    {
      item->next = tmp;
      new_list = item;
      return (NULL);
    }
  while (tmp)
    {
      if ((!tmp->next) || (item->st_mtime <= tmp->st_mtime))
	{
	  item->next = tmp->next;
	  tmp->next = item;
	  return (NULL);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

static t_list_file	*reverse_list(t_list_file *begin)
{
  return (begin);
}

int			list_sort(t_infos *infos)
{
  t_list_file		*(*func)(t_list_file *);
  t_list_file		*tmp;

  if (is_flag(infos->flags, 't'))
    func = sort_by_time;
  tmp = infos->begin_path_scan->begin_file_to_print;
  while (tmp)
    {
      func(tmp);
      tmp = tmp->next;
    }
  infos->begin_path_scan->begin_file_to_print = sort_by_time(NULL);
  if (is_flag(infos->flags, 'r'))
    infos->begin_path_scan->begin_file_to_print =
      reverse_list(infos->begin_path_scan->begin_file_to_print);
  return (0);
}
