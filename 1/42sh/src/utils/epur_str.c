/*
** epur_str2.c for  in /home/yau_t//local/Projets/semestre_2/42sh/src/utils
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Wed May 11 15:59:17 2011 tom-brent yau
** Last update Sun May 22 17:46:41 2011 tom-brent yau
*/

#include	<string.h>
#include	"sh.h"
#include	"utils.h"

static int	is_symb(char c, char *symb)
{
  int		i;

  i = 0;
  while (symb[i])
    {
      if (symb[i] == c)
	return (1);
      i++;
    }
  return (0);
}

static void	separate(char *str, char *sep)
{
  int	i;
  int	j;
  char	tmp[SIZE + 1];

  i = 0;
  j = 0;
  memset(tmp, 0, SIZE + 1);
  strncpy(tmp, str, SIZE);
  while (tmp[i] && i < SIZE && j < SIZE)
    {
      while (tmp[i] && tmp[i] != ' ' && !is_symb(tmp[i], sep) && j < SIZE)
	str[j++] = tmp[i++];
      if (tmp[i] == ' ' && i < SIZE && j < SIZE)
	str[j++] = tmp[i++];
      else if (i && i < SIZE && j < SIZE && is_symb(tmp[i], sep))
	str[j++] = ' ';
      if (is_symb(tmp[i], sep) && i < SIZE && j < SIZE)
	{
	  while (is_symb(tmp[i], sep) && i < SIZE && j < SIZE)
	    str[j++] = tmp[i++];
	  if (tmp[i] && tmp[i] != ' ' && i < SIZE && j < SIZE)
	    str[j++] = ' ';
	}
    }
  str[j] = 0;
}

void	epur_str(char *str, char *delim, char *sep)
{
  int	pos;
  int	pos2;

  pos = 0;
  pos2 = 0;
  while (str[pos] && pos < SIZE)
    {
      pos += len_eq_c(str + pos, delim);
      while (str[pos] && !is_symb(str[pos], delim) && pos < SIZE)
	str[pos2++] = str[pos++];
      if (pos < SIZE && len_eq_c(str + pos, delim) != (int)strlen(str + pos))
	{
	  str[pos2++] = ' ';
	  pos++;
	}
    }
  str[pos2] = 0;
  separate(str, sep);
}
