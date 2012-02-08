/*
** word_list.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/parser
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed Apr  6 12:01:20 2011 tom-brent yau
** Last update Sat May 14 16:24:44 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	"sh.h"
#include	"init_node.h"

t_tree	*word(t_lex **lex)
{
  t_tree	*node;

  if (*lex == NULL || (*lex)->info.type != WORD)
    return (NULL);
  node = init_node(*lex);
  *lex = (*lex)->next;
  return (node);
}

static t_tree	*cmd_arg(t_lex **lex)
{
  t_tree	*node;

  if (*lex == NULL || (*lex)->info.type != CMD_ARG)
    return (NULL);
  node = init_node(*lex);
  *lex = (*lex)->next;
  return (node);
}

static t_tree	*cmd(t_lex **lex)
{
  t_tree	*node;

  if (*lex == NULL || (*lex)->info.type != CMD)
    return (NULL);
  node = init_node(*lex);
  *lex = (*lex)->next;
  return (node);
}

static void	get_last_args(t_tree *cmd, t_lex *lex)
{
  t_lex	*tmp;
  t_lex	*tmp2;

  while (lex && lex->info.type != CMD_ARG &&
	 lex->info.type != OPE_PIPE &&
	 lex->info.type != OPE_AND &&
	 lex->info.type != OPE_OR &&
	 lex->info.type != SEMICOLON)
    lex = lex->next;
  if (lex == NULL || lex->info.type != CMD_ARG)
    return ;
  tmp = lex->prev;
  while (lex && lex->info.type == CMD_ARG)
    {
      tmp2 = lex;
      cmd->right = cmd_arg(&lex);
      cmd = cmd->right;
      free(tmp2->info.str);
      free(tmp2);
    }
  tmp->next = lex;
}

t_tree	*word_list(t_lex **lex)
{
  t_tree	*node;
  t_tree	*tmp;

  if (*lex == NULL || (*lex)->info.type != CMD)
    return (NULL);
  node = cmd(lex);
  tmp = node;
  while (*lex && (*lex)->info.type == CMD_ARG)
    {
      tmp->right = cmd_arg(lex);
      tmp = tmp->right;
    }
  if (*lex && ((*lex)->info.type == OPE_RED_RIGHT ||
	       (*lex)->info.type == OPE_DOUBLE_RIGHT ||
	       (*lex)->info.type == OPE_RED_LEFT ||
	       (*lex)->info.type == OPE_DOUBLE_RIGHT))
    get_last_args(tmp, *lex);
  return (node);
}
