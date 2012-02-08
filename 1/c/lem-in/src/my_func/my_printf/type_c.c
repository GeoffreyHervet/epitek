/*
** type_c.c for type_c in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 12:17:32 2010 tom-brent yau
** Last update Fri Mar 25 02:10:15 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

t_option	type_c(t_option option)
{
  char	c;

  c = (char) va_arg(option.arg, int);
  if (option.minus == 0)
    {
      while (option.field_width - 1 > 0)
	{
	  my_putchar_p(' ', &option);
	  option.field_width--;
	}
    }
  my_putchar_p(c, &option);
  if (option.minus == 1)
    {
      while (option.field_width - 1 > 0)
	{
	  my_putchar_p(' ', &option);
	  option.field_width--;
	}
    }
  return (option);
}
