/*
** simple_cmd_elem.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May  5 22:12:05 2011 tom-brent yau
** Last update Thu May 12 15:26:51 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"init_node.h"
#include	"redirection.h"
#include	"word.h"
#include	"word_list.h"

t_tree	*simple_cmd_elem(t_lex **lex)
{
  t_tree	*node;
  t_tree	*tmp;

  if ((node = right_redirection(lex)))
    {
      if ((node->left = word_list(lex)))
	return (node);
      return (NULL);
    }
  else if ((node = word_list(lex)))
    {
      tmp = node;
      if ((node = right_redirection(lex)))
	node->left = tmp;
      else
	node = tmp;
      return (node);
    }
  return (NULL);
}
