/*
** dir_list.c for my_ls in /home/hervet_g//work/projets/my_ls
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Dec 17 10:40:31 2010 geoffrey hervet
** Last update Sat Dec 18 15:12:01 2010 geoffrey hervet
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<dirent.h>
#include	<stdio.h>
#include	<errno.h>
#include	<stdlib.h>

#include	<libmy.h>

#include	"my_ls.h"
#include	"dir_list.h"
#include	"is_flag.h"
#include	"dir_gestion.h"
#include	"list_sort.h"

static int	have_to_save(char *file, t_infos *infos)
{
  if (!is_flag(infos->flags, 'R'))
    return (0);
  if (file[0] == '.' && !is_flag(infos->flags, 'a'))
    return (0);
  if (file[0] == '.' && !file[1])
    return (0);
  if (file[0] == '.' && file[1] == '.' && !file[2])
    return (0);
  return (1);
}

static int	dir_read(t_infos *infos, DIR *directory)
{
  struct dirent	*file;

  while ((file = readdir(directory)))
    {
      if (have_to_save(file->d_name, infos))
	if (save_path(infos,
		      get_path(infos->begin_path_scan->name, file->d_name),
		      1)
	    == -1)
	  return (-1);
      if (do_inlist(infos, file->d_name) == -1)
	return (-1);
    }
  return (0);
}

int		dir_list(t_infos *infos)
{
  DIR		*directory;

  infos->begin_path_scan->begin_file_to_print = NULL;
  if ((directory = opendir(infos->begin_path_scan->name)) == NULL ||
      is_flag(infos->flags, 'd'))
    {
      if (!is_flag(infos->flags, 'd') && open_direrror(infos, errno) == -1)
	return (-1);
      if (errno == ENOTDIR || is_flag(infos->flags, 'd'))
	if (do_inlist(infos, infos->begin_path_scan->name) == -1)
	  return (-1);
    }
  else if (dir_read(infos, directory) == -1)
    return (-1);
  closedir(directory);
  list_sort(infos);
  return (-1);
}
