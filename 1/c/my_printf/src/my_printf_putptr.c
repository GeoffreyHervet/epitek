/*
** my_printf_putprtr.c for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 19 21:41:08 2010 geoffrey hervet
** Last update Sun Nov 21 02:25:18 2010 geoffrey hervet
*/

#include	<stdarg.h>
#include	<unistd.h>
#include	"libmy_printf.h"

static void	my_printf_puthex_nbr(unsigned int nbr, t_params *params)
{
  if (nbr < 10)
    my_printf_putchar('0' + nbr);
  else
    my_printf_putchar(nbr + 'a' - 10);
  params->char_printed++;
}

static int	my_printf_putnill(t_params *params)
{
  write(1, "(nill)", 6);
  params->char_printed += 6;
  return (0);
}

int		my_printf_putptr(t_params *params)
{
  unsigned int	nbr;
  unsigned int	power;
  unsigned int	tmp;

  if ((nbr = va_arg(params->args, unsigned int)) == 0)
    return (my_printf_putnill(params));
  power = 1;
  write(1, "0x", 2);
  params->char_printed += 2;
  tmp = nbr;
  while (tmp >= 16)
    {
      power *= 16;
      tmp /= 16;
    }
  while (power)
    {
      my_printf_puthex_nbr(nbr / power, params);
      nbr %= power;
      power /= 16;
    }
  return (0);
}
