/*
** disp_space_string.c for disp_space_string in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Fri Nov 19 15:10:45 2010 tom-brent yau
** Last update Fri Mar 25 02:07:35 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	disp_space_string(t_option *option, int s_len)
{
  if ((option->precision > s_len || option->precision == 0)
      && option->if_precision == 0)
    {
      while (option->field_width - s_len > 0)
	{
	  my_putchar_p(' ', option);
	  option->field_width--;
	}
    }
  else
    {
      while (option->field_width - option->precision > 0)
	{
	  my_putchar_p(' ', option);
	  option->field_width--;
	}
    }
}
