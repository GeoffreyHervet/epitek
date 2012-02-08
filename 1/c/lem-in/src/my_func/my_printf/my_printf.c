/*
** my_printf.c for my_printf in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Sat Nov 13 18:18:14 2010 tom-brent yau
** Last update Sat Apr 16 17:27:46 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

int	my_printf(char *str, ...)
{
  t_option	option;

  option.pos = 0;
  option.char_printed = 0;
  va_start(option.arg, str);
  while (str && str[option.pos])
    {
      if (str[option.pos] == '%' && str[option.pos + 1])
	call_func(str, &option);
      else
	my_putchar_p(str[option.pos++], &option);
    }
  va_end(option.arg);
  return (option.char_printed);
}
