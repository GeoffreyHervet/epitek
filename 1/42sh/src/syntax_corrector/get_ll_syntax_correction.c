/*
** get_ll_syntax_correction.c for  in /home/rufin_q//projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sat May 21 17:27:26 2011 quentin rufin
** Last update Wed Jun  8 17:20:30 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<stdio.h>
#include	"sh.h"
#include	"dist_levenshtein.h"
#include	"xmalloc.h"
#include	"utils.h"
#include	"xstrdup.h"
#include	"apply_correction.h"
#include	"syntax_correction.h"

static t_list_correc	*add_in_list(t_list_correc *list, char *name)
{
  t_list_correc		*new;
  t_list_correc		*tmp;
  t_list_correc		*next;

  tmp = list;
  new = xmalloc(sizeof(*new));
  new->name = xstrdup(name);
  new->next = NULL;
  if (list == NULL)
    return (new);
  while (tmp->next != NULL && strcmp(name, tmp->name) > 0)
    tmp = tmp->next;
  next = tmp->next;
  tmp->next = new;
  if (next != NULL)
    new->next = next;
  return (list);
}

static t_list_correc	*get_all(t_list_correc *list, char *path)
{
  DIR			*direc;
  struct dirent		*dirent;

  if ((direc = opendir(path)) == NULL)
    return (list);
  while ((dirent = readdir(direc)) != NULL)
    {
      if (dirent->d_name[0] != '.')
	list = add_in_list(list, dirent->d_name);
    }
  closedir(direc);
  return (list);
}

static t_list_correc	*get_builtins(t_list_correc *list)
{
  int			count;
  char			*builtin[] = {
    "alias",
    "cd",
    "env",
    "echo",
    "exit",
    "history",
    "setenv",
    "unalias",
    "unsetenv",
    NULL};

  count = 0;
  while (builtin[count] != NULL)
    {
      list = add_in_list(list, builtin[count]);
      count++;
    }
  return (list);
}

t_list_correc		*get_ll_syntax_correction(t_env **env)
{
  char			path[SIZE + 1];
  char			*all_paths;
  t_list_correc		*first;
  int			count;

  first = NULL;
  first = get_builtins(first);
  if (env == NULL)
    return (first);
  if (find_env_var(*env, "PATH") == NULL ||
      (all_paths = (find_env_var(*env, "PATH")->var + 5)) == NULL)
    return (first);
  while (all_paths[0] != 0)
    {
      count = strclen(all_paths, ":");
      strncpy(path, all_paths, count % SIZE);
      path[count % SIZE] = 0;
      first = get_all(first, path);
      all_paths += count + len_eq_c(all_paths + count, ":");
    }
  return (first);
}
