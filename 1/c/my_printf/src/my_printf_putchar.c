/*
** my_print_putchar.c for my_printf in /home/hervet_g//work/projets/c/printf
** 
** Made by geoffrey hervet
** Login   <hervet_g@epitech.net>
** 
** Started on  Fri Nov 19 20:33:11 2010 geoffrey hervet
** Last update Fri Nov 19 21:28:18 2010 geoffrey hervet
*/

#include	<unistd.h>
#include	<stdarg.h>

#include	"libmy_printf.h"

void	my_printf_putchar(char c)
{
  write(1, &c, 1);
}

int	my_printf_put_char(t_params *params)
{
  my_printf_putchar((char) va_arg(params->args, int));
  return (1);
}
