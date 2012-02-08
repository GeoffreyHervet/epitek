/*
** get_word.c for  in /home/rufin_q/projet/42sh/42sh/src/lexer
** 
** Made by quentin rufin
** Login   <rufin_q@epitech.net>
** 
** Started on  Wed Apr 20 15:16:35 2011 quentin rufin
** Last update Sun May 15 15:43:44 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>

#include	"sh.h"

#include	"check_function.h"
#include	"choose_type.h"
#include	"get_the_last.h"
#include	"quotes.h"
#include	"insert_alias.h"
#include	"chg_tilde_to_home.h"
#include	"utils.h"

static void	init_aliases(t_aliases *alias)
{
  while (alias != NULL)
  {
    alias->selected = 0;
    alias = alias->next;
  }
}

static int	is_alias(const char *str, t_aliases *aliases)
{
  while (aliases != NULL)
  {
    if (!strcmp(str, aliases->name))
      return ((aliases->selected) ? 0: 1);
    aliases = aliases->next;
  }
  return (0);
}

static int	alias_insertion(char *str, t_inf *infos, t_lex *new, int count)
{
  while (is_alias(new->info.str, infos->aliases) == 1)
    count = insert_alias(new, infos->aliases, str, count);
  count = 0;
  if (quotes(str, &count, *(infos->env)))
    return (-1);
  free(new->info.str);
  new->info.str = strndup(str, count);
  return (count);
}

int		get_word(t_lex **ptr, char *str, t_inf *infos)
{
  t_lex		*new;
  int		count;
  char		tmp[SIZE + 2];

  count = 0;
  if (!check_word(*str) && *str != '\'' && *str != '"' && *str != '$')
    return (0);
  if (*str == '~')
    chg_tilde_to_home(str, *(infos->env));
  init_aliases(infos->aliases);
  new = get_the_last(ptr);
  if (quotes(str, &count, *(infos->env)))
    return (-1);
  while (str[count] && check_word(str[count]))
    count++;
  new->info.str = strndup(str, count);
  new->info.type = choose_type(new);
  while (new->info.type == CMD && is_alias(new->info.str, infos->aliases) == 1)
    if ((count = alias_insertion(str, infos, new, count)) == -1)
      return (-1);
  count += len_eq_c(str + count, " \t");
  strncpy(tmp, str + count, SIZE);
  strncpy(str, tmp, SIZE);
  return (1);
}
