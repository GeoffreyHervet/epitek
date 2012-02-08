/*
** call_func.c for call_func in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue Nov 16 11:26:39 2010 tom-brent yau
** Last update Fri Mar 25 02:06:36 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_type	type[] = {
  {'d', &type_d},
  {'i', &type_d},
  {'s', &type_s},
  {'c', &type_c},
  {'o', &type_o},
  {'u', &type_u},
  {'x', &type_x_down},
  {'X', &type_x_up},
  {'p', &type_p},
  {'b', &type_b},
  {'S', &type_s_up},
  {0, 0}
};

int	call_func(char *str, t_option *option)
{
  int	pos2;

  option->zero_pad = 0;
  option->minus = 0;
  option->hash = 0;
  option->plus = 0;
  option->space = 0;
  option->field_width = 0;
  option->precision = 0;
  option->if_precision = 0;
  pos2 = 0;
  if (if_param(str, *option) == 0)
    {
      my_putchar_p(str[option->pos++], option);
      return (0);
    }
  get_flags(str, option);
  while (str[option->pos] != type[pos2].type && type[pos2].type)
    pos2++;
  if (type[pos2].type)
    *option = (type[pos2].f)(*option);
  else if (str[option->pos] == '%')
    my_putchar_p('%', option);
  option->pos++;
  return (0);
}
