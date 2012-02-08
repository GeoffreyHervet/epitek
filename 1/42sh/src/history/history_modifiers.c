/*
** history_modifiers.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/history
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu May 12 19:50:26 2011 tom-brent yau
** Last update Fri May 13 17:58:05 2011 tom-brent yau
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"sh.h"
#include	"history.h"
#include	"utils.h"

static int	get_arg_nb(char *str, int begin, int nb)
{
  char		tmp[SIZE + 1];
  int		pos;

  pos = begin;
  memset(tmp, 0, SIZE + 1);
  while (nb-- > 0 && str[pos] != ':' && str[pos])
    {
      pos += strclen(str + pos, " :");
      if (str[pos] && str[pos] != ':')
	++pos;
    }
  if (str[pos] == ':')
    return (FALSE);
  strncpy(tmp, str + pos, strclen(str + pos, " :"));
  replace_cmd(str, tmp, begin, strclen(str + begin, ":") + 1
      + len_eq_c(str + begin + strclen(str + begin, ":") + 1, "0123456789"));
  return (TRUE);
}

static void	substitute_cmd(char *str, char *sub, int pos, int len_sub)
{
  char		tmp[SIZE + 1];

  memset(tmp, 0, SIZE + 1);
  strncpy(tmp, str, SIZE);
  memset(str, 0, SIZE + 1);
  strncpy(str, tmp, pos);
  strncat(str, sub, SIZE - strlen(str) - len_sub);
  strncat(str, tmp + pos + len_sub, strclen(tmp + pos + len_sub, ":"));
  pos = strlen(str);
  pos += strclen(tmp + pos, " ");
  strncat(str, tmp + pos, SIZE - strlen(str));
}

static int	substitute(char *str, int begin, int count)
{
  char		tmp[SIZE + 1];
  int		pos;

  memset(tmp, 0, SIZE + 1);
  if (str[count++] != '/' ||
      strclen(str + count, "/") == (int)strlen(str + count))
    return (FALSE);
  strncpy(tmp, str + count, strclen(str + count, "/"));
  pos = begin;
  while (pos < count && strncmp(tmp, str + pos, strlen(tmp)))
    ++pos;
  if (pos >= count)
    return (FALSE);
  memset(tmp, 0, SIZE + 1);
  count += strclen(str + count, "/");
  if (str[count++] == 0)
    return (FALSE);
  strncpy(tmp, str + count, strclen(str + count, "/"));
  substitute_cmd(str, tmp, pos, strlen(tmp));
  return (TRUE);
}

int	history_modifiers(char *str, int begin, int count)
{
  int	ret;

  ++count;
  ret = FALSE;
  if (str[count] >= '0' && str[count] <= '9')
    {
      if ((ret = get_arg_nb(str, begin, atoi(str + count))) == FALSE)
	fprintf(stderr, "Bad argument selector\n");
    }
  else if (str[count] == 's')
    {
      if ((ret = substitute(str, begin, count + 1)) == FALSE)
	fprintf(stderr, "Modifier failed\n");
    }
  return (ret);
}
