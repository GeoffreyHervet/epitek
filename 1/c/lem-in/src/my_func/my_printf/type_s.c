/*
** type_s.c for type_s in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 11:37:13 2010 tom-brent yau
** Last update Fri Mar 25 02:13:40 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_option	type_s(t_option option)
{
  char	*s;
  int	pos;
  int	precision;

  pos = 0;
  precision = option.precision;
  s = va_arg(option.arg, char *);
  if (s == 0)
    {
      my_putstr_p("(null)", &option);
      return (option);
    }
  if (option.minus == 0)
    disp_space_string(&option, my_strlen(s));
  if ((precision > my_strlen(s) || precision == 0) && option.if_precision == 0)
    my_putstr_p(s, &option);
  else if (precision != 0 && option.if_precision)
    while (precision--)
      my_putchar_p(s[pos++], &option);
  if (option.minus == 1)
    disp_space_string(&option, my_strlen(s));
  return (option);
}
