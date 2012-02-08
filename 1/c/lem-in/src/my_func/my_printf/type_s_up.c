/*
** type_s_up.c for type_s_up in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue Nov 16 10:41:36 2010 tom-brent yau
** Last update Fri Mar 25 02:14:08 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	disp_s_up(t_option *option, char *s)
{
  int	pos;
  int	precision;

  precision = option->precision;
  pos = 0;
  if ((precision > my_strlen(s) || precision == 0) &&
      option->if_precision == 0)
    precision = my_strlen(s);
  while (s[pos] && precision > 0)
    {
      if (s[pos] < 32 || s[pos] >= 127)
        {
          my_putchar_p('\\', option);
	  if (s[pos] < 64)
	    my_putchar_p('0', option);
          if (s[pos] < 8)
            my_putchar_p('0', option);
          my_putnbr_base(option, s[pos++], "01234567");
        }
      else
        my_putchar_p(s[pos++], option);
      precision--;
    }
}

t_option	type_s_up(t_option option)
{
  char	*s;
  int	pos;
  int	precision;

  precision = option.precision;
  s = va_arg(option.arg, char *);
  if (s == 0)
    {
      my_putstr_p("(null)", &option);
      return (option);
    }
  pos = 0;
  while (s[pos] && (precision-- || option.if_precision == 0))
    {
      if (s[pos] < 32 || s[pos] >= 127)
	option.field_width -= 3;
      pos++;
    }
  if (option.minus == 0)
    disp_space_string(&option, my_strlen(s));
  disp_s_up(&option, s);
  if (option.minus == 1)
    disp_space_string(&option, my_strlen(s));
  return (option);
}
