/*
** dir_list.c for my_ls in /home/hervet_g//work/projets/my_ls
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Dec 17 10:40:31 2010 geoffrey hervet
** Last update Sat Dec 18 14:03:29 2010 geoffrey hervet
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
#include	"dir_gestion.h"

int		open_direrror(t_infos *infos, int errnum)
{
  if (errnum == EACCES || errnum == ENFILE || errnum == ENOENT ||
      errnum == ENOMEM)
    {
      my_putstr(infos->exec_name, 2);
      my_putstr(": error on \"", 2);
      my_putstr(infos->begin_path_scan->name, 2);
      my_putstr("\" :", 2);
      if (errnum == EACCES)
	my_putstr("Permission denied\n", 2);
      if (errnum == ENFILE)
	my_putstr("Too many files are currently open in the stystem\n", 2);
      if (errnum == ENOENT)
	my_putstr("Directory doesn't exist\n", 2);
      if (errnum == ENOMEM)
	my_putstr("Insufficient memory to complete the operation\n", 2);
      if (errnum == EACCES || errnum == ENOENT)
	return (0);
      return (-1);
    }
  return (-1);
}

static int	do_stat(t_infos *infos, t_list_file *file)
{
  struct stat	buf;
  char		*path;

  path = get_path(infos->begin_path_scan->name, file->name);
  if (stat(path, &buf) == -1)
    return (-1);
  file->st_mode = buf.st_mode;
  file->st_uid = buf.st_uid;
  file->st_gid = buf.st_gid;
  file->st_size = buf.st_size;
  file->st_mtime = buf.st_mtime;
  file->st_nlink = buf.st_nlink;
  return (0);
}

int		do_inlist(t_infos *infos, char *name)
{
  t_list_file	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);
  tmp->next = infos->begin_path_scan->begin_file_to_print;
  tmp->name = name;
  if (infos->have_stat)
    if (do_stat(infos, tmp) == -1)
      return (-1);
  infos->begin_path_scan->begin_file_to_print = tmp;
  return (0);
}

char		*get_path(char *path, char *file)
{
  char		*tmp;
  int		idx;
  int		idx2;

  idx = my_strlen(path) + my_strlen(path) + 2;
  if ((tmp = malloc(sizeof(*tmp) * idx)) == NULL)
    return (NULL);
  idx = -1;
  while (path[++idx])
    tmp[idx] = path[idx];
  tmp[idx++] = '/';
  idx2 = 0;
  while (file[idx2])
    {
      tmp[idx++] = file[idx2];
      ++idx2;
    }
  tmp[idx] = 0;
  return (tmp);
}

int		save_path(t_infos *infos, char *name, int have_free)
{
  t_list_path	*tmp;
  char		*path;
  struct stat	buf;

  path = get_path(infos->begin_path_scan->name, name);
  if (stat(path, &buf) == -1)
    return (0);
  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (-1);
  if (!S_ISDIR(buf.st_mode))
    return (0);

  tmp->name = name;
  tmp->have_free = have_free;
  tmp->next = infos->begin_path_scan->next;
  infos->begin_path_scan->next = tmp;
  return (0);
}
