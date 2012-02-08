/*
** my_printf_putuns.c for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 19 21:41:08 2010 geoffrey hervet
** Last update Sat Nov 20 20:46:11 2010 geoffrey hervet
*/

#include	<stdarg.h>

#include	"libmy_printf.h"

int		my_printf_putuns(t_params *params)
{
  unsigned int	nbr;
  unsigned int	power;
  unsigned int	tmp;

  nbr = va_arg(params->args, int);
  power = 1;

  tmp = nbr;
  while (tmp >= 10)
    {
      power *= 10;
      tmp /= 10;
    }
  while (power)
    {
      my_printf_putchar('0' + nbr / power);
      params->char_printed++;
      nbr %= power;
      power /= 10;
    }
  return (0);
}
