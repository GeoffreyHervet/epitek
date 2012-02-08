/*
** disp_zero_unsigned.c for disp_zero_unsigned in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Nov 18 19:30:30 2010 tom-brent yau
** Last update Fri Mar 25 02:08:37 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	disp_zero_unsigned(t_option *option, int len, unsigned int nb,
			   int base)
{
  while (len - nb_len_unsigned(nb, base) > 0)
    {
      my_putchar_p('0', option);
      len--;
    }
}
