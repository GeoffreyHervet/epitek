/*
** simple_cmd.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue Apr  5 22:00:03 2011 tom-brent yau
** Last update Fri May 13 23:45:12 2011 quentin rufin
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"init_node.h"
#include	"command.h"
#include	"redirection.h"

static t_tree	*pth(t_lex **lex)
{
  t_tree	*node;

  if (*lex == NULL || (*lex)->info.type != PTH_BEG)
    return (NULL);
  node = init_node(*lex);
  *lex = (*lex)->next;
  if ((node->right = command(lex)) && *lex && (*lex)->info.type == PTH_END)
    {
      *lex = (*lex)->next;
      return (node);
    }
  return (NULL);
}

static t_tree	*bckqt(t_lex **lex)
{
  t_tree	*node;

  if (*lex == NULL || (*lex)->info.type != BACK_QUOTE)
    return (NULL);
  *lex = (*lex)->next;
  if ((node = command(lex)) && *lex && (*lex)->info.type == BACK_QUOTE)
    {
      *lex = (*lex)->next;
      return (node);
    }
  return (NULL);
}

t_tree	*simple_cmd(t_lex **lex)
{
  t_tree	*node;

  if ((node = pth(lex)) || (node = bckqt(lex)) ||
      (node = redirection(lex)))
    {
      return (node);
    }
  return (NULL);
}
