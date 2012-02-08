/*
** read_semicolon.c for  in /home/rufin_q/projet/42sh/42sh/src/parser
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Wed Apr 27 14:41:18 2011 quentin rufin
** Last update Thu May 12 17:19:42 2011 quentin rufin
*/

#include	<stdlib.h>
#include	<string.h>
#include	"sh.h"
#include	"read_functions.h"
#include	"xstrdup.h"

int	read_semicolon(t_tree *node, t_lex **lex)
{
  read_backgd(node->left, lex);
  if (*lex == NULL || (*lex)->info.type != SEMICOLON)
    return (0);
  node->info.str = xstrdup((*lex)->info.str);
  node->info.type = SEMICOLON;
  while (*lex && (*lex)->info.type == SEMICOLON)
    *lex = (*lex)->next;
  if (*lex)
    return (1);
  return (0);
}
