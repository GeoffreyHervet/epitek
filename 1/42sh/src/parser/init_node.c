/*
** init_node.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr 13 20:33:50 2011 tom-brent yau
** Last update Thu May 12 18:10:18 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"
#include	"xmalloc.h"
#include	"xstrdup.h"

t_tree	*init_node(t_lex *lex)
{
  t_tree	*node;

  node = xmalloc(sizeof(*node));
  memset(node, 0, sizeof(*node));
  if (lex)
    {
      node->info.type = lex->info.type;
      node->info.str = xstrdup(lex->info.str);
    }
  return (node);
}
