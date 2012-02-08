/*
** simple_btree.c for ex01 in /home/hervet_g/piscine/piscine_cpp_d02a-2015-hervet_g/ex01
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Thu Jan 05 17:41:35 2012 geoffrey hervet
** Last update Thu Jan 05 17:41:35 2012 geoffrey hervet
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"simple_btree.h"

t_bool		btree_is_empty(t_tree tree)
{
  if (tree == NULL)
    return TRUE;
  return FALSE;
}

unsigned int	btree_get_size(t_tree tree)
{
  unsigned int	size = 0;

  void		__rec(t_tree node)
  {
    size++;
    if (!btree_is_empty(node->left))
      __rec(node->left);
    if (!btree_is_empty(node->right))
      __rec(node->right);
  }
  if (!btree_is_empty(tree))
    __rec(tree);
  return size;
}

unsigned int	btree_get_depth(t_tree tree)
{
  unsigned int	__rec(t_tree node, unsigned int depth)
  {
    if (btree_is_empty(node))
      return depth;
    unsigned int left = __rec(node->left, depth + 1);
    unsigned int right= __rec(node->right, depth + 1);
    return (left > right) ? left : right;
  }
  return __rec(tree, 0);
}

t_bool		btree_create_node(t_tree *node_ptr, double value)
{
  if (NULL == (*node_ptr = malloc(sizeof(**node_ptr))))
    return FALSE;
  (*node_ptr)->value = value;
  (*node_ptr)->left = NULL;
  (*node_ptr)->right = NULL;
  return TRUE;
}

t_bool		btree_delete(t_tree *root_ptr)
{
  if (btree_is_empty(*root_ptr))
    return FALSE;
  void		__free_rec(t_tree node)
  {
    if (!btree_is_empty(node->left))
     __free_rec(node->left);
    if (!btree_is_empty(node->right))
      __free_rec(node->right);
    free(node);
  }
  __free_rec(*root_ptr);
  *root_ptr = NULL;
  return FALSE;
}


double		btree_get_max_value(t_tree tree)
{
  if (btree_is_empty(tree))
    return 0;
  double  	__rec_max(t_tree node)
  {
    double	__get_max(double a, double b)
    {
      return a > b ? a : b;
    }
    double	max = node->value;
    if (!btree_is_empty(node->left))
      max = __get_max(max, __rec_max(node->left));
    if (!btree_is_empty(node->right))
      max = __get_max(max, __rec_max(node->right));
    return max;
  }
  return __rec_max(tree);
}

double		btree_get_min_value(t_tree tree)
{
  if (btree_is_empty(tree))
    return 0;
  double  	__rec_min(t_tree node)
  {
    double	__get_mix(double a, double b)
    {
      return a < b ? a : b;
    }
    double	min = node->value;
    if (!btree_is_empty(node->left))
      min = __get_mix(min, __rec_min(node->left));
    if (!btree_is_empty(node->right))
      min = __get_mix(min, __rec_min(node->right));
    return min;
  }
  return __rec_min(tree);
}
