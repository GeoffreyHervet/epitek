/*
** syntax_correction.c for  in /home/rufin_q//projet/42sh/42sh/src/syntax_corrector
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Tue May 10 18:12:30 2011 quentin rufin
** Last update Sun May 22 23:03:57 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<stdio.h>

#include	"sh.h"

#include	"dist_levenshtein.h"
#include	"apply_correction.h"

void			check_syntax_correction(t_tree *cmd, t_list_correc *list)
{
  int			dist;
  int			tmp_dist;
  char			*tmp_name;
  int			size;

  size = (int)strlen(cmd->info.str);
  if (size == 0 || size == 1)
    return ;
  tmp_name = NULL;
  dist = 10;
  tmp_dist = 10;
  while (tmp_dist != 0 && list->next != NULL)
    {
      tmp_dist  = xcalc_dist_levenshtein(cmd->info.str, list->name);
      if (tmp_dist < dist)
	{
	  dist = tmp_dist;
	  tmp_name = list->name;
	}
      list = list->next;
    }
  if (dist != 0 && dist <= 2)
    apply_correction(cmd, tmp_name);
}
