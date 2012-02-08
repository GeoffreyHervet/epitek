/*
** type_o.c for type_o in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 15:36:49 2010 tom-brent yau
** Last update Fri Mar 25 02:10:48 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_option	type_o(t_option option)
{
  unsigned int	o;

  o = va_arg(option.arg, unsigned int);
  if (option.hash == 1)
    option.field_width--;
  if (option.zero_pad == 1 && option.minus == 0 && option.precision <= 0)
    disp_zero_unsigned(&option, option.field_width, o, 8);
  else if (option.minus == 0)
    disp_space_unsigned(&option, o, 8);
  if (option.precision - nb_len_unsigned(o, 8) > 0)
    disp_zero_unsigned(&option, option.precision, o, 8);
  if (option.hash == 1)
    my_putchar_p('0', &option);
  if (option.precision != 0 || option.if_precision == 0 || o != 0)
    my_putnbr_base(&option, o, "01234567");
  if (option.minus == 1)
    disp_space_unsigned(&option, o, 8);
  return (option);
}
