/*
** my_printf_puthex.c for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Sat Nov 20 10:08:09 2010 geoffrey hervet
** Last update Sat Nov 20 18:24:18 2010 geoffrey hervet
*/

#include	<stdarg.h>

#include	"libmy_printf.h"

static void	my_printf_puthex_nbr(int nbr, int type, t_params *params)
{
  if (nbr < 10)
    my_printf_putchar('0' + nbr);
  else if (type)
    my_printf_putchar(nbr + 'A' - 10);
  else
    my_printf_putchar(nbr + 'a' - 10);
  params->char_printed++;
}

static int	my_printf_puthex(t_params *params, int type)
{
  unsigned int	nbr;
  unsigned int	power;
  unsigned int	tmp;

  nbr = va_arg(params->args, unsigned int);
  power = 1;
  tmp = nbr;

  while (tmp >= 16)
    {
      power *= 16;
      tmp /= 16;
    }
  while (power)
    {
      my_printf_puthex_nbr(nbr / power, type, params);
      nbr %= power;
      power /= 16;
    }

  return (0);
}

int		my_printf_puthexl(t_params *params)
{
  return (my_printf_puthex(params, 0));
}

int		my_printf_puthexu(t_params *params)
{
  return (my_printf_puthex(params, 1));
}
