/*
** insert_alias.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/lexer
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed May 11 17:09:18 2011 tom-brent yau
** Last update Wed May 11 23:54:55 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<string.h>

#include	"sh.h"

#include	"check_function.h"

static void	str_add(const char *alias,
			 char *str,
			 int count)
{
  char		tmp[SIZE + 1];

  memset(tmp, 0, SIZE + 1);
  strncpy(tmp, str + count, strlen(str + count) + 1);
  memset(str, 0, SIZE + 1);
  strncpy(str, alias, SIZE);
  strncat(str, tmp, SIZE - strlen(str));
}

int	insert_alias(t_lex *new,
		     t_aliases *aliases,
		     char *str,
		     int idx)
{
  while (strcmp(new->info.str, aliases->name))
    aliases = aliases->next;
  aliases->selected = 1;
  str_add(aliases->value, str, idx);
  idx = 0;
  while (check_word(str[idx]))
    idx++;
  free(new->info.str);
  new->info.str = strndup(str, idx);
  return (idx);
}
