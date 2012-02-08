/*
** free_tree.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/utils
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr 27 15:09:09 2011 tom-brent yau
** Last update Wed Apr 27 15:12:05 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"

void	free_tree(t_tree *tree)
{
  if (tree)
    {
      if (tree->left)
	free_tree(tree->left);
      if (tree->right)
	free_tree(tree->right);
      free(tree->info.str);
      free(tree);
    }
}
