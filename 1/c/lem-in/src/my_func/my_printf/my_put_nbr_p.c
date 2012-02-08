/*
** my_put_nbr.c for my_put_nbr in /home/yau_t//my_printf
** 
** Made by tom-brent yau
** Login   <yau_t@epitech.net>
** 
** Started on  Thu Nov 18 21:39:15 2010 tom-brent yau
** Last update Fri Mar 25 02:04:26 2011 tom-brent yau
*/

#include	<stdarg.h>
#include	"my_printf.h"

void	my_put_nbr_p(t_option *option, int nb)
{
  if (nb >= 0)
    nb = -nb;
  else
    my_putchar_p('-', option);
  if (nb <= -10)
    my_put_nbr_p(option, (-(nb / 10)));
  my_putchar_p((-(nb % 10)) + '0', option);
}
