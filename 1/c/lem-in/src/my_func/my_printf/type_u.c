/*
** type_u.c for type_u in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 15:39:49 2010 tom-brent yau
** Last update Sun Nov 21 21:30:19 2010 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_option	type_u(t_option option)
{
  unsigned int	u;

  u = va_arg(option.arg, unsigned int);
  if (option.zero_pad == 1 && option.minus == 0)
    disp_zero_unsigned(&option, option.field_width, u, 10);
  else if (option.minus == 0)
    disp_space_unsigned(&option, u, 10);
  if (option.precision - nb_len_unsigned(u, 10) > 0)
    disp_zero_unsigned(&option, option.precision, u, 10);
  if (option.precision != 0 || option.if_precision == 0 || u != 0)
    my_putnbr_base(&option, u, "0123456789");
  if (option.minus == 1)
    disp_space_unsigned(&option, u, 10);
  return (option);
}
