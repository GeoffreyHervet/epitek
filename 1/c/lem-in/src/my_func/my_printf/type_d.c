/*
** type_d.c for type_d in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 11:38:10 2010 tom-brent yau
** Last update Fri Mar 25 02:12:45 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_option	type_d(t_option option)
{
  int	d;

  d = va_arg(option.arg, int);
  if (option.space == 1 && option.plus == 0)
    {
      my_putchar_p(' ', &option);
      option.field_width--;
    }
  else if (option.plus == 1 && d >= 0)
    {
      my_putchar_p('+', &option);
      option.field_width--;
    }
  if (option.zero_pad == 1 && option.minus == 0 && option.if_precision == 0)
    disp_zero_int(&option, option.field_width, d);
  else if (option.minus == 0)
    disp_space_int(&option, d);
  if (option.precision - nb_len(d) > 0)
    disp_zero_int(&option, option.precision, d);
  if ((option.precision != 0 || option.if_precision == 0) || d != 0)
    my_put_nbr_p(&option, d);
  if (option.minus == 1)
    disp_space_int(&option, d);
  return (option);
}
