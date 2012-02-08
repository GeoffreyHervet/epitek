/*
** type_b.c for type_b in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Tue Nov 16 10:35:52 2010 tom-brent yau
** Last update Sun Nov 21 21:29:14 2010 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_option	type_b(t_option option)
{
  unsigned int	b;

  b = va_arg(option.arg, unsigned int);
  if (option.zero_pad == 1 && option.minus == 0 && option.precision <= 0)
    disp_zero_unsigned(&option, option.field_width, b, 2);
  else if (option.minus == 0)
    disp_space_unsigned(&option, b, 2);
  if (option.precision - nb_len_unsigned(b, 2) > 0)
    disp_zero_unsigned(&option, option.precision, b, 2);
  if ((option.precision != 0 || option.if_precision == 0) || b != 0)
    my_putnbr_base(&option, b, "01");
  if (option.minus == 1)
    disp_space_unsigned(&option, b, 2);
  return (option);
}
