/*
** type_p.c for type_p in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 15:46:38 2010 tom-brent yau
** Last update Fri Mar 25 02:13:18 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_option	type_p(t_option option)
{
  unsigned int	p;

  p = (unsigned int) va_arg(option.arg, void *);
  if (p == 0)
    {
      my_putstr_p("(nil)", &option);
      return (option);
    }
  option.field_width -= 2;
  if (option.minus == 0)
    disp_space_unsigned(&option, p, 16);
  my_putstr_p("0x", &option);
  if (option.precision - nb_len_unsigned(p, 16) > 0)
    disp_zero_unsigned(&option, option.precision, p, 16);
  my_putnbr_base(&option, p, "0123456789abcdef");
  if (option.minus == 1)
    disp_space_unsigned(&option, p, 16);
  return (option);
}
