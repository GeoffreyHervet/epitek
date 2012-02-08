/*
** my_printf_putstra.c for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 19 17:54:37 2010 geoffrey hervet
** Last update Sat Nov 20 16:22:48 2010 geoffrey hervet
*/

#include	<stdarg.h>
#include	<unistd.h>

#include	"libmy_printf.h"

static int	my_printf_put_oct(int nbr, int power)
{
  while (power)
    {
      my_printf_putchar('0' + nbr / power);
      nbr %= power;
      power /= 8;
    }

  return (0);
}

static int	my_printf_put_unprintable(int char_u)
{
  my_printf_putchar('\\');
  my_printf_put_oct(char_u, 8*8);
  return (4);
}

int		my_printf_putstra(t_params *params)
{
  char		*aff;
  int		idx;

  idx = -1;
  aff = va_arg(params->args, char *);

  while (aff && aff[++idx])
    {
      if ((aff[idx] < 32) || (aff[idx] >= 127))
	params->char_printed += my_printf_put_unprintable((int) aff[idx]);
      else
	{
	  my_printf_putchar(aff[idx]);
	  params->char_printed ++;
	}
    }

  return (0);
}
