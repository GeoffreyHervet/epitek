/*
** exec_tree.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/exec
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Apr 15 14:48:56 2011 tom-brent yau
** Last update Mon May  9 12:36:28 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"exec_and_or.h"

int	exec_tree(t_tree *tree, t_inf *infos)
{
  int	ret;

  ret = FALSE;
  if (tree->info.type == SEMICOLON)
    {
      if (tree->left)
	ret = exec_tree(tree->left, infos);
      if (tree->right)
	ret = exec_tree(tree->right, infos);
    }
  else
    ret = exec_and_or(tree, infos);
  return (ret);
}
