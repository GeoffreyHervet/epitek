/*
** variable.c for marvin in /home/hervet_g//work/rush/marvin/src
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 26 23:14:09 2010 geoffrey hervet
** Last update Sun Nov 28 16:52:16 2010 geoffrey hervet
*/

#include	<stdlib.h>

#include	"marvin.h"
#include	"variable.h"
#include	"my_put_var.h"

static int	set_name_pos(t_marvin *marvin, int start, int end)
{
  t_variable	*variable;

  if ((variable = malloc(sizeof(*variable))) == NULL)
    return (-1);
  variable->next = NULL;
  variable->end_name = end - 1;
  variable->start_name = ++start;
  variable->is_ptr = 0;
  end = 0;
  while (start--)
    {
      if (marvin->str[start] == '*')
	variable->is_ptr++;
      else if (marvin->str[start] > ' ')
	{
	  variable->end_type = start + 1;
	  start = -1;
	  while (marvin->str[++start] <= ' ');
	  variable->start_type = start;
	  return (my_put_var(marvin, variable));
	}
    }
  return (-1);
}

int		variable(t_marvin *marvin)
{
  int		idx;
  int		semicolon;
  int		char_scanned;
  t_variable	*variable;

  if ((malloc(sizeof(*variable))) == NULL)
    return (-1);
  semicolon = 0;
  char_scanned = 0;
  idx = marvin->len_str;
  while (idx--)
    {
      if (marvin->str[idx] == ';')
	semicolon = marvin->len_str;
      else if (semicolon)
	{
	  if ((marvin->str[idx] <= ' ' || marvin->str[idx] == '*') && (char_scanned))
	    return (set_name_pos(marvin, idx, semicolon));
	  if ((marvin->str[idx] >= 'a' && marvin->str[idx] <= 'z') ||
	      (marvin->str[idx] >= 'A' && marvin->str[idx] <= 'Z'))
	    char_scanned = 1;
	}
    }
  return (-1);
}
