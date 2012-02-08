/*
** many_commands.c for  in /home/rufin_q/projet/42sh/42sh
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Wed Apr 27 12:07:53 2011 quentin rufin
** Last update Thu May  5 22:59:56 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"
#include	"init_node.h"
#include	"pipeline.h"
#include	"command.h"
#include	"read_functions.h"
#include	"utils.h"

t_tree		*many_commands(t_lex **lex)
{
  t_tree	*node;

  node = init_node(NULL);
  if ((node->left = command(lex)))
    {
      if (read_semicolon(node, lex))
	{
	  node->right = many_commands(lex);
	  return (node);
	}
      node = free_node_ret_leaf(node, node->left);
      return (node);
    }
  free(node);
  return (NULL);
}
