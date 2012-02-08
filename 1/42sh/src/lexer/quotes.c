/*
** quotes.c for lexer in /home/igix/42sh/src/lexer
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  mer. mai 11 07:34:37 2011 geoffrey hervet
** Last update Thu May 19 20:57:50 2011 tom-brent yau
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>

#include		"sh.h"

#include		"check_function.h"
#include		"quotes.h"
#include		"set_backslahes.h"
#include		"utils.h"
#include		"xmalloc.h"

static void		update_str(char *str,
				    int beg,
				    int end,
				    char *insert)
{
  char			tmp[SIZE + 1];

  memset(tmp, 0, SIZE + 1);
  strncpy(tmp, str, beg);
  strncat(tmp, insert, SIZE - strlen(tmp));
  strncat(tmp, str + end, SIZE - strlen(tmp));
  memset(str, 0, SIZE + 1);
  strncpy(str, tmp, SIZE);
}

static void		check_env_var(int *begin_dol,
				      char *str,
                                      t_env *env)
{
  char			val[SIZE + 1];
  int			idx;
  int			idx2;
  char			*chr;

  idx2 = *begin_dol + 1;
  idx = 0;
  memset(val, 0, SIZE + 1);
  while (str[idx2] != '"' && check_word(str[idx2]))
  {
    if (idx < SIZE)
      val[idx++] = str[idx2];
    else
      val[0] = 0;
    idx2++;
  }
  val[idx] = 0;
  if (val[0])
    env = find_env_var(env, val);
  chr = (env == NULL) ? NULL : (strchr(env->var, '=') + 1);
  update_str(str, *begin_dol, idx2, (chr == NULL) ? "" : chr);
  *begin_dol = *begin_dol + ((chr == NULL) ? 0 : strlen(chr)) - 1;
}

static int		update_str_quote(int quote_begin,
					 int *quote_end,
					 char *str)
{
  int			idx;
  int			dec;

  idx = quote_begin;
  dec = 1;
  while (str[idx])
  {
    if (idx + dec == *quote_end)
      dec++;
    str[idx] = str[idx + dec];
    idx++;
  }
  str[idx] = 0;
  str[idx + 1] = 0;
  *quote_end = *quote_end - 2;
  if (*quote_end < 0)
    *quote_end = 0;
  return (0);
}

static int		reset_quote(char *str,
				    int idx,
                                    int *quote_begin)
{
  *quote_begin = idx;
  return (((str[idx]) == '"') + 1);
}

int			quotes(char *str,
			       int *count,
                               t_env *env)
{
  int			quote;
  int			quote_begin;
  int			idx;

  idx = -1;
  quote = 0;
  quote_begin = 0;
  while ((++idx != -1 && str[idx]) && (quote || check_word(str[idx]) ||
  str[idx] == '$' || str[idx] == '\'' || str[idx] == '"' || str[idx] == '\\'))
  {
    if ((str[idx] == '"' && quote == 2) || (str[idx] == '\'' && quote == 1))
      quote = update_str_quote(quote_begin, &idx, str);
    else if (!quote && (str[idx] == '"' || (str[idx] == '\'')))
      quote = reset_quote(str, idx, &quote_begin);
    else if (str[idx] == '\\' && (str[idx + 1] == '\'' || str[idx + 1] == '"'))
      set_backslashes(str, idx);
    if ((!quote || quote == 2) && (str[idx] == '$'))
      check_env_var(&idx, str, env);
  }
  *count = *count + idx;
  if (quote)
    fprintf(stderr, "Unmatched %c.\n", (quote == 1) ? '\'' : '"');
  return (quote);
}
