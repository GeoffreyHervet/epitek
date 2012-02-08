/*
** free_node_ret_leaf.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr 27 15:28:12 2011 tom-brent yau
** Last update Wed Apr 27 15:30:06 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"

t_tree	*free_node_ret_leaf(t_tree *tree, t_tree *leaf)
{
  free(tree->info.str);
  free(tree);
  return (leaf);
}
