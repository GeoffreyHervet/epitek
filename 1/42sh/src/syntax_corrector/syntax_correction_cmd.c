/*
** syntax_correction_cmd.c for  in /home/rufin_q/projet/42sh/42sh/src/exec
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Mon Apr 25 15:39:09 2011 quentin rufin
** Last update Tue May 10 19:58:42 2011 quentin rufin
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "sh.h"
#include "dist_levenshtein.h"
#include "xmalloc.h"
#include "utils.h"

static void	find_the_smallest_dist(int *dist, char *path,
				       t_tree *cmd, char *name)
{
  DIR		*direc;
  struct dirent *dirent;
  int		tmp_dist;
  int		bol;

  bol = 1;
  if ((direc = opendir(path)) == NULL)
    return ;
  while ((dirent = readdir(direc)) != NULL && bol)
    {
      tmp_dist = xcalc_dist_levenshtein(dirent->d_name, cmd->info.str);
      if (tmp_dist < *dist)
	{
	  *dist = tmp_dist;
	  strncpy(name, dirent->d_name, SIZE);
	}
      if (tmp_dist == 0)
	bol = 0;
    }
  closedir(direc);
}

void	syntax_correction_cmd(t_tree *cmd, t_env **env)
{
  char	name[SIZE + 1];
  int	distance;
  int	count;
  char	*all_paths;
  char	one_path[SIZE + 1];

  memset(name, 0, SIZE + 1);
  distance = 100;
  if (find_env_var(*env, "PATH") == NULL ||
      (all_paths = (find_env_var(*env, "PATH")->var + 5)) == NULL)
    return ;
  while (all_paths[0] != 0)
    {
      count = strclen(all_paths, ":");
      strncpy(one_path, all_paths, count % SIZE);
      one_path[count % SIZE] = 0;
      find_the_smallest_dist(&distance, one_path, cmd, name);
      all_paths += count + len_eq_c(all_paths + count, ":");
    }
  if (distance == 1 && distance != 0 && distance != (int)strlen(name))
    apply_correction(cmd, name);
}
