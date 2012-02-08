/*
** my_putnbr_base.c for my_putnbr_base in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Mon Nov 15 17:14:59 2010 tom-brent yau
** Last update Fri Mar 25 02:09:31 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	my_putnbr_base(t_option *option, unsigned int nb, char *base)
{
  if (nb >= my_strlen_unsigned(base))
    my_putnbr_base(option, (nb / my_strlen_unsigned(base)), base);
  my_putchar_p(base[nb % my_strlen_unsigned(base)], option);
}
