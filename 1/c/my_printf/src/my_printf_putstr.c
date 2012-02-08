/*
** my_printf_putstr.c for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 19 17:54:37 2010 geoffrey hervet
** Last update Sun Nov 21 01:58:29 2010 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdarg.h>

#include	"libmy_printf.h"

int	my_printf_putstr(t_params *params)
{
  char	*aff;
  int	idx;

  idx = 0;
  aff = va_arg(params->args, char *);

  if (aff == NULL)
    {
      write(1, "(null)", 6);
      params->char_printed += 6;
      return (0);
    }
  while (aff && aff[idx])
    my_printf_putchar(aff[idx++]);
  params->char_printed += idx;

  return (0);
}
