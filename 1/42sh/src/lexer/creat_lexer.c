/*
** creat_lexer.c for  in /home/rufin_q//projet/42sh/42sh/src
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Mon Apr  4 22:08:56 2011 quentin rufin
** Last update Thu May 19 21:01:45 2011 tom-brent yau
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sh.h"

#include "check_function.h"
#include "utils.h"
#include "get_all_ope.h"
#include "get_word.h"
#include "free_lex.h"
#include "xmalloc.h"

t_lex	*creat_lexer(char *str, t_inf *infos)
{
  t_lex	*ptr;
  int	ret1;
  int	ret2;

  ptr = NULL;
  while (str[0] != 0 && str[0] != '#')
    {
      ret1 = get_word(&ptr, str, infos);
      ret2 = get_all_ope(&ptr, str);
      if (ret1 <= 0 && ret2 == 0)
	{
          if (ret1 == 0)
            fprintf(stderr, "'%c' Unmatched\n", *str);
	  free_lex(ptr);
	  return (NULL);
	}
    }
  return (ptr);
}
