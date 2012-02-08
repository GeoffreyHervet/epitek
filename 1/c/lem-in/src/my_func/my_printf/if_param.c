/*
** if_param.c for if_param in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Nov 20 15:42:22 2010 tom-brent yau
** Last update Sun Nov 21 21:51:21 2010 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

int	if_param(char *str, t_option option)
{
  int	pos;
  int	pos2;

  option.pos++;
  while (str[option.pos])
    {
      pos = 0;
      pos2 = 0;
      while (str[option.pos] != flags[pos].flag && flags[pos].flag)
	pos++;
      while (str[option.pos] != type[pos2].type && type[pos2].type)
	pos2++;
      if (flags[pos].flag)
	(flags[pos].p)(&option);
      else if ((str[option.pos] >= '1' && str[option.pos] <= '9')
	       || str[option.pos] == '.' || str[option.pos] == '*')
	get_len(str, &option);
      else if (type[pos2].type || str[option.pos] == '%')
	return (1);
      option.pos++;
    }
  return (0);
}
