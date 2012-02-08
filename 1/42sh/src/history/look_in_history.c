/*
** look_in_history.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/lexer
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 12 12:38:47 2011 tom-brent yau
** Last update Sun May 22 19:13:48 2011 tom-brent yau
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"sh.h"

#include	"history.h"
#include	"utils.h"

static int	pick_leadchars(char *str, int count, t_history *list)
{
  int	pos;

  pos = count + 1;
  pos += strclen(str + pos, " :");
  while (list->next != NULL)
    list = list->next;
  while (list != NULL && list->cmd != NULL &&
	 strncmp(list->cmd, str + count + 1, pos - (count + 1)))
    list = list->previous;
  if (list == NULL || list->cmd == NULL)
    {
      fprintf(stderr, "Event not found\n");
      return (FALSE);
    }
  replace_cmd(str, list->cmd, count, pos - count);
  return (TRUE);
}

static int	pick_nb(char *str, int count, t_history *list, int nb)
{
  t_history	*tmp_list;
  int	current;

  tmp_list = list;
  while (tmp_list->next != NULL)
    tmp_list = tmp_list->next;
  current = tmp_list->id;
  if (nb < 0)
    nb = current + nb + 1;
  while (list != NULL && list->id != nb)
    list = list->next;
  if (list == NULL || list->cmd == NULL)
    {
      fprintf(stderr, "%d: No such event\n", nb);
      return (FALSE);
    }
  replace_cmd(str, list->cmd, count, len_eq_c(str + count, "!-0123456789"));
  return (TRUE);
}

static int	pick_last(char *str, int count, t_history *list)
{
  while (list != NULL && list->next != NULL)
    list = list->next;
  if (list->cmd == NULL)
    return (FALSE);
  replace_cmd(str, list->cmd, count, 2);
  return (TRUE);
}

int	look_in_history(char *str, int begin, t_history *list)
{
  int	pos;
  int	ret;

  if (list == NULL)
    return (FALSE);
  pos = begin + 1;
  ret = TRUE;
  if (str[pos] == '!')
    ret = pick_last(str, begin, list);
  else if ((str[pos] >= '0' && str[pos] <= '9')
	   || str[pos] == '-')
    ret = pick_nb(str, begin, list, atoi(str + pos));
  else if (str[pos] && str[pos] != ':')
    ret = pick_leadchars(str, begin, list);
  if (ret == FALSE)
    return (ret);
  while (str[(pos += strclen(str + pos, ":!"))] && str[pos] != '!')
    {
      if ((ret = history_modifiers(str, begin, pos)) == FALSE)
	return (FALSE);
      pos = begin;
    }
  return (ret);
}
