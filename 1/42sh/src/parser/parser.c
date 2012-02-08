/*
** parser.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Apr  7 16:31:03 2011 tom-brent yau
** Last update Wed May 11 15:26:45 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"sh.h"
#include	"many_commands.h"
#include	"utils.h"

static void	show_error(t_lex *lex)
{
  if ((lex->info.type == OPE_DOUBLE_RIGHT ||
       lex->info.type == OPE_RED_RIGHT ||
       lex->info.type == OPE_DOUBLE_LEFT ||
       lex->info.type == OPE_RED_LEFT) && lex->next)
    fprintf(stderr, "Ambiguous redirection\n");
  else if (lex->info.type == OPE_PIPE || lex->info.type == OPE_AND
	   || lex->info.type == OPE_OR ||
	   lex->info.type == OPE_DOUBLE_RIGHT ||
	   lex->info.type == OPE_RED_RIGHT ||
	   lex->info.type == OPE_DOUBLE_LEFT ||
	   lex->info.type == OPE_RED_LEFT)
    fprintf(stderr, "Invalid null command\n");
  else
    fprintf(stderr, "Syntax error near '%s'\n", lex->info.str);
}

t_tree	*parser(t_lex *lex)
{
  t_tree	*root;

  if (lex == NULL)
    return (NULL);
  root = many_commands(&lex);
  if (lex)
    {
      show_error(lex);
      free_tree(root);
      root = NULL;
    }
  return (root);
}
