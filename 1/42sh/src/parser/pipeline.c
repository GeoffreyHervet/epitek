/*
** command.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue Apr  5 16:46:12 2011 tom-brent yau
** Last update Thu May 12 17:22:25 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"
#include	"init_node.h"
#include	"simple_cmd.h"
#include	"utils.h"
#include	"xstrdup.h"

static int	read_pipe(t_tree *node, t_lex **lex)
{
  if (*lex == NULL || (*lex)->info.type != OPE_PIPE
      || (*lex)->next == NULL)
    return (0);
  node->info.str = xstrdup((*lex)->info.str);
  node->info.type = OPE_PIPE;
  *lex = (*lex)->next;
  return (1);
}

t_tree	*pipeline(t_lex **lex)
{
  t_tree	*node;

  node = init_node(NULL);
  if ((node->left = simple_cmd(lex)))
    {
      if (read_pipe(node, lex))
	{
	  node->right = pipeline(lex);
	  return (node);
	}
      node = free_node_ret_leaf(node, node->left);
      return (node);
    }
  free(node);
  return (NULL);
}
