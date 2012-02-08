/*
** disp_space_int.c for disp_sapce_int in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Nov 18 18:58:13 2010 tom-brent yau
** Last update Fri Mar 25 02:07:11 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	disp_space_int(t_option *option, int nb)
{
  if (option->precision != 0 || option->if_precision == 0 || nb != 0)
    {
      while (option->field_width - nb_len(nb) > 0 &&
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
