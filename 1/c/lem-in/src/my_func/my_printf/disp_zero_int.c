/*
** disp_zero_int.c for disp_zero_int in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Nov 18 18:59:56 2010 tom-brent yau
** Last update Fri Mar 25 02:08:21 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	disp_zero_int(t_option *option, int len, int nb)
{
  while (len - nb_len(nb) > 0)
    {
      my_putchar_p('0', option);
      len--;
    }
}
