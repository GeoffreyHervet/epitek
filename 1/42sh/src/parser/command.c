/*
** command.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue Apr  5 16:46:12 2011 tom-brent yau
** Last update Thu Jun  9 18:36:47 2011 kevin boulain
*/

#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"
#include	"init_node.h"
#include	"pipeline.h"
#include	"utils.h"
#include	"xstrdup.h"

static int	read_and(t_tree *node, t_lex **lex)
{
  if (*lex == NULL || (*lex)->info.type != OPE_AND
      || (*lex)->next == NULL)
    return (0);
  node->info.str = xstrdup((*lex)->info.str);
  node->info.type = OPE_AND;
  *lex = (*lex)->next;
  return (1);
}

static int	read_or(t_tree *node, t_lex **lex)
{
  if (*lex == NULL || (*lex)->info.type != OPE_OR
      || (*lex)->next == NULL)
    return (0);
  node->info.str = xstrdup((*lex)->info.str);
  node->info.type = OPE_OR;
  *lex = (*lex)->next;
  return (1);
}

void	read_backgd(t_tree *node, t_lex **lex)
{
  if (*lex == NULL || (*lex)->info.type != BACKGROUND)
    node->bg = 0;
  else
    {
      node->bg = 1;
      *lex = (*lex)->next;
    }
}

static	int	and_or(t_lex *lex)
{
  return (lex != NULL &&
      (lex->info.type == OPE_AND || lex->info.type == OPE_OR ));
}

t_tree	*command(t_lex **lex)
{
  t_tree	*node;
  t_tree	*tmp;

  if ((tmp = pipeline(lex)))
    {
      while (and_or(*lex))
	{
	  node = init_node(*lex);
          read_or(node, lex);
          read_and(node, lex);
	  node->left = tmp;
	  node->right = pipeline(lex);
	  if (and_or(*lex))
	    {
	      tmp = init_node(*lex);
              read_or(tmp, lex);
              read_and(tmp, lex);
	      tmp->left = node;
	      tmp->right = pipeline(lex);
	    }
	}
      return (tmp);
    }
  return (NULL);
}
