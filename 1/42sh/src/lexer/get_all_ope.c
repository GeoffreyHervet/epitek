/*
** get_all_ope.c for  in /home/rufin_q/projet/42sh/42sh/src/lexer
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Wed Apr 20 15:19:14 2011 quentin rufin
** Last update Thu May 12 17:35:38 2011 tom-brent yau
*/

#include <sh.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "get_the_last.h"

const t_info	all_ope[] = {
  {">>", OPE_DOUBLE_RIGHT},
  {">", OPE_RED_RIGHT},
  {"<<", OPE_DOUBLE_LEFT},
  {"<", OPE_RED_LEFT},
  {">&", AGR_FD},
  {"&>", AGR_FD},
  {"&&", OPE_AND},
  {"||", OPE_OR},
  {"|", OPE_PIPE},
  {"&", BACKGROUND},
  {"(", PTH_BEG},
  {")", PTH_END},
  {"`", BACK_QUOTE},
  {"!", EXCL_MARK},
  {";", SEMICOLON},
  {0, -1}};

int		get_all_ope(t_lex **ptr, char *str)
{
  int		count;
  t_lex		*new;
  int		size;
  char		tmp[SIZE + 1];

  count = 0;
  while (all_ope[count].str != 0)
    {
      if (strncmp(str, all_ope[count].str,
		  strlen(all_ope[count].str)) == 0)
	{
	  size = strlen(all_ope[count].str);
	  new = get_the_last(ptr);
	  new->info.str = strndup(str, size);
	  new->info.type = all_ope[count].type;
	  size += len_eq_c(str + size, " \t");
	  strncpy(tmp, str + size, SIZE);
	  strncpy(str, tmp, SIZE);
	  return (1);
	}
      count++;
    }
  return (0);
}
