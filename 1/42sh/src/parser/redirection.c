/*
** redirection.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr  6 14:57:16 2011 tom-brent yau
** Last update Fri May  6 15:06:34 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"init_node.h"
#include	"simple_cmd_elem.h"
#include	"redirection.h"
#include	"word.h"

t_tree	*right_redirection(t_lex **lex)
{
  t_tree	*node;

  if (*lex == NULL || ((*lex)->info.type != OPE_RED_RIGHT &&
		       (*lex)->info.type != OPE_DOUBLE_RIGHT &&
		       (*lex)->info.type != AGR_FD))
    return (NULL);
  node = init_node(*lex);
  if ((*lex)->next && (*lex)->next->info.type == WORD)
    *lex = (*lex)->next;
  node->right = word(lex);
  return (node);
}

static t_tree	*left_redirection(t_lex **lex)
{
  t_tree	*node;

  if (*lex == NULL || ((*lex)->info.type != OPE_RED_LEFT &&
		       (*lex)->info.type != OPE_DOUBLE_LEFT))
    return (NULL);
  node = init_node(*lex);
  if ((*lex)->next && (*lex)->next->info.type == WORD)
    *lex = (*lex)->next;
  node->right = word(lex);
  return (node);
}

static t_tree	*last_right(t_lex **lex, t_tree *node)
{
  t_tree	*tmp;
  t_tree	*tmp2;

  tmp = node;
  if ((node = right_redirection(lex)))
    {
      tmp2 = tmp->left;
      tmp->left = node;
      node->left = tmp2;
      node = tmp;
    }
  else
    node = tmp;
  return (node);
}

static t_tree	*first_right(t_lex **lex)
{
  t_tree	*node;
  t_tree	*tmp;

  if (*lex == NULL || (*lex)->next == NULL ||
      ((*lex)->info.type != OPE_RED_RIGHT &&
       (*lex)->info.type != OPE_DOUBLE_RIGHT &&
       (*lex)->info.type != AGR_FD))
    return (NULL);
  if ((*lex)->next->next == NULL ||
      ((*lex)->next->next->info.type != OPE_RED_LEFT &&
       (*lex)->next->next->info.type != OPE_DOUBLE_LEFT))
    return (NULL);
  if ((node = right_redirection(lex)))
    {
      tmp = node;
      if ((node = left_redirection(lex)))
	{
	  node->left = tmp;
	  node->left->left = simple_cmd_elem(lex);
	  return (node);
	}
    }
  return (NULL);
}

t_tree	*redirection(t_lex **lex)
{
  t_tree	*node;
  t_tree	*tmp;

  if ((node = first_right(lex)))
    return (node);
  if ((node = left_redirection(lex)))
    {
      if ((node->left = simple_cmd_elem(lex)))
	return (node);
    }
  else if ((node = simple_cmd_elem(lex)))
    {
      tmp = node;
      if ((node = left_redirection(lex)))
	{
	  node->left = tmp;
	  node = last_right(lex, node);
	}
      else
	node = tmp;
      return (node);
    }
  return (NULL);
}
