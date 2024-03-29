/*
** type_x_down.c for type_x_down in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 15:42:14 2010 tom-brent yau
** Last update Fri Mar 25 02:14:29 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_option	type_x_down(t_option option)
{
  unsigned int	x;

  x = va_arg(option.arg, unsigned int);
  if (option.hash == 1)
    option.field_width--;
  if (option.zero_pad == 1 && option.minus == 0 && option.precision <= 0)
    disp_zero_unsigned(&option, option.field_width, x, 16);
  else if (option.minus == 0)
    disp_space_unsigned(&option, x, 16);
  if (option.precision - nb_len_unsigned(x, 16) > 0)
    disp_zero_unsigned(&option, option.precision, x, 16);
  if (option.hash == 1)
    my_putstr_p("0x", &option);
  if (option.precision != 0 || option.if_precision == 0 || x != 0)
    my_putnbr_base(&option, x, "0123456789abcdef");
  if (option.minus == 1)
    disp_space_unsigned(&option, x, 16);
  return (option);
}
