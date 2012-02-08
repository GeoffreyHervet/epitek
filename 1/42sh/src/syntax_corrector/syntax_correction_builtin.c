/*
** syntax_correction.c for  in /home/rufin_q/projet/42sh/42sh/src/exec
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Sun Apr 24 21:06:59 2011 quentin rufin
** Last update Wed Apr 27 18:40:12 2011 tom-brent yau
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "sh.h"
#include "dist_levenshtein.h"

char	*list_builtin[] = {
    "cd",
    "env",
    "setenv",
    "unsetenv",
    "alias",
    "unalias",
    "echo",
    NULL};

void	syntax_correction_builtin(t_tree *cmd)
{
  char	*name;
  int	distance;
  int	count;
  int	tmp_dist;

  count = 1;
  distance = xcalc_dist_levenshtein(cmd->info.str, list_builtin[0]);
  name = list_builtin[0];
  while (list_builtin[count] != NULL && distance != 0)
    {
      tmp_dist = xcalc_dist_levenshtein(cmd->info.str, list_builtin[count]);
      if (tmp_dist < distance)
	{
	  name = list_builtin[count];
	  distance = tmp_dist;
	}
      count++;
    }
  if (distance <= 2 && distance != 0 && (int)strlen(name) != distance)
    apply_correction(cmd, name);
}
