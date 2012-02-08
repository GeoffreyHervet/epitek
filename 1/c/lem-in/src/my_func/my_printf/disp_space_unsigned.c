/*
** disp_space_unsigned.c for disp_space_unsigned in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Nov 18 19:32:58 2010 tom-brent yau
** Last update Fri Mar 25 02:08:03 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	disp_space_unsigned(t_option *option, unsigned int nb, int base)
{
  if (option->precision != 0 || option->if_precision == 0 || nb != 0)
    {
      while (option->field_width - nb_len_unsigned(nb, base) > 0 &&
	     option->field_width - option->precision > 0)
	{
	  my_putchar_p(' ', option);
	  option->field_width--;
	}
    }
  else
    {
      while (option->field_width > 0)
	{
	  my_putchar_p(' ', option);
	  option->field_width--;
	}
    }
}
