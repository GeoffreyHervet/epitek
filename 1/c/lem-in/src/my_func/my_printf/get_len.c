/*
** get_len.c for get_len in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue Nov 16 17:55:21 2010 tom-brent yau
** Last update Sun Nov 21 21:58:54 2010 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	get_precision(char *str, t_option *option)
{
  int	nb;

  nb = -1;
  option->pos++;
  if (str[option->pos] == '*')
    option->precision = va_arg(option->arg, int);
  else
    {
      str += option->pos;
      if (my_getnbr(str) > 0)
	option->precision = my_getnbr(str);
      if (my_getnbr(str) > 0)
	nb = nb_len(option->precision) - 1;
      else if (my_getnbr(str) < 0)
	nb = nb_len(option->precision);
      str -= option->pos;
      option->pos += nb;
    }
  option->if_precision = 1;
}

void	get_len(char *str, t_option *option)
{
  int	nb;

  nb = 0;
  if (str[option->pos] == '.')
    get_precision(str, option);
  else
    {
      if (str[option->pos] == '*')
	option->field_width = va_arg(option->arg, int);
      else
	{
	  str += option->pos;
	  option->field_width = my_getnbr(str);
	  nb = nb_len(option->field_width) - 1;
	  str -= option->pos;
	  option->pos += nb;
	}
    }
}
