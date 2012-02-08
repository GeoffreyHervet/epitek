/*
** my_printf_putbin.c for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 19 22:46:13 2010 geoffrey hervet
** Last update Sat Nov 20 14:11:55 2010 geoffrey hervet
*/

#include	<stdarg.h>

#include	"libmy_printf.h"

static int	my_printf_put_bin(int nbr, t_params *params)
{
  if (nbr < 0)
    {
      nbr *= -1;
      my_printf_putchar(PRTF_LESS);
      params->char_printed++;
    }
  if (nbr < 2)
    {
      my_printf_putchar('0' + nbr);
      params->char_printed++;
      return (0);
    }

  return (nbr);
}

int		my_printf_putbin(t_params *params)
{
  int		nbr;
  int		power;
  int		tmp;

  nbr = va_arg(params->args, int);
  power = 1;
  if (nbr < 2)
    if ((nbr = my_printf_put_bin(nbr, params)) == 0)
      return (0);

  tmp = nbr;
  while (tmp >= 2)
    {
      power *= 2;
      tmp /= 2;
    }
  while (power)
    {
      my_printf_putchar('0' + nbr / power);
      params->char_printed++;
      nbr %= power;
      power /= 2;
    }

  return (0);
}

